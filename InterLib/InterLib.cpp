#include "pch.h"
#include "Interlib.h"

namespace InterLib
{
	INTER2D_REGULAR::INTER2D_REGULAR()
	{
		empty_value = -9999999;
		valide = false;
	}

	INTER2D_REGULAR::INTER2D_REGULAR(int space_width, int space_height)
	{
		empty_value = -9999999;
		valide = false;
		SpaceWidth = space_width;
		SpaceHeight = space_height;
	}

	void INTER2D_REGULAR::SetSpaceDimensions(int space_width, int space_height)
	{
		SpaceWidth = space_width;
		SpaceHeight = space_height;
	}

	void INTER2D_REGULAR::SetEmptyValue(double value)
	{
		empty_value = value;
	}

	double INTER2D_REGULAR::GetEmptyValue()
	{
		return empty_value;
	}

	bool INTER2D_REGULAR::IsValide()
	{
		return valide;
	}

	bool INTER2D_REGULAR::SetGridPoints(std::vector<Eigen::Vector3f> points, int cols, int rows)
	{
		if (points.size() != cols * rows) valide = false;
		else
		{
			GridCols = cols;
			GridRows = rows;
			GivenPoints = points;
			valide = true;
		}

		return valide;
	}


	bool PointInsideTriangle2D(float P[2], float A[2], float B[2], float C[2], float tolerance = 0.01)
	{
		Eigen::Vector3f AB, AC, PA, PB, PC;

		AB(0) = B[0] - A[0]; AB(1) = B[1] - A[1]; AB(2) = 0;
		AC(0) = C[0] - A[0]; AC(1) = C[1] - A[1]; AC(2) = 0;
		PA(0) = A[0] - P[0]; PA(1) = A[1] - P[1]; PA(2) = 0;
		PB(0) = B[0] - P[0]; PB(1) = B[1] - P[1]; PB(2) = 0;
		PC(0) = C[0] - P[0]; PC(1) = C[1] - P[1]; PC(2) = 0;

		float S = 0.5 * (AB.cross(AC)).norm();  // surface of trinagle ABC
		float S1 = 0.5 * (PA.cross(PB)).norm(); // surface of trinagle ABP
		float S2 = 0.5 * (PB.cross(PC)).norm(); // surface of triangle BCP
		float S3 = 0.5 * (PC.cross(PA)).norm(); // surface of triangle CAP
		return (abs(S - S1 - S2 - S3) / S <= tolerance); // P is inside ABC if the sum of three surfaces S1 S2 and S3 is equal to the surface of the whole triangle ABC
	}

	Eigen::Vector2f DetectPositionInSquare(float P[2], float A[2], float B[2], float C[2], float D[2])
	{
		Eigen::Vector2f X;
		Eigen::Vector2f u1, u2, u;
		Eigen::Vector2f v1, v2, v;

		float px = P[0], py = P[1];

		float dh1, dh2;
		float dv1, dv2;
		float au, bu, av, bv, a, b;

		//calculate the vectors of horizontal and vertical axis
		u1(0) = B[0] - A[0]; u1(1) = B[1] - A[1];
		u2(0) = C[0] - D[0]; u2(1) = C[1] - D[1];
		u = (u1 + u2) / 2; u /= u.norm();

		v1(0) = A[0] - D[0]; v1(1) = A[1] - D[1];
		v2(0) = B[0] - C[0]; v2(1) = B[1] - C[1];
		v = (v1 + v2) / 2; v /= v.norm();

		//calculate the parameters a and b of the lines passing by the focal center and parallel to uv and uh respectiveley (y=a*x+b)
		au = u(1) / u(0);  bu = py - au * px;
		av = v(1) / v(0);  bv = py - av * px;

		//calculate the interaction between horizontal axis and AD
		//and then calculate the distance dh1 between the intersection point and the focal center
		a = (A[1] - D[1]) / (A[0] - D[0]);  b = D[1] - a * D[0];
		P[0] = (bu - b) / (a - au);  P[1] = a * P[0] + b;  // P is the intersection point
		dh1 = sqrt(pow(P[0] - px, 2.0) + pow(P[1] - py, 2.0));

		//calculate the interaction between horizontal axis and BC
		//and then calculate the distance dh2 between the intersection point and the focal center
		a = (B[1] - C[1]) / (B[0] - C[0]);  b = B[1] - a * B[0];
		P[0] = (bu - b) / (a - au);  P[1] = a * P[0] + b;  // P is the intersection point
		dh2 = sqrt(pow(P[0] - px, 2.0) + pow(P[1] - py, 2.0));

		//calculate the interaction between horizontal axis and AB
		//and then calculate the distance dv1 between the intersection point and the focal center
		a = (A[1] - B[1]) / (A[0] - B[0]);  b = A[1] - a * A[0];
		P[0] = (bv - b) / (a - av);  P[1] = a * P[0] + b;  // P is the intersection point
		dv1 = sqrt(pow(P[0] - px, 2.0) + pow(P[1] - py, 2.0));

		//calculate the interaction between horizontal axis and CD
		//and then calculate the distance dv2 between the intersection point and the focal center
		a = (C[1] - D[1]) / (C[0] - D[0]);  b = C[1] - a * C[0];
		P[0] = (bv - b) / (a - av);  P[1] = a * P[0] + b;  // P is the intersection point
		dv2 = sqrt(pow(P[0] - px, 2.0) + pow(P[1] - py, 2.0));

		X.x() = dh1 / (dh1 + dh2);
		X.y() = dv1 / (dv1 + dv2);

		return X;
	}

	Eigen::MatrixXf INTER2D_REGULAR::Interpolate(int p)
	{
		Eigen::MatrixXf M = Eigen::MatrixXf::Zero(SpaceHeight, SpaceWidth);

		float P[2], A[2], B[2], C[2], D[2];
		int corners[4];
		float ds[4];

		for( int y = 0; y < SpaceHeight; y++)
			for (int x = 0; x < SpaceWidth; x++)
			{
				//point coordinates
				P[0] = x;  P[1] = y;

				//find square
				bool in_square = false;
				for( int c = 0; c < GridCols - 1 && !in_square; c++)
					for (int r = 0; r < GridRows - 1 && !in_square; r++)
					{
						corners[0] = r * GridCols + c;
						corners[1] = r * GridCols + c + 1;
						corners[2] = (r + 1) * GridCols + c + 1;
						corners[3] = (r + 1) * GridCols + c;

						A[0] = GivenPoints.at(corners[0]).x();  A[1] = GivenPoints.at(corners[0]).y();
						B[0] = GivenPoints.at(corners[1]).x();  B[1] = GivenPoints.at(corners[1]).y();
						C[0] = GivenPoints.at(corners[2]).x();  C[1] = GivenPoints.at(corners[2]).y();
						D[0] = GivenPoints.at(corners[3]).x();  D[1] = GivenPoints.at(corners[3]).y();

						in_square = PointInsideTriangle2D(P, A, B, C, 0.00001) || PointInsideTriangle2D(P, C, D, A, 0.00001);
					}

				if (!in_square)
				{
					M(y, x) = empty_value;
				}
				else
				{
					Eigen::Vector2f pos = DetectPositionInSquare(P, A, B, C, D);

					float F1 = (1 - pos.x()) * GivenPoints.at(corners[0]).z() + pos.x() * GivenPoints.at(corners[1]).z();
					float F2 = (1 - pos.x()) * GivenPoints.at(corners[3]).z() + pos.x() * GivenPoints.at(corners[2]).z();
					float F = (1 - pos.y()) * F1 + pos.y() *F2;
					M(y, x) = F;

					/*
					for( int i = 0; i < 4; i++)
						ds[i] = sqrt(pow(x - GivenPoints.at(corners[i]).x(), 2.0) + pow(y - GivenPoints.at(corners[i]).y(), 2.0));

					if (ds[0] == 0) M(y, x) = GivenPoints.at(corners[0]).z();
					else if (ds[1] == 0) M(y, x) = GivenPoints.at(corners[1]).z();
					else if (ds[2] == 0) M(y, x) = GivenPoints.at(corners[2]).z();
					else if (ds[3] == 0) M(y, x) = GivenPoints.at(corners[3]).z();
					else
					{
						for (int k = 0; k < 4; k++) ds[k] = 1 / pow(ds[k], float(p));
						M(y, x) = 0;
						for (int k = 0; k < 4; k++) M(y, x) += GivenPoints.at(corners[k]).z() * ds[k];
						M(y, x) /= ds[0] + ds[1] + ds[2] + ds[3];
					}
					*/
				}
			}

		return M;
	}

	long ScalarToRainbow(double scalar_value, double min, double max)
	{
		long r = 0, g = 0, b = 0;
		long argb = 4278190080;  //alpha


		if (scalar_value >=max) { r = 255; g = 0; b = 0; }
		else if (scalar_value <= min ) { r = 0; g = 0; b = 255; }
		else
		{

			double f = (scalar_value - min) / (max - min); //normalize
			f = (1 - f) / 0.25;		//invert and group

			int X = int(f);   // integer part
			int Y = int((f - X) * 255.0);   //fractional part from 0 to 255

			if (X == 0) { r = 255; g = Y; b = 0; }
			else if (X == 1) { r = 255 - Y; g = 255; b = 0; }
			else if (X == 2) { r = 0; g = 255; b = Y; }
			else if (X == 3) { r = 0; g = 255 - Y; b = 255; }
		}

		argb += r * 65536 + g * 256 + b;

		return argb;
	}

	void ScalarMatrixToRainbow(Eigen::MatrixXf M, Eigen::MatrixXd &ARGB, double min, double max)
	{
		int rows = M.rows();
		int cols = M.cols();
		ARGB = Eigen::MatrixXd::Zero(rows, cols);

		for( int r=0; r<rows; r++)
			for (int c = 0; c < cols; c++)
			{
				if (M(r, c) <= -999999) ARGB(r, c) = 0;
				else ARGB(r, c) = ScalarToRainbow(M(r, c), min, max);
			}
	}
}