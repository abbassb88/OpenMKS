#include "pch.h"
#include "MeshLib.h"



struct halfedge2edge
{
	halfedge2edge(const Mesh& m, std::vector<edge_descriptor>& edges)
		: m_mesh(m), m_edges(edges)
	{}
	void operator()(const halfedge_descriptor& h) const
	{
		m_edges.push_back(edge(h, m_mesh));
	}
	const Mesh& m_mesh;
	std::vector<edge_descriptor>& m_edges;
};

struct Construct {
	Mesh& mesh;
	template < typename PointIterator>
	Construct(Mesh& mesh, PointIterator b, PointIterator e)
		: mesh(mesh)
	{
		for (; b != e; ++b) {
			boost::graph_traits<Mesh>::vertex_descriptor v;
			v = add_vertex(mesh);
			mesh.point(v) = *b;
		}
	}
	Construct& operator=(const Facet f)
	{
		typedef boost::graph_traits<Mesh>::vertex_descriptor vertex_descriptor;
		typedef boost::graph_traits<Mesh>::vertices_size_type size_type;
		mesh.add_face(vertex_descriptor(static_cast<size_type>(f[0])),
			vertex_descriptor(static_cast<size_type>(f[1])),
			vertex_descriptor(static_cast<size_type>(f[2])));
		return *this;
	}
	Construct&
		operator*() { return *this; }
	Construct&
		operator++() { return *this; }
	Construct
		operator++(int) { return *this; }
};


void remesh_function(Mesh* m_mesh, float target_edge_length, int nb_iter)
{
	//split borders
	std::vector<edge_descriptor> border;
	PMP::border_halfedges(faces(*m_mesh),
		*m_mesh,
		boost::make_function_output_iterator(halfedge2edge(*m_mesh, border)));
	PMP::split_long_edges(border, target_edge_length, *m_mesh);
	//remeshing
	PMP::isotropic_remeshing(
		faces(*m_mesh),
		target_edge_length,
		*m_mesh,
		PMP::parameters::number_of_iterations(nb_iter)
		.protect_constraints(true)//i.e. protect border, here
	);
}



CLOUDPOINT::CLOUDPOINT()
{
	point[0] = point[1] = point[2] = 0;
	normal[0] = normal[1] = 0; normal[2] = 1;
}

void CLOUDPOINT::SetPoint(float p[3])
{
	for (int i = 0; i < 3; i++) point[i] = p[i];
}

void CLOUDPOINT::SetNormal(float n[3])
{
	for (int i = 0; i < 3; i++) normal[i] = n[i];
}

void CLOUDPOINT::Set(float p[3], float n[3])
{
	for (int i = 0; i < 3; i++) point[i] = p[i];
	for (int i = 0; i < 3; i++) normal[i] = n[i];
}

void CLOUDPOINT::GetPoint(float p[3])
{
	for (int i = 0; i < 3; i++) p[i] = point[i];
}

void CLOUDPOINT::GetNormal(float n[3])
{
	for (int i = 0; i < 3; i++) n[i] = normal[i];
}


TRIANGLE::TRIANGLE()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) points[i][j] = 0;
	normal[0] = normal[1] = 0; normal[2] = 1;
}

TRIANGLE::~TRIANGLE()
{

}

void TRIANGLE::SetPoint(int index, float p[3])
{
	for (int i = 0; i < 3; i++) points[index][i] = p[i];
}

void TRIANGLE::SetNormal(float n[3])
{
	for (int i = 0; i < 3; i++) normal[i] = n[i];
}

void TRIANGLE::GetPoint(int index, float p[3])
{
	for (int i = 0; i < 3; i++) p[i] = points[index][i];
}

void TRIANGLE::GetNormal(float n[3])
{
	for (int i = 0; i < 3; i++) n[i] = normal[i];
}


POINT3D::POINT3D()
{
	X[0] = X[1] = X[2] = 0;
	color[0] = color[1] = color[2] = 1;
}

POINT3D::~POINT3D()
{

}

void POINT3D::SetCoord(float x[3])
{
	for (int i = 0; i < 3; i++) X[i] = x[i];
}

void POINT3D::SetCoord(float x, float y, float z)
{
	X[0] = x; X[1] = y; X[2] = z;
}

void POINT3D::SetColor(float c[3])
{
	for (int i = 0; i < 3; i++) color[i] = c[i];
}

void POINT3D::SetColor(float r, float g, float b)
{
	color[0] = r; color[1] = g; color[2] = b;
}

void POINT3D::GetCoord(float x[3])
{
	for (int i = 0; i < 3; i++) x[i] = X[i];
}

void POINT3D::GetColor(float c[3])
{
	for (int i = 0; i < 3; i++) c[i] = color[i];
}

float POINT3D::GetX() { return X[0]; }

float POINT3D::GetY() { return X[1]; }

float POINT3D::GetZ() { return X[2]; }

bool POINT3D::operator==(POINT3D P)
{
	return (X[0] == P.GetX() && X[1] == P.GetY() && X[2] == P.GetZ());
}




FACE3D::FACE3D()
{
	for (int i = 0; i < 3; i++)
	{
		points[i] = 0;
		normal[i] = 0;
	}
	normal[2] = 1;
}

FACE3D::~FACE3D() {}

void FACE3D::SetPoint(int index, int point)
{
	points[index] = point;
}

void FACE3D::SetPoints(int p1, int p2, int p3)
{
	points[0] = p1; points[1] = p2; points[2] = p3;
}

void FACE3D::SetNormal(float n[3])
{
	for (int i = 0; i < 3; i++) normal[i] = n[i];
}

void FACE3D::SetNormal(float x, float y, float z)
{
	normal[0] = x; normal[1] = y; normal[2] = z;
}

int FACE3D::GetPoint(int index) { return points[index]; }

void FACE3D::GetNormal(float n[3])
{
	for (int i = 0; i < 3; i++) n[i] = normal[i];
}

float FACE3D::GetNormalX()
{
	return normal[0];
}

float FACE3D::GetNormalY()
{
	return normal[1];
}

float FACE3D::GetNormalZ()
{
	return normal[2];
}





OBJECT3D::OBJECT3D()
{
	Points = NULL;
	Faces = NULL;
	PointsNB = FacesNB = 0;
}

OBJECT3D::~OBJECT3D()
{
	if (PointsNB > 0) delete[] Points;
	if (FacesNB > 0) delete[] Faces;
}

void OBJECT3D::SaveToSTL(char* filename)
{
	char NAME[80] = "mesh";
	long NB = FacesNB;
	short A = 0;
	float value[3];

	FILE* f;
	fopen_s(&f, filename, "wb");

	fwrite(NAME, sizeof(char), 80, f);
	fwrite(&NB, sizeof(long), 1, f);

	for (long i = 0; i < NB; i++)
	{
		Faces[i].GetNormal(value);
		fwrite(value, sizeof(float), 3, f);
		for (int k = 0; k < 3; k++)
		{
			Points[Faces[i].GetPoint(k)].GetCoord(value);
			fwrite(value, sizeof(float), 3, f);
		}
		fwrite(&A, sizeof(short), 1, f);
	}

	fclose(f);
}

void OBJECT3D::SaveToTXT(char* filename)
{
	float value[3];
	FILE* f;
	fopen_s(&f, filename, "wb");
	fprintf(f, "%d     %d\n\n\n", PointsNB, FacesNB);
	for (int i = 0; i < PointsNB; i++)
		fprintf(f, "%f  %f  %f\n", Points[i].GetX(), Points[i].GetY(), Points[i].GetZ());

	for (int i = 0; i < FacesNB; i++)
	{
		fprintf(f, "%d  %d  %d", Faces[i].GetPoint(0), Faces[i].GetPoint(1), Faces[i].GetPoint(2));
		Faces[i].GetNormal(value);
		fprintf(f, "  |  %f  %f  %f\n", value[0], value[1], value[2]);
	}

	fclose(f);
}

void OBJECT3D::FromTriangles(TRIANGLE* triangles, int trinb)
{
	float value[3];
	float normal[3];

	if (PointsNB > 0) { POINT3D* P; P = Points; Points = NULL; delete[] P; }
	if (FacesNB > 0) { FACE3D* F; F = Faces; Faces = NULL; delete[] F; }

	PointsNB = 0;
	FacesNB = trinb;
	Faces = new FACE3D[FacesNB];
	Points = new POINT3D[FacesNB * 3];

	for (int i = 0; i < FacesNB; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			triangles[i].GetPoint(j, value);
			bool b = false;
			for (int k = 0; k < PointsNB && !b; k++)
				if (Points[k].GetX() == value[0] && Points[k].GetY() == value[1] && Points[k].GetZ() == value[2])
				{
					Faces[i].SetPoint(j, k); b = true;
				}


			if (!b)
			{
				Points[PointsNB].SetCoord(value);
				Faces[i].SetPoint(j, PointsNB);
				PointsNB++;
			}
		}
		triangles[i].GetNormal(value);
		Faces[i].SetNormal(value);

	}
}


bool OBJECT3D::FromPointClouds_Poisson(CLOUDPOINT* pc, int pointsnb, int neighborsnb, double avespacef)
{
	bool bool_result = false;
	Polyhedron output_mesh;
	float V[3], N[3];
	Pwn P; std::vector<Pwn> points;
	Vector_3 normal;
	int trinb;

	//fill points
	for (int i = 0; i < pointsnb; i++)
	{
		pc[i].GetPoint(V);
		pc[i].GetNormal(N);
		P = Pwn(Point_3(V[0], V[1], V[2]), Vector_3(N[0], N[1], N[2]));
		points.insert(points.end(), P);
	}

	//define average spacing
	double average_spacing = CGAL::compute_average_spacing<CGAL::Sequential_tag>
		(points, neighborsnb, CGAL::parameters::point_map(CGAL::First_of_pair_property_map<Pwn>()));

	//create mesh and save it in file
	if (CGAL::poisson_surface_reconstruction_delaunay
	(points.begin(), points.end(),
		CGAL::First_of_pair_property_map<Pwn>(),
		CGAL::Second_of_pair_property_map<Pwn>(),
		output_mesh, avespacef* average_spacing))
	{
		bool_result = true;

		trinb = output_mesh.size_of_facets();

		TRIANGLE* triangles = new TRIANGLE[trinb];


		Point_3 P1, P2, P3;
		auto fa = output_mesh.facets_begin();
		for (int i = 0; i < trinb; i++)
		{
			auto he = fa->halfedge();
			P1 = he->vertex()->point();
			V[0] = P1.x(); V[1] = P1.y(); V[2] = P1.z();
			triangles[i].SetPoint(0, V);
			he = he->next();

			P2 = he->vertex()->point();
			V[0] = P2.x(); V[1] = P2.y(); V[2] = P2.z();
			triangles[i].SetPoint(1, V);
			he = he->next();

			P3 = he->vertex()->point();
			V[0] = P3.x(); V[1] = P3.y(); V[2] = P3.z();
			triangles[i].SetPoint(2, V);

			normal = CGAL::unit_normal(P1, P2, P3);
			N[0] = normal.x(); N[1] = normal.y(); N[2] = normal.z();
			triangles[i].SetNormal(N);


			std::advance(fa, 1);
		}

		FromTriangles(triangles, trinb);

		delete[] triangles;
	}


	return bool_result;

}


bool OBJECT3D::FromPointClouds_Poisson(CLOUDPOINT* pc, int pointsnb, int neighborsnb, float sm_angle, float sm_radius, float sm_distance, bool remeshing, float target_edge_length, int nb_iter)
{
	bool bool_result = false;
	Polyhedron output_mesh;
	Mesh m_mesh;

	float V[3], N[3];
	Point_with_normal P; PointList points;
	Vector_3 normal;
	int trinb;

	//fill points
	for (int i = 0; i < pointsnb; i++)
	{
		pc[i].GetPoint(V);
		pc[i].GetNormal(N);
		P = Point_with_normal(Point_3(V[0], V[1], V[2]), Vector_3(N[0], N[1], N[2]));
		points.insert(points.end(), P);
	}

	//Poisson Reconstruction
	Poisson_reconstruction_function function(points.begin(), points.end(),
		CGAL::make_normal_of_point_with_normal_map(PointList::value_type()));

	// Computes the Poisson indicator function f() at each vertex of the triangulation.
	if (!function.compute_implicit_function()) bool_result = false;

	else
	{
		//define average spacing
		float average_spacing = CGAL::compute_average_spacing<CGAL::Sequential_tag>(points, neighborsnb);

		// Gets one point inside the implicit surface and computes implicit function bounding sphere radius.
		Point_3 inner_point = function.get_inner_point();
		Sphere_3 bsphere = function.bounding_sphere();
		float radius = std::sqrt(bsphere.squared_radius());



		// Defines the implicit surface: requires defining a conservative bounding sphere centered at inner point.
		float sm_sphere_radius = 5.0 * radius;
		float sm_dichotomy_error = sm_distance * average_spacing / 1000.0; // Dichotomy error must be << sm_distance
		Surface_3 surface(function, Sphere_3(inner_point, sm_sphere_radius * sm_sphere_radius), sm_dichotomy_error / sm_sphere_radius);


		// Defines surface mesh generation criteria
		CGAL::Surface_mesh_default_criteria_3<STr> criteria(sm_angle,  // Min triangle angle (degrees)
			sm_radius * average_spacing,  // Max triangle size
			sm_distance * average_spacing); // Approximation error

		// Generates surface mesh with manifold option
		STr tr; // 3D Delaunay triangulation for surface mesh generation
		C2t3 c2t3(tr); // 2D complex in 3D Delaunay triangulation
		CGAL::make_surface_mesh(c2t3,                                 // reconstructed mesh
			surface,                              // implicit surface
			criteria,                             // meshing criteria
			CGAL::Manifold_with_boundary_tag());  // require manifold mesh

		if (tr.number_of_vertices() == 0) bool_result = false;
		else
		{
			CGAL::facets_in_complex_2_to_triangle_mesh(c2t3, output_mesh);

			//refine
			std::vector<Polyhedron::Facet_handle>  new_facets;
			std::vector<Vertex_handle> new_vertices;
			CGAL::Polygon_mesh_processing::refine(output_mesh,
				faces(output_mesh),
				std::back_inserter(new_facets),
				std::back_inserter(new_vertices),
				CGAL::Polygon_mesh_processing::parameters::density_control_factor(2.));



			//remeshing
			if (remeshing)
			{
				//covert poly to mesh
				CGAL::copy_face_graph(output_mesh, m_mesh);

				//triangulate mesh
				CGAL::Polygon_mesh_processing::triangulate_faces(m_mesh);

				//remeshing
				//remesh_function(&m_mesh, target_edge_length, nb_iter);

				//covert mesh to poly
				output_mesh.clear();
				CGAL::copy_face_graph(m_mesh, output_mesh);

			}




			trinb = output_mesh.size_of_facets();

			TRIANGLE* triangles = new TRIANGLE[trinb];


			Point_3 P1, P2, P3;
			auto fa = output_mesh.facets_begin();
			for (int i = 0; i < trinb; i++)
			{
				auto he = fa->halfedge();
				P1 = he->vertex()->point();
				V[0] = P1.x(); V[1] = P1.y(); V[2] = P1.z();
				triangles[i].SetPoint(0, V);
				he = he->next();

				P2 = he->vertex()->point();
				V[0] = P2.x(); V[1] = P2.y(); V[2] = P2.z();
				triangles[i].SetPoint(1, V);
				he = he->next();

				P3 = he->vertex()->point();
				V[0] = P3.x(); V[1] = P3.y(); V[2] = P3.z();
				triangles[i].SetPoint(2, V);

				normal = CGAL::unit_normal(P1, P2, P3);
				N[0] = normal.x(); N[1] = normal.y(); N[2] = normal.z();
				triangles[i].SetNormal(N);


				std::advance(fa, 1);
			}

			FromTriangles(triangles, trinb);

			delete[] triangles;



			bool_result = true;
		}
	}
	return bool_result;

}

bool OBJECT3D::FromPointClouds_ScaleSpace(CLOUDPOINT* pc, int pointsnb, int scale, int neighborsnb, int samples, bool remeshing, float target_edge_length, int nb_iter)
{
	bool bool_result = false;
	float V[3], N[3];
	Point_with_normal P;  std::vector<Point_with_normal> points;
	Vector_3 normal;
	Point_3 P1, P2, P3;
	int index;

	//fill points
	points.clear();
	for (int i = 0; i < pointsnb; i++)
	{
		pc[i].GetPoint(V);
		pc[i].GetNormal(N);
		normal = Vector_3(N[0], N[1], N[2]);
		P = Point_with_normal(V[0], V[1], V[2], normal);
		points.insert(points.end(), P);
	}

	//reconstruct surface
	Reconstruction reconstruct(points.begin(), points.end());
	Smoother smoother(neighborsnb, samples);
	reconstruct.increase_scale(scale, smoother);
	Mesher mesher(smoother.squared_radius());
	reconstruct.reconstruct_surface(mesher);

	//fill the data in the OBJECT3D
	if (PointsNB > 0) { POINT3D* P; P = Points; Points = NULL; delete[] P; }
	if (FacesNB > 0) { FACE3D* F; F = Faces; Faces = NULL; delete[] F; }

	PointsNB = reconstruct.number_of_points();
	FacesNB = reconstruct.number_of_facets();
	Faces = new FACE3D[FacesNB];
	Points = new POINT3D[PointsNB];

	auto po = reconstruct.points_begin();
	auto fa = reconstruct.facets_begin();
	for (int i = 0; i < PointsNB; i++)
	{
		Points[i].SetCoord(po->x(), po->y(), po->z());
		std::advance(po, 1);
	}

	for (int i = 0; i < FacesNB; i++)
	{
		for (int k = 0; k < 3; k++) Faces[i].SetPoint(k, fa->at(k));
		index = Faces[i].GetPoint(0);
		P1 = Point_3(Points[index].GetX(), Points[index].GetY(), Points[index].GetZ());
		index = Faces[i].GetPoint(1);
		P2 = Point_3(Points[index].GetX(), Points[index].GetY(), Points[index].GetZ());
		index = Faces[i].GetPoint(2);
		P3 = Point_3(Points[index].GetX(), Points[index].GetY(), Points[index].GetZ());

		normal = CGAL::unit_normal(P1, P2, P3);
		Faces[i].SetNormal(normal.x(), normal.y(), normal.z());

		std::advance(fa, 1);
	}
	return bool_result;

}

bool OBJECT3D::FromPointClouds_AdvancingFront(CLOUDPOINT* pc, int pointsnb)
{
	Point_3 P;
	float V[3], N[3];
	Vector_3 normal;
	std::vector<Point_3> points;
	std::vector<Facet> facets;
	Mesh m; Polyhedron output_mesh;

	//fill points
	points.clear();
	for (int i = 0; i < pointsnb; i++)
	{
		pc[i].GetPoint(V);
		pc[i].GetNormal(N);
		normal = Vector_3(N[0], N[1], N[2]);
		P = Point_with_normal(V[0], V[1], V[2], normal);
		points.insert(points.end(), P);
	}


	//reconstruct surface
	Construct construct(m, points.begin(), points.end());

	CGAL::advancing_front_surface_reconstruction(points.begin(),
		points.end(),
		construct);

	CGAL::copy_face_graph(m, output_mesh);

	//fill points
	long trinb = output_mesh.size_of_facets();

	TRIANGLE* triangles = new TRIANGLE[trinb];


	Point_3 P1, P2, P3;
	auto fa = output_mesh.facets_begin();
	for (int i = 0; i < trinb; i++)
	{
		auto he = fa->halfedge();
		P1 = he->vertex()->point();
		V[0] = P1.x(); V[1] = P1.y(); V[2] = P1.z();
		triangles[i].SetPoint(0, V);
		he = he->next();

		P2 = he->vertex()->point();
		V[0] = P2.x(); V[1] = P2.y(); V[2] = P2.z();
		triangles[i].SetPoint(1, V);
		he = he->next();

		P3 = he->vertex()->point();
		V[0] = P3.x(); V[1] = P3.y(); V[2] = P3.z();
		triangles[i].SetPoint(2, V);

		normal = CGAL::unit_normal(P1, P2, P3);
		N[0] = normal.x(); N[1] = normal.y(); N[2] = normal.z();
		triangles[i].SetNormal(N);


		std::advance(fa, 1);
	}

	FromTriangles(triangles, trinb);

	delete[] triangles;


	return true;
}




int SQUARE(int x)
{
	return x * x;
}

void CGAL_JET_ESTIMATE_NORMALS(CLOUDPOINT* pc, int pointsnb, int neigborsnb)
{
	float V[3];
	Pwn P; std::list<Pwn> points;
	Vector_3 normal;

	//fill points
	for (int i = 0; i < pointsnb; i++)
	{
		pc[i].GetPoint(V);
		P = Pwn(Point_3(V[0], V[1], V[2]), Vector_3(1, 1, 1));
		points.insert(points.end(), P);
	}

	//estimate normals
	CGAL::jet_estimate_normals<Concurrency_tag>(points, neigborsnb,
		CGAL::parameters::point_map(CGAL::First_of_pair_property_map<Pwn>()).
		normal_map(CGAL::Second_of_pair_property_map<Pwn>()));

	//must orient normals
	std::list<Pwn>::iterator unoriented_points_begin =
		CGAL::mst_orient_normals(points, neigborsnb,
			CGAL::parameters::point_map(CGAL::First_of_pair_property_map<Pwn>()).
			normal_map(CGAL::Second_of_pair_property_map<Pwn>()));


	//fill the normals
	auto point = points.begin();
	for (int i = 0; i < pointsnb; i++)
	{
		normal = point->second;
		V[0] = normal.x();
		V[1] = normal.y();
		V[2] = normal.z();
		pc[i].SetNormal(V);
		std::advance(point, 1);
	}
}

void CGAL_PCA_ESTIMATE_NORMALS(CLOUDPOINT* pc, int pointsnb, int neigborsnb)
{
	float V[3];
	Pwn P; std::list<Pwn> points;
	Vector_3 normal;

	//fill points
	for (int i = 0; i < pointsnb; i++)
	{
		pc[i].GetPoint(V);
		P = Pwn(Point_3(V[0], V[1], V[2]), Vector_3(1, 1, 1));
		points.insert(points.end(), P);
	}

	//estimate normals
	CGAL::pca_estimate_normals<Concurrency_tag>(points, neigborsnb,
		CGAL::parameters::point_map(CGAL::First_of_pair_property_map<Pwn>()).
		normal_map(CGAL::Second_of_pair_property_map<Pwn>()));


	//must orient normals
	std::list<Pwn>::iterator unoriented_points_begin =
		CGAL::mst_orient_normals(points, neigborsnb,
			CGAL::parameters::point_map(CGAL::First_of_pair_property_map<Pwn>()).
			normal_map(CGAL::Second_of_pair_property_map<Pwn>()));


	auto point = points.begin();
	//fill the normals
	for (int i = 0; i < pointsnb; i++)
	{
		normal = point->second;
		V[0] = normal.x();
		V[1] = normal.y();
		V[2] = normal.z();
		pc[i].SetNormal(V);
		std::advance(point, 1);
	}
}