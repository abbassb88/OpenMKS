#include "myKinect2 Sensor.h"


void ExportCalibration(char *filename)
{
	FILE* f;
	fopen_s(&f, filename, "wb");
	fwrite(&Kinect2NB, sizeof(int), 1, f);
	for (int i = 0; i < Kinect2NB; i++)
	{
		fwrite(myKinect2App[i].serialnumber, sizeof(char), 30, f);
		for (int j = 0; j < 9; j++) fwrite(&(myKinect2App[i].Rotation(j)), sizeof(float), 1, f);
		for (int j = 0; j < 3; j++) fwrite(&(myKinect2App[i].Translation(j)), sizeof(float), 1, f);
	}

	fclose(f);
}

int ImportCalibration(char* filename)
{
	int N = 0;
	float M[9], V[3]; 

	char serialnumber[50] = "";
	FILE *f, *g;
	fopen_s(&f, filename, "rb");
	fopen_s(&g, "00-transformation.txt", "wb");
	fread(&N, sizeof(int), 1, f);
	for (int i = 0; i < N && i < Kinect2NB; i++)
	{
		fread(serialnumber, sizeof(char), 30, f);

		for (int j = 0; j < 9; j++) fread(&(myKinect2App[i].Rotation(j)), sizeof(float), 1, f);
		for (int j = 0; j < 3; j++) fread(&(myKinect2App[i].Translation(j)), sizeof(float), 1, f);

		fprintf(g, "**************\n\r");
		for (int j = 0; j < 9; j++) fprintf(g, "%f   ", myKinect2App[i].Rotation(j)); fprintf(g, "\n\r");
		for (int j = 0; j < 3; j++) fprintf(g, "%f   ", myKinect2App[i].Translation(j)); fprintf(g, "\n\r\n\r");


		/*
		for (int j = 0; j < 9; j++) fread(&M[j], sizeof(float), 1, f);
		for (int j = 0; j < 3; j++)	fread(&V[j], sizeof(float), 1, f);
		
		for (int k = 0; k < Kinect2NB; k++) if(strcmpi(myKinect2App[k].serialnumber, serialnumber)==0)
		{
			for (int j = 0; j < 9; j++) myKinect2App[k].Rotation(j) = M[j];
			for (int j = 0; j < 3; j++) myKinect2App[k].Translation(j) = V[j];
		}
		*/

	}
	fclose(f);
	fclose(g);
	return N;
}




void LOAD_KINECTS_ONLINE()
{
	float M_PI = acos(-1);
	float Pos[3];
	int nb;
	string serial;
	libfreenect2::Freenect2Device* dev;
	libfreenect2::PacketPipeline* pipeline[2];

	libfreenect2::setGlobalLogger(NULL);

	nb = freenect2.enumerateDevices();
	if (nb > 0)
	{
		myKinect2App = new Kinect2APP[nb];
		Kinect2NB = nb;
		for (int i = 0; i < Kinect2NB; i++)
		{
			serial = freenect2.getDeviceSerialNumber(i);
			pipeline[i] = new libfreenect2::CpuPacketPipeline();
			myKinect2App[i].init(freenect2.openDevice(serial, pipeline[i]));
			myKinect2App[i].SetRefPointsSize(Kinect2NB);
			myKinect2App[i].opened = true;

			if (serial == "295502535247")  //yellow
			{
				myKinect2App[i].SetGlobalColor(1, 1, 0);
			}
			else if (serial == "016568250647")  //green
			{
				myKinect2App[i].SetGlobalColor(0, 1, 0);
			}
			else if (serial == "014903450647")  //red
			{
				myKinect2App[i].SetGlobalColor(1, 0, 0);
			}
			else if (serial == "212043235047") //blue
			{
				myKinect2App[i].SetGlobalColor(0, 0, 1);
			}
			myKinect2App[i].depthMin = 0.5;
			myKinect2App[i].depthMax = 3;

			myKinect2App[i].Stop();
			myKinect2App[i].Clear();

			myKinect2App[i].RefIndex = 0;
		}
	}
}

void SHUTDOWN_KINECTS_2()
{
	if (Kinect2NB > 0)
	{
		for (int i = 0; i < Kinect2NB; i++)
			if (myKinect2App[i].opened)
				myKinect2App[i].ShutDown();
		delete[] myKinect2App;
	}
	Kinect2NB = 0;
}