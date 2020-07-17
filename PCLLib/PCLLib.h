#include "pch.h"
#include "PCLLib.h"




//**************************CL_Data**************************************//
struct CL_DATA {
	PointCloudXYZRGBN::Ptr cloud;
	Eigen::Matrix3f R;
	Eigen::Vector3f T;
	float maxX = 9999, minX = -9999;
	float maxY = 9999, minY = -9999;

	double align_error = 0;

	void Init()
	{
		cloud = PointCloudXYZRGBN::Ptr(new PointCloudXYZRGBN);
		R = Eigen::Matrix3f::Zero();
		T = Eigen::Vector3f::Zero();
	}
	void Clear()
	{
		cloud->clear();
		R = Eigen::MatrixXf::Identity(3, 3);
		T = Eigen::VectorXf::Zero(3);
		align_error = 0;
	}
	void frompcdfile(char* filename)
	{
		pcl::PCDReader reader;
		reader.read<PointXYZRGBN>(filename, *cloud);
	}
	void resetmaxmin()
	{
		maxX = 9999; minX = -9999;
		maxY = 9999; minY = -9999;
	}
	void setmaxmin(float xmin, float xmax, float ymin, float ymax)
	{
		maxX = xmax; minX = xmin;
		maxY = ymax; minY = ymin;
	}
	void exportcloudply(char* filename)
	{
		pcl::PLYWriter write;
		write.write<PointXYZRGBN>(filename, *cloud);
	}

	void operator =(CL_DATA cldata)
	{
		Clear();
		R = cldata.R;
		T = cldata.T;
		for (int i = 0; i < cldata.cloud->width; i++)
			cloud->insert(cloud->end(), cldata.cloud->at(i));
	}
};




//**************************CL_ALIGN_SETTINGS**************************************//
CL_ALIGN_SETTINGS::CL_ALIGN_SETTINGS()
{
	SetRegisteredZone(-9999, 9999, -9999, 9999);
	SetICPMaxCorrespondenceDistance(0.5f);
	SetSCPDownSampleLeaf(0.005f);
	SetSCPNormalRadiusSearch(0.05f);
	SetSCPFeaturesRadiusSearch(0.01f);
	SetSCPSimilarityThreshold(0.9f);
	SetSCPMaxCorrespondenceDistance(2.5f);
	SetSCPInlierFraction(0.25f);
	SetSCPMaxIterationsNumber(50000);
	SetSCPNumberOfSamples(3);
	SetCorrespondenceRandomness(5);
}

void CL_ALIGN_SETTINGS::SetRegisteredZone(float minx, float maxx, float miny, float maxy)
{
	xmin = minx; xmax = maxx;  ymin = miny; ymax = maxy;
}

void CL_ALIGN_SETTINGS::SetRegisteredZone(float p1[3], float p2[3], float p3[3])
{
	xmin = xmax = p1[0];
	if (p2[0] < xmin) xmin = p2[0];
	if (p3[0] < xmin) xmin = p3[0];
	if (p2[0] > xmax) xmax = p2[0];
	if (p3[0] > xmax) xmax = p3[0];

	ymin = ymax = p1[1];
	if (p2[1] < ymin) ymin = p2[1];
	if (p3[1] < ymin) ymin = p3[1];
	if (p2[1] > ymax) ymax = p2[1];
	if (p3[1] > ymax) ymax = p3[1];
}


void CL_ALIGN_SETTINGS::SetRegisteredZone(Eigen::VectorXf* P)
{
	xmin = 99999; xmax = -99999;  ymin = 99999; ymax = -99999;

	for (int i = 0; i < 3; i++)
	{

		if (P[i](0) < xmin) xmin = P[i](0);
		if (P[i](0) > xmax) xmax = P[i](0);

		if (P[i](1) < ymin) ymin = P[i](1);
		if (P[i](1) > ymax) ymax = P[i](1);
	}
}

bool CL_ALIGN_SETTINGS::IsPointInsideRegisteredZone(float xyz[3])
{
	bool B = false;
	if (xyz[0] <= xmax && xyz[0] >= xmin && xyz[1] <= ymax && xyz[1] >= ymin) B = true;
	return B;
}

void CL_ALIGN_SETTINGS::SetICPMaxCorrespondenceDistance(float value)
{
	icp_maxcorrdist = value;
}

void CL_ALIGN_SETTINGS::SetSCPDownSampleLeaf(float value)
{
	scp_leaf = value;
}

void CL_ALIGN_SETTINGS::SetSCPNormalRadiusSearch(float value)
{
	scp_normalradiussearch = value;
}

void CL_ALIGN_SETTINGS::SetSCPFeaturesRadiusSearch(float value)
{
	scp_featuresradiussearch = value;
}

void CL_ALIGN_SETTINGS::SetSCPSimilarityThreshold(float value)
{
	scp_simthr = value;
}

void CL_ALIGN_SETTINGS::SetSCPMaxCorrespondenceDistance(float value)
{
	scp_corrdist = value;
}

void CL_ALIGN_SETTINGS::SetSCPInlierFraction(float value)
{
	scp_inlierfraction = value;
}

void CL_ALIGN_SETTINGS::SetSCPMaxIterationsNumber(int value)
{
	scp_maxitr = value;
}

void CL_ALIGN_SETTINGS::SetSCPNumberOfSamples(int value)
{
	scp_samplesnb = value;
}

void CL_ALIGN_SETTINGS::SetCorrespondenceRandomness(int value)
{
	scp_corrnb = value;
}




//**************************PCL_POINTCLOUD**************************************//
PCL_POINTCLOUD::PCL_POINTCLOUD() : cl_data(new CL_DATA())
{
	cl_data->Init();
}

PCL_POINTCLOUD::~PCL_POINTCLOUD()
{
	//delete[] cl_data;
}

void PCL_POINTCLOUD::Clear()
{
	cl_data->Clear();
}

void PCL_POINTCLOUD::AddPoint(float x, float y, float z, float r, float g, float b)
{
	PointXYZRGBN P;
	P.x = x; P.y = y; P.z = z;
	P.r = (r * 255); P.g = (g * 255); P.b = (b * 255);
	cl_data->cloud->insert(cl_data->cloud->end(), P);
}

void PCL_POINTCLOUD::FillFromPcdFile(char* filename)
{
	cl_data->frompcdfile(filename);
}

int PCL_POINTCLOUD::GetCloudWidth()
{
	return cl_data->cloud->width;
}

void PCL_POINTCLOUD::FilterOutliers(int meank, float threshold)
{
	PointCloudXYZRGBN::Ptr source(new PointCloudXYZRGBN);
	pcl::StatisticalOutlierRemoval<PointXYZRGBN> sor;

	for (int i = 0; i < GetCloudWidth(); i++) source->insert(source->end(), cl_data->cloud->at(i));

	sor.setInputCloud(source);
	sor.setMeanK(meank);
	sor.setStddevMulThresh(threshold);
	sor.filter(*cl_data->cloud);
}

void PCL_POINTCLOUD::SetXYZ(int index, float xyz[3])
{
	cl_data->cloud->at(index).x = xyz[0];
	cl_data->cloud->at(index).y = xyz[1];
	cl_data->cloud->at(index).z = xyz[2];
}

void PCL_POINTCLOUD::GetPoint(int index, float xyz[3], float rgb[3])
{
	PointXYZRGBN P;
	P = cl_data->cloud->at(index);
	xyz[0] = P.x;
	xyz[1] = P.y;
	xyz[2] = P.z;
	rgb[0] = float(P.r) / 255;
	rgb[1] = float(P.g) / 255;
	rgb[2] = float(P.b) / 255;
}

void PCL_POINTCLOUD::GetXYZ(int index, float xyz[3])
{
	PointXYZRGBN P;
	P = cl_data->cloud->at(index);
	xyz[0] = P.x;
	xyz[1] = P.y;
	xyz[2] = P.z;
}

void PCL_POINTCLOUD::GetRGB(int index, float rgb[3])
{
	PointXYZRGBN P;
	P = cl_data->cloud->at(index);
	rgb[0] = P.r;
	rgb[1] = P.g;
	rgb[2] = P.b;
}

void PCL_POINTCLOUD::GetNormal(int index, float normal[3])
{
	PointXYZRGBN P;
	P = cl_data->cloud->at(index);
	normal[0] = P.normal_x;
	normal[1] = P.normal_y;
	normal[2] = P.normal_z;
}

void PCL_POINTCLOUD::ResetMaxMin()
{
	cl_data->resetmaxmin();
}

void PCL_POINTCLOUD::SetMaxMin(float xmin, float xmax, float ymin, float ymax)
{
	cl_data->setmaxmin(xmin, xmax, ymin, ymax);
}

void PCL_POINTCLOUD::ExportCloudPly(char* filename)
{
	cl_data->exportcloudply(filename);
}

void PCL_POINTCLOUD::GetRotationMatrix(Eigen::Matrix3f* M)
{
	*M = cl_data->R;
}

void PCL_POINTCLOUD::GetTranslationVector(Eigen::Vector3f* V)
{
	*V = cl_data->T;
}

double PCL_POINTCLOUD::GetAlignError()
{
	return cl_data->align_error;
}

bool PCL_POINTCLOUD::Align_ICP(PCL_POINTCLOUD target, float MaxCorrDist)
{
	bool B = false; float value[3];
	Eigen::Matrix4f M = Eigen::Matrix4f::Zero();
	PointCloudXYZRGBN::Ptr sourcecloud(new PointCloudXYZRGBN);
	PointCloudXYZRGBN::Ptr targetcloud(new PointCloudXYZRGBN);

	//fill source cloud
	for (int i = 0; i < GetCloudWidth(); i++)
	{
		GetXYZ(i, value);
		if (align_settings.IsPointInsideRegisteredZone(value))
		{
			sourcecloud->insert(sourcecloud->end(), cl_data->cloud->at(i));
		}
	}



	//fill target cloud
	for (int i = 0; i < target.GetCloudWidth(); i++)
	{
		target.GetXYZ(i, value);
		if (target.align_settings.IsPointInsideRegisteredZone(value))
		{
			targetcloud->insert(targetcloud->end(), target.cl_data->cloud->at(i));
		}
	}


	pcl::IterativeClosestPoint<PointXYZRGBN, PointXYZRGBN> icp;
	icp.setInputSource(sourcecloud);
	icp.setInputTarget(targetcloud);
	icp.setMaxCorrespondenceDistance(MaxCorrDist);
	pcl::PointCloud<PointXYZRGBN> Final;
	icp.align(Final);
	B = icp.hasConverged();
	cl_data->align_error = icp.getFitnessScore();

	if (B)
	{
		M = icp.getFinalTransformation();


		for (int r = 0; r < 3; r++)
			for (int c = 0; c < 3; c++)
				cl_data->R(r, c) = M(r, c);

		for (int i = 0; i < 3; i++)
			cl_data->T(i) = M(i, 3);
	}

	return B;
}

bool PCL_POINTCLOUD::Align_ICP(PCL_POINTCLOUD source, PCL_POINTCLOUD target, int N, float MaxCorrDist)
{
	bool B = false; float value[3];
	Eigen::Matrix4f M = Eigen::Matrix4f::Zero();
	PointCloudXYZRGBN::Ptr sourcecloud(new PointCloudXYZRGBN);
	PointCloudXYZRGBN::Ptr targetcloud(new PointCloudXYZRGBN);

	//fill source cloud
	for (int i = 0; i < N; i++)
	{
		source.GetXYZ(i, value);
		sourcecloud->insert(sourcecloud->end(), cl_data->cloud->at(i));
	}



	//fill target cloud
	for (int i = 0; i < N; i++)
	{
		target.GetXYZ(i, value);
		targetcloud->insert(targetcloud->end(), target.cl_data->cloud->at(i));
	}


	pcl::IterativeClosestPoint<PointXYZRGBN, PointXYZRGBN> icp;
	icp.setInputSource(sourcecloud);
	icp.setInputTarget(targetcloud);
	icp.setMaxCorrespondenceDistance(MaxCorrDist);
	pcl::PointCloud<PointXYZRGBN> Final;
	icp.align(Final);
	B = icp.hasConverged();
	cl_data->align_error = icp.getFitnessScore();

	if (B)
	{
		M = icp.getFinalTransformation();


		for (int r = 0; r < 3; r++)
			for (int c = 0; c < 3; c++)
				cl_data->R(r, c) = M(r, c);

		for (int i = 0; i < 3; i++)
			cl_data->T(i) = M(i, 3);
	}

	return B;
}


bool PCL_POINTCLOUD::Align_SCP(PCL_POINTCLOUD targetcl, bool downsample, float leaf, float normalradiussearch, float featuresradiussearch, int maxitr, int samplesnb, int corrnb, float simthr, float corrdist, float inlierfraction)
{
	bool B;
	float value[3];
	PointNT P;
	Eigen::Matrix4f M = Eigen::Matrix4f::Zero();

	//http://pointclouds.org/documentation/tutorials/alignment_prerejective.php

	PointCloudT::Ptr source(new PointCloudT); int NS = GetCloudWidth();
	PointCloudT::Ptr target(new PointCloudT);  int NT = targetcl.GetCloudWidth();
	PointCloudT::Ptr source_aligned(new PointCloudT);
	FeatureCloudT::Ptr source_features(new FeatureCloudT);
	FeatureCloudT::Ptr target_features(new FeatureCloudT);

	//fill source
	for (int i = 0; i < NS; i++)
	{
		GetXYZ(i, value);
		if (align_settings.IsPointInsideRegisteredZone(value))
		{
			P.x = value[0]; P.y = value[1]; P.z = value[2];
			source->insert(source->end(), P);
		}
	}

	//fill target
	for (int i = 0; i < NT; i++)
	{
		targetcl.GetXYZ(i, value);
		if (targetcl.align_settings.IsPointInsideRegisteredZone(value))
		{
			P.x = value[0]; P.y = value[1]; P.z = value[2];
			target->insert(target->end(), P);
		}
	}

	if (downsample)
	{
		// Downsample
		pcl::VoxelGrid<PointNT> grid;
		grid.setLeafSize(leaf, leaf, leaf);
		grid.setInputCloud(source);
		grid.filter(*source);
		grid.setInputCloud(target);
		grid.filter(*target);
	}


	// Estimate normals for scene
	pcl::NormalEstimationOMP<PointNT, PointNT> nest;
	nest.setRadiusSearch(normalradiussearch);
	nest.setInputCloud(target);
	nest.compute(*target);

	// Estimate features
	FeatureEstimationT fest;
	fest.setRadiusSearch(featuresradiussearch);
	fest.setInputCloud(source);
	fest.setInputNormals(source);
	fest.compute(*source_features);
	fest.setInputCloud(target);
	fest.setInputNormals(target);
	fest.compute(*target_features);


	// Perform alignment
	pcl::SampleConsensusPrerejective<PointNT, PointNT, FeatureT> align;
	align.setInputSource(source);
	align.setSourceFeatures(source_features);
	align.setInputTarget(target);
	align.setTargetFeatures(target_features);
	align.setMaximumIterations(maxitr); // Number of RANSAC iterations (50000)
	align.setNumberOfSamples(samplesnb); // Number of points to sample for generating/prerejecting a pose (3)
	align.setCorrespondenceRandomness(corrnb); // Number of nearest features to use (5)
	align.setSimilarityThreshold(simthr); // Polygonal edge length similarity threshold   (0.9f)
	align.setMaxCorrespondenceDistance(corrdist * leaf); // Inlier threshold  (2.5f*leaf)
	align.setInlierFraction(inlierfraction); // Required inlier fraction for accepting a pose hypothesis  (0.25f)


	pcl::ScopeTime t("Alignment");
	align.align(*source_aligned);
	cl_data->align_error = align.getFitnessScore();

	B = align.hasConverged();

	if (B)
	{
		M = align.getFinalTransformation();


		for (int r = 0; r < 3; r++)
			for (int c = 0; c < 3; c++)
				cl_data->R(r, c) = M(r, c);

		for (int i = 0; i < 3; i++)
			cl_data->T(i) = M(i, 3);
	}

	return B;
}

void PCL_POINTCLOUD::operator=(PCL_POINTCLOUD target)
{
	*cl_data = *(target.cl_data);
}


void PCL_POINTCLOUD::operator+(PCL_POINTCLOUD target)
{
	int N = GetCloudWidth();
	if (target.GetCloudWidth() < N) N = target.GetCloudWidth();

	for (int i = 0; i < N; i++)
	{
		cl_data->cloud->at(i).x += target.cl_data->cloud->at(i).x;
		cl_data->cloud->at(i).y += target.cl_data->cloud->at(i).y;
		cl_data->cloud->at(i).z += target.cl_data->cloud->at(i).z;
		cl_data->cloud->at(i).r += target.cl_data->cloud->at(i).r;
		cl_data->cloud->at(i).g += target.cl_data->cloud->at(i).g;
		cl_data->cloud->at(i).b += target.cl_data->cloud->at(i).b;
	}
}

void PCL_POINTCLOUD::operator/(int n)
{
	for (int i = 0; i < GetCloudWidth(); i++)
	{
		cl_data->cloud->at(i).x /= float(n);
		cl_data->cloud->at(i).y /= float(n);
		cl_data->cloud->at(i).z /= float(n);
		cl_data->cloud->at(i).r /= float(n);
		cl_data->cloud->at(i).g /= float(n);
		cl_data->cloud->at(i).b /= float(n);
	}
}


double ICPDefaultMaxCorrDist()
{
	pcl::IterativeClosestPoint<PointXYZRGBN, PointXYZRGBN> icp;
	return icp.getMaxCorrespondenceDistance();
}
