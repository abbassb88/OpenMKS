#include "pch.h"
#include "MLlib.h"


namespace MLLib
{

	LINEAR_REGRESSION_CLASS::LINEAR_REGRESSION_CLASS()
	{
		Clear();
	}

	void LINEAR_REGRESSION_CLASS::Clear()
	{
		done = false;
		ready = false;
		b = 0;
	}

	bool LINEAR_REGRESSION_CLASS::IsDone() { return done; }

	void LINEAR_REGRESSION_CLASS::SetDimensions(int data_rows_nb, int variables_nb)
	{
		X = Eigen::MatrixXf::Ones(data_rows_nb, variables_nb + 1);
		Y = Eigen::VectorXf::Zero(data_rows_nb);
		ready = false;
		done = false;
	}

	bool LINEAR_REGRESSION_CLASS::AddDataRow(int row, float y, Eigen::VectorXf x)
	{
		if(Y.rows() > 0 && X.rows() > 0 && X.rows() == Y.rows())
		if (row < X.rows() && row < Y.rows() && x.size() == X.cols() - 1)
		{
			Y(row) = y;
			for (size_t k = 0; k < x.size(); k++)
				X(row, k + 1) = x(k);

			if ((X.transpose() * X).determinant() != 0 && Y.norm() != 0) ready = true;

			return true;
		}
		else return false;
	}

	void LINEAR_REGRESSION_CLASS::SetX(Eigen::MatrixXf x)
	{
		X = x;

		if (X.cols() > 0 && X.rows() > 0 && Y.size() > 0 && Y.size() == X.rows())
			ready = false;
		else ready = false;
		done = false;
	}

	void LINEAR_REGRESSION_CLASS::SetY(Eigen::VectorXf y)
	{
		Y = y;

		if (X.cols() > 0 && X.rows() > 0 && Y.size() > 0 && Y.size() == X.rows())
			ready = false;
		else ready = false;
		done = false;
	}

	bool LINEAR_REGRESSION_CLASS::Calculate()
	{
		if (ready)
		{
			float y_mean = 0;
			Eigen::VectorXf x_mean = Eigen::VectorXf::Zero(X.cols());

			a = (X.transpose() * X).inverse() * X.transpose() * Y;


			for (int i = 0; i < X.rows(); i++)
			{
				y_mean += Y(i);
				for (size_t k = 0; k < X.cols(); k++) x_mean(k) += X(i, k);
			}

			y_mean /= float(X.rows());   x_mean /= float(X.rows());

			b = y_mean - x_mean.transpose() * a;

			done = true;
		}

		return done;
	}


	float LINEAR_REGRESSION_CLASS::CalculateValue(Eigen::VectorXf x)
	{
		if (done && x.size() == a.size() - 1)
		{
			float value = a(0) + b;
			for (int i = 0; i < x.size(); i++) value += a(i + 1) * x(i);
			return value;
		}
		else return 0;
	}

	std::ostringstream LINEAR_REGRESSION_CLASS::ConvertToStream()
	{

		std::ostringstream ss;
		ss << "A ="; for (int i = 0; i < a.size(); i++) ss <<"  "<< a(i);
		ss << "  |  B = " << b << std::endl;

		return ss;
	}

	Eigen::VectorXf LINEAR_REGRESSION_CLASS::GetA()
	{
		if (done) return a;
		else return Eigen::VectorXf::Zero(0);
	}

	float LINEAR_REGRESSION_CLASS::GetB()
	{
		if (done) return b;
		else 0;
	}

	void LINEAR_REGRESSION_CLASS::Set(Eigen::VectorXf vector_a, float constant_b)
	{
		a = vector_a;
		b = constant_b;
		done = true;
	}
}