#define _CRT_SECURE_NO_DEPRECATE
#include "stdafx.h"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <opencv\highgui.h>
#include <opencv\cv.h>

using namespace cv;
using namespace std;

void Checkvehicle(int frame_num);
void drowGraph(int val[3]);
bool Ismoving(Mat previous, Mat current);
//void drawline();
void mouse1(int event, int x, int y, int flags, void *ptr );
void mouse2(int event, int x, int y, int flags, void *ptr );

bool Negative_flag=false;
bool Positive_flag=true;
int Vehicle_Count=0;
float current_avg_sum=0;
float current_sum=0;
Mat prev_frame;
Mat Current_frame;
Mat frame;
int lane1_X=1000;
int lane1_Y=800;
int lane1_length=75;
int lane1_height=50;
int lane2_X=1000;
int lane2_Y=800;
int lane2_length=75;
int lane2_height=50;
int mouse_flag=0;

//Graph
int arraySize = 1000;
int RGBHold[1000][3];
int graphCount = 0;
int mouseClick1_X;
int mouseClick1_Y;
int mouseClick2_X;
int mouseClick2_Y;

int main(int argc, char* argv[])
{
	/*float avgb;
	float avgr;
	float avgg;*/
	float sum_avgb=0;
	float sum_avgr=0;
	float sum_avgg=0;
	float previous_sum=0;
	float mov_avg[4]={0};
	int X_diff=0;
	int Y_diff=0;
	int remainder;
	int divident;
	
	//bool bSuccess=true;
    VideoCapture cap("C:\\Users\\Rp-PC\\Desktop\\Project Traffic count\\7-30-58.MTS"); // open the video file for reading

    if(!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the video file" << endl;
		return -1;
	}

	//cap.set(CV_CAP_PROP_POS_MSEC, 300); //start the video at 300ms

	double fps = cap.get(CV_CAP_PROP_FPS); //get the frames per seconds of the video

	cout << "Frame per seconds : " << fps << endl;

    namedWindow("MyVideo",WINDOW_NORMAL);  //create a window called "MyVideo"
	cout << "Click where ever you want"<<'\n' ;

	cap.read(frame);
	imshow("MyVideo", frame);
	
	setMouseCallback("MyVideo", mouse1,0);
	//setMouseCallback("MyVideo", mouse2,0);
	
	waitKey(15000);

	if((mouseClick1_X-mouseClick2_X) < 0)
		X_diff = (mouseClick1_X-mouseClick2_X)*-1;
	if((mouseClick1_X-mouseClick2_X) > 0)
		X_diff = mouseClick1_X-mouseClick2_X;

	if((mouseClick1_Y-mouseClick2_Y) < 0)
		Y_diff = (mouseClick1_Y-mouseClick2_Y)*-1;
	if((mouseClick1_Y-mouseClick2_Y) > 0)
		Y_diff = mouseClick1_Y-mouseClick2_Y;

	remainder = X_diff % Y_diff;
	divident = X_diff / Y_diff;

	if(divident==0)
	{
		if((mouseClick1_X-mouseClick2_X) < 0)
			mouseClick1_X=mouseClick2_X-Y_diff;
		if((mouseClick1_X-mouseClick2_X) > 0)
			mouseClick2_X=mouseClick1_X-Y_diff;

		divident=1;
		remainder=0;
	}
	

	namedWindow("Background Substracted",WINDOW_NORMAL);
	ofstream myfile;
	 myfile.open ("C:\\Users\\Rp-PC\\Desktop\\Project Traffic count\\Note\\negative_smooth_movingAVG2.txt");
	int count;
	count=0;
	
	cap.read(prev_frame);
	prev_frame=prev_frame(Rect(mouseClick1_X+50,mouseClick1_Y-20,X_diff+100,Y_diff+40));

    while(1)
    {
		bool bSuccess = cap.read(frame); // read a new frame from video
		count++;
		Current_frame=frame.clone();
		Current_frame=Current_frame(Rect(mouseClick1_X+50,mouseClick1_Y-20,X_diff+100,Y_diff+40));
	  
		myfile << '\n';
		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video file" << endl;
			break;
		}

		//---------------My area--------------- Reading a pixel
		float sum_avgb=0;
		float sum_avgr=0;
		float sum_avgg=0;

		
		int j=0;
		int i=0;
		for( i=0 ; i < X_diff ; i++)
		{
			Vec3b bgrPixel = frame.at<Vec3b>( j+mouseClick1_Y , i+mouseClick1_X);
			sum_avgb += bgrPixel.val[0];
			sum_avgg += bgrPixel.val[1];
			sum_avgr += bgrPixel.val[2];
			if(remainder > i && ((i%divident+1)==0) )
				j++;
			if(remainder <= i && (i%(divident)==0) )
				j++;
		}

		//for(int i = lane2_X; i < lane2_X + lane2_length; i++)
		//{
		//	avgb = 0;
		//	avgr = 0;
		//	avgg = 0;
		//	for(int j = lane2_Y; j < lane2_Y + lane2_height; j++)
		//	{
		//		Vec3b bgrPixel = frame.at<Vec3b>(i, j);

		//		//Average calculating
		//		avgb += bgrPixel.val[0];
		//		avgg += bgrPixel.val[1];
		//		avgr += bgrPixel.val[2];
		//	}
		//		
		//	sum_avgb += avgb / lane2_height;
		//	sum_avgr += avgr / lane2_height;
		//	sum_avgg += avgg / lane2_height;
		//}
		sum_avgb /= i;
		sum_avgr /= i;
		sum_avgg /= i;


		//----------------------------------Calculating sum
		current_sum=(sum_avgb + sum_avgg + sum_avgr) / 3 - previous_sum;		
		
		//if(current_sum<=1&&current_sum>=-1)
			//current_sum=0;
		/*if(mov_avg[0]==0&&mov_avg[1]==0&&mov_avg[2]==0&&mov_avg[3]==0)
			current_avg_sum=0;
		else if(mov_avg[0]==0&&mov_avg[1]==0&&mov_avg[2]==0)
			current_avg_sum=mov_avg[3];
		else if(mov_avg[0]==0&&mov_avg[1]==0)
			current_avg_sum=(mov_avg[3]+mov_avg[2])/2;
		else if(mov_avg[0]==0)
			current_avg_sum=(mov_avg[3]+mov_avg[2]+mov_avg[1])/3;
		else
			current_avg_sum=(mov_avg[3]+mov_avg[2]+mov_avg[1]+mov_avg[0])/4;*/
		//printf("%.1f ",sum_avgb+sum_avgg+sum_avgr);

		int toGraph[] = {current_sum ,current_sum ,current_sum };
		drowGraph(toGraph);
		
		myfile << current_sum ;
		Checkvehicle(count);
		myfile << " ";

		//----------------------------------- Editing a pixel

		/*uchar pixValue;
		for (int row =lane2_X; row < lane2_X+75; row++) {
			for (int col =lane2_Y ; col < lane2_Y+50; col++) {
				Vec3b &intensity = frame.at<Vec3b>(col, row);
				for(int k = 0; k < frame.channels(); k++) {
					pixValue=0;
					intensity.val[k] = pixValue;
				}
			}
		}*/
		line(frame,Point(mouseClick1_X,mouseClick1_Y),Point(mouseClick2_X,mouseClick2_Y),Scalar(0,0,255),5,8,0);
		rectangle(frame,Point(mouseClick1_X+50,mouseClick1_Y-20),Point(mouseClick2_X-50,mouseClick2_Y+20),Scalar (255,0,0),5,8,0);
		//namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"
        imshow("MyVideo", frame); //show the frame in "MyVideo" window
        if(waitKey(2) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break; 
		}
		
		previous_sum = ( sum_avgb + sum_avgg + sum_avgr)/3;
		/*mov_avg[0]=mov_avg[1];
		mov_avg[1]=mov_avg[2];
		mov_avg[2]=mov_avg[3];
		mov_avg[3]=current_sum;*/
	   
	   prev_frame=Current_frame.clone();
	}

	//ofstream myfile;
	myfile.close();
    return 0;

}


void Checkvehicle(int frame_num)
{

	if( current_sum > 0 )
	{
		Positive_flag=true;
	}

	if( Negative_flag & Positive_flag & Ismoving( prev_frame, Current_frame ))
	{
		Vehicle_Count++;
		cout << "Number of veicles="<<Vehicle_Count <<   "      Frame number="<<frame_num<<'\n';
		Negative_flag = false;
	}

	if( current_sum < 0 )
	{
		Negative_flag = true;
		Positive_flag = false;
	}
}

bool Ismoving(Mat previous, Mat current)
{
	Mat temp;
	int thresh = 15,	//if any R,G,B value in a pixel is changed more that 'thresh' it will be detected
		percentage = 10;	//if 'current' image chnaged more than 'percentage'% respect to 'previous' image, funtion will return true

	int threshold_sum= ( previous.cols * previous.rows * 3 * 255 * percentage ) / 100; //6% 
	int sum = 0;
	absdiff(previous, current, temp);
	blur(temp, temp, Size(5,5));
	erode(temp, temp, Mat());
	dilate(temp, temp, Mat());
	threshold(temp, temp, thresh, 255, THRESH_BINARY);
	imshow("Background Substracted",temp);
	waitKey(1);
	
		
	for(int x=0; x < temp.rows; x++)
	{
		for (int y=0; y < temp.cols; y++)
		{
			sum += temp.at<Vec3b>(x,y)[0] + temp.at<Vec3b>(x,y)[1] + temp.at<Vec3b>(x,y)[2];	
		}
	}
	
	if(sum > threshold_sum)
	{
		cout<<"Moving"<<'\n';
		return true;
	}

	cout<<"Not_Moving"<<'\n';
	return false;
}

void drowGraph(int val[3])
{
	Mat graph(600,arraySize,frame.type());
	//Vec3b bgrPixel = frame.at<Vec3b>(X, Y);

	if(graphCount >= arraySize)
	{	
		for (int i = 0; i < arraySize - 1; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				RGBHold[i][j] = RGBHold[i + 1][j];
			}
		}
			
		for (int j = 0; j < 3; j++)
		{
			RGBHold[graphCount-1][j] = val[j];
		}
	}
	else
	{
		for (int j = 0; j < 3; j++)
		{
			RGBHold[graphCount][j] = val[j];
			//cout<< RGBHold[count][j] << endl;
		}			
		graphCount++;
	}

	for (int i = 0; i < 12; i++)
	{
		if(i==6)
		{
			line(graph, Point(0,600 - i*50), Point(arraySize,600 - i*50), Scalar(255,255,255),2);
		}
		else
		{
			line(graph, Point(0,600 - i*50), Point(arraySize,600 - i*50), Scalar(0,0,0),1);
		}
	}	

	for (int i = 1; i < min(graphCount,arraySize); i++)
	{
		line(graph, Point(i-1,300 - RGBHold[i-1][0]), Point(i,300 - RGBHold[i][0]), Scalar(255,0,0),1);
		line(graph, Point(i-1,300 - RGBHold[i-1][1]), Point(i,300 - RGBHold[i][1]), Scalar(0,255,0),1);
		line(graph, Point(i-1,300 - RGBHold[i-1][2]), Point(i,300 - RGBHold[i][2]), Scalar(0,0,255),1);
	}
	namedWindow("Graph",WINDOW_NORMAL);
	imshow("Graph", graph); //show the frame in "MyVideo" window
}

//void drawline()
//{
//	line(frame,Point(mouseClick1->x,mouseClick1->y),Point(mouseClick2->x,mouseClick2->y),Scalar(0,0,255),2,8);
//}

void mouse1(int event, int x, int y, int flags, void *ptr )
{
    if( event != CV_EVENT_LBUTTONDOWN )
            return;
	if(mouse_flag==1)
	{
		mouseClick2_X = x;
		mouseClick2_Y = y;
		cout<< mouseClick2_X<<"****"<<mouseClick2_Y<<endl;
		mouse_flag = 2;
	}
	if(mouse_flag==0)
	{
		mouseClick1_X = x;
		mouseClick1_Y = y;
		cout<< mouseClick1_X<<" "<<mouseClick1_Y<<endl;
		mouse_flag = 1;
	}
	if(mouse_flag==2)
	{
		line(frame,Point(mouseClick1_X,mouseClick1_Y),Point(mouseClick2_X,mouseClick2_Y),Scalar(0,0,255),5,8,0);
		mouse_flag = 0;
	}
}


void mouse2(int event, int x, int y, int flags, void *ptr )
{
	 if( event != CV_EVENT_RBUTTONDOWN )
            return;

	mouseClick2_X = x;
	mouseClick2_Y = y;
   cout<< mouseClick2_X<<" "<<mouseClick2_Y<<endl; 
}