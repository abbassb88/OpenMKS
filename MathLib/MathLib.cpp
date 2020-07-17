#include "pch.h"
#include "MathLib.h"

namespace MathLib
{
	float Mean(Eigen::VectorXf x)
	{
		int N = x.size();
		float var = 0;
		
		for (int i = 0; i < N; i++) var += x(i);

		var /= float(N);

		return var;
	}

	float Variance(Eigen::VectorXf x)
	{
		float var = 0;
		if (x.size() > 0)
		{
			for (int i = 0; i < x.size(); i++) var += x(i) * x(i);
			var /= float(x.size());
			var -= x.mean() * x.mean();
		}
		return var;
	}

	float Standard_Deviation(Eigen::VectorXf x)
	{
		return sqrt(Variance(x));
	}

	float Covariance(Eigen::VectorXf x, Eigen::VectorXf y)
	{
		int N = x.size();
		if (N > 0 && y.size() == N)
		{
			//Cov(X,Y) = E(XY) - E(X)E(Y);

			float Ex = x.mean();   //E(X)
			float Ey = y.mean();   //E(Y)
			float Exy = 0;

			// calculate E(XY)
			for (int i = 0; i < N; i++) Exy += x(i) * y(i);
			Exy /= float(N);


			return Exy - Ex * Ey;
		}
		else return 0;
	}


	float Correlation(Eigen::VectorXf x, Eigen::VectorXf y)
	{
		float ss = Standard_Deviation(x) * Standard_Deviation(y);
		if (ss == 0)
			return 0;
		else
			return Covariance(x, y) / ss;
	}
}