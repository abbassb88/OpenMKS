#pragma once

#ifdef CVLIB_EXPORTS
#define CVLIB_API __declspec(dllexport)
#else
#define CVLIB_API __declspec(dllimport)
#endif

#ifdef   CVLIB_EXPORTS 
/*Enabled as "export" while compiling the dll project*/
#define DLLEXPORT __declspec(dllexport)  
#else
/*Enabled as "import" in the Client side for using already created dll file*/
#define DLLEXPORT __declspec(dllimport)  
#endif

namespace CVLib
{
	class DLLEXPORT CalibrationSettings
	{

	public:
		int boardWidth, boardHeight;              // The size of the board -> Number of items by width and height
		bool flexiblesize;			 // to fix chessboard size or to automatically detect the size of the chessboard
		float squareSize;            // The size of a square in your defined unit (point, millimeter,etc).
		float aspectRatio;           // The aspect ratio

		bool calibZeroTangentDist;   // Assume zero tangential distortion
		bool calibFixPrincipalPoint; // Fix the principal point at the center
		bool flipVertical;           // Flip the captured images around the horizontal axis
		std::string outputFileName;       // The name of the file where to write
		bool useFisheye;             // use fisheye camera model for calibration
		bool fixK1;                  // fix K1 distortion coefficient
		bool fixK2;                  // fix K2 distortion coefficient
		bool fixK3;                  // fix K3 distortion coefficient
		bool fixK4;                  // fix K4 distortion coefficient
		bool fixK5;                  // fix K5 distortion coefficient

		bool goodInput;
		int flag;

		enum Pattern { NOT_EXISTING, CHESSBOARD, CIRCLES_GRID, ASYMMETRIC_CIRCLES_GRID };
		enum InputType { INVALID, CAMERA, VIDEO_FILE, IMAGE_LIST };

	public:
		CalibrationSettings();

		void write(std::string filename);

		bool read(std::string filename);

		void validate();

	};
	extern "C" CVLIB_API CalibrationSettings * createCalibrationSettings();

	struct DLLEXPORT RESULTS_DATA;
	extern "C" CVLIB_API RESULTS_DATA * createRESULTS_DATA();

	class DLLEXPORT CalibrationResults
	{
	public:
		RESULTS_DATA* CornerPoints;
		float squareSize;            // The size of a square in your defined unit (point, millimeter,etc).
		double fx, fy;   //focal distances
		double cx, cy;   //focal center
		double k1, k2, k3, p1, p2;  //distortion parameters
		char calibration_time[128]; //calibration start time
		double avg_reprojection_error; // calibration error

		int GridRowsNB, GridColsNB;

		CalibrationResults();
		~CalibrationResults();
		void ClearPoints();
		void write(std::string filename);
		int GetCornersNB(int frame = 0);
		void GetCornerPoint(int frame, int index, float& x, float& y);
		int GetFramesNB();
		bool IsChessBoardParallelToCamera(int frame, float tolerance_x, float tolerance_y);

		void operator =(CalibrationResults r);
	};
	extern "C" CVLIB_API CalibrationResults * createCalibrationResults();

	extern "C" CVLIB_API bool CalibrateCameraFromImage(unsigned int* IMAGE, int width, int height, CalibrationSettings s, CalibrationResults * r, bool showimage = false);

	extern "C" CVLIB_API bool DetectChessBoardFromImage(unsigned int* IMAGE, int width, int height, CalibrationSettings s, CalibrationResults * r, bool showimage = false);

	extern "C" CVLIB_API bool DetectFocalCenterGridPosition(CalibrationResults * cr, float px, float py, float &c, float &r);

}