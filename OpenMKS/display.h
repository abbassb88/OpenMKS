#include "Settings.h"

double CamPosition[3] = { 1,1,1 };
double TargetPosition[3] = { 0,0,0 };

bool MouseClicked[3] = { false };   //left   right   middle
int MouseX, MouseY;


void GL_LIGHTING(bool b)
{


	float ltposition[4] = { CamPosition[0], CamPosition[1], CamPosition[2], 1.0f };
	OpenGL::GL::Light(OpenGL::LightName::Light0, OpenGL::LightParameter::Position, ltposition);
	float f[4] = { 0.1f, 0.1f, 0.1f, 1.0f };
	OpenGL::GL::Light(OpenGL::LightName::Light0, OpenGL::LightParameter::Ambient, f);
	f[0] = f[1] = f[2] = 0.7;
	OpenGL::GL::Light(OpenGL::LightName::Light0, OpenGL::LightParameter::Diffuse, f);
	if (b)
	{
		OpenGL::GL::Enable(OpenTK::Graphics::OpenGL::EnableCap::ColorMaterial);
		OpenGL::GL::Enable(OpenTK::Graphics::OpenGL::EnableCap::Lighting);
		OpenGL::GL::Enable(OpenTK::Graphics::OpenGL::EnableCap::Light0);

		f[0] = f[1] = f[2] = 0.8f;
		OpenGL::GL::Material(OpenTK::Graphics::OpenGL::MaterialFace::Front, OpenTK::Graphics::OpenGL::MaterialParameter::Specular, f);
		f[0] = f[1] = f[2] = f[3] = 50.0f;
		OpenGL::GL::Material(OpenTK::Graphics::OpenGL::MaterialFace::Front, OpenTK::Graphics::OpenGL::MaterialParameter::Shininess, f);
	}
	else
	{
		OpenGL::GL::Disable(OpenTK::Graphics::OpenGL::EnableCap::ColorMaterial);
		OpenGL::GL::Disable(OpenTK::Graphics::OpenGL::EnableCap::Lighting);
		OpenGL::GL::Disable(OpenTK::Graphics::OpenGL::EnableCap::Light0);
	}
}

void DRAW_GRID()
{
	OpenGL::GL::LineWidth(0.05f);
	OpenGL::GL::Begin(OpenGL::BeginMode::Lines);
	OpenGL::GL::Color3(Vector3(0.45, 0.45, 0.45));

	float N = 50;

	for (float i = 0; i < N; i+=0.1)
	{
		OpenGL::GL::Vertex3(Vector3(-N,i,0));
		OpenGL::GL::Vertex3(Vector3(N, i, 0));

		OpenGL::GL::Vertex3(Vector3(-N, -i, 0));
		OpenGL::GL::Vertex3(Vector3(N, -i, 0));

		OpenGL::GL::Vertex3(Vector3(i, -N, 0));
		OpenGL::GL::Vertex3(Vector3(i, N, 0));

		OpenGL::GL::Vertex3(Vector3(-i, -N, 0));
		OpenGL::GL::Vertex3(Vector3(-i, N, 0));
	}
	OpenGL::GL::End();


	// the axes
	
	OpenGL::GL::LineWidth(5.0f);
	OpenGL::GL::Begin(OpenGL::BeginMode::Lines);

	OpenGL::GL::Enable(OpenGL::EnableCap::LineSmooth);
	
	OpenGL::GL::Color3(Vector3(1, 0, 0));  //choose red color for x vector
	OpenGL::GL::Vertex3(Vector3(0, 0, 0));
	OpenGL::GL::Vertex3(Vector3(0.1, 0, 0));

	OpenGL::GL::Color3(Vector3(0, 1, 0));  //choose green color for y vector
	OpenGL::GL::Vertex3(Vector3(0, 0, 0));
	OpenGL::GL::Vertex3(Vector3(0, 0.1, 0));

	OpenGL::GL::Color3(Vector3(0, 0, 1));  //choose green color for y vector
	OpenGL::GL::Vertex3(Vector3(0, 0, 0));
	OpenGL::GL::Vertex3(Vector3(0, 0, 0.1));

	OpenGL::GL::LineWidth(1.0f);

	OpenGL::GL::End();
	
}


void DISPLAY_3D(GLControl ^g, bool light = true)
{
	int w = g->Width;
	int h = g->Height;
	float D = (float)(w) / (float)(h);


	if (light)	OpenGL::GL::ClearColor( Color4(SETTINGS::Display::backcolor[0], SETTINGS::Display::backcolor[1], SETTINGS::Display::backcolor[2], 1));
	else	OpenGL::GL::ClearColor(Color4::Black);
	OpenTK::Graphics::OpenGL::GL::Clear(OpenGL::ClearBufferMask::ColorBufferBit);
	OpenGL::GL::MatrixMode(OpenGL::MatrixMode::Projection);
	OpenGL::GL::LoadIdentity();
	OpenGL::GL::LoadMatrix(Matrix4::CreatePerspectiveFieldOfView(1, D, 0.1, 1000));
	OpenGL::GL::MatrixMode(OpenGL::MatrixMode::Modelview);
	OpenGL::GL::LoadIdentity();
	OpenGL::GL::LoadMatrix(Matrix4::LookAt(CamPosition[0], CamPosition[1], CamPosition[2], TargetPosition[0], TargetPosition[1], TargetPosition[2], 0, 0, 1));
	OpenGL::GL::Viewport(0, 0, w, h);

	OpenGL::GL::Enable(OpenTK::Graphics::OpenGL::EnableCap(0x0B44));
	OpenGL::GL::Clear(OpenTK::Graphics::OpenGL::ClearBufferMask(0x00000100));
	OpenGL::GL::Enable(OpenTK::Graphics::OpenGL::EnableCap::DepthTest);


	//show grid
	if(SETTINGS::Display::show_grid) DRAW_GRID();


	//// draw objects here


	GL_LIGHTING(light);
	Surface3D.Draw3D();

	GL_LIGHTING(false);
	for (int i = 0; i < Kinect2NB; i++) myKinect2App[i].Draw3D();


	if (light) g->SwapBuffers();		
}

void DISPLAY_ForSelection(GLControl^ g, int kinect2index)
{
	int w = g->Width;
	int h = g->Height;
	float D = (float)(w) / (float)(h);


	OpenGL::GL::ClearColor(Color4::Black);
	OpenTK::Graphics::OpenGL::GL::Clear(OpenGL::ClearBufferMask::ColorBufferBit);
	OpenGL::GL::MatrixMode(OpenGL::MatrixMode::Projection);
	OpenGL::GL::LoadIdentity();
	OpenGL::GL::LoadMatrix(Matrix4::CreatePerspectiveFieldOfView(1, D, 0.1, 10000));
	OpenGL::GL::MatrixMode(OpenGL::MatrixMode::Modelview);
	OpenGL::GL::LoadIdentity();
	OpenGL::GL::LoadMatrix(Matrix4::LookAt(CamPosition[0], CamPosition[1], CamPosition[2], TargetPosition[0], TargetPosition[1], TargetPosition[2], 0, 0, 1));
	OpenGL::GL::Viewport(0, 0, w, h);

	OpenGL::GL::Enable(OpenTK::Graphics::OpenGL::EnableCap(0x0B44));
	OpenGL::GL::Clear(OpenTK::Graphics::OpenGL::ClearBufferMask(0x00000100));
	OpenGL::GL::Enable(OpenTK::Graphics::OpenGL::EnableCap::DepthTest);


	myKinect2App[kinect2index].DrawPointsForSelection();
}


void ZoomCam(double amount)
{
	double X = TargetPosition[0] - CamPosition[0];
	double Y = TargetPosition[1] - CamPosition[1];
	double Z = TargetPosition[2] - CamPosition[2];
	double L = sqrt(X*X + Y * Y + Z * Z);
	X = X / L; Y = Y / L; Z = Z / L;
	CamPosition[0] += X * amount;
	CamPosition[1] += Y * amount;
	CamPosition[2] += Z * amount;
}



void RotateCam(double phi, double theta)
{
	double X = TargetPosition[0] - CamPosition[0];
	double Y = TargetPosition[1] - CamPosition[1];
	double Z = TargetPosition[2] - CamPosition[2];
	double L = sqrt(X*X + Y * Y + Z * Z);
	
	X = X / L; Y = Y / L; Z = Z / L;

	double Lxy = sqrt(X*X + Y * Y);

	if (sqrt(X*X + Y * Y) != 0)
	{
		Z = Z * cos(phi) + sin(phi)*sqrt(1 - Z * Z);
		double ex = X * sqrt(1 - Z * Z) / Lxy;
		double ey = Y * sqrt(1 - Z * Z) / Lxy;

		X = ex * cos(theta) - ey * sin(theta);
		Y = ey * cos(theta) + ex * sin(theta);

		CamPosition[0] = TargetPosition[0] - X * L;
		CamPosition[1] = TargetPosition[1] - Y * L;
		CamPosition[2] = TargetPosition[2] - Z * L;
	}

}


void PanCam(double right, double up)
{
	
	double X = TargetPosition[0] - CamPosition[0];
	double Y = TargetPosition[1] - CamPosition[1];
	double L = sqrt(X*X + Y * Y);
	X = right * X / L;
	Y = - right *Y / L;
	
	CamPosition[0] += Y;	TargetPosition[0] += Y;
	CamPosition[1] += X;	TargetPosition[1] += X;
	CamPosition[2] += up;	TargetPosition[2] += up;
}