#include "stdafx.h"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <fstream>

using namespace cv;
using namespace std;
bool Negative_flag=false;
bool Positive_flag=true;
int Vehicle_Count=0;
float current_avg_sum=0;
void Checkvehicle(int frame_num);
float current_sum=0;

int main(int argc, char* argv[])
{
	float avgb;
	float avgr;
	float avgg;
	float sum_avgb=0;
	float sum_avgr=0;
	float sum_avgg=0;
	float previous_sum=0;
	
	float mov_avg[4]={0};
	
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

    namedWindow("MyVideo",WINDOW_NORMAL); //create a window called "MyVideo"
	ofstream myfile;
	 myfile.open ("C:\\Users\\Rp-PC\\Desktop\\Project Traffic count\\Note\\negative_smooth_movingAVG2.txt");
	int count;
	count=0;
	  
    while(1)
    {
		//printf("       %d\n",count);
       Mat frame;
       bool bSuccess = cap.read(frame); // read a new frame from video
	   count++;
	   //cout<< "Frames "<<frame.cols<<"  "  <<frame.rows;


	   if(count%2==0)
	   {
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
		for(int i = 150; i < 225; i++)
		{
			avgb=0;
			avgr=0;
			avgg=0;
			for(int j = 800; j < 850; j++)
			{
				Vec3b bgrPixel = frame.at<Vec3b>(i, j);

		//Average calculating

				avgb=avgb+bgrPixel.val[0];
				avgg=avgg+bgrPixel.val[1];
				avgr=avgr+bgrPixel.val[2];
			}
			sum_avgb=sum_avgb+avgb;
			sum_avgr=sum_avgr+avgr;
			sum_avgg=sum_avgg+avgg;
		}
		//----------------------------------Calculating sum
		current_sum=sum_avgb+sum_avgg+sum_avgr-previous_sum;
		if(current_sum<=4000&&current_sum>=-4000)
			current_sum=0;
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
		myfile << current_sum ;
		Checkvehicle(count);
		myfile << " ";

		//----------------------------------- Editing a pixel

		uchar pixValue;
		for (int row = 150; row < 225; row++) {
			for (int col =800 ; col < 850; col++) {
				Vec3b &intensity = frame.at<Vec3b>(col, row);
				for(int k = 0; k < frame.channels(); k++) {
					pixValue=0;
					intensity.val[k] = pixValue;
				}
			}
		}		
		//namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"
        imshow("MyVideo", frame); //show the frame in "MyVideo" window
        if(waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break; 
		}
		//frame_prevoius=frame;
		previous_sum=sum_avgb+sum_avgg+sum_avgr;
		/*mov_avg[0]=mov_avg[1];
		mov_avg[1]=mov_avg[2];
		mov_avg[2]=mov_avg[3];
		mov_avg[3]=current_sum;*/
	   }
	}

	//ofstream myfile;
	myfile.close();
    return 0;

}


void Checkvehicle(int frame_num)
{

	if((int)current_sum>0)Positive_flag=true;
	

	if(Negative_flag&&Positive_flag)
	{
		Vehicle_Count++;
		cout << "Number of veicles="<<Vehicle_Count <<   "      Frame number="<<frame_num<<'\n';
		Negative_flag=false;
	}

	if((int)current_sum<0){Negative_flag=true;Positive_flag=false;}
}