

#pragma once

#ifdef PCLLIB_EXPORTS
#define PCLLIB_API __declspec(dllexport)
#else
#define PCLLIB_API __declspec(dllimport)
#endif

#ifdef  PCLLIB_EXPORTS 
/*Enabled as "export" while compiling the dll project*/
#define DLLEXPORT __declspec(dllexport)  
#else
/*Enabled as "import" in the Client side for using already created dll file*/
#define DLLEXPORT __declspec(dllimport)  
#endif


struct DLLEXPORT CL_DATA;
extern "C" PCLLIB_API CL_DATA * createCL_DATA();


struct DLLEXPORT CL_ALIGN_SETTINGS {
	//limits of registered zone
	float xmin, xmax, ymin, ymax;

	//icp parameters
	float icp_maxcorrdist;

	//scp parameters
	float scp_leaf, scp_normalradiussearch, scp_featuresradiussearch, scp_simthr, scp_corrdist, scp_inlierfraction;
	int scp_maxitr, scp_samplesnb, scp_corrnb;

	//functions
	CL_ALIGN_SETTINGS();
	void SetRegisteredZone(float minx, float maxx, float miny, float maxy);
	void SetRegisteredZone(float p1[3], float p2[3], float p3[3]);
	void SetRegisteredZone(Eigen::VectorXf* P);
	bool IsPointInsideRegisteredZone(float xyz[3]);
	void SetICPMaxCorrespondenceDistance(float value);  // default value = 0.5f
	void SetSCPDownSampleLeaf(float value);  // default value = 0.005f
	void SetSCPNormalRadiusSearch(float value);  // default value = 0.05f
	void SetSCPFeaturesRadiusSearch(float value);  // default value = 0.01f
	void SetSCPSimilarityThreshold(float value); // Polygonal edge length similarity threshold. default value = 0.9f
	void SetSCPMaxCorrespondenceDistance(float value);  // Inlier threshold. default value =2.5f
	void SetSCPInlierFraction(float value); // Required inlier fraction for accepting a pose hypothesis. default value = 0.25f
	void SetSCPMaxIterationsNumber(int value);  // Number of RANSAC iterations. default value = 50000
	void SetSCPNumberOfSamples(int value);   // Number of points to sample for generating/prerejecting a pose . defalut value = 3
	void SetCorrespondenceRandomness(int value);  // Number of nearest features to use. default value = 5

};
extern "C" PCLLIB_API CL_ALIGN_SETTINGS * createCL_ALIGN_SETTINGS();


class DLLEXPORT PCL_POINTCLOUD {
public:
	CL_DATA* cl_data;
	CL_ALIGN_SETTINGS align_settings;

	PCL_POINTCLOUD();
	~PCL_POINTCLOUD();
	void Clear();
	void AddPoint(float x, float y, float z, float r, float g, float b);
	void FillFromPcdFile(char* filename);
	int GetCloudWidth();
	void FilterOutliers(int meank, float threshold);
	void SetXYZ(int index, float xyz[3]);
	void GetPoint(int index, float xyz[3], float rgb[3]);
	void GetXYZ(int index, float xyz[3]);
	void GetRGB(int index, float rgb[3]);
	void GetNormal(int index, float normal[3]);
	void ResetMaxMin();
	void SetMaxMin(float xmin, float xmax, float ymin, float ymax);
	void ExportCloudPly(char* filename);
	void GetRotationMatrix(Eigen::Matrix3f* M);
	void GetTranslationVector(Eigen::Vector3f* V);
	double GetAlignError();
	bool Align_ICP(PCL_POINTCLOUD target, float MaxCorrDist);
	bool Align_ICP(PCL_POINTCLOUD source, PCL_POINTCLOUD target, int N, float MaxCorrDist = 9999);
	bool Align_SCP(PCL_POINTCLOUD target, bool downsample, float leaf, float normalradiussearch, float featuresradiussearch, int maxitr, int samplesnb, int corrnb, float simthr, float corrdist, float inlierfraction);
	void operator =(PCL_POINTCLOUD target);
	void operator +(PCL_POINTCLOUD target);
	void operator /(int n);
};

extern "C" PCLLIB_API PCL_POINTCLOUD * createPCL_POINTCLOUD();


extern "C" PCLLIB_API double ICPDefaultMaxCorrDist();