#include "ImageProcessor.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include "BasicExcel.hpp"
#include "ExcelFormat.h"

using namespace cv;
using namespace std;
using namespace ExcelFormat;

void CallBackFunc(int event, int x, int y, int flags, void* userdata);
bool ImageProcessor::proccess_start = false;	// Flag will be true after proccess start
bool ImageProcessor::Isclicked = false;
bool ImageProcessor::Isclicked2 = false;
bool ImageProcessor::First_mouse_click_done = false;
int ImageProcessor::Lane = 0;
bool ImageProcessor::temp_flag = false;
bool ImageProcessor::isVideoRun = false;
bool ImageProcessor::isVideoOut = false;
bool ImageProcessor::isVideoShow = true;
std::string ImageProcessor::currentVideo;
int ImageProcessor::totFrams;
int ImageProcessor::currentFrame;
int hours;
int minutes;
int seconds;

Mat ImageProcessor::temp;
Mat ImageProcessor::previous;

int *ImageProcessor::w;
int	*ImageProcessor::h;
int	*ImageProcessor::x_cord;  
int *ImageProcessor::y_cord;

ImageProcessor::ImageProcessor()
{
	Number_Of_Vehicles = 0;	//Vehicle count
	Start_Hour = 0;
	Start_Minute = 0;
	Start_Second = 0;
	No_Lanes = 1;
}
ImageProcessor::ImageProcessor(string sInputFileName, string sOutputFileName, std::string sOutputFileNameTxt, int iStartHour, int iStartMinute, int iStartSecond, int iNoLanes) :inputFileName(sInputFileName), outputFileName(sOutputFileName), Start_Hour(iStartHour), Start_Minute(iStartMinute), Start_Second(iStartSecond), No_Lanes(iNoLanes)
{
	this->outputFileNameTxt = sOutputFileNameTxt;
}
bool ImageProcessor::MarkTrackers()
{
	CvCapture* cap = cvCreateFileCapture(inputFileName.c_str());	//Open video.Video will be reopend Later

	
	VideoWriter Video;
	char String_to_show[20];
	if (isVideoOut)
	{

		Video.open(outputFileName.c_str(), CV_FOURCC('M', 'P', '4', '3'), 30, Size(1440, 1080), true);
		if (!Video.isOpened())
		{
			cout << "Could not open the output video for write\n";
			isVideoRun = false;
			return false;
		}
	}
	Moving_flag = new bool[No_Lanes];
	Man_Move = new bool[No_Lanes];

	for (int i = 0; i < No_Lanes; i++)
	{
		Moving_flag[i] = Man_Move[i] = false;
	}

	Colours = new RGB[No_Lanes];
	Move_Along_X = new CG[No_Lanes];
	w = new int[No_Lanes];
	h = new int[No_Lanes];
	x_cord = new int[No_Lanes];
	y_cord = new int[No_Lanes];

	namedWindow("Mark the Lanes", WINDOW_NORMAL);
	previous = cvQueryFrame(cap);
	
	imshow("Mark the Lanes", previous);
	waitKey(1);

	/*Allow user two draw Rectangles*/
	for (Lane = 0; Lane < No_Lanes; Lane++)
	{
		
		//cout << "Click On The First Point:\n";
		while (!Isclicked2)
		{
			if( !cvGetWindowHandle("Mark the Lanes") )
			{
				Isclicked = false;
				Isclicked2 = false;
				First_mouse_click_done = false;
				return false;
			}
			if (First_mouse_click_done);
				//cout << "Cancelled......................\n\nClick On The First Point:\n";
			First_mouse_click_done = false;

			while (!Isclicked)
			{
				if( !cvGetWindowHandle("Mark the Lanes") )
				{
					Isclicked = false;
					Isclicked2 = false;
					First_mouse_click_done = false;
					return false;
				}
				setMouseCallback("Mark the Lanes", CallBackFunc, 0);
				waitKey(0);
				if (Isclicked){
					First_mouse_click_done = true;
					break;
				}

			}

			
			cout << "\nClick On The Second Point:\n";
			if (!Isclicked2){
				setMouseCallback("Mark the Lanes", CallBackFunc, 0);
				waitKey(0);
			}
		}

		Isclicked = false;
		Isclicked2 = false;
		First_mouse_click_done = false;
		if (w[Lane] < 0)
		{
			x_cord[Lane] += w[Lane];
			w[Lane] *= -1;
		}

		if (h[Lane] < 0)
		{
			y_cord[Lane] += h[Lane];
			h[Lane] *= -1;
		}
		rectangle(previous, Point(x_cord[Lane], y_cord[Lane]), Point(x_cord[Lane] + w[Lane], y_cord[Lane] + h[Lane]), Scalar(255, 0, 0), 5, 8, 0);
		sprintf(String_to_show, "%d", Lane + 1);
		putText(previous, String_to_show, Point(x_cord[Lane] + w[Lane] / 2 - 17, y_cord[Lane] + h[Lane] / 2 + 20), FONT_HERSHEY_SIMPLEX, 1.5, Scalar(255, 0, 0), 4, 8, false);
		/***********************************************************/

	}
	cv::setMouseCallback("Mark the Lanes", NULL, NULL);
	return true;
	/*****************************************************************************/
}
int ImageProcessor::Start()
{
	isVideoRun = true;
	proccess_start = true;
	bool flag = false;

	VideoWriter Video;
	char String_to_show[20];
	CvCapture* cap = cvCreateFileCapture(inputFileName.c_str());	//reopen video for proccess
	previous = cvQueryFrame(cap);

	for (int i = 0; i < No_Lanes; i++)
	{
		vector<int> temp;
		for (int j = 0; j < 96; j++)
		{
			temp.push_back(0);
		}
		Lane_count.push_back(temp);

	}
	if (isVideoShow)
	{
		namedWindow("Output", WINDOW_NORMAL);
	}
	totFrams = cvGetCaptureProperty(cap, CV_CAP_PROP_FRAME_COUNT);

	for (int j = 0; (j<100)&&isVideoRun; j++)	//27000 frames for 15 minutes(Frame rate=30)
	{

		currentFrame = cvGetCaptureProperty(cap, CV_CAP_PROP_POS_FRAMES);
		image = crop = cvQueryFrame(cap);	//capture Frame
		image = crop = cvQueryFrame(cap);
		image = crop = cvQueryFrame(cap);
		curentTimeBlock = (Start_Hour * 60 + Start_Minute + (3 * j + 2) / 1800)/(15);

		if (image.empty())
		{
			//cout << "\n**********END OF VIDEO*********";

			cvDestroyWindow("Output");
			return totFrams;
		}
		temp = image.clone();

		if (image.empty())
			isVideoRun = false;

		for (Lane = 0; Lane < No_Lanes; Lane++){

			bool moving = Ismoving(previous(Rect(x_cord[Lane], y_cord[Lane], w[Lane], h[Lane])), image(Rect(x_cord[Lane], y_cord[Lane], w[Lane], h[Lane])));

			/*Draw the rectangle on the Lane and print the Lane number in the rectangle*/
			Point point_1(x_cord[Lane], y_cord[Lane]);
			Point point_2(x_cord[Lane] + w[Lane], y_cord[Lane] + h[Lane]);
			rectangle(temp, point_1, point_2, cvScalar(255, 0, 0), 6, 8, 0);
			sprintf(String_to_show, "%d", Lane + 1);
			putText(temp, String_to_show, Point(x_cord[Lane] + w[Lane] / 2 - 17, y_cord[Lane] + h[Lane] / 2 + 20), FONT_HERSHEY_SIMPLEX, 1.5, Scalar(255, 0, 0), 4, 8, false);
			/***********************************************************/
		}

		cout << '\n';
		previous = image.clone();

		/*Draw filled pollygonals to show vehicle counts*/
		const Point* ppt[1] = { rook_points };
		int npt[] = { 5 };
		for (int i = 0; i < No_Lanes; i++){
			rook_points[0] = Point(10, 30 + 42 * (i - 1) + 13);
			rook_points[1] = Point(250, 30 + 42 * (i - 1) + 13);
			rook_points[2] = Point(250, 30 + 42 * i + 5);
			rook_points[3] = Point(10, 30 + 42 * i + 5);
			rook_points[4] = Point(10, 30 + 42 * (i - 1) + 13);
			fillPoly(temp, ppt, npt, 1, Scalar(175, 0, 150), 8);
		}
		/********************************************************************/

		/*print vehice count*/
		for (Lane = 0; Lane < No_Lanes; Lane++){
			sprintf(String_to_show, "Lane %d=%d", Lane + 1, Lane_count[Lane][curentTimeBlock]);
			putText(temp, String_to_show, Point(25, 30 + 42 * Lane), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 2, 8, false);
		}
		/*********************************************************************/

		/*calculate and print time*/
		seconds = ((3 * j + 2) / 30 + Start_Second) % 60;
		minutes = ((3 * j + 2) / 1800 + Start_Minute) % 60;
		hours = Start_Hour + ((3 * j + 2) / 1800 + Start_Minute) / 60;

		sprintf(String_to_show, "Time=%d.%d.%d", hours, minutes, seconds);
		putText(temp, String_to_show, Point(1000, 38), FONT_ITALIC, 1.2, Scalar(0, 0, 255), 2, 8, false);
		/**********************************************************************/

		if (isVideoShow)
		{
			imshow("Output", temp);	//show video
		}

		if (isVideoOut)
		{
			Video.write(temp);		//write video
		}
		while (!waitKey(5))
			flag = false;
	}
	isVideoRun = false;
	if (isVideoShow)
	{
		cvDestroyWindow("Output");
	}
	proccess_start=false;
	return totFrams;
}


/* pass two cropped images of same size to function,use Imagename=Imagename(X,Y,Width,Hieght); to crop and
previous = crrent.clone() to save the previous frame */
bool ImageProcessor::Ismoving(Mat previous, Mat current)
{
	Mat temp;
	int thresh = 6,	//if any R,G,B value in a pixel is changed more that 'thresh' it will be detected
		percentage = 30;	//if 'current' image chnaged more than 'percentage'% respect to 'previous' image, funtion will return true
	int Thresh_Along_X = 85;		//not used
	char window_name[10];
	int threshold_sum = (previous.cols*previous.rows * 3 * 255 * percentage) / 100; //6% 
	int sum = 0;

	if (Moving_flag[Lane])
		percentage = 6;

	sprintf(window_name, "Lane_%d", Lane + 1);
	//namedWindow(window_name, WINDOW_NORMAL);

	/*create binary image*/
	absdiff(previous, current, temp);
	blur(temp, temp, Size(5, 5));
	erode(temp, temp, Mat());
	threshold(temp, temp, thresh, 255, CV_THRESH_BINARY);
	/**********************************************************/

	//imshow(window_name, temp);
	//waitKey(1);


	for (int x = 0; x < temp.rows; x++)
	for (int y = 0; y<temp.cols; y++)
		sum += (int)temp.at<Vec3b>(x, y)[0] + (int)temp.at<Vec3b>(x, y)[1] + (int)temp.at<Vec3b>(x, y)[2];

	bool changed = Ischanged(previous, current);	//check whethe colours are changed



	if (sum>threshold_sum&&changed&&!Moving_flag[Lane])
	{
		cout << "Moving  ";
		/*if(!Moving_flag[Lane])
		{
		Move_Along_X[Lane].Distance=0;
		Move_Along_X[Lane].Current_x=Move_Along_X[Lane].Last_x=Find_CG(temp);

		}

		else
		{
		Move_Along_X[Lane].Current_x=Find_CG(temp);
		Move_Along_X[Lane].Distance+=Move_Along_X[Lane].Current_x-Move_Along_X[Lane].Last_x;
		cout<<Move_Along_X[Lane].Current_x<<" ";
		Move_Along_X[Lane].Last_x=Move_Along_X[Lane].Current_x;
		}

		if(((abs(Move_Along_X[Lane].Distance)*100)/current.cols)>Thresh_Along_X)
		{

		Man_Move[Lane]=true;
		cout<<"Man ";
		}
		*/

		Moving_flag[Lane] = true;
		return true;

	}

	else if (sum > threshold_sum&&Moving_flag[Lane])
	{
		cout << "Moving  ";
		/*if(!Moving_flag[Lane])
		{
		Move_Along_X[Lane].Distance=0;
		Move_Along_X[Lane].Current_x=Move_Along_X[Lane].Last_x=Find_CG(temp);

		}

		else
		{
		Move_Along_X[Lane].Current_x=Find_CG(temp);
		Move_Along_X[Lane].Distance+=Move_Along_X[Lane].Current_x-Move_Along_X[Lane].Last_x;
		cout<<Move_Along_X[Lane].Current_x<<" ";
		Move_Along_X[Lane].Last_x=Move_Along_X[Lane].Current_x;
		}

		if(((abs(Move_Along_X[Lane].Distance)*100)/current.cols)>Thresh_Along_X)
		{

		Man_Move[Lane]=true;
		cout<<"Man ";
		}*/


		Moving_flag[Lane] = true;
		return true;
	}

	cout << "Not_Moving  ";

	if (Moving_flag[Lane] && !Man_Move[Lane]){      //Man move is not using for now
		Number_Of_Vehicles++;
		Lane_count[Lane][curentTimeBlock]++;
	}

	Moving_flag[Lane] = Man_Move[Lane] = false;
	return false;


}

/*Check whether there's a considerable colour change between two adjacent frames*/
bool  ImageProcessor::Ischanged(Mat previous, Mat current)
{
	int Prev_sum = 0,
		Cur_sum = 0;
	int Percentage_thresh = 3;	//Function will return true if current image's colour is changed more than 'Percentage_thresh'%

	for (int x = 0; x < previous.rows; x++)
	for (int y = 0; y < previous.cols; y++)
		Prev_sum += (int)previous.at<Vec3b>(x, y)[0] + (int)previous.at<Vec3b>(x, y)[1] + (int)previous.at<Vec3b>(x, y)[2];


	for (int x = 0; x < current.rows; x++)
	for (int y = 0; y<current.cols; y++)
		Cur_sum += (int)current.at<Vec3b>(x, y)[0] + (int)current.at<Vec3b>(x, y)[1] + (int)current.at<Vec3b>(x, y)[2];



	int percentage;

	if (Cur_sum>Prev_sum)
	{
		percentage = (Cur_sum - Prev_sum) * 100;
		percentage /= Prev_sum;
	}


	if (Cur_sum <= Prev_sum)
	{
		percentage = (Prev_sum - Cur_sum) * 100;
		percentage /= Prev_sum;
	}

	cout << percentage << " ";		//percentage will be print on console,we can observe percentages when there's a vehicle and adjust it if not detecting

	if (percentage > Percentage_thresh)
		return true;

	return false;

}

/*Detect mouse moves and events of keyboard*/
void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	if (!ImageProcessor::proccess_start)
	{
		if (event == EVENT_RBUTTONDOWN)
		{
			ImageProcessor::Isclicked = false;
			ImageProcessor::Isclicked2 = false;
			namedWindow("Mark the Lanes", WINDOW_NORMAL);
			imshow("Mark the Lanes", ImageProcessor::previous);
		}
		else if (event == EVENT_LBUTTONDOWN)
		{
			ImageProcessor::Isclicked = true;
			if (ImageProcessor::First_mouse_click_done)
			{
				ImageProcessor::Isclicked2 = true;
			}
			if (!ImageProcessor::First_mouse_click_done)
			{
				ImageProcessor::x_cord[ImageProcessor::Lane] = x;
				ImageProcessor::y_cord[ImageProcessor::Lane] = y;
			}

			ImageProcessor::temp = ImageProcessor::previous.clone();
			circle(ImageProcessor::temp, Point(x, y), 4, Scalar(0, 0, 255), 5, 8, 0);
			namedWindow("Mark the Lanes", WINDOW_NORMAL);
			imshow("Mark the Lanes", ImageProcessor::temp);

			if (ImageProcessor::First_mouse_click_done)
			{
				ImageProcessor::w[ImageProcessor::Lane] = x - ImageProcessor::x_cord[ImageProcessor::Lane];
				ImageProcessor::h[ImageProcessor::Lane] = y - ImageProcessor::y_cord[ImageProcessor::Lane];

			}
		}
		
		else if (event == EVENT_MOUSEMOVE && ImageProcessor::Isclicked)
		{
			ImageProcessor::temp = ImageProcessor::previous.clone();
			rectangle(ImageProcessor::temp, Point(ImageProcessor::x_cord[ImageProcessor::Lane], ImageProcessor::y_cord[ImageProcessor::Lane]), Point(x, y), Scalar(255, 0, 0), 5, 8, 0);
			circle(ImageProcessor::temp, Point(ImageProcessor::x_cord[ImageProcessor::Lane], ImageProcessor::y_cord[ImageProcessor::Lane]), 4, Scalar(0, 0, 255), 5, 8, 0);
			namedWindow("Mark the Lanes", WINDOW_NORMAL);
			imshow("Mark the Lanes", ImageProcessor::temp);
			waitKey(1);
		}

		if (event == EVENT_MOUSEMOVE && flags == EVENT_FLAG_SHIFTKEY)
		{
			ImageProcessor::temp_flag = true;
		}

		else if (event == EVENT_MOUSEMOVE)
		{
			if (ImageProcessor::temp_flag)
			{
				ImageProcessor::temp_flag = false;
			}
		}
	}
	else
	{
		return;
	}
}

/*Following functions are not using*/
void ImageProcessor::Show_Avg(Mat image, Mat B_image)
{
	Colours[Lane].B = Colours[Lane].G = Colours[Lane].R = 0;
	for (int x = 0; x < (image.rows) / 5; x++)
	for (int y = 0; y < (image.rows) / 5; y++){
		Colours[Lane].B += (int)image.at<Vec3b>(x, y)[0];
		Colours[Lane].G += (int)image.at<Vec3b>(x, y)[1];
		Colours[Lane].R += (int)image.at<Vec3b>(x, y)[2];
	}
	cout << Colours[Lane].B << "   " << Colours[Lane].G << "   " << Colours[Lane].R << "   ";

}

int ImageProcessor::Find_CG(Mat Binary_image)
{
	int Sigma_Ax = 0,
		Sigma_A = 0;
	return 0;
	for (int x = y_cord[Lane]; x < y_cord[Lane] + h[Lane]; x++)
	{

		for (int y = x_cord[Lane]; y < x_cord[Lane] + w[Lane]; y++){
			Sigma_Ax += (y - x_cord[Lane])*((int)image.at<Vec3b>(x, y)[0] + (int)image.at<Vec3b>(x, y)[1] + (int)image.at<Vec3b>(x, y)[2]);
			Sigma_A += (int)image.at<Vec3b>(x, y)[0] + (int)image.at<Vec3b>(x, y)[1] + (int)image.at<Vec3b>(x, y)[2];
		}
	}

	if (Sigma_A <= 0)
	{
		cout << "Image is Fully Black" << Sigma_A << "  ";
		return -1;
	}
	return Sigma_Ax / Sigma_A;
}

//void ImageProcessor::saveResults()
//{
//	std::ofstream resultFile;
//    resultFile.open (outputFileNameTxt.c_str());
//	resultFile << "Results\n\n";
//	resultFile << "Time Block ,\t\t\t";
//
//	for (int i = 0; i < No_Lanes; i++)
//	{
//		resultFile << "Lane " << (i + 1) << ",\t";
//	}
//	resultFile << endl;
//	for (int i = 0; i < 96; i++)
//	{
//		resultFile << "15 Minutes from " << (i / 4) << ":" << (i % 4) * 15<<",\t";
//		for (int j = 0; j < No_Lanes; j++)
//		{
//			resultFile << Lane_count[j][i] << ",\t";
//		}
//		resultFile << endl;
//	}
//	resultFile.close();	
//}

void ImageProcessor::saveResults(int start_h,int start_min,int start_second)
{

	string Excel_lane;
	char buffer[100];

	std::ofstream resultFile;
    resultFile.open (outputFileNameTxt.c_str());
	resultFile << "Results\n\n";
	resultFile << "Time Block ,\t\t\t";

	BasicExcel xls("Sample.xls");
	//xls.New(1);
	BasicExcelWorksheet* sheet = xls.GetWorksheet(0);
	XLSFormatManager fmt_mgr(xls);

	//ExcelFont font_red_bold;
	//font_red_bold._weight = FW_BOLD;
	//font_red_bold._color_index = EGA_RED;

	//CellFormat fmt_red_bold(fmt_mgr, font_red_bold);
	//fmt_red_bold.set_color1(COLOR1_PAT_SOLID);			// solid background
	//fmt_red_bold.set_color2(MAKE_COLOR2(EGA_BLUE,0));	// blue background

	ExcelFont font_bold;
	font_bold._weight = FW_BOLD;

	CellFormat fmt_bold(fmt_mgr);
	fmt_bold.set_font(font_bold);

	BasicExcelCell* cell = sheet->Cell(1, 1);
	cell->Set("Time Block");
	cell->SetFormat(fmt_bold);

	for (int i = 0; i < No_Lanes; i++)
	{
		resultFile << "Lane " << (i + 1) << ",\t";
		BasicExcelCell* cell = sheet->Cell(1, i+4);
		sprintf(buffer, "Lane %d", i+1);
		cell->Set(buffer);
		cell->SetFormat(fmt_bold);
	
	for (int i = 0; i < No_Lanes; i++)
	{
		resultFile << "Lane " << (i + 1) << ",\t";

	}
	resultFile << endl;
	for (int i = 0; i < 96; i++)
	{
		BasicExcelCell* cell = sheet->Cell(i+2, 1);
		resultFile << "15 Minutes from " << (i / 4) << ":" << (i % 4) * 15<<",\t";

		CellFormat fmt_red_bold(fmt_mgr, font_bold);
		fmt_bold.set_color1(COLOR1_PAT_SOLID);			
		fmt_bold.set_color2(MAKE_COLOR2(EGA_RED,EGA_WHITE));

		sprintf(buffer, "15 Minutes from %d : %d", i/4,(i%4)*15);
		cell->Set(buffer);
		//cell->SetFormat(fmt_bold);

		for (int j = 0; j < No_Lanes; j++)
		{
			BasicExcelCell* cell = sheet->Cell(i+2, j+4);
			resultFile << Lane_count[j][i] << ",\t";

			fmt_bold.set_format_string(XLS_FORMAT_INTEGER);

			CellFormat fmt_red_bold(fmt_mgr, font_bold);
			fmt_bold.set_color1(COLOR1_PAT_SOLID);			
			fmt_bold.set_color2(MAKE_COLOR2(EGA_BLUE,0));

			cell->Set(Lane_count[j][i]);
			cell->SetFormat(fmt_bold);
		}
		resultFile << endl;
	}
	resultFile.close();

	//color correcting in cells where videos are availabla(turning orange to red)
	for(int hou=start_h;hou<=hours;hou++)
	{
		for(int minu=start_min;minu<=minutes;minu++)
		{
			BasicExcelCell* cell = sheet->Cell(2+hou*4+minu/15,1);
			fmt_bold.set_color1(COLOR1_PAT_SOLID);			
			fmt_bold.set_color2(MAKE_COLOR2(EGA_WHITE,0));

			//cell->Set(buffer);
			cell->SetFormat(fmt_bold);
		}
	}

	//color correcting where the starting 15 min block is not completed by the video(turning orange to red)
	if(start_min % 15 != 0)
	{
		BasicExcelCell* cell = sheet->Cell(2+start_h*4+start_min/15,1);
		fmt_bold.set_color1(COLOR1_PAT_SOLID);			
		fmt_bold.set_color2(MAKE_COLOR2(EGA_RED,0));

		cell->SetFormat(fmt_bold);
	}

	//color correcting where the ending 15 min block is not completed by the video(turning orange to red)
	if((start_min+minutes) % 15 != 0)
	{
		BasicExcelCell* cell = sheet->Cell(3+(start_h+hours)*4+(start_min+minutes)/15,1);
		fmt_bold.set_color1(COLOR1_PAT_SOLID);			
		fmt_bold.set_color2(MAKE_COLOR2(EGA_RED,0));

		cell->SetFormat(fmt_bold);
	}
	xls.SaveAs("Sample_result.xls");

		resultFile << "15 Minutes from " << (i / 4) << ":" << (i % 4) * 15<<",\t";
		for (int j = 0; j < No_Lanes; j++)
		{
			resultFile << Lane_count[j][i] << ",\t";
		}
		resultFile << endl;
	}
	resultFile.close();	
}