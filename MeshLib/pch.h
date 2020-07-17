// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#define CGAL_EIGEN3_ENABLED


#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/Polygon_mesh_processing/triangulate_faces.h>
#include <CGAL/poisson_surface_reconstruction.h>
#include <CGAL/Scale_space_surface_reconstruction_3.h>
#include <CGAL/Advancing_front_surface_reconstruction.h>
#include <CGAL/IO/read_xyz_points.h>
#include <CGAL/jet_estimate_normals.h>
#include <CGAL/pca_estimate_normals.h>
#include <CGAL/mst_orient_normals.h>
#include <CGAL/property_map.h>
#include <CGAL/Polygon_mesh_processing/remesh.h>
#include <CGAL/Polygon_mesh_processing/border.h>
#include <boost/function_output_iterator.hpp>
#include <CGAL/array.h>
#include <CGAL/disable_warnings.h>
#include <list>
#include <fstream>
#include <vector>
#include <algorithm>


// Types
typedef CGAL::cpp11::array<std::size_t, 3> Facet;

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef CGAL::Poisson_reconstruction_function<Kernel> Poisson_reconstruction_function;
typedef CGAL::Implicit_surface_3<Kernel, Poisson_reconstruction_function> Surface_3;
typedef Kernel::Sphere_3 Sphere_3;
typedef Kernel::Point_3 Point_3;
typedef Kernel::Vector_3 Vector_3;
typedef std::pair<Point_3, Vector_3> Pwn;
typedef CGAL::Point_with_normal_3<Kernel> Point_with_normal;
typedef std::vector<Point_with_normal> PointList;
typedef CGAL::Surface_mesh<Point_3> Mesh;
typedef CGAL::Polyhedron_3<Kernel> Polyhedron;
typedef CGAL::Scale_space_surface_reconstruction_3<Kernel>    Reconstruction;
typedef CGAL::Advancing_front_surface_reconstruction<> FS_Reconstruction;
typedef CGAL::Scale_space_reconstruction_3::Weighted_PCA_smoother< Kernel > Smoother;
typedef CGAL::Scale_space_reconstruction_3::Alpha_shape_mesher< Kernel >    Mesher;
typedef CGAL::Surface_mesh_default_triangulation_3 STr;
typedef CGAL::Surface_mesh_complex_2_in_triangulation_3<STr> C2t3;
typedef boost::graph_traits<Mesh>::halfedge_descriptor halfedge_descriptor;
typedef boost::graph_traits<Mesh>::edge_descriptor     edge_descriptor;
typedef Polyhedron::Vertex_handle   Vertex_handle;
namespace PMP = CGAL::Polygon_mesh_processing;

// Concurrency
#ifdef CGAL_LINKED_WITH_TBB
typedef CGAL::Parallel_tag Concurrency_tag;
#else
typedef CGAL::Sequential_tag Concurrency_tag;
#endif


#endif //PCH_H
