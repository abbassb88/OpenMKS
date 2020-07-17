#pragma once

#ifdef INTERLIB_EXPORTS
#define INTERLIB_API __declspec(dllexport)
#else
#define INTERLIB_API __declspec(dllimport)
#endif

#ifdef  INTERLIB_EXPORTS 
/*Enabled as "export" while compiling the dll project*/
#define DLLEXPORT __declspec(dllexport)  
#else
/*Enabled as "import" in the Client side for using already created dll file*/
#define DLLEXPORT __declspec(dllimport)  
#endif

namespace InterLib
{


	//Newral Network Class
	class DLLEXPORT INTER2D_REGULAR
	{
	private:
		int SpaceWidth;   //2D space width
		int SpaceHeight;   //2D space height
		int GridCols;   //grid points columns number
		int GridRows;	//grid points rows number
		std::vector<Eigen::Vector3f> GivenPoints;   // vector of grid points, each point contains [ x, y, value ]
		bool valide;   // if the information are valide and if it is possible to execute the interpolation
		double empty_value;     // the value to be used for ignored points in the 2D space

	public:
		INTER2D_REGULAR();
		INTER2D_REGULAR(int space_width, int space_height);
		void SetSpaceDimensions(int space_width, int space_height);
		void SetEmptyValue(double value);
		double GetEmptyValue();
		bool IsValide();
		bool SetGridPoints(std::vector<Eigen::Vector3f> points, int cols, int rows);
		Eigen::MatrixXf Interpolate(int p = 2);
	};
	extern "C" INTERLIB_API INTER2D_REGULAR * createCalibrationSettings();


	extern "C" INTERLIB_API long ScalarToRainbow(double scalar_value, double min, double max);
	extern "C" INTERLIB_API void ScalarMatrixToRainbow(Eigen::MatrixXf M, Eigen::MatrixXd &ARGB, double min, double max);

}