#include "Surface 3D.h"

#include <libfreenect.h>
#include <libfreenect_sync.h>

#include <libfreenect2/libfreenect2.hpp>
#include <libfreenect2/frame_listener_impl.h>
#include <libfreenect2/registration.h>
#include <libfreenect2/packet_pipeline.h>
#include <libfreenect2/logger.h>

// https://www.youtube.com/watch?v=L1Kgm4S8c90
// https://www.youtube.com/watch?v=E1eIg54clGo


libfreenect2::Freenect2 freenect2;
int Kinect2NB = 0;




class Kinect2APP{
public:
	int RefIndex = 0;
	char serialnumber[30] = "";

	PCL_POINTCLOUD Points;
	float GlobalColor[3];
	Eigen::Vector3f Focal_Center;
	bool normals_calculate = false;

	int m_width = 512;
	int m_height = 424;

	bool started = false;
	bool opened = true;

	float depthMin = 0.5, depthMax = 1.5;
	//for display:
	bool DrawPoints = true;
	bool DrawNormals = true;
	bool DrawPset = true;

	//for calibration
	vector<vector<Eigen::Vector3f>> RefPoints;
	Eigen::VectorXf Translation = Eigen::VectorXf::Zero(3);
	Eigen::MatrixXf Rotation = Eigen::MatrixXf::Identity(3, 3);

	Eigen::MatrixXf GridPointsData;

	CVLib::CalibrationResults CalibResults;

	MLLib::LINEAR_REGRESSION_CLASS Regression_calibration_x;
	MLLib::LINEAR_REGRESSION_CLASS Regression_calibration_y;
	MLLib::LINEAR_REGRESSION_CLASS Regression_calibration_d;

	int left_refindex;
	int right_refindex;
	int slicing_points[3];

private:
	libfreenect2::Freenect2Device* dev;
	libfreenect2::SyncMultiFrameListener* listener;

	int filter_width_half;
	int filter_height_half;
	float filter_tolerance;

	int UpSampleFactor = 2;

	float* distort_map_x;
	float* distort_map_y;
	float* depth_to_color_map_x;
	float* depth_to_color_map_y;
	int* depth_to_color_map_yi;

	libfreenect2::Frame *registered_frame;
	libfreenect2::Frame* undistorted_frame;

	int frame_ID;

public:
	float adjust_a = 0;
	float adjust_b = 0;
	float* depth_data;
	float* depth_data_undistorted;
	unsigned int* rgb_data;

	libfreenect2::Freenect2Device::IrCameraParams IrParameters;
	libfreenect2::Freenect2Device::ColorCameraParams ColorParameters;

	Kinect2APP()
	{
		GridPointsData = Eigen::MatrixXf::Zero(0, 22);
		RefIndex = 0;
		SetSlicingData(-1, -1, 0, 0, 0);

		depth_data = new float[512 * 424];
		depth_data_undistorted = new float[512 * 424];
		rgb_data = new unsigned int[1920 * 1080];

		registered_frame = NULL;
		undistorted_frame = NULL;
		distort_map_x = NULL;
		distort_map_y = NULL;
		depth_to_color_map_x = NULL;
		depth_to_color_map_y = NULL;
		depth_to_color_map_yi = NULL;

		frame_ID = 0;
	}
	~Kinect2APP()
	{
		delete[] depth_data;
		delete[] depth_data_undistorted;
		delete[] rgb_data;

		if (registered_frame != NULL)	delete registered_frame;
		if (undistorted_frame != NULL)	delete undistorted_frame;
	}
	void init(libfreenect2::Freenect2Device* d)
	{
		libfreenect2::Freenect2Device::Config config;
		config.MinDepth = 0.005f;
		config.MaxDepth = 4.5f;
		config.EnableBilateralFilter = true;
		config.EnableEdgeAwareFilter = true;

		listener = new libfreenect2::SyncMultiFrameListener(libfreenect2::Frame::BGRX | libfreenect2::Frame::Color | libfreenect2::Frame::Ir | libfreenect2::Frame::Depth);
		dev = d;
		dev->setConfiguration(config);
		dev->setColorFrameListener(listener);
		dev->setIrAndDepthFrameListener(listener);
		sprintf(serialnumber, "%s", dev->getSerialNumber());

		frame_ID = 0;
		//IrParameters = dev->getIrCameraParams();
		//ColorParameters = dev->getColorCameraParams();
	}
	void CreateParams()
	{
		UpSampleFactor = SETTINGS::Scan::upsampling_factor;

		if (distort_map_x) { delete[] distort_map_x; distort_map_x = NULL; }
		if (distort_map_y) { delete[] distort_map_y; distort_map_y = NULL; }
		if (depth_to_color_map_x) { delete[] depth_to_color_map_x; depth_to_color_map_x = NULL; }
		if (depth_to_color_map_y) { delete[] depth_to_color_map_y; depth_to_color_map_y = NULL; }
		if (depth_to_color_map_yi) { delete[] depth_to_color_map_yi; depth_to_color_map_yi = NULL; }

		distort_map_x = new float[512 * UpSampleFactor * 424 * UpSampleFactor];
		distort_map_y = new float[512 * UpSampleFactor * 424 * UpSampleFactor];
		depth_to_color_map_x = new float[512 * UpSampleFactor * 424 * UpSampleFactor];
		depth_to_color_map_y = new float[512 * UpSampleFactor * 424 * UpSampleFactor];
		depth_to_color_map_yi = new int[512 * UpSampleFactor * 424 * UpSampleFactor];

		SetCamParams(IrParameters, ColorParameters);
	}

	void DeleteParams()
	{
		if (distort_map_x) { delete[] distort_map_x; distort_map_x = NULL; }
		if (distort_map_y) { delete[] distort_map_y; distort_map_y = NULL; }
		if (depth_to_color_map_x) { delete[] depth_to_color_map_x; depth_to_color_map_x = NULL; }
		if (depth_to_color_map_y) { delete[] depth_to_color_map_y; depth_to_color_map_y = NULL; }
		if (depth_to_color_map_yi) { delete[] depth_to_color_map_yi; depth_to_color_map_yi = NULL; }
	}
	void Start()
	{
		if (!started)
		{
			frame_ID = 0;
			dev->start();
			IrParameters = dev->getIrCameraParams();
			ColorParameters = dev->getColorCameraParams();
			started = true;
			CreateParams();
			
		}
	}

	void Stop()
	{
		if (started)
		{
			frame_ID = 0;
			//libfreenect2::FrameMap frames;
			//listener->waitForNewFrame(frames);

			dev->stop();
			started = false;
			//listener->release(frames);
		}
		DeleteParams();
	}

	void ShutDown()
	{
		if (started) dev->stop();
		dev->close();
		started = false;
		delete dev;
		delete listener;
	}
	void depth_to_color(float mx, float my, float& rx, float& ry) const
	{

		float depth_q = 0.01;
		float color_q = 0.002199;

		mx = (mx - IrParameters.cx) * depth_q;
		my = (my - IrParameters.cy) * depth_q;

		float wx =
			(mx * mx * mx * ColorParameters.mx_x3y0) + (my * my * my * ColorParameters.mx_x0y3) +
			(mx * mx * my * ColorParameters.mx_x2y1) + (my * my * mx * ColorParameters.mx_x1y2) +
			(mx * mx * ColorParameters.mx_x2y0) + (my * my * ColorParameters.mx_x0y2) + (mx * my * ColorParameters.mx_x1y1) +
			(mx * ColorParameters.mx_x1y0) + (my * ColorParameters.mx_x0y1) + (ColorParameters.mx_x0y0);

		float wy =
			(mx * mx * mx * ColorParameters.my_x3y0) + (my * my * my * ColorParameters.my_x0y3) +
			(mx * mx * my * ColorParameters.my_x2y1) + (my * my * mx * ColorParameters.my_x1y2) +
			(mx * mx * ColorParameters.my_x2y0) + (my * my * ColorParameters.my_x0y2) + (mx * my * ColorParameters.my_x1y1) +
			(mx * ColorParameters.my_x1y0) + (my * ColorParameters.my_x0y1) + (ColorParameters.my_x0y0);

		rx = (wx / (ColorParameters.fx * color_q)) - (ColorParameters.shift_m / ColorParameters.shift_d);
		ry = (wy / color_q) + ColorParameters.cy;
	}
	void distort(float mx, float my, float& x, float& y) const
	{
		// see http://en.wikipedia.org/wiki/Distortion_(optics) for description
		float dx = (mx - IrParameters.cx) / IrParameters.fx;
		float dy = (my - IrParameters.cy) / IrParameters.fy;
		float dx2 = dx * dx;
		float dy2 = dy * dy;
		float r2 = dx2 + dy2;
		float dxdy2 = 2 * dx * dy;
		float kr = 1 + ((IrParameters.k3 * r2 + IrParameters.k2) * r2 + IrParameters.k1) * r2;
		x = IrParameters.fx * (dx * kr + IrParameters.p2 * (r2 + 2 * dx2) + IrParameters.p1 * dxdy2) + IrParameters.cx;
		y = IrParameters.fy * (dy * kr + IrParameters.p1 * (r2 + 2 * dy2) + IrParameters.p2 * dxdy2) + IrParameters.cy;
	}

	void SetCamParams(libfreenect2::Freenect2Device::IrCameraParams irparams, libfreenect2::Freenect2Device::ColorCameraParams rgbparams)
	{
		int n = UpSampleFactor;
		IrParameters = irparams; ColorParameters = rgbparams;
		filter_width_half = 0; filter_height_half = 1; filter_tolerance = 0.01f;

		float mx, my;
		float index_x, index_y;
		float rx, ry;
		float* map_dist_x = distort_map_x;
		float* map_dist_y = distort_map_y;
		float* map_x = depth_to_color_map_x;
		float* map_y = depth_to_color_map_y;
		int* map_yi = depth_to_color_map_yi;

		for (float y = 0; y < 424 * n; y++) {
			for (float x = 0; x < 512 * n; x++) {
				// compute the dirstored coordinate for current pixel
				distort(x / float(n), y / float(n), mx, my);
				if (mx < 0 || mx >= 512 || my < 0 || my >= 424)
					index_x = index_y = -1;
				else
				{
					// computing the index from the coordianted for faster access to the data
					index_x = mx;
					index_y = my;

				}
				*map_dist_x++ = index_x;
				*map_dist_y++ = index_y;

				// compute the depth to color mapping entries for the current pixel
				depth_to_color(mx, my, rx, ry);
				*map_x++ = rx;
				*map_y++ = ry;
				// compute the y offset to minimize later computations
				*map_yi++ = (int)(ry + 0.5f);
			}
		}
	}
	void Apply(unsigned int* rgb_data, float* depth_data, const bool enable_filter, libfreenect2::Frame* bigdepth)
	{
		int n = UpSampleFactor;
		// Check if all frames are valid and have the correct size
		/*
		if (!rgb || !depth || !undistorted || !registered ||
			rgb->width != 1920 || rgb->height != 1080 || rgb->bytes_per_pixel != 4 ||
			depth->width != 512 || depth->height != 424 || depth->bytes_per_pixel != 4 ||
			undistorted->width != n * 512 || undistorted->height != n * 424 || undistorted->bytes_per_pixel != 4 ||
			registered->width != n * 512 || registered->height != n * 424 || registered->bytes_per_pixel != 4)
			return;

		const float* depth_data = (float*)depth->data;
		const unsigned int* rgb_data = (unsigned int*)rgb->data;
		*/
		//if (registered != NULL) delete registered;

		if (registered_frame != NULL) delete registered_frame;
		registered_frame = new libfreenect2::Frame(512 * n, 424 * n, 4);

		if (undistorted_frame != NULL) delete undistorted_frame;
		undistorted_frame = new libfreenect2::Frame(512 * n, 424 * n, 4);

		float* undistorted_data = (float*)undistorted_frame->data;
		unsigned int* registered_data = (unsigned int*)registered_frame->data;
		const float* map_dist_x = distort_map_x;
		const float* map_dist_y = distort_map_y;
		const float* map_x = depth_to_color_map_x;
		const float* map_y = depth_to_color_map_y;
		const int* map_yi = depth_to_color_map_yi;

		const int size_depth = 512 * 424 * n * n;
		const int size_color = 1920 * 1080;
		const float color_cx = ColorParameters.cx + 0.5f; // 0.5f added for later rounding

		// size of filter map with a border of filter_height_half on top and bottom so that no check for borders is needed.
		// since the color image is wide angle no border to the sides is needed.
		const int size_filter_map = size_color + 1920 * filter_height_half * 2;
		// offset to the important data
		const int offset_filter_map = 1920 * filter_height_half;

		// map for storing the min z values used for each color pixel
		float* filter_map = NULL;
		// pointer to the beginning of the important data
		float* p_filter_map = NULL;

		// map for storing the color offset for each depth pixel
		int* depth_to_c_off = new int[size_depth];
		int* map_c_off = depth_to_c_off;

		// initializing the depth_map with values outside of the Kinect2 range
		if (enable_filter) {
			filter_map = bigdepth ? (float*)bigdepth->data : new float[size_filter_map];
			p_filter_map = filter_map + offset_filter_map;

			for (float* it = filter_map, *end = filter_map + size_filter_map; it != end; ++it) {
				*it = std::numeric_limits<float>::infinity();
			}
		}

		/* Fix depth distortion, and compute pixel to use from 'rgb' based on depth measurement,
		 * stored as x/y offset in the rgb data.
		 */

		 // iterating over all pixels from undistorted depth and registered color image
		 // the four maps have the same structure as the images, so their pointers are increased each iteration as well
		for (int i = 0; i < size_depth; ++i, ++undistorted_data, ++map_dist_x, ++map_dist_y, ++map_x, ++map_y, ++map_yi, ++map_c_off) {
			// getting index of distorted depth pixel
			const float index_x = *map_dist_x;
			const float index_y = *map_dist_y;

			// check if distorted depth pixel is outside of the depth image
			if (index_x < 0 || index_y<0) {
				*map_c_off = -1;
				*undistorted_data = 0;
				continue;
			}

			// getting depth value for current pixel
			float z, d[4], f1_x, f2_x, f1_y, f2_y; int indexes[4];

			indexes[0] = int(index_x) + int(index_y) * 512;

			if( index_x == float(int(index_x)) && index_y == float(int(index_y)))
				z = depth_data[indexes[0]];
			else
			{
				indexes[0] = int(index_x) + int(index_y) * 512;
				indexes[1] = int(index_x + 1) + int(index_y) * 512;
				indexes[2] = int(index_x) + int(index_y + 1) * 512;
				indexes[3] = int(index_x + 1) + int(index_y + 1) * 512;

				f1_x = index_x - int(index_x); f2_x = 1 - f1_x;
				f1_y = index_y - int(index_y); f2_y = 1 - f1_y;

				d[0] = pow(sqrt(f1_x * f1_x + f1_y * f1_y), SETTINGS::Scan::interpolation_factor);
				d[1] = pow(sqrt(f2_x * f2_x + f1_y * f1_y), SETTINGS::Scan::interpolation_factor);
				d[2] = pow(sqrt(f1_x * f1_x + f2_y * f2_y), SETTINGS::Scan::interpolation_factor);
				d[3] = pow(sqrt(f2_x * f2_x + f2_y * f2_y), SETTINGS::Scan::interpolation_factor);

				z = 0; float w = 0;
				for (int k = 0; k < 4; k++) if( indexes[k] < size_depth && depth_data[indexes[k]] > 0.5)
				{
					z += depth_data[indexes[k]] / d[k];
					w += 1 / d[k];
				}
				if (w == 0) z = 0;
				else z /= w;
			}
			*undistorted_data = z;


			// checking for invalid depth value
			if (z <= 0.0f) {
				*map_c_off = -1;
				continue;
			}

			// calculating x offset for rgb image based on depth value
			const float rx = (*map_x + (ColorParameters.shift_m / z)) * ColorParameters.fx + color_cx;
			const int cx = rx; // same as round for positive numbers (0.5f was already added to color_cx)
			// getting y offset for depth image
			const int cy = *map_y; // *map_yi;
			// combining offsets
			const int c_off = cx + cy * 1920;

			// check if c_off is outside of rgb image
			// checking rx/cx is not needed because the color image is much wider then the depth image
			if (c_off < 0 || c_off >= size_color) {
				*map_c_off = -1;
				continue;
			}

			// saving the offset for later
			*map_c_off = c_off;

			if (enable_filter) {
				// setting a window around the filter map pixel corresponding to the color pixel with the current z value
				int yi = (cy - filter_height_half) * 1920 + cx - filter_width_half; // index of first pixel to set
				for (int r = -filter_height_half; r <= filter_height_half; ++r, yi += 1920) // index increased by a full row each iteration
				{
					float* it = p_filter_map + yi;
					for (int c = -filter_width_half; c <= filter_width_half; ++c, ++it)
					{
						// only set if the current z is smaller
						if (z < *it)
							*it = z;
					}
				}
			}
		}

		/* Construct 'registered' image. */

		// reseting the pointers to the beginning
		map_c_off = depth_to_c_off;
		undistorted_data = (float*)undistorted_frame->data;

		/* Filter drops duplicate pixels due to aspect of two cameras. */
		if (enable_filter) {
			// run through all registered color pixels and set them based on filter results
			for (int i = 0; i < size_depth; ++i, ++map_c_off, ++undistorted_data, ++registered_data) {
				const int c_off = *map_c_off;

				// check if offset is out of image
				if (c_off < 0) {
					*registered_data = 0;
					continue;
				}

				const float min_z = p_filter_map[c_off];
				const float z = *undistorted_data;

				// check for allowed depth noise
				*registered_data = (z - min_z) / z > filter_tolerance ? 0 : *(rgb_data + c_off);
			}

			if (!bigdepth) delete[] filter_map;
		}
		else
		{
			// run through all registered color pixels and set them based on c_off
			for (int i = 0; i < size_depth; ++i, ++map_c_off, ++registered_data) {
				const int c_off = *map_c_off;

				// check if offset is out of image
				*registered_data = c_off < 0 ? 0 : *(rgb_data + c_off);
			}
		}
		delete[] depth_to_c_off;
	}
	void getPointXYZ(float r, float c, float& x, float& y, float& z)
	{
		int n = UpSampleFactor;
		const float bad_point = std::numeric_limits<float>::quiet_NaN();
		const float cx(IrParameters.cx), cy(IrParameters.cy);
		const float fx(1 / (IrParameters.fx)), fy(1 / (IrParameters.fy));
		float* undistorted_data = (float*)undistorted_frame->data;
		float depth_val = undistorted_data[512 * n * int(r) + int(c)] / 1000.0f; //scaling factor, so that value of 1 is one meter.
		if (isnan(depth_val) || depth_val <= 0.001)
		{
			//depth value is not valid
			x = y = z = bad_point;
		}
		else
		{
			z = depth_val;
			x = (c / float(n) - cx) * fx * depth_val;
			y = (r / float(n) - cy) * fy * depth_val;


			if (Regression_calibration_x.IsDone() && Regression_calibration_y.IsDone() && Regression_calibration_d.IsDone())
			{
				Eigen::VectorXf AX = Regression_calibration_x.GetA();
				Eigen::VectorXf AY = Regression_calibration_y.GetA();

				r = r / float(n) - cy;
				c = c / float(n) - cx;
				int regression_order = (AX.size() - 1) / 3;
				Eigen::VectorXf inputsV = Eigen::VectorXf::Zero(3 * regression_order);

				for (int i = 0; i < regression_order; i++)
				{
					inputsV(0 + i * 3) = pow(r, float(i) + 1);
					inputsV(1 + i * 3) = pow(c, float(i) + 1);
					inputsV(2 + i * 3) = pow(depth_val, float(i) + 1);
				}

				float ex = Regression_calibration_x.CalculateValue(inputsV);
				float ey = Regression_calibration_y.CalculateValue(inputsV);
				float ed = Regression_calibration_d.CalculateValue(inputsV);

				x *= 1 - ex / 100.0;
				y *= 1 - ey / 100.0;
				
				if (z > 0.5)
				{
					z -= SETTINGS::Scan::depth_origin;
					z *= 1 - ed / 100.0;
					z += SETTINGS::Scan::depth_origin;
				}
				
			}

		}
	}
	void getPointXYZRGB(int r, int c, float& x, float& y, float& z, float& rgb)
	{
		int n = UpSampleFactor;
		getPointXYZ(r, c, x, y, z);

		if (isnan(z))
		{
			rgb = 0;
		}
		else
		{
			float* registered_data = (float*)registered_frame->data;
			rgb = registered_data[registered_frame->width * r + c];
		}
	}

	Eigen::Vector3f getPointfromFrame(float r, float c)
	{
		Eigen::Vector3f P;
		float  x, y, z, depth_val;
		getPointXYZ(r, c, x, z, y);

		P(0) = y;
		P(1) = x;
		P(2) = -z;

		P = Rotation * P + Translation;

		return P;
	}
	vector<Eigen::Vector3f> ConvertChessBoardTo3D(CVLib::CalibrationResults* R)
	{
		int n = UpSampleFactor;
		float depth_val;
		float X = 0, Y = 0, Z = 0;
		Eigen::Vector3f P;
		vector<Eigen::Vector3f> retPoints;

		for (int i = 0; i < R->GetCornersNB(R->GetFramesNB()-1); i++)
		{
			float r, c;
			R->GetCornerPoint(R->GetFramesNB() - 1, i, c, r);

			P = getPointfromFrame(r,c);
			retPoints.push_back(P);
		}
		
		//focal center:
		//P = getPointfromFrame(IrParameters.cy * float(n), IrParameters.cx * float(n));
		//retPoints.push_back(P);


		return retPoints;
	}
	void CreatePointCloud()
	{
		int n = UpSampleFactor;
		float X = 0, Y = 0, Z = 0, RGBVALUE = 0;
		float V[3], color[3];
		float depth_val;
		libfreenect2::Frame depth2rgb(1920, 1080 + 2, 4); // check here (https://github.com/OpenKinect/libfreenect2/issues/337) and here (https://github.com/OpenKinect/libfreenect2/issues/464) why depth2rgb image should be bigger
		Apply(rgb_data, depth_data, true, &depth2rgb);
		
		Points.Clear();

		int i = 0, N=0;
		
		
		for (int r = 0; r < registered_frame->height; r++)
			for (int c = 0; c < registered_frame->width; c++)
			{

				getPointXYZRGB(r, c, X, Z, Y, RGBVALUE);

				const uint8_t* p = reinterpret_cast<uint8_t*>(&RGBVALUE);
				uint8_t BL = p[0];      color[2] = float(BL) / 255;
				uint8_t GRN = p[1];     color[1] = float(GRN) / 255;
				uint8_t RD = p[2];		color[0] = float(RD) / 255;

				V[0] = Y;
				V[1] = X;
				V[2] = -Z;

				Points.AddPoint(V[0], V[1], V[2], color[0], color[1], color[2]);

				if (c % n == 0 && r % n == 0)
				{
					depth_data_undistorted[N] = depth_val * 1000;
					N++;
				}
			}

		getPointXYZRGB(IrParameters.cy, IrParameters.cx, Focal_Center(1), Focal_Center(2), Focal_Center(0), RGBVALUE);
		Focal_Center(2) *= -1;

		m_width = registered_frame->width;
		m_height = registered_frame->height;

		System::Console::WriteLine(L"");
		System::Console::WriteLine(gcnew System::String(serialnumber) + L"  Point CLoud Created");
		System::Console::WriteLine(L"");
		
	}
	int GetDepthFrameFromDevice(int frames_number = 1)
	{
		libfreenect2::Registration* registration = new libfreenect2::Registration(IrParameters, ColorParameters);
		int* depth_frNB;  depth_frNB = new int[512 * 424];

		for (int k = 0; k < 512 * 424; k++) depth_data[k] = depth_frNB[k] = 0;
			   
		for (int i = 0; i < frames_number; i++)
		{
			libfreenect2::FrameMap frames;
			Sleep(100);
			if (!listener->waitForNewFrame(frames, 10000)) // 1 seconds
				return false;

			libfreenect2::Frame* rgb = frames[libfreenect2::Frame::Color];
			libfreenect2::Frame* ir = frames[libfreenect2::Frame::Ir];
			libfreenect2::Frame* depth = frames[libfreenect2::Frame::Depth];

			float* depth_d = (float*)depth->data;
			int* rgb_d = (int*)rgb->data;

			for (int k = 0; k < 512 * 424; k++) if (depth_d[k] <= depthMax * 1000 && depth_d[k] >= depthMin * 1000)
			{
				depth_data[k] += depth_d[k];
				depth_frNB[k]++;
			}


			if (i == 0) for (int k = 0; k < 1920 * 1080; k++) rgb_data[k] = rgb_d[k];
			listener->release(frames);
		}

		if (frames_number > 1)
			for (int k = 0; k < 512 * 424; k++)
				if (depth_frNB[k] > 0)
					depth_data[k] /= float(depth_frNB[k]);
				else depth_data[k] = 0;


		delete[] depth_frNB;

		System::Console::WriteLine("Depth Frame from device has been taken.");

		return true;
	}
	int GetDepthFrame(int frames_number = 1, bool fillgapse = false)
	{
		bool B = GetDepthFrameFromDevice(frames_number);
		if (B)
		{
			frame_ID++;
			if (fillgapse) FillDepthGapes();
			CreatePointCloud();

			System::Console::WriteLine(L"");
			System::Console::WriteLine(L"Kincet SN: " + gcnew System::String(serialnumber) +"   Taking Frame  " + frame_ID);
			System::Console::WriteLine(L"");
		}

		return B;
	}

	bool CaluclateRotationTranslation(vector<vector<Eigen::Vector3f>> reference, int excluded_device = -1 )
	{
		bool B = false;

		Eigen::Matrix3f R; Eigen::Vector3f T;

		//reverse the coordinates
		ReverseTransformedCorrdinates(Rotation, Translation);

		if (EstimateRotationMatrix(RefPoints, reference, R, T, excluded_device))
		{
			//set new rotation matrix and translation vector
			Rotation = R; Translation = T; 

			B = true;
		}

		//calculate new coordinates of all points
		CalculateTransformedCoordinates(Rotation, Translation);

		return B;
	}

	bool CaluclateRotationTranslation(vector<Eigen::Vector3f> reference_points, int dest_device)
	{
		bool B = false;

		Eigen::Matrix3f R; Eigen::Vector3f T;

		vector < vector<Eigen::Vector3f>> source, dest;
		source.clear();   dest.clear();

		source.push_back(RefPoints.at(dest_device));
		dest.push_back(reference_points);

		//reverse the coordinates
		ReverseTransformedCorrdinates(Rotation, Translation);

		if (EstimateRotationMatrix(source, dest, R, T))
		{
			//set new rotation matrix and translation vector
			Rotation = R; Translation = T;

			B = true;
		}

		//calculate new coordinates of all points
		CalculateTransformedCoordinates(Rotation, Translation);

		return B;
	}

	void ExportFrame(char* filename)
	{
		FILE* f;
		float P[3];		

		fopen_s(&f, filename, "wb");

		fwrite(&IrParameters, sizeof(libfreenect2::Freenect2Device::IrCameraParams), 1, f);
		fwrite(&ColorParameters, sizeof(libfreenect2::Freenect2Device::ColorCameraParams), 1, f);

		fwrite(depth_data, sizeof(float), 512 * 424, f);
		fwrite(rgb_data, sizeof(unsigned int), 1920 * 1080, f);		

		fclose(f);
	}

	void ImportFrame(char* filename)
	{
		FILE* f; int N = 0; float P[3];

		fopen_s(&f, filename, "rb");
		
		fread(&IrParameters, sizeof(libfreenect2::Freenect2Device::IrCameraParams), 1, f);
		fread(&ColorParameters, sizeof(libfreenect2::Freenect2Device::ColorCameraParams), 1, f);

		fread(depth_data, sizeof(float), 512 * 424, f);
		fread(rgb_data, sizeof(unsigned int), 1920 * 1080, f);		

		for (int i = 0; i < 512 * 424; i++)
			if (depth_data[i] > depthMax * 1000) depth_data[i] = 0;
			
		fclose(f);


		System::Console::WriteLine(L"");
		System::Console::WriteLine(gcnew System::String(serialnumber) + L"  Frame Loaded From File");
		System::Console::WriteLine(L"");
	}

	void FillDepthGapes()
	{
		int N; float depth_value = 0;
		for (int r = 0; r < 424; r++) for (int c = 0; c < 512; c++)
		{
			N = 0; depth_value = 0;
			if (depth_data[c + r * 512] <= 0.5)
			{
				if (c - 1 >= 0)
				{
					if (r - 1 >= 0 && depth_data[c - 1 + (r - 1) * 512] > 0.5)
					{
						depth_value += depth_data[c - 1 + (r - 1) * 512]; N++;
					}
					if (depth_data[c - 1 + r * 512] > 0.5)
					{
						depth_value += depth_data[c - 1 + r * 512]; N++;
					}
					if (r + 1 <= 423 && depth_data[c - 1 + (r + 1) * 512] > 0.5)
					{
						depth_value += depth_data[c - 1 + (r + 1) * 512]; N++;
					}
				}

				if (r - 1 >= 0 && depth_data[c + (r - 1) * 512] > 0.5)
				{
					depth_value += depth_data[c + (r - 1) * 512]; N++;
				}
				if (r + 1 < 424 && depth_data[c + (r + 1) * 512] > 0.5)
				{
					depth_value += depth_data[c + (r + 1) * 512]; N++;
				}

				if (c + 1 < 512)
				{
					if (r - 1 >= 0 && depth_data[c + 1 + (r - 1) * 512] > 0.5)
					{
						depth_value += depth_data[c + 1 + (r - 1) * 512]; N++;
					}
					if (depth_data[c + 1 + r * 512] > 0.5)
					{
						depth_value += depth_data[c + 1 + r * 512]; N++;
					}
					if (r + 1 < 424 && depth_data[c + 1 + (r + 1) * 512] > 0.5)
					{
						depth_value += depth_data[c + 1 + (r + 1) * 512]; N++;
					}
				}

				depth_data[c + r * 512] = depth_value / float(N);

			}
		}
	}

	void ImportIntrinsicParams(char* filename)
	{
		ifstream f;
		char ligne[100];
		int N = 0; float P[3];

		f.open(filename, std::ifstream::in);


		f.getline(ligne, 100);
		IrParameters.fx = atof(ligne);
		f.getline(ligne, 100);
		IrParameters.fy = atof(ligne);
		f.getline(ligne, 100);
		IrParameters.cx = atof(ligne);
		f.getline(ligne, 100);
		IrParameters.cy = atof(ligne);
		f.getline(ligne, 100);
		IrParameters.k1 = atof(ligne);
		f.getline(ligne, 100);
		IrParameters.k2 = atof(ligne);
		f.getline(ligne, 100);
		IrParameters.k3 = atof(ligne);
		f.getline(ligne, 100);
		IrParameters.p1 = atof(ligne);
		f.getline(ligne, 100);
		IrParameters.p2 = atof(ligne);

	}
	/*
	int ImagePsetImageFile(char* filename)
	{
		float x=0, y=0, z=0, depth_val;
		int n = settings.upsampling_factor;
		CreateParams();
		libfreenect2::Frame depth2rgb(1920, 1080 + 2, 4); // check here (https://github.com/OpenKinect/libfreenect2/issues/337) and here (https://github.com/OpenKinect/libfreenect2/issues/464) why depth2rgb image should be bigger
		Apply(rgb_data, depth_data, true, &depth2rgb);

		FILE* f;
		int N; float V[2];
		fopen_s(&f, filename, "rb");
		fread(&N, sizeof(int), 1, f);
		for (int i = 0; i < N; i++)
		{
			fread(V, sizeof(float), 2, f);
			getPointXYZ(V[1], V[0], x, z, y);
			Pset[PsetNB].x() = y;
			Pset[PsetNB].y() = x;
			Pset[PsetNB].z() = -z;

			Pset[PsetNB] = Rotation * Pset[PsetNB] + Translation;

			PsetNB++;
		}
		fclose(f);
		return N;
	}
	*/
	void RgbToBitmap(System::Drawing::Bitmap^ bmp_rgb)
	{
		for (int c = 0; c < 1920; c++) for (int r = 0; r < 1080; r++)
			bmp_rgb->SetPixel(c, r, System::Drawing::Color::FromArgb(rgb_data[r * 1920 + c]));
	}
	void DepthToBitmap(System::Drawing::Bitmap^ bmp_ir)
	{
		unsigned int color;
		for (int c = 0; c < 512; c++) for (int r = 0; r < 424; r++) {
			color = 4278190080 + (unsigned int)(depth_data[r * 512 + c] * 1677.7215);
			bmp_ir->SetPixel(c, r, System::Drawing::Color::FromArgb(color));
		}
		//bmp_ir->Save("01-ir.png", System::Drawing::Imaging::ImageFormat::Png);
	}
	void UndistortedDepthToBitmap(System::Drawing::Bitmap^ bmp_ir_undist)
	{
		unsigned int color;
		for (int c = 0; c < 512; c++) for (int r = 0; r < 424; r++) {
			color = 4278190080 + (unsigned int)(depth_data_undistorted[r * 512 + c] * 1677.7215);
			bmp_ir_undist->SetPixel(c, r, System::Drawing::Color::FromArgb(color));
		}
		//bmp_ir_undist->Save("01-ir.png", System::Drawing::Imaging::ImageFormat::Png);
	}
	void DepthRGBToBitmap(System::Drawing::Bitmap^ bmp_ir_rgb)
	{
		int n = SETTINGS::Scan::upsampling_factor;
		const float color_cx = ColorParameters.cx + 0.5f; // 0.5f added for later rounding
		float rx, ry;
		unsigned int color;

		for (float c = 0; c < 512 * n; c++) for (float r = 0; r < 424 * n; r++) {
			depth_to_color(c/n, r/n, rx, ry);

			rx = (rx + (ColorParameters.shift_m / depth_data[int(c/n) + 512 * int(r/n)] )) * ColorParameters.fx + color_cx;
			
			if (rx < 0 || rx > 1920 || ry < 0 || ry>1080)
				color = 4278190080;
			else color = rgb_data[int(rx) + int(ry) * 1920];
			
			bmp_ir_rgb->SetPixel(c, r, System::Drawing::Color::FromArgb(color));
		}
	}
	void UndistRGBToBitmap(System::Drawing::Bitmap^ bmp_ir_rgb)
	{
		int n = SETTINGS::Scan::upsampling_factor;
		unsigned int* rgb = (unsigned int*)registered_frame->data;
		for (int c = 0; c < 512 * n; c++) for (int r = 0; r < 424 * n; r++)
			bmp_ir_rgb->SetPixel(c, r, System::Drawing::Color::FromArgb(rgb[r * 512 * n + c]));
	}
	unsigned int UndistRGBpixel(int r, int c)
	{
		int n = SETTINGS::Scan::upsampling_factor;
		unsigned int* rgb = (unsigned int*)registered_frame->data;
		return rgb[r * 512 * n + c];
	}
	void ModifyUndistRGBpixel(int r, int c, unsigned int value)
	{
		int n = SETTINGS::Scan::upsampling_factor;
		unsigned int* rgb = (unsigned int*)registered_frame->data;
		rgb[r * 512 * n + c] = value;
	}
	void UndistRGB_FillBlank(unsigned int color)
	{
		int n = SETTINGS::Scan::upsampling_factor;
		unsigned int* rgb = (unsigned int*)registered_frame->data;

		for (int r = 0; r < 424 * n; r++) for (int c = 0; c < 512 * n; c++)
			if (rgb[r * 512 * n + c] == 0) rgb[r * 512 * n + c] = color;
	}

	void UndistRGB_FromBMP(System::Drawing::Bitmap^ bmp)
	{
		unsigned int* rgb = (unsigned int*)registered_frame->data;
		int n = SETTINGS::Scan::upsampling_factor;
		int width = n * 512, height = 424 * n;

		if (bmp->Width == width && bmp->Height == height)
		{
			System::Console::WriteLine(L"");
			System::Console::WriteLine(L"Writing BMP to Undist RGB Frame");
			System::Console::WriteLine(L"");
			for (int r = 0; r < height; r++) for (int c = 0; c < width; c++)
			{
				rgb[r * 512 * n + c] = bmp->GetPixel(c, r).ToArgb();
			}
		}
		else
		{
			System::Console::WriteLine(L"");
			System::Console::WriteLine(L"Failed Writing BMP to Undist RGB Frame !");
			System::Console::WriteLine(L"");
		}
	}
	void UndistRGB_FromBMP(System::String^ filename)
	{
		System::Drawing::Bitmap^ bmp = gcnew System::Drawing::Bitmap(filename);
		UndistRGB_FromBMP(bmp);
	}
	void UndistRGB_WithCorners_ToBitmap(System::Drawing::Bitmap^ bmp_ir_rgb)
	{
		CVLib::CalibrationResults* CalibResults;
		CalibResults = new CVLib::CalibrationResults();

		int n = SETTINGS::Scan::upsampling_factor;
		unsigned int* rgb = (unsigned int*)registered_frame->data;
		for (int c = 0; c < 512 * n; c++) for (int r = 0; r < 424 * n; r++)
			bmp_ir_rgb->SetPixel(c, r, System::Drawing::Color::FromArgb(rgb[r * 512 * n + c]));
		
		DetectChessBoardCorner2D(SETTINGS::calibsettings, CalibResults);
		if (CalibResults->GetFramesNB() > 0)
		{
			int frame = CalibResults->GetFramesNB() - 1;
			if (CalibResults->GetCornersNB(frame) > 0)
			{
				int frame = CalibResults->GetFramesNB() - 1;
				int PNB = CalibResults->GetCornersNB(frame);
				float x = 0, y = 0;

				System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(bmp_ir_rgb);

				System::Drawing::Brush^ b = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Red);
				for (int i = 0; i < PNB; i++)
				{
					CalibResults->GetCornerPoint(frame, i, x, y);
					g->FillEllipse(b, int(x - 6), int(y - 6), 13, 13);
				}
				///
			}
		}
	}
	bool DetectChessBoardCorner2D(CVLib::CalibrationSettings s, CVLib::CalibrationResults* R, int col_slice1 = -99999, int col_slice2 = 99999)
	{
		unsigned int *image = new unsigned int[registered_frame->width * registered_frame->height];
		unsigned int* rgb = (unsigned int*)registered_frame->data;

		for (int r = 0; r < registered_frame->height; r++)
			for (int c = 0; c < registered_frame->width; c++)
				if (c >= col_slice1  && c <= col_slice2)
					image[r * registered_frame->width + c] = rgb[r * registered_frame->width + c];
				else image[r * registered_frame->width + c] = 0;

		bool B =  DetectChessBoardFromImage(image, registered_frame->width, registered_frame->height, s, R);

		System::Drawing::Bitmap^ bmp = gcnew System::Drawing::Bitmap(registered_frame->width, registered_frame->height);

		unsigned int color;
		for (int c = 0; c < registered_frame->width; c++) for (int r = 0; r < registered_frame->height; r++)
			bmp->SetPixel(c, r, System::Drawing::Color::FromArgb(image[r * registered_frame->width + c]));

		bmp->Save("000.png", System::Drawing::Imaging::ImageFormat::Png);
		delete[] image;

		return B;
	}
	bool DetectChessBoardCorner3D(int index, int col_slice1 = -99999, int col_slice2 = 99999, bool parallel = true)
	{
		System::Console::WriteLine("");
		bool B=false;
		System::Console::WriteLine("Ref Point Vector Size = " + RefPoints.size() + "   |   index = " + index);
		if( index >=0 && RefPoints.size() > index)
		if (registered_frame != NULL && undistorted_frame != NULL)
		{
			RefPoints.at(index).clear();
			vector<Eigen::Vector3f> GridPoints;
			if (DetectChessBoardCorner2D(SETTINGS::calibsettings, &CalibResults, col_slice1, col_slice2))
			{
				if (!parallel || CalibResults.IsChessBoardParallelToCamera(CalibResults.GetFramesNB() - 1, SETTINGS::Scan::chessboard_tolerance, SETTINGS::Scan::chessboard_tolerance))
				{
					GridPoints = ConvertChessBoardTo3D(&CalibResults);
					AddPointsSet(GridPoints, index);
					CalculateGridDimensionsErrors(GridPoints, &CalibResults);
					B = true;
				}
				
			}
		}

		System::Console::WriteLine("");
		return B;
	}

	void CalculateGridDimensionsErrors(const vector<Eigen::Vector3f> GridPoints, CVLib::CalibrationResults* R)
	{
		int n = SETTINGS::Scan::upsampling_factor;
		int index;
		float* undistorted_data = (float*)undistorted_frame->data;
		Eigen::MatrixXf RESULTS = Eigen::MatrixXf::Zero(R->GetCornersNB(R->GetFramesNB()-1), 22);  //frame, grid_x, grid_y, r, c, r - cy, c - cx, depth,  H-dist, H-dist-meas, Herr, Herr%, V-dist, V-dist-meas, Verr, Verr%
		int grid_cols = R->GridColsNB, grid_rows = R->GridRowsNB;
		vector<float> Herrors;
		vector<float> Verrors;
		float error;
		Eigen::Vector3f P, P1, P2, P3, P4, C;
		float cx = IrParameters.cx;
		float cy = IrParameters.cy;
		float x, y, value[3];
		float rc, cc;
		Eigen::Matrix3f Rot; Eigen::Vector3f Trans;

		vector<vector< Eigen::Vector3f>> source(1), destination(1);

		Eigen::Vector3f Uh, Uv;
		Eigen::Vector3f I, J;
		I(0) = 1; I(1) = 0; I(2) = 0;
		J(0) = 0; J(1) = 1; J(2) = 0;

		C = getPointfromFrame(cy, cx);
		//getPointXYZ(cy, cx, C(0), C(1), C(2));
		System::String^ s = L"Focal Center in  3D:  " + C(0)+L"   " + C(1) + L"   " + C(2);
		System::Console::WriteLine(s);

		if(CVLib::DetectFocalCenterGridPosition(R, cx, cy, cc, rc))
		{
			System::Console::WriteLine("Focal Center detected...  cc = " + cc + "     rc = " + rc);
			index = int(cc) + int(rc) * grid_cols;
			P1 = GridPoints.at(index);
			System::Console::WriteLine("indexes 1:   " + index + L"   P1: " + P1(0) + "    " + P1(1) + "   " + P1(2));
			index = int(cc) + 1 + int(rc) * grid_cols;
			P2 = GridPoints.at(index);
			System::Console::WriteLine("indexes 2:   " + index + L"   P2: " + P2(0) + "    " + P2(1) + "   " + P2(2));
			index = int(cc) + 1 + (int(rc) + 1) * grid_cols;
			P3 = GridPoints.at(index);
			System::Console::WriteLine("indexes 3:   " + index + L"   P3: " + P3(0) + "    " + P3(1) + "   " + P3(2));
			index = int(cc) + (int(rc) + 1) * grid_cols;
			P4 = GridPoints.at(index);
			System::Console::WriteLine("indexes 4:   " + index + L"   P4: " + P4(0) + "    " + P4(1) + "   " + P4(2) );

			for (int r = 0; r < grid_rows; r++)
				for (int c = 0; c < grid_cols; c++)
				{
					index = r * grid_cols + c;
					R->GetCornerPoint(R->GetFramesNB() - 1, index, x, y);
					getPointXYZ(y, x, P1(0), P1(1), P1(2));
					destination.at(0).push_back(P1);
					P1(0) = (R->squareSize * (float(c) - cc));
					P1(1) = (R->squareSize * (float(r) - rc));
					P1(2) = 0;
					source.at(0).push_back(P1);
				}
			
			//Calculate rotation and translation matrix;
			P(0) = P(1) = P(2) = 0;
			getPointXYZ(cy, cx, C(0), C(1), C(2));
			EstimateRotationMatrix(source, destination, P, C, Rot, Trans);
			System::String^ s2 = L"Trans:  " + Trans(0) + L"   " + Trans(1) + L"   " + Trans(2);
			System::Console::WriteLine(s2);


			for (int r = 0; r < grid_rows; r++)
				for (int c = 0; c < grid_cols; c++)
				{
					//index of corner points in the grid
					index = r * grid_cols + c;

					//Current coordinates in the 3D eulerian System
					R->GetCornerPoint(R->GetFramesNB() - 1, index, x, y);
					getPointXYZ(y, x, P(0), P(1), P(2));

					//estimated real coordinates in the 3D eulerian System
					P1(0) = (R->squareSize * (float(c) - cc));
					P1(1) = (R->squareSize * (float(r) - rc));
					P1(2) = 0;
					P1 = Rot * P1 + Trans;

					//Fill Data
					RESULTS(index, 0) = frame_ID;
					RESULTS(index, 1) = r;			//r
					RESULTS(index, 2) = c;			//r
					RESULTS(index, 3) = y;			//r
					RESULTS(index, 4) = x;			//c
					RESULTS(index, 5) = y - cy;		//r - cy
					RESULTS(index, 6) = x - cx;		//c - cx

					RESULTS(index, 7) = undistorted_data[512 * n * int(y) + int(x)] / 1000.0f;  //depth


					RESULTS(index, 8) = P1(0);									//horizontal real distance
					RESULTS(index, 9) = P(0);									//horizontal measured distance
					RESULTS(index, 10) = RESULTS(index, 9) - RESULTS(index, 8);				// horizontal error (m)
					if (RESULTS(index, 9) == 0) RESULTS(index, 11) = 0; else
					RESULTS(index, 11) = RESULTS(index, 10) * 100 / RESULTS(index, 9);			// horizontal error (%)

					RESULTS(index, 12) = P1(1);													//Vertical real distance
					RESULTS(index, 13) = P(1);													//Vertical measured distance
					RESULTS(index, 14) = RESULTS(index, 13) - RESULTS(index, 12);
					if (RESULTS(index, 13) == 0) RESULTS(index, 15) = 0; else
					RESULTS(index, 15) = RESULTS(index, 14) * 100 / RESULTS(index, 13);

					RESULTS(index, 16) = P1(2) - SETTINGS::Scan::depth_origin;					//depth real distance
					RESULTS(index, 17) = P(2) - SETTINGS::Scan::depth_origin;					//depth measured distance
					RESULTS(index, 18) = RESULTS(index, 17) - RESULTS(index, 16);
					if (RESULTS(index, 17) == 0) RESULTS(index, 19) = 0; else
						RESULTS(index, 19) = RESULTS(index, 18) * 100 / RESULTS(index, 17);

					float N = 0;
					RESULTS(index, 20) = 0;
					if (c > 0)
					{
						R->GetCornerPoint(R->GetFramesNB() - 1, r * grid_cols + c - 1, x, y);
						getPointXYZ(y, x, P1(0), P1(1), P1(2));
						RESULTS(index, 20) += (P - P1).norm();
						N++;
					}
					
					if (c < grid_cols - 1)
					{
						R->GetCornerPoint(R->GetFramesNB() - 1, r * grid_cols + c + 1, x, y);
						getPointXYZ(y, x, P1(0), P1(1), P1(2));
						RESULTS(index, 20) += (P - P1).norm();
						N++;
					}
					RESULTS(index, 20) /= N;
					RESULTS(index, 20) = fabs(RESULTS(index, 20) - R->squareSize);


					N = 0;
					RESULTS(index, 21) = 0;
					if (r > 0)
					{
						R->GetCornerPoint(R->GetFramesNB() - 1, (r - 1) * grid_cols + c, x, y);
						getPointXYZ(y, x, P1(0), P1(1), P1(2));
						RESULTS(index, 21) += (P - P1).norm();
						N++;
					}

					if (r < grid_rows - 1)
					{
						R->GetCornerPoint(R->GetFramesNB() - 1, (r + 1) * grid_cols + c, x, y);
						getPointXYZ(y, x, P1(0), P1(1), P1(2));
						RESULTS(index, 21) += (P - P1).norm();
						N++;
					}

					RESULTS(index, 21) /= N;
					RESULTS(index, 21) = fabs(RESULTS(index, 21) - R->squareSize);

				}
			
			AddGridPointsData(RESULTS);
			
		}
		else
		System::Console::WriteLine("Focal Center NOT detected...");
	}

	void SetSlicingData(int lri, int rri, int sp1, int sp2, int sp3)
	{
		left_refindex = lri;
		right_refindex = rri;
		slicing_points[0] = sp1;
		slicing_points[1] = sp2;
		slicing_points[2] = sp3;
	}

	void Clear()
	{
		float V[3] = { 0 };
		started = normals_calculate = false;
		DrawPoints = DrawNormals = true;
		Points.Clear();
		Focal_Center(0) = Focal_Center(1) = Focal_Center(2) = 0;
	}


	void PrintRegressionData()
	{
		Eigen::VectorXf A = Eigen::VectorXf::Zero(Regression_calibration_x.GetA().size());
		System::Console::WriteLine("");
		System::Console::WriteLine("Regression ");
		System::String^ S = L"";

		A = Regression_calibration_x.GetA();
		S = L"AX (" + A.size() + L") = "; for (int i = 0; i < A.size(); i++) S += L"    " + A(i);
		S += L"  |  BX = " + Regression_calibration_x.GetB();
		System::Console::WriteLine(S);

		A = Regression_calibration_y.GetA();
		S = L"AY (" + A.size() + L") = "; for (int i = 0; i < A.size(); i++) S += L"    " + A(i);
		S += L"  |  BY = " + Regression_calibration_y.GetB();
		System::Console::WriteLine(S);


		A = Regression_calibration_d.GetA();
		S = L"Ad (" + A.size() + L") = "; for (int i = 0; i < A.size(); i++) S += L"    " + A(i);
		S += L"  |  Bd = " + Regression_calibration_d.GetB();
		System::Console::WriteLine(S);

		System::Console::WriteLine("");
	}
	void ClearRegression()
	{
		Regression_calibration_x.Clear();
		Regression_calibration_y.Clear();
		Regression_calibration_d.Clear();
	}

	void SetRefPointsSize(int n)
	{
		Eigen::Vector3f P = Eigen::Vector3f::Zero();
		vector<Eigen::Vector3f> VP(0);
		//VP.clear(); VP.push_back(P); VP.clear();
		for (int i = 0; i < RefPoints.size(); i++) RefPoints.at(i).clear();
		RefPoints.clear();
		for (int i = 0; i < n; i++) RefPoints.push_back(VP);
	}

	bool AddRefPoint(int index, Eigen::Vector3f point)
	{
		bool B = false;
		if (RefPoints.size() > index)
		{
			RefPoints.at(index).push_back(point);
			B = true;
		}

		return B;
	}

	bool AddRefPoint(int index, float point[3])
	{
		bool B = false;
		if (RefPoints.size() > index)
		{
			Eigen::Vector3f p;
			p(0) = point[0];
			p(1) = point[1];
			p(2) = point[2];
			RefPoints.at(index).push_back(p);
			B = true;
		}

		return B;
	}

	void ClearGridPointsData()
	{
		GridPointsData.conservativeResize(0, 22);
	}

	bool AddGridPointsData(Eigen::MatrixXf values)
	{
		if (values.cols() != GridPointsData.cols() || values.rows() == 0) return false;
		else
		{
			int rows = GridPointsData.rows();
			GridPointsData.conservativeResize(rows + values.rows(), values.cols());
			for (int r = 0; r < values.rows(); r++)
				for (int c = 0; c < GridPointsData.cols(); c++)
					GridPointsData(rows + r, c) = values(r, c);
			return true;
		}
	}

	void SetGlobalColor(float r, float g, float b)
	{
		GlobalColor[0] = r; GlobalColor[1] = g; GlobalColor[2] = b;
	}

	System::String^ GetSerialNumber()
	{
		return (gcnew System::String(serialnumber));
	}

	int GetPointsNB()
	{
		return Points.GetCloudWidth();
	}

	void ReverseTransformedCorrdinates(Eigen::MatrixXf r, Eigen::VectorXf t)
	{
		PCL_POINTCLOUD temp;
		temp.Clear();
		Eigen::VectorXf p = Eigen::VectorXf::Zero(3);
		float V[3], C[3];
		for (int i = 0; i < Points.GetCloudWidth(); i++)
		{
			Points.GetPoint(i, V, C);
			p << V[0], V[1], V[2];
			p = r.inverse() * (p - t);
			V[0] = p[0]; V[1] = p[1]; V[2] = p[2];
			temp.AddPoint(V[0], V[1], V[2], C[0], C[1], C[2]);
		}
		Points.Clear();
		Points = temp;

		//reverse RefPpoints
		for (int i = 0; i < RefPoints.size(); i++)
			for (int k = 0; k < RefPoints.at(i).size(); k++)
			{
				RefPoints.at(i).at(k) = r.inverse() * (RefPoints.at(i).at(k) - t);
			}

	}

	void CalculateTransformedCoordinates(Eigen::MatrixXf r, Eigen::VectorXf t)
	{
		PCL_POINTCLOUD temp;
		Eigen::VectorXf p = Eigen::VectorXf::Zero(3);
		float V[3], C[3];
		int N = 0;

		temp.Clear();
		for (int i = 0; i < Points.GetCloudWidth(); i++)
		{
			Points.GetPoint(i, V, C);

			if (
				true
				//V[0] >= depthMin && V[0] <= depthMax
				//&& V[1] >= -0.15 && V[1] <= 0.15
				/*
				&& V[2] >=verticalMin && V[2]<=verticalMax
				*/
				)
			{

				p << V[0], V[1], V[2];

				p = r * p + t;
				V[0] = p[0]; V[1] = p[1]; V[2] = p[2];



				/*
				if ((AngleZ == 0 && V[1]<-slope1 * V[0] && V[1]> slope1 * V[0])
					|| (AngleZ == 90 && V[1] < -slope2 * V[0] && V[1] < slope2 * V[0])
					|| (AngleZ == 180 && V[1] > -slope1 * V[0] && V[1] < slope1 * V[0])
					|| (AngleZ == -90 && V[1] > -slope2 * V[0] && V[1] > slope2 * V[0])
					)
					*/
				if (V[2] >= 0.05 && V[2] <= 1 && V[1] >= -0.14 && V[1] <= 0.14 && V[0] >= -0.14 && V[0] <= 0.14)
					temp.AddPoint(V[0], V[1], V[2], C[0], C[1], C[2]);
			}
		}
		Points.Clear();
		Points = temp;


		//calculate transformed coordinate for RefPpoints
		for (int i = 0; i < RefPoints.size(); i++)
			for (int k = 0; k < RefPoints.at(i).size(); k++)
			{
				RefPoints.at(i).at(k) = r * RefPoints.at(i).at(k) + t;
			}


		System::Console::WriteLine(L"");
		System::Console::WriteLine(gcnew System::String(serialnumber) + L"  Transformation Calculated");
		System::Console::WriteLine(L"");
	}

	void AddPointsSet(vector<Eigen::Vector3f> Points, int index)
	{
		if (RefPoints.size() > index)
		{
			int NB = Points.size();

			for (int i = 0; i < NB; i++)
				RefPoints.at(index).push_back(Points.at(i));
		}
	}

	void Draw3D()
	{
		float point[3], normal[3], rgb[3];

		if (normals_calculate && DrawNormals)
		{
			OpenGL::GL::LineWidth(0.1f);
			OpenGL::GL::Begin(OpenGL::BeginMode::Lines);
			OpenGL::GL::Color3(Vector3(1, 1, 1));
			for (int i = 0; i < GetPointsNB(); i++)
			{
				Points.GetXYZ(i, point);
				Points.GetNormal(i, normal);

				OpenGL::GL::Vertex3(point[0], point[1], point[2]);
				for (int k = 0; k < 3; k++) point[k] += SETTINGS::Display::cloud_normal_size * normal[k];
				OpenGL::GL::Vertex3(point[0], point[1], point[2]);
			}
			OpenGL::GL::End();
		}


		if (DrawPoints)
		{
			OpenGL::GL::PointSize(SETTINGS::Display::cloud_point_size);
			OpenGL::GL::Begin(OpenGL::BeginMode::Points);
			OpenGL::GL::Color3(Vector3(GlobalColor[0], GlobalColor[1], GlobalColor[2]));

			for (int i = 0; i < GetPointsNB(); i++)
			{
				Points.GetPoint(i, point, rgb);

				if (SETTINGS::Display::pointscolor) OpenGL::GL::Color3(Vector3(rgb[0], rgb[1], rgb[2]));

				OpenGL::GL::Vertex3(point[0], point[1], point[2]);
			}
			OpenGL::GL::End();
		}

		if (DrawPset)
		{
			OpenGL::GL::PointSize(10);
			OpenGL::GL::Begin(OpenGL::BeginMode::Points);
			OpenGL::GL::Color3(Vector3(GlobalColor[0], GlobalColor[1], GlobalColor[2]));

			for (int i = 0; i < RefPoints.size(); i++)
				for (int j = 0; j < RefPoints.at(i).size(); j++)
				{
					point[0] = RefPoints.at(i).at(j)(0);
					point[1] = RefPoints.at(i).at(j)(1);
					point[2] = RefPoints.at(i).at(j)(2);

					OpenGL::GL::Vertex3(point[0], point[1], point[2]);
				}
			point[0] = Focal_Center(0);
			point[1] = Focal_Center(1);
			point[2] = Focal_Center(2);
			OpenGL::GL::Vertex3(point[0], point[1], point[2]);

			OpenGL::GL::End();
		}
	}

	void DrawPointsForSelection()
	{
		float point[3];
		int r = 0, g = 0, b = 1;

		OpenGL::GL::PointSize(SETTINGS::Display::selection_point_size);
		OpenGL::GL::Begin(OpenGL::BeginMode::Points);

		for (int i = 0; i < GetPointsNB(); i++)
		{
			Points.GetXYZ(i, point);
			OpenGL::GL::Color3(Vector3(float(r) / 255, float(g) / 255, float(b) / 255));
			OpenGL::GL::Vertex3(point[0], point[1], point[2]);

			b++;
			if (b > 255) { b = 0; g++; }
			if (g > 255) { g = 0; r++; }
		}
		OpenGL::GL::End();
	}

	int SelectedPoint(int r, int g, int b)
	{
		return (b - 1) + g * 256 + r * 256 * 256;
	}

	void Filter()
	{
		float point[3];

		Points.FilterOutliers(SETTINGS::Mesh::filter_meank, SETTINGS::Mesh::filter_threshold);
	}

	void ExportInfors(char* filename)
	{
		FILE* f;
		fopen_s(&f, filename, "wb");

		fprintf(f, "Kinect %s\n\r", serialnumber);

		fprintf(f, "Rotation Matrix:\n\r");
		for (int i = 0; i < 3; i++)
			fprintf(f, "%f\t%f\t%f\n\r", Rotation(i, 0), Rotation(i, 1), Rotation(i, 2));


		fprintf(f, "Rotation << %f, %f, %f, %f, %f, %f, %f, %f, %f;\n\r", Rotation(0, 0), Rotation(0, 1), Rotation(0, 2), Rotation(1, 0), Rotation(1, 1), Rotation(1, 2), Rotation(2, 0), Rotation(2, 1), Rotation(2, 2));

		fprintf(f, "Translation Vector:\n\r");
		fprintf(f, "%f\t%f\t%f\n\r", Translation(0), Translation(1), Translation(2));

		fclose(f);
	}

	void ExportPoints(char* FileName)
	{
		float point[3], rgb[3];
		float REGISTER[6];
		FILE* f;
		f = fopen(FileName, "wb");
		for (int i = 0; i < GetPointsNB(); i++)
		{
			Points.GetPoint(i, point, rgb);

			REGISTER[0] = point[0];
			REGISTER[1] = point[1];
			REGISTER[2] = point[2];
			REGISTER[3] = rgb[0];
			REGISTER[4] = rgb[1];
			REGISTER[5] = rgb[2];

			fwrite(REGISTER, sizeof(float), 6, f);
		}
		fclose(f);
	}

	void ImportPoints(char* FileName)
	{
		float point[3], rgb[3];
		float REGISTER[6];
		FILE* f;
		f = fopen(FileName, "rb");
		Points.Clear();
		fread(REGISTER, sizeof(float), 6, f);
		while (!feof(f))
		{
			Points.AddPoint(REGISTER[0], REGISTER[1], REGISTER[2], REGISTER[3], REGISTER[4], REGISTER[5]);
			fread(REGISTER, sizeof(float), 6, f);
		}

		fclose(f);
	}

	void ImportFromSTL(char* filename)
	{
		char stlHeader[80]; long N; short A;
		float point[3], normalvector[3];
		FILE* f;
		f = fopen(filename, "rb");
		Points.Clear();
		fread(stlHeader, sizeof(char), 80, f);
		fread(&N, sizeof(long), 1, f);

		for (int i = 0; i < N; i++)
		{
			fread(normalvector, sizeof(float), 3, f);
			for (int k = 0; k < 3; k++)
			{
				fread(point, sizeof(float), 3, f);
				Points.AddPoint(point[0], point[1], point[2], 1, 1, 1);
			}
			fread(&A, sizeof(short), 1, f);
		}

		fclose(f);
	}

	void ExportGridPointsData_CSV(char* filename)
	{
		FILE* f;
		fopen_s(&f, filename, "wb");
		for (int r = 0; r < GridPointsData.rows(); r++)
		{
			for (int c = 0; c < GridPointsData.cols(); c++)
				fprintf(f, "%f, ", GridPointsData(r, c));
			fprintf(f, "\n");
		}
		fclose(f);
	}

	void ExportGridPointsData_GPD(char* filename)
	{
		int rows = GridPointsData.rows();
		int cols = GridPointsData.cols();
		FILE* f;
		fopen_s(&f, filename, "wb");
		fwrite(&rows, sizeof(int), 1, f);
		fwrite(&cols, sizeof(int), 1, f);
		for (int r = 0; r < rows; r++)
			for (int c = 0; c < cols; c++)
				fwrite(&GridPointsData(r, c), sizeof(float), 1, f);
		fclose(f);
	}

	bool ImportGridPointsData_GPD(char* filename)
	{
		bool B = true;
		int rows, rows0, cols, cols0, frame = -9999;
		FILE* f;
		float value;

		rows0 = GridPointsData.rows();
		cols0 = GridPointsData.cols();
		fopen_s(&f, filename, "rb");

		fread(&rows, sizeof(int), 1, f);
		fread(&cols, sizeof(int), 1, f);


		if (cols == cols0)
		{
			GridPointsData.conservativeResize(rows0 + rows, cols0);

			for (int r = rows0; r < rows0 + rows; r++)
			{
				fread(&GridPointsData(r, 0), sizeof(float), 1, f);

				if (GridPointsData(r, 0) == frame) GridPointsData(r, 0) = GridPointsData(r - 1, 0);
				else
				{
					frame = GridPointsData(r, 0);
					if (r == 0) GridPointsData(r, 0) = 0;
					else  GridPointsData(r, 0) = GridPointsData(r - 1, 0) + 1;
				}

				for (int c = 1; c < cols; c++)
				{
					fread(&GridPointsData(r, c), sizeof(float), 1, f);
				}
			}
		}
		else B = false;
		fclose(f);
		return B;
	}

	void ImportLinearRegression(char* filename)
	{

		System::Console::WriteLine("");
		System::Console::WriteLine("Open Regression File");
		int N;
		Eigen::VectorXf a;
		float temp, b;
		FILE* f;
		fopen_s(&f, filename, "rb");

		fread(&N, sizeof(int), 1, f);
		System::Console::WriteLine("N = " + N);


		a = Eigen::VectorXf(N);

		for (int i = 0; i < N; i++) {
			fread(&temp, sizeof(float), 1, f); a(i) = temp;
		}
		fread(&b, sizeof(float), 1, f);
		Regression_calibration_x.Set(a, b);

		for (int i = 0; i < N; i++) {
			fread(&temp, sizeof(float), 1, f); a(i) = temp;
		}
		fread(&b, sizeof(float), 1, f);
		Regression_calibration_y.Set(a, b);

		for (int i = 0; i < N; i++) {
			fread(&temp, sizeof(float), 1, f); a(i) = temp;
		}
		fread(&b, sizeof(float), 1, f);
		Regression_calibration_d.Set(a, b);


		fclose(f);

		System::Console::WriteLine("Regression X:");
		System::Console::WriteLine(gcnew System::String(Regression_calibration_x.ConvertToStream().str().c_str()));
		System::Console::WriteLine("Regression Y:");
		System::Console::WriteLine(gcnew System::String(Regression_calibration_y.ConvertToStream().str().c_str()));
		System::Console::WriteLine("Regression D:");
		System::Console::WriteLine(gcnew System::String(Regression_calibration_d.ConvertToStream().str().c_str()));
		System::Console::WriteLine("Regression Is Done?   " + Regression_calibration_x.IsDone() + "  |  " + Regression_calibration_y.IsDone() + "  |  " + Regression_calibration_d.IsDone());
		int regression_order = (Regression_calibration_x.GetA().size() - 1) / 3;
		System::Console::WriteLine("Regression order = :" + regression_order);
		System::Console::WriteLine("");

	}

	bool ExportLinearRegression(char* filename)
	{
		bool Result = Regression_calibration_x.IsDone() && Regression_calibration_y.IsDone() && Regression_calibration_d.IsDone() && Regression_calibration_x.GetA().size() == Regression_calibration_y.GetA().size() && Regression_calibration_x.GetA().size() == Regression_calibration_d.GetA().size();

		if (Result)
		{

			int N = Regression_calibration_x.GetA().size();
			float b;
			Eigen::VectorXf a;

			FILE* f;
			fopen_s(&f, filename, "wb");

			fwrite(&N, sizeof(int), 1, f);

			a = Regression_calibration_x.GetA();
			b = Regression_calibration_x.GetB();
			for (int i = 0; i < N; i++) fwrite(&a(i), sizeof(float), 1, f);
			fwrite(&b, sizeof(float), 1, f);

			a = Regression_calibration_y.GetA();
			b = Regression_calibration_y.GetB();
			for (int i = 0; i < N; i++) fwrite(&a(i), sizeof(float), 1, f);
			fwrite(&b, sizeof(float), 1, f);

			a = Regression_calibration_d.GetA();
			b = Regression_calibration_d.GetB();
			for (int i = 0; i < N; i++) fwrite(&a(i), sizeof(float), 1, f);
			fwrite(&b, sizeof(float), 1, f);

			fclose(f);
		}

		return Result;
	}
};

Kinect2APP* myKinect2App;


vector<vector<Eigen::Vector3f>> CreateRefPointsVector(int device_index)
{
	vector<vector<Eigen::Vector3f>> refpoints_vector;
	vector<Eigen::Vector3f> refpoints(0);

	for (int i = 0; i < Kinect2NB; i++)
	{
		refpoints_vector.push_back(refpoints);
		
		if (myKinect2App[i].RefPoints.size() > device_index)
			for (int k = 0; k < myKinect2App[i].RefPoints.at(device_index).size(); k++)
				refpoints_vector.at(i).push_back(myKinect2App[i].RefPoints.at(device_index).at(k));
				

	}

	return refpoints_vector;
}


void CalculateRegistationError(float &mean, float &min, float &max)
{
	long NB = 0;
	float error;
	mean = 0; min = 9999; max = -9999;

	for (int i = 0; i < Kinect2NB; i++)
	{
		for (int j = 0; j < myKinect2App[i].RefPoints.size(); j++)
		{
			int n = myKinect2App[i].RefPoints.at(j).size();
			if (n > myKinect2App[j].RefPoints.at(i).size()) n = myKinect2App[j].RefPoints.at(i).size();

			for (int k = 0; k < n; k++)
			{
				error = (myKinect2App[i].RefPoints.at(j).at(k) - myKinect2App[j].RefPoints.at(i).at(k)).norm();
				NB++;
				mean += error;
				if (error < min) min = error;
				if (error > max) max = error;
			}

		}
	}

	mean /= double(NB);
}