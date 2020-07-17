#pragma once



class SURFACE3D {
public:
	OBJECT3D Mesh;
	CLOUDPOINT ClPoints[1200000];
	int ClPointsNB = 0;
	bool DrawPoints = true;
	float PointsColor[3] = {1,1,1};
	
	void Clear()
	{
		ClPointsNB = 0;
		if (Mesh.PointsNB > 0)
		{
		
			POINT3D *P;
			P = Mesh.Points;
			Mesh.Points = NULL;
			delete[] P;
			Mesh.PointsNB = 0;
		}
		if (Mesh.FacesNB > 0)
		{
			FACE3D* F;
			F = Mesh.Faces;
			Mesh.Faces = NULL;
			delete[] F;
			Mesh.FacesNB = 0;
		}
	}
	void SetColors(float r, float g, float b)
	{
		for (int i = 0; i < Mesh.PointsNB; i++)
			Mesh.Points[i].SetColor(r, g, b);
	}

	void AddPoints(PCL_POINTCLOUD P)
	{
		float V[3];
		for (int i = 0; i < P.GetCloudWidth(); i++)
		{
			P.GetXYZ(i, V);
			ClPoints[ClPointsNB].SetPoint(V);
			ClPointsNB++;
		}
	}

	void Draw3D()
	{
		int index;
		float value[3], v;
		OpenGL::GL::Begin(OpenGL::BeginMode::Triangles);

		for (int i = 0; i < Mesh.FacesNB; i++)
		{
			Mesh.Faces[i].GetNormal(value);
			v = sqrt(value[0] * value[0] + value[1] * value[1] + value[2] * value[2]);
			for (int i = 0; i < 3; i++) value[i] /= v;
			OpenGL::GL::Normal3(value);

			for (int k = 0; k < 3; k++)
			{
				index = Mesh.Faces[i].GetPoint(k);
				Mesh.Points[index].GetColor(value);
				//value[0] = 0.707; value[1] = 0.898; value[2] = 0.113;
				OpenGL::GL::Color3(value);

				Mesh.Points[index].GetCoord(value);
				OpenGL::GL::Vertex3(value);
			}
		}
		OpenGL::GL::End();



		if (DrawPoints)
		{
			OpenGL::GL::PointSize(SETTINGS::Display::cloud_point_size);
			OpenGL::GL::Begin(OpenGL::BeginMode::Points);
			OpenGL::GL::Color3(Vector3(PointsColor[0], PointsColor[1], PointsColor[2]));

			for (int i = 0; i < ClPointsNB; i++)
			{
				ClPoints[i].GetPoint(value);

				OpenGL::GL::Vertex3(value[0], value[1], value[2]);
			}
			OpenGL::GL::End();
		}
	}

	void SwitchFaces(int f1, int f2)
	{
		int P[3]; float normal1[3], normal2[3];

		for (int k = 0; k < 3; k++) P[k] = Mesh.Faces[f1].GetPoint(k);
		Mesh.Faces[f1].GetNormal(normal1);

		Mesh.Faces[f1].SetPoints(Mesh.Faces[f2].GetPoint(0) , Mesh.Faces[f2].GetPoint(1), Mesh.Faces[f2].GetPoint(2));
		Mesh.Faces[f2].GetNormal(normal2);  Mesh.Faces[f1].SetNormal(normal2);

		Mesh.Faces[f2].SetPoints(P[0], P[1], P[2]); Mesh.Faces[f2].SetNormal(normal1);
	}

	void RemoveDuplicateFaces()
	{
		float P[3];
		for (int i = 0; i < Mesh.FacesNB; i++)
		{
			P[0] = -(Mesh.Points[Mesh.Faces[i].GetPoint(0)].GetX() + Mesh.Points[Mesh.Faces[i].GetPoint(1)].GetX() + Mesh.Points[Mesh.Faces[i].GetPoint(2)].GetX()) / 3;
			P[1] = -(Mesh.Points[Mesh.Faces[i].GetPoint(0)].GetY() + Mesh.Points[Mesh.Faces[i].GetPoint(1)].GetY() + Mesh.Points[Mesh.Faces[i].GetPoint(2)].GetY()) / 3;
			P[2] = -(Mesh.Points[Mesh.Faces[i].GetPoint(0)].GetZ() + Mesh.Points[Mesh.Faces[i].GetPoint(1)].GetZ() + Mesh.Points[Mesh.Faces[i].GetPoint(2)].GetZ()) / 3;

			if (P[0] * Mesh.Faces[i].GetNormalX() + P[1] * Mesh.Faces[i].GetNormalY() > 0)
			{
				SwitchFaces(i, Mesh.FacesNB-1);
				Mesh.FacesNB--;
			}
		}
	}


	void ImportPoints(char* FileName)
	{
		float point[3];
		float REGISTER[6] = { 0,0,0,0,0,0 };
		FILE* f;
		f = fopen(FileName, "rb");
		ClPointsNB = 0;
		fread(REGISTER, sizeof(float), 6, f);
		while (!feof(f))
		{
			for (int k = 0; k < 3; k++) point[k] = REGISTER[k];
			ClPoints[ClPointsNB].SetPoint(point);
			ClPointsNB++;
			fread(REGISTER, sizeof(float), 6, f);
		}

		fclose(f);
	}

	void ImportPointsFromSTL(char* FileName)
	{
		char stlHeader[80]; long N; short A;
		float point[3], normalvector[3];
		FILE* f;
		f = fopen(FileName, "rb");
		ClPointsNB = 0;
		fread(stlHeader, sizeof(char), 80, f);
		fread(&N, sizeof(long), 1, f);

		for (int i = 0; i < N; i++)
		{
			fread(normalvector, sizeof(float), 3, f);
			for (int k = 0; k < 3; k++)
			{
				fread(point, sizeof(float), 3, f);
				bool exist = false;
				float existing_point[3];
				for (int p = 0; p < ClPointsNB && !exist; p++)
				{
					ClPoints[p].GetPoint(existing_point);
					if (point[0] == existing_point[0] && point[1] == existing_point[1] && point[2] == existing_point[2])
						exist = true;
				}
				if (!exist)
				{
					ClPoints[ClPointsNB].SetPoint(point);
					ClPointsNB++;
				}
			}
			fread(&A, sizeof(short), 1, f);
		}

		fclose(f);
	}

	void ExtractPoints(char* FileName)
	{
		float point[3];
		float REGISTER[6] = { 0,0,0,0,0,0 };
		FILE* f;
		f = fopen(FileName, "wb");
		for (int i = 0; i < ClPointsNB; i++)
		{
			ClPoints[i].GetPoint(point);
			for (int k = 0; k < 3; k++) REGISTER[k] = point[k];

			fwrite(REGISTER, sizeof(float), 6, f);
		}
		fclose(f);
	}

	void ExportToSTL(char* filename)
	{
		Mesh.SaveToSTL(filename);
	}

	void CreateMesh()
	{
		if (SETTINGS::Mesh::mesh_algorithm == 1) // poisson algorithm  only
		{
			CGAL_PCA_ESTIMATE_NORMALS(ClPoints, ClPointsNB, SETTINGS::Mesh::normals_estimation_neighbors_nb);
			Mesh.FromPointClouds_Poisson(ClPoints, ClPointsNB, SETTINGS::Mesh::meshP_neighbors_nb, SETTINGS::Mesh::meshP_smoothangle, SETTINGS::Mesh::meshP_triangleSize, SETTINGS::Mesh::meshP_error, true, 1, 1);
		}
		else if(SETTINGS::Mesh::mesh_algorithm == 2)  // scale-space algorithm only
		{
			Mesh.FromPointClouds_ScaleSpace(ClPoints, ClPointsNB, SETTINGS::Mesh::meshSS_average_space, SETTINGS::Mesh::meshSS_neighbors_nb, SETTINGS::Mesh::meshSS_samples, true, 1, 1);
		}
		else   //combined algorithms
		{
			//poisson algorithm
			CGAL_PCA_ESTIMATE_NORMALS(ClPoints, ClPointsNB, SETTINGS::Mesh::normals_estimation_neighbors_nb);
			Mesh.FromPointClouds_Poisson(ClPoints, ClPointsNB, SETTINGS::Mesh::meshP_neighbors_nb, SETTINGS::Mesh::meshP_smoothangle, SETTINGS::Mesh::meshP_triangleSize, SETTINGS::Mesh::meshP_error, true, 1, 1);


			//refill points from mesh
			float V[3];
			CLOUDPOINT* CLPNT = new CLOUDPOINT[Mesh.PointsNB + 1]; int CLNB = Mesh.PointsNB;
			for (int i = 0; i < Mesh.PointsNB; i++)
			{
				Mesh.Points[i].GetCoord(V);
				CLPNT[i].SetPoint(V);
			}

			//scale space algorithm
			Mesh.FromPointClouds_ScaleSpace(CLPNT, CLNB, SETTINGS::Mesh::meshSS_average_space, SETTINGS::Mesh::meshSS_neighbors_nb, SETTINGS::Mesh::meshSS_samples, true, 1, 1);

			delete[] CLPNT;
		}
		
	}
};

SURFACE3D Surface3D;