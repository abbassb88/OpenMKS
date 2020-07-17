#include "pch.h"
#include "CVLib.h"


namespace CVLib
{
	CalibrationSettings::CalibrationSettings() : goodInput(false)
	{
		flexiblesize = true;
		boardWidth = 11;
		boardHeight = 7;
		squareSize = 10;
		aspectRatio = 1;
		calibZeroTangentDist = true;
		calibFixPrincipalPoint = false;
		flipVertical = false;
		useFisheye = false;
		fixK1 = false;
		fixK2 = false;
		fixK3 = false;
		fixK4 = false;
		fixK5 = false;
		outputFileName = "out_camera_data.xml";
		validate();
	}


	void CalibrationSettings::write(std::string filename)
	{
		FileStorage fs;
		fs.open(filename, FileStorage::WRITE);

		fs << "{"
			<< "BoardSize_Width" << boardWidth
			<< "BoardSize_Height" << boardHeight
			<< "Square_Size" << squareSize
			<< "Calibrate_FixAspectRatio" << aspectRatio
			<< "Calibrate_AssumeZeroTangentialDistortion" << calibZeroTangentDist
			<< "Calibrate_FixPrincipalPointAtTheCenter" << calibFixPrincipalPoint

			<< "Write_outputFileName" << outputFileName

			<< "Input_FlipAroundHorizontalAxis" << flipVertical
			<< "}";
	}

	bool CalibrationSettings::read(string filename)
	{
		FileStorage fs(filename, FileStorage::READ); // Read the settings
		if (!fs.isOpened())
		{
			return false;
		}

		fs["Settings"] >> *this;
		fs.release();
		return true;
	}

	void CalibrationSettings::validate()
	{
		goodInput = true;
		if (boardWidth <= 0 || boardHeight <= 0)
		{
			goodInput = false;
		}
		if (squareSize <= 10e-6)
		{
			goodInput = false;
		}

		flag = 0;
		if (calibFixPrincipalPoint) flag |= CALIB_FIX_PRINCIPAL_POINT;
		if (calibZeroTangentDist)   flag |= CALIB_ZERO_TANGENT_DIST;
		if (aspectRatio)            flag |= CALIB_FIX_ASPECT_RATIO;
		if (fixK1)                  flag |= CALIB_FIX_K1;
		if (fixK2)                  flag |= CALIB_FIX_K2;
		if (fixK3)                  flag |= CALIB_FIX_K3;
		if (fixK4)                  flag |= CALIB_FIX_K4;
		if (fixK5)                  flag |= CALIB_FIX_K5;

		if (useFisheye) {
			// the fisheye model has its own enum, so overwrite the flags
			flag = fisheye::CALIB_FIX_SKEW | fisheye::CALIB_RECOMPUTE_EXTRINSIC;
			if (fixK1)                   flag |= fisheye::CALIB_FIX_K1;
			if (fixK2)                   flag |= fisheye::CALIB_FIX_K2;
			if (fixK3)                   flag |= fisheye::CALIB_FIX_K3;
			if (fixK4)                   flag |= fisheye::CALIB_FIX_K4;
			if (calibFixPrincipalPoint) flag |= fisheye::CALIB_FIX_PRINCIPAL_POINT;
		}

	}

	struct RESULTS_DATA {
	public:
		vector<vector<Point2f> > imagePoints;

		bool AdjustOrder(int frame, int cols, int rows)
		{
			bool B = false;

			if (frame >= imagePoints.size()) B = false;
			else if (cols * rows != imagePoints[frame].size()) B = false;
			else
			{
				int NB = cols * rows;
				Point2f temp;

				if (imagePoints[frame].at(0).x > imagePoints[frame].at(NB - 1).x)
					for (int c = 0; c < cols / 2; c++)
						for (int r = 0; r < rows; r++)
						{
							temp = imagePoints[frame].at(c + r * cols);
							imagePoints[frame].at(c + r * cols) = imagePoints[frame].at(cols - c - 1 + r * cols);
							imagePoints[frame].at(cols - c - 1 + r * cols) = temp;
						}


				if (imagePoints[frame].at(0).y > imagePoints[frame].at(NB - 1).y)
					for (int r = 0; r < rows / 2; r++)
						for (int c = 0; c < cols; c++)
						{
							temp = imagePoints[frame].at(c + r * cols);
							imagePoints[frame].at(c + r * cols) = imagePoints[frame].at(c + (rows - r - 1) * cols);
							imagePoints[frame].at(c + (rows - r - 1) * cols) = temp;
						}
			}
			return B;
		}

	};

	CalibrationResults::CalibrationResults()
	{
		CornerPoints = new RESULTS_DATA();
		fx = fy = cx = cy = k1 = k2 = k3 = p1 = p2 = 0;
		calibration_time[0] = '\0';
		squareSize = 0;
		avg_reprojection_error = 0;
		GridRowsNB = GridColsNB = 0;
	}

	CalibrationResults::~CalibrationResults()
	{
		delete CornerPoints;
	}


	void CalibrationResults::ClearPoints()
	{
		CornerPoints->imagePoints.clear();
	}


	void CalibrationResults::write(std::string filename)
	{
		int rows = CornerPoints->imagePoints.size();
		int cols = CornerPoints->imagePoints[0].size();

		int N = int(rows * cols);
		float V[2];
		FILE* f = NULL;
		fopen_s(&f, filename.c_str(), "wb");

		//fprintf(f, "%d\n", N);
		fwrite(&N, sizeof(int), 1, f);

		for (int r = 0; r < rows; r++)
			for (int c = 0; c < cols; c++)
			{
				V[0] = CornerPoints->imagePoints[r][c].x;
				V[1] = CornerPoints->imagePoints[r][c].y;
				fwrite(V, sizeof(float), 2, f);
				//fprintf(f, "%f,  %f\n", V[0], V[1]);
			}

		fclose(f);
	}

	int CalibrationResults::GetCornersNB(int frame)
	{
		return CornerPoints->imagePoints[frame].size();
	}

	void CalibrationResults::GetCornerPoint(int frame, int index, float& x, float& y)
	{
		x = CornerPoints->imagePoints[frame][index].x;
		y = CornerPoints->imagePoints[frame][index].y;
	}

	int CalibrationResults::GetFramesNB()
	{
		return CornerPoints->imagePoints.size();
	}

	bool CalibrationResults::IsChessBoardParallelToCamera(int frame, float tolerance_x, float tolerance_y)
	{
		bool RESULT = false;
		float x[4], y[4];
		if (GetFramesNB() > frame)
			if (GetCornersNB(frame) > 0)
			{
				GetCornerPoint(frame, 0, x[0], y[0]);
				GetCornerPoint(frame, GridColsNB - 1, x[1], y[1]);
				GetCornerPoint(frame, GridRowsNB * GridColsNB - 1, x[2], y[2]);
				GetCornerPoint(frame, GridColsNB * (GridRowsNB - 1), x[3], y[3]);

				if (fabs(y[0] - y[1]) <= tolerance_y && fabs(y[2] - y[3]) <= tolerance_y
					&& fabs(x[0] - x[3]) <= tolerance_x && fabs(x[1] - x[2]) <= tolerance_x)
					RESULT = true;
			}

		return RESULT;
	}

	void CalibrationResults::operator =(CalibrationResults r)
	{
		squareSize = r.squareSize;
		fx = r.fx;
		fy = r.fy;
		cx = r.cx;
		cy = r.cy;
		k1 = r.k1;
		k2 = r.k2;
		k3 = r.k3;
		p1 = r.p1;
		p2 = r.p2;
		GridRowsNB = r.GridRowsNB;
		GridColsNB = r.GridColsNB;
		sprintf_s(calibration_time, "%s", r.calibration_time);
		avg_reprojection_error = r.avg_reprojection_error;

		float x, y;
		if (CornerPoints->imagePoints.size() > 0) CornerPoints->imagePoints[0].clear();
		CornerPoints->imagePoints.clear();

		Point2f P;
		vector<Point2f> VP;
		for (int f = 0; f < GetFramesNB(); f++)
			for (int i = 0; i < r.GetCornersNB(f); i++)
			{
				r.GetCornerPoint(f, i, x, y);
				P.x = x; P.y = y;
				VP.push_back(P);
			}
		CornerPoints->imagePoints.push_back(VP);
	}

	void readNode(const FileNode& node, CalibrationSettings& x)  //Read serialization for this class
	{

		node["BoardSize_Width"] >> x.boardWidth;
		node["BoardSize_Height"] >> x.boardHeight;
		node["Square_Size"] >> x.squareSize;
		node["Write_outputFileName"] >> x.outputFileName;
		node["Calibrate_AssumeZeroTangentialDistortion"] >> x.calibZeroTangentDist;
		node["Calibrate_FixPrincipalPointAtTheCenter"] >> x.calibFixPrincipalPoint;
		node["Calibrate_UseFisheyeModel"] >> x.useFisheye;
		node["Input_FlipAroundHorizontalAxis"] >> x.flipVertical;
		node["Fix_K1"] >> x.fixK1;
		node["Fix_K2"] >> x.fixK2;
		node["Fix_K3"] >> x.fixK3;
		node["Fix_K4"] >> x.fixK4;
		node["Fix_K5"] >> x.fixK5;

		x.validate();
	}

	static inline void read(const FileNode& node, CalibrationSettings& x, const CalibrationSettings& default_value = CalibrationSettings())
	{
		if (node.empty())
			x = default_value;
		else
			readNode(node, x);
	}

	enum { DETECTION = 0, CAPTURING = 1, CALIBRATED = 2 };

	bool runCalibrationAndSave(CalibrationSettings& s, Size imageSize, Mat& cameraMatrix, Mat& distCoeffs,
		CalibrationResults* r, float grid_width);


	bool DetectChessBoardFromImage(unsigned int* IMAGE, int width, int height, CalibrationSettings s, CalibrationResults* r, bool showimage)
	{
		bool RET = true;


		//if s is not good input
		if (!s.goodInput)
		{
			return -1;
		}

		//winsize??
		int winSize = 11;

		//gird width
		float grid_width = s.squareSize * (s.boardWidth - 1);

		Mat cameraMatrix, distCoeffs;
		Size imageSize;
		clock_t prevTimestamp = 0;

		//fill image into matrix
		Mat view(height, width, CV_8UC4);
		std::memcpy(view.data, IMAGE, width * height * sizeof(unsigned int));
		imageSize = view.size();
		if (s.flipVertical)    flip(view, view, 0);


		// find pattern
		vector<Point2f> pointBuf;

		bool found;

		int chessBoardFlags = CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_NORMALIZE_IMAGE;

		//board size
		Size boardSize;

		boardSize.width = s.boardWidth;
		boardSize.height = s.boardHeight + 1;

		do
		{
			pointBuf.clear();
			boardSize.height--;
			if (boardSize.height < 3)
			{
				boardSize.width--;
				boardSize.height = s.boardHeight;
			}

			if (!s.useFisheye) {
				// fast check erroneously fails with high distortions like fisheye
				chessBoardFlags |= CALIB_CB_FAST_CHECK;
			}

			// Find feature points on the input format
			found = findChessboardCorners(view, boardSize, pointBuf, chessBoardFlags);
		} while (s.flexiblesize && !found && boardSize.width > 4);

		// if pattern found
		if (found)
		{
			r->GridColsNB = boardSize.width;
			r->GridRowsNB = boardSize.height;

			Mat viewGray;
			cvtColor(view, viewGray, COLOR_BGR2GRAY);
			cornerSubPix(viewGray, pointBuf, Size(winSize, winSize),
				Size(-1, -1), TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 30, 0.0001));

			r->CornerPoints->imagePoints.clear();
			r->CornerPoints->imagePoints.push_back(pointBuf);
			r->CornerPoints->AdjustOrder(0, r->GridColsNB, r->GridRowsNB);
			r->squareSize = s.squareSize;

			// Draw the corners.
			drawChessboardCorners(view, boardSize, Mat(pointBuf), found);

			if (showimage) imshow("Image View", view); //show image
		}
		else
		{
			RET = false;
			r->GridColsNB = 0;
			r->GridRowsNB = 0;
		}


		return RET;
	}


	bool CalibrateCameraFromImage(unsigned int* IMAGE, int width, int height, CalibrationSettings s, CalibrationResults* r, bool showimage)
	{
		bool RET = true;

		//if s is not good input
		if (!s.goodInput)
		{
			return -1;
		}

		//winsize??
		int winSize = 11;

		//gird width
		float grid_width = s.squareSize * (s.boardWidth - 1);

		Mat cameraMatrix, distCoeffs;
		Size imageSize;
		clock_t prevTimestamp = 0;
		const Scalar RED(0, 0, 255), GREEN(0, 255, 0);
		const char ESC_KEY = 27;

		//for (;;)
		{
			//fill image into matrix
			Mat view(height, width, CV_8UC4);
			std::memcpy(view.data, IMAGE, width * height * sizeof(unsigned int));
			imageSize = view.size();
			if (s.flipVertical)    flip(view, view, 0);


			// find pattern
			vector<Point2f> pointBuf;

			bool found;

			int chessBoardFlags = CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_NORMALIZE_IMAGE;


			//board size
			Size boardSize;

			boardSize.width = s.boardWidth;
			boardSize.height = s.boardHeight;


			found = findChessboardCorners(view, boardSize, pointBuf, chessBoardFlags);


			// if pattern found
			if (found)
			{
				r->GridColsNB = boardSize.width;
				r->GridRowsNB = boardSize.height;

				Mat viewGray;
				cvtColor(view, viewGray, COLOR_BGR2GRAY);
				cornerSubPix(viewGray, pointBuf, Size(winSize, winSize),
					Size(-1, -1), TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 30, 0.0001));

				r->CornerPoints->imagePoints.push_back(pointBuf);

				// Draw the corners.
				drawChessboardCorners(view, boardSize, Mat(pointBuf), found);



				//Calibration and save results
				if (runCalibrationAndSave(s, imageSize, cameraMatrix, distCoeffs, r, grid_width))
				{
					if (showimage) imshow("Image View", view); //show image
				}
				else
				{
					RET = false;

					r->GridColsNB = 0;
					r->GridRowsNB = 0;
				}
			}
			else RET = false;
		}


		return RET;

	}

	//! [compute_errors]
	static double computeReprojectionErrors(const vector<vector<Point3f> >& objectPoints,
		const vector<vector<Point2f> >& imagePoints,
		const vector<Mat>& rvecs, const vector<Mat>& tvecs,
		const Mat& cameraMatrix, const Mat& distCoeffs,
		vector<float>& perViewErrors, bool fisheye)
	{
		vector<Point2f> imagePoints2;
		size_t totalPoints = 0;
		double totalErr = 0, err;
		perViewErrors.resize(objectPoints.size());

		for (size_t i = 0; i < objectPoints.size(); ++i)
		{
			if (fisheye)
			{
				fisheye::projectPoints(objectPoints[i], imagePoints2, rvecs[i], tvecs[i], cameraMatrix,
					distCoeffs);
			}
			else
			{
				projectPoints(objectPoints[i], rvecs[i], tvecs[i], cameraMatrix, distCoeffs, imagePoints2);
			}
			err = norm(imagePoints[i], imagePoints2, NORM_L2);

			size_t n = objectPoints[i].size();
			perViewErrors[i] = (float)std::sqrt(err * err / n);
			totalErr += err * err;
			totalPoints += n;
		}

		return std::sqrt(totalErr / totalPoints);
	}
	//! [compute_errors]
	//! [board_corners]
	static void calcBoardCornerPositions(Size boardSize, float squareSize, vector<Point3f>& corners,
		CalibrationSettings::Pattern patternType = CalibrationSettings::CHESSBOARD)
	{
		corners.clear();

		switch (patternType)
		{
		case CalibrationSettings::CHESSBOARD:
		case CalibrationSettings::CIRCLES_GRID:
			for (int i = 0; i < boardSize.height; ++i)
				for (int j = 0; j < boardSize.width; ++j)
					corners.push_back(Point3f(j * squareSize, i * squareSize, 0));
			break;

		case CalibrationSettings::ASYMMETRIC_CIRCLES_GRID:
			for (int i = 0; i < boardSize.height; i++)
				for (int j = 0; j < boardSize.width; j++)
					corners.push_back(Point3f((2 * j + i % 2) * squareSize, i * squareSize, 0));
			break;
		default:
			break;
		}
	}
	//! [board_corners]
	static bool runCalibration(CalibrationSettings& s, Size& imageSize, Mat& cameraMatrix, Mat& distCoeffs,
		CalibrationResults* r, vector<Mat>& rvecs, vector<Mat>& tvecs,
		vector<float>& reprojErrs, vector<Point3f>& newObjPoints,
		float grid_width)
	{
		Size boardSize(s.boardWidth, s.boardHeight);
		//! [fixed_aspect]
		cameraMatrix = Mat::eye(3, 3, CV_64F);
		if (s.flag & CALIB_FIX_ASPECT_RATIO)
			cameraMatrix.at<double>(0, 0) = s.aspectRatio;
		//! [fixed_aspect]
		if (s.useFisheye) {
			distCoeffs = Mat::zeros(4, 1, CV_64F);
		}
		else {
			distCoeffs = Mat::zeros(8, 1, CV_64F);
		}

		vector<vector<Point3f> > objectPoints(1);
		calcBoardCornerPositions(boardSize, s.squareSize, objectPoints[0]);
		objectPoints[0][s.boardWidth - 1].x = objectPoints[0][0].x + grid_width;
		newObjPoints = objectPoints[0];

		objectPoints.resize(r->CornerPoints->imagePoints.size(), objectPoints[0]);

		//Find intrinsic and extrinsic camera parameters
		double rms;
		if (s.useFisheye) {
			Mat _rvecs, _tvecs;
			rms = fisheye::calibrate(objectPoints, r->CornerPoints->imagePoints, imageSize, cameraMatrix, distCoeffs, _rvecs,
				_tvecs, s.flag);

			rvecs.reserve(_rvecs.rows);
			tvecs.reserve(_tvecs.rows);
			for (int i = 0; i < int(objectPoints.size()); i++) {
				rvecs.push_back(_rvecs.row(i));
				tvecs.push_back(_tvecs.row(i));
			}
		}
		else {
			int iFixedPoint = -1;

			rms = calibrateCameraRO(objectPoints, r->CornerPoints->imagePoints, imageSize, iFixedPoint,
				cameraMatrix, distCoeffs, rvecs, tvecs, newObjPoints,
				s.flag | CALIB_USE_LU);
		}

		bool ok = checkRange(cameraMatrix) && checkRange(distCoeffs);

		objectPoints.clear();
		objectPoints.resize(r->CornerPoints->imagePoints.size(), newObjPoints);
		r->avg_reprojection_error = computeReprojectionErrors(objectPoints, r->CornerPoints->imagePoints, rvecs, tvecs, cameraMatrix,
			distCoeffs, reprojErrs, s.useFisheye);

		return ok;
	}


	// Print camera parameters to the output file
	static void saveCameraParams(CalibrationSettings& s, Size& imageSize, Mat& cameraMatrix, Mat& distCoeffs,
		const vector<Mat>& rvecs, const vector<Mat>& tvecs,
		const vector<float>& reprojErrs, CalibrationResults* r, const vector<Point3f>& newObjPoints)
	{
		FileStorage fs(s.outputFileName, FileStorage::WRITE);

		struct tm t2;
		time_t tm;
		time(&tm);
		localtime_s(&t2, &tm);
		strftime(r->calibration_time, sizeof(r->calibration_time), "%c", &t2);

		r->squareSize = s.squareSize;

		fs << "calibration_time" << r->calibration_time;

		if (!rvecs.empty() || !reprojErrs.empty())
			fs << "nr_of_frames" << (int)std::max(rvecs.size(), reprojErrs.size());
		fs << "image_width" << imageSize.width;
		fs << "image_height" << imageSize.height;
		fs << "board_width" << s.boardWidth;
		fs << "board_height" << s.boardHeight;
		fs << "square_size" << s.squareSize;

		if (s.flag & CALIB_FIX_ASPECT_RATIO)
			fs << "fix_aspect_ratio" << s.aspectRatio;

		if (s.flag)
		{
			std::stringstream flagsStringStream;
			if (s.useFisheye)
			{
				flagsStringStream << "flags:"
					<< (s.flag & fisheye::CALIB_FIX_SKEW ? " +fix_skew" : "")
					<< (s.flag & fisheye::CALIB_FIX_K1 ? " +fix_k1" : "")
					<< (s.flag & fisheye::CALIB_FIX_K2 ? " +fix_k2" : "")
					<< (s.flag & fisheye::CALIB_FIX_K3 ? " +fix_k3" : "")
					<< (s.flag & fisheye::CALIB_FIX_K4 ? " +fix_k4" : "")
					<< (s.flag & fisheye::CALIB_RECOMPUTE_EXTRINSIC ? " +recompute_extrinsic" : "");
			}
			else
			{
				flagsStringStream << "flags:"
					<< (s.flag & CALIB_USE_INTRINSIC_GUESS ? " +use_intrinsic_guess" : "")
					<< (s.flag & CALIB_FIX_ASPECT_RATIO ? " +fix_aspectRatio" : "")
					<< (s.flag & CALIB_FIX_PRINCIPAL_POINT ? " +fix_principal_point" : "")
					<< (s.flag & CALIB_ZERO_TANGENT_DIST ? " +zero_tangent_dist" : "")
					<< (s.flag & CALIB_FIX_K1 ? " +fix_k1" : "")
					<< (s.flag & CALIB_FIX_K2 ? " +fix_k2" : "")
					<< (s.flag & CALIB_FIX_K3 ? " +fix_k3" : "")
					<< (s.flag & CALIB_FIX_K4 ? " +fix_k4" : "")
					<< (s.flag & CALIB_FIX_K5 ? " +fix_k5" : "");
			}
			fs.writeComment(flagsStringStream.str());
		}

		fs << "flags" << s.flag;

		fs << "fisheye_model" << s.useFisheye;

		// camera matrix
		fs << "camera_matrix" << cameraMatrix;  ////
		double* camMat = (double*)cameraMatrix.data;
		r->fx = camMat[0];
		r->cx = camMat[2];
		r->fy = camMat[4];
		r->cy = camMat[5];

		//distortion coefficient
		fs << "distortion_coefficients" << distCoeffs;  ////
		double* distMat = (double*)distCoeffs.data;
		r->k1 = distMat[0];
		r->k2 = distMat[1];
		r->p1 = distMat[2];
		r->p2 = distMat[3];
		r->k3 = distMat[4];

		//average reprojection error
		fs << "avg_reprojection_error" << r->avg_reprojection_error;
		if (!reprojErrs.empty())
			fs << "per_view_reprojection_errors" << Mat(reprojErrs);

		if (!rvecs.empty() && !tvecs.empty())
		{
			CV_Assert(rvecs[0].type() == tvecs[0].type());
			Mat bigmat((int)rvecs.size(), 6, CV_MAKETYPE(rvecs[0].type(), 1));
			bool needReshapeR = rvecs[0].depth() != 1 ? true : false;
			bool needReshapeT = tvecs[0].depth() != 1 ? true : false;

			for (size_t i = 0; i < rvecs.size(); i++)
			{
				Mat r = bigmat(Range(int(i), int(i + 1)), Range(0, 3));
				Mat t = bigmat(Range(int(i), int(i + 1)), Range(3, 6));

				if (needReshapeR)
					rvecs[i].reshape(1, 1).copyTo(r);
				else
				{
					//*.t() is MatExpr (not Mat) so we can use assignment operator
					CV_Assert(rvecs[i].rows == 3 && rvecs[i].cols == 1);
					r = rvecs[i].t();
				}

				if (needReshapeT)
					tvecs[i].reshape(1, 1).copyTo(t);
				else
				{
					CV_Assert(tvecs[i].rows == 3 && tvecs[i].cols == 1);
					t = tvecs[i].t();
				}
			}
			fs.writeComment("a set of 6-tuples (rotation vector + translation vector) for each view");
			fs << "extrinsic_parameters" << bigmat;
		}

		if (!r->CornerPoints->imagePoints.empty())
		{
			Mat imagePtMat((int)r->CornerPoints->imagePoints.size(), (int)r->CornerPoints->imagePoints[0].size(), CV_32FC2);
			for (size_t i = 0; i < r->CornerPoints->imagePoints.size(); i++)
			{
				Mat R = imagePtMat.row(int(i)).reshape(2, imagePtMat.cols);
				Mat imgpti(r->CornerPoints->imagePoints[i]);
				imgpti.copyTo(R);
			}
			fs << "image_points" << imagePtMat;
		}

		if (!newObjPoints.empty())
		{
			fs << "grid_points" << newObjPoints;
		}
	}


	//! [run_and_save]
	bool runCalibrationAndSave(CalibrationSettings& s, Size imageSize, Mat& cameraMatrix, Mat& distCoeffs,
		CalibrationResults* r, float grid_width)
	{
		vector<Mat> rvecs, tvecs;
		vector<float> reprojErrs;
		vector<Point3f> newObjPoints;

		bool ok = runCalibration(s, imageSize, cameraMatrix, distCoeffs, r, rvecs, tvecs, reprojErrs, newObjPoints, grid_width);


		if (ok)
		{
			saveCameraParams(s, imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, reprojErrs, r, newObjPoints);
		}
		return ok;
	}
	//! [run_and_save]


	bool PointInsideTriangle2D(float P[2], float A[2], float B[2], float C[2], float tolerance = 0.01)
	{
		Eigen::Vector3f AB, AC, PA, PB, PC;

		AB(0) = B[0] - A[0]; AB(1) = B[1] - A[1]; AB(2) = 0;
		AC(0) = C[0] - A[0]; AC(1) = C[1] - A[1]; AC(2) = 0;
		PA(0) = A[0] - P[0]; PA(1) = A[1] - P[1]; PA(2) = 0;
		PB(0) = B[0] - P[0]; PB(1) = B[1] - P[1]; PB(2) = 0;
		PC(0) = C[0] - P[0]; PC(1) = C[1] - P[1]; PC(2) = 0;

		float S = 0.5 * (AB.cross(AC)).norm();  // surface of trinagle ABC
		float S1 = 0.5 * (PA.cross(PB)).norm(); // surface of trinagle ABP
		float S2 = 0.5 * (PB.cross(PC)).norm(); // surface of triangle BCP
		float S3 = 0.5 * (PC.cross(PA)).norm(); // surface of triangle CAP
		return (abs(S - S1 - S2 - S3) / S <= tolerance); // P is inside ABC if the sum of three surfaces S1 S2 and S3 is equal to the surface of the whole triangle ABC
	}

	bool DetectFocalCenterGridPosition(CalibrationResults * cr, float px, float py, float& c, float& r)
	{
		bool INSIDE = false;
		int cols = cr->GridColsNB;
		int rows = cr->GridRowsNB;
		int frame_index = cr->GetFramesNB() - 1;
		int index;

		float P[2], A[2], B[2], C[2], D[2];

		P[0] = px; P[1] = py;

		for( int x = 0; x < cols - 1 && !INSIDE; x++)
			for ( int y = 0; y < rows - 1 && !INSIDE; y++)
			{
				index = y * cols + x;
				cr->GetCornerPoint(frame_index, index, A[0], A[1]);

				index = y * cols + x + 1;
				cr->GetCornerPoint(frame_index, index, B[0], B[1]);

				index = (y + 1) * cols + x + 1;
				cr->GetCornerPoint(frame_index, index, C[0], C[1]);

				index = (y + 1) * cols + x;
				cr->GetCornerPoint(frame_index, index, D[0], D[1]);

				INSIDE = PointInsideTriangle2D(P, A, B, C) || PointInsideTriangle2D(P, A, C, D);
				if (INSIDE) { c = x; r = y; }
			}
		
		if (INSIDE)
		{
			Eigen::Vector2f u1, u2, u;
			Eigen::Vector2f v1, v2, v;

			float dh1, dh2;
			float dv1, dv2;
			float au, bu, av, bv, a, b;

			//calculate the vectors of horizontal and vertical axis
			u1(0) = B[0] - A[0]; u1(1) = B[1] - A[1];
			u2(0) = C[0] - D[0]; u2(1) = C[1] - D[1];
			u = (u1 + u2) / 2; u /= u.norm();

			v1(0) = A[0] - D[0]; v1(1) = A[1] - D[1];
			v2(0) = B[0] - C[0]; v2(1) = B[1] - C[1];
			v = (v1 + v2) / 2; v /= v.norm();

			//calculate the parameters a and b of the lines passing by the focal center and parallel to uv and uh respectiveley (y=a*x+b)
			au = u(1) / u(0);  bu = py - au * px;
			av = v(1) / v(0);  bv = py - av * px;

			//calculate the interaction between horizontal axis and AD
			//and then calculate the distance dh1 between the intersection point and the focal center
			a = (A[1] - D[1]) / (A[0] - D[0]);  b = D[1] - a * D[0];
			P[0] = (bu - b) / (a - au);  P[1] = a * P[0] + b;  // P is the intersection point
			dh1 = sqrt(pow(P[0] - px,2.0) + pow(P[1] - py,2.0));

			//calculate the interaction between horizontal axis and BC
			//and then calculate the distance dh2 between the intersection point and the focal center
			a = (B[1] - C[1]) / (B[0] - C[0]);  b = B[1] - a * B[0];
			P[0] = (bu - b) / (a - au);  P[1] = a * P[0] + b;  // P is the intersection point
			dh2 = sqrt(pow(P[0] - px, 2.0) + pow(P[1] - py, 2.0));

			//calculate the interaction between horizontal axis and AB
			//and then calculate the distance dv1 between the intersection point and the focal center
			a = (A[1] - B[1]) / (A[0] - B[0]);  b = A[1] - a * A[0];
			P[0] = (bv - b) / (a - av);  P[1] = a * P[0] + b;  // P is the intersection point
			dv1 = sqrt(pow(P[0] - px, 2.0) + pow(P[1] - py, 2.0));

			//calculate the interaction between horizontal axis and CD
			//and then calculate the distance dv2 between the intersection point and the focal center
			a = (C[1] - D[1]) / (C[0] - D[0]);  b = C[1] - a * C[0];
			P[0] = (bv - b) / (a - av);  P[1] = a * P[0] + b;  // P is the intersection point
			dv2 = sqrt(pow(P[0] - px, 2.0) + pow(P[1] - py, 2.0));

			c += dh1 / (dh1 + dh2);
			r += dv1 / (dv1 + dv2);

		}
		else c = r = -1;

		return INSIDE;
	}
}