#include "pch.h"

namespace SETTINGS
{
	bool load_kinect_online = false;

	namespace Mesh
	{
		float filter_meank = 50.0;
		float filter_threshold = 1.0;
		int normals_estimation_neighbors_nb = 150;
		int meshSS_neighbors_nb = 12, meshSS_average_space = 4, meshSS_samples = 1;
		int meshP_neighbors_nb = 60, meshP_smoothangle = 30;
		float meshP_error = 0.2, meshP_triangleSize = 0.7;
		int mesh_algorithm = 3; // 1- Poisson   2-Spare-Scale      // 3- combined
	}

	namespace Display
	{
		float backcolor[3] = { 0.5, 0.5, 0.5 };
		bool show_grid = true;

		float cloud_point_size = 1.0;
		float selection_point_size = 2.0;
		float cloud_normal_size = 0.025;

		bool pointscolor = false;
	}

	namespace Scan
	{
		int frames_number = 4;

		int upsampling_factor = 1;
		float interpolation_factor = 1.0;

		float chessboard_tolerance = 500;

		int regression_order = 3;

		bool fill_gaps = false;

		float depth_origin = 0.5;
	}



	CVLib::CalibrationSettings calibsettings;

	void Init()
	{
		calibsettings.flexiblesize = TRUE;		calibsettings.squareSize = 0.089666;
		calibsettings.boardHeight = 7; calibsettings.boardWidth = 11;
	}
}



bool EstimateRotationMatrix(vector<vector<Eigen::Vector3f>> source, vector<vector<Eigen::Vector3f>> destination, Eigen::Vector3f Ci, Eigen::Vector3f Cf, Eigen::Matrix3f& Rotation, Eigen::Vector3f& Translation, int excluded_device)
{
	bool B = false;

	if (destination.size() > 0 && destination.size() == source.size())
	{
		int NB = destination.size();
		int total_points = 0;

		Eigen::MatrixXf H = Eigen::MatrixXf::Zero(3, 3);


		B = true;

		//Fill H matrix
		for (int i = 0; i < NB; i++) if (i != excluded_device)
		{
			int n = source.at(i).size();
			if (n > destination.at(i).size()) n = destination.at(i).size();

			for (int k = 0; k < n; k++)
			{
				H += (source.at(i).at(k) - Ci) * (destination.at(i).at(k) - Cf).transpose();
				total_points++;
			}
		}

		if (total_points >= 3)
		{
			B = true;

			//SVD calculation
			Eigen::JacobiSVD<Eigen::MatrixXf> svd(H, Eigen::ComputeThinU | Eigen::ComputeThinV);

			Eigen::MatrixXf U = svd.matrixU();
			Eigen::MatrixXf V = svd.matrixV();

			//calculate rotation matrix
			Rotation = V * U.transpose();
			if (Rotation.determinant() < 0)
			{
				V(0, 2) *= -1;
				V(1, 2) *= -1;
				V(2, 2) *= -1;

				Rotation = V * U.transpose();
			}

			//calculate translation vector 
			Translation = -Rotation * Ci + Cf;
		}

	}
	return B;
}



bool EstimateRotationMatrix(vector<vector<Eigen::Vector3f>> source, vector<vector<Eigen::Vector3f>> destination, Eigen::Matrix3f& Rotation, Eigen::Vector3f& Translation, int excluded_device)
{
	bool B = false;

	if (destination.size() > 0 && destination.size() == source.size())
	{
		int NB = destination.size();

		Eigen::MatrixXf H = Eigen::MatrixXf::Zero(3, 3);
		Eigen::Vector3f Ci = Eigen::Vector3f::Zero();
		Eigen::Vector3f Cf = Eigen::Vector3f::Zero();


		//calculate the barycenters Ci and Cf
		int total_points = 0;
		for (int i = 0; i < NB; i++) if (i != excluded_device)
		{
			int n = source.at(i).size();
			if (n > destination.at(i).size()) n = destination.at(i).size();

			for (int k = 0; k < n; k++)
			{
				Ci += source.at(i).at(k);
				Cf += destination.at(i).at(k);
				total_points++;
			}
		}

		if (total_points >= 3)
		{

			B = true;
			Ci /= total_points;
			Cf /= total_points;

			//Fill H matrix
			for (int i = 0; i < NB; i++) if (i != excluded_device)
			{
				int n = source.at(i).size();
				if (n > destination.at(i).size()) n = destination.at(i).size();

				for (int k = 0; k < n; k++)
					H += (source.at(i).at(k) - Ci) * (destination.at(i).at(k) - Cf).transpose();
			}


			//SVD calculation
			Eigen::JacobiSVD<Eigen::MatrixXf> svd(H, Eigen::ComputeThinU | Eigen::ComputeThinV);

			Eigen::MatrixXf U = svd.matrixU();
			Eigen::MatrixXf V = svd.matrixV();

			//calculate rotation matrix
			Rotation = V * U.transpose();
			if (Rotation.determinant() < 0)
			{
				V(0, 2) *= -1;
				V(1, 2) *= -1;
				V(2, 2) *= -1;

				Rotation = V * U.transpose();
			}

			//calculate translation vector 
			Translation = -Rotation * Ci + Cf;
		}
	}
	return B;
}