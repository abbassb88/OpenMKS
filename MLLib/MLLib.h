#pragma once

#ifdef MLLIB_EXPORTS
#define MLLIB_API __declspec(dllexport)
#else
#define MLLIB_API __declspec(dllimport)
#endif

#ifdef  MLLIB_EXPORTS 
/*Enabled as "export" while compiling the dll project*/
#define DLLEXPORT __declspec(dllexport)  
#else
/*Enabled as "import" in the Client side for using already created dll file*/
#define DLLEXPORT __declspec(dllimport)  
#endif

namespace MLLib
{
	//Linear Regression Class
	class DLLEXPORT LINEAR_REGRESSION_CLASS
	{
	private:
		// Y = aX + b;
		Eigen::MatrixXf X;  //input
		Eigen::VectorXf Y;	//inout
		bool ready, done;  // ready = weather input data are valide and ready for caluclation      done = weather calculation is done 
		Eigen::VectorXf a;	//output
		float b;	//output
	public:
		LINEAR_REGRESSION_CLASS();
		void Clear();
		bool IsDone();
		void SetDimensions(int data_rows_nb, int variables_nb);
		bool AddDataRow(int row, float y, Eigen::VectorXf x);
		void SetX(Eigen::MatrixXf x);
		void SetY(Eigen::VectorXf y);
		bool Calculate();
		float CalculateValue(Eigen::VectorXf x);
		Eigen::VectorXf GetA();
		float GetB();
		void Set(Eigen::VectorXf vector_a, float constant_b);
		std::ostringstream ConvertToStream();

	};
	extern "C" MLLIB_API LINEAR_REGRESSION_CLASS * createLINEAR_REGRESSION_CLASS();
}