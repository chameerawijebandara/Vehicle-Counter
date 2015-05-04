#pragma once

#include <opencv2\highgui\highgui.hpp>

class ImageProcessor
{
public:
	ImageProcessor();
	ImageProcessor::ImageProcessor(std::string sInputFileName, std::string sOutputFileName, int iStartHour, int iStartMinute, int iStartSecond, int iNoLanes);

	bool Ismoving(cv::Mat previous, cv::Mat current);
	void Show_Avg(cv::Mat image, cv::Mat B_image);	//not used
	bool Ischanged(cv::Mat previous, cv::Mat current);
	int Find_CG(cv::Mat Binary_image);	//not used
	void Start();

	/*These detail will taken from rectangles drawn by*/
	static int *w;			// width of the rect
	static int	*h;			// hieght of the rect
	static int	*x_cord;     // X cord of first point
	static int *y_cord;     // Y cord of first point

	static cv::Mat temp;
	static cv::Mat previous;

	static bool temp_flag;
	static bool proccess_start;	// Flag will be true after proccess start
	static bool Isclicked;
	static bool Isclicked2;
	static bool First_mouse_click_done;
	static bool isVideoRun;

	static int Lane;			// Current Lane number wich the proccess is doing

	/* NOT USED*/
	static class RGB
	{
	public: int R, G, B;
	};

	static class CG
	{
	public: int Last_x,
			Current_x,
			Distance;
	};

private:
	cv::Point rook_points[5];	// 5 points To draw filled pollygonal to show Lane counts
	cv::Mat image, crop;
	
	bool *Moving_flag; // Flag will be true if something is moving in respective Lane
	bool *Man_Move;		//not used
	
	int Number_Of_Vehicles = 0;	//Vehicle count
	int *Lane_count;

	/* NOT USED*/
	RGB *Colours;	
	CG *Move_Along_X;

	int Start_Hour = 0;
	int Start_Minute = 0;
	int Start_Second = 0;

	int No_Lanes = 1;
	std::string inputFileName;
	std::string outputFileName;
	
};
