// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here

#include <iostream>
#include <time.h>
#include <Eigen/Eigen>
#include <Eigen/SVD>
#include <libfreenect.h>
#include <fstream>

#include "../CVLib/CVLib.h"
#include "../Interlib/Interlib.h"
#include "../MathLib/MathLib.h"
#include "../MeshLib/MeshLib.h"
#include "../MLLib/MLLib.h"
#include "../PCLLib/PCLLib.h"

using namespace std;

using namespace OpenTK;
using namespace OpenTK::Input;
using namespace OpenTK::Graphics;
using namespace OpenTK::Graphics::OpenGL;

Eigen::MatrixXf M;


//settings parameters used in the program
namespace SETTINGS
{
	extern bool load_kinect_online;

	namespace Mesh
	{
		extern float filter_meank;
		extern float filter_threshold;
		extern int normals_estimation_neighbors_nb;
		extern int meshSS_neighbors_nb, meshSS_average_space, meshSS_samples;
		extern int meshP_neighbors_nb, meshP_smoothangle;
		extern float meshP_error, meshP_triangleSize;
		extern int mesh_algorithm;
	}

	namespace Display
	{
		extern float backcolor[3];
		extern bool show_grid;
		extern float cloud_point_size;
		extern float selection_point_size;
		extern float cloud_normal_size;
		extern bool pointscolor;
	}

	namespace Scan
	{
		extern int frames_number;
		extern int upsampling_factor;
		extern float interpolation_factor;
		extern float chessboard_tolerance;
		extern int regression_order;
		extern bool fill_gaps;
		extern float depth_origin;
	}

	extern CVLib::CalibrationSettings calibsettings;
	extern void Init();
}
/////


//two overload functions to estimate rotation and translation matrices of a point set to be aligned with another point set using SVD-based rigid transformation
bool EstimateRotationMatrix(vector<vector<Eigen::Vector3f>> source, vector<vector<Eigen::Vector3f>> destination, Eigen::Vector3f Ci, Eigen::Vector3f Cf, Eigen::Matrix3f& Rotation, Eigen::Vector3f& Translation, int excluded_device = -1);
bool EstimateRotationMatrix(vector<vector<Eigen::Vector3f>> source, vector<vector<Eigen::Vector3f>> destination, Eigen::Matrix3f& Rotation, Eigen::Vector3f& Translation, int excluded_device = -1);

#endif //PCH_H
