#pragma once

#ifdef MATHLIB_EXPORTS
#define MATHLIB_API __declspec(dllexport)
#else
#define MATHLIB_API __declspec(dllimport)
#endif

#ifdef  MATHLIB_EXPORTS 
/*Enabled as "export" while compiling the dll project*/
#define DLLEXPORT __declspec(dllexport)  
#else
/*Enabled as "import" in the Client side for using already created dll file*/
#define DLLEXPORT __declspec(dllimport)  
#endif

namespace MathLib
{
	extern "C" MATHLIB_API float Mean(Eigen::VectorXf x);
	extern "C" MATHLIB_API float Variance(Eigen::VectorXf x);
	extern "C" MATHLIB_API float Standard_Deviation(Eigen::VectorXf x);
	extern "C" MATHLIB_API float Covariance(Eigen::VectorXf x, Eigen::VectorXf y);
	extern "C" MATHLIB_API float Correlation(Eigen::VectorXf x, Eigen::VectorXf y);
}