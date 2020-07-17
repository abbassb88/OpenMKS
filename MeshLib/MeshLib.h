#pragma once

#include <vector>

#ifdef MESHLIB_EXPORTS
#define MESHLIB_API __declspec(dllexport)
#else
#define MESHLIB_API __declspec(dllimport)
#endif

#ifdef  MESHLIB_EXPORTS 
/*Enabled as "export" while compiling the dll project*/
#define DLLEXPORT __declspec(dllexport)  
#else
/*Enabled as "import" in the Client side for using already created dll file*/
#define DLLEXPORT __declspec(dllimport)  
#endif

class DLLEXPORT CLOUDPOINT {
private:
	float point[3], normal[3];
public:
	CLOUDPOINT();
	void SetPoint(float[3]);
	void SetNormal(float[3]);
	void Set(float[3], float[3]);
	void GetPoint(float[3]);
	void GetNormal(float[3]);
};

extern "C" MESHLIB_API CLOUDPOINT * createCLOUDPOINT();



class DLLEXPORT TRIANGLE {
private:
	float points[3][3], normal[3];
public:
	TRIANGLE();
	~TRIANGLE();
	void SetPoint(int, float[3]);
	void SetNormal(float[3]);
	void GetPoint(int, float[3]);
	void GetNormal(float[3]);
};

extern "C" MESHLIB_API TRIANGLE * createTRIANGLE();


class DLLEXPORT POINT3D {
private:
	float X[3];
	float color[3];
public:
	POINT3D();
	~POINT3D();
	void SetCoord(float[3]);
	void SetCoord(float, float, float);
	void SetColor(float[3]);
	void SetColor(float, float, float);
	void GetCoord(float[3]);
	void GetColor(float[3]);
	float GetX();
	float GetY();
	float GetZ();

	bool operator==(POINT3D);
};

extern "C" MESHLIB_API POINT3D * createPOINT3D();



class DLLEXPORT FACE3D {
private:
	int points[3];
	float normal[3];
public:
	FACE3D();
	~FACE3D();
	void SetPoint(int, int);
	void SetPoints(int, int, int);
	void SetNormal(float[3]);
	void SetNormal(float, float, float);
	int GetPoint(int);
	void GetNormal(float[3]);
	float GetNormalX();
	float GetNormalY();
	float GetNormalZ();
};

extern "C" MESHLIB_API FACE3D * createFACE3D();



class DLLEXPORT OBJECT3D {
public:
	POINT3D* Points;
	FACE3D* Faces;
	int PointsNB, FacesNB;

	OBJECT3D();
	~OBJECT3D();

	void SaveToSTL(char*);
	void SaveToTXT(char*);
	void FromTriangles(TRIANGLE*, int);
	bool FromPointClouds_Poisson(CLOUDPOINT*, int, int, double);
	bool FromPointClouds_Poisson(CLOUDPOINT*, int, int, float, float, float, bool, float, int);
	bool FromPointClouds_ScaleSpace(CLOUDPOINT*, int, int, int, int, bool, float, int);
	bool FromPointClouds_AdvancingFront(CLOUDPOINT*, int);

};

extern "C" MESHLIB_API OBJECT3D * createOBJECT3D();



extern "C" MESHLIB_API int SQUARE(int);

extern "C" MESHLIB_API void CGAL_JET_ESTIMATE_NORMALS(CLOUDPOINT*, int, int);

extern "C" MESHLIB_API void CGAL_PCA_ESTIMATE_NORMALS(CLOUDPOINT*, int, int);