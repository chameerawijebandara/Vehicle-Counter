#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>


using namespace cv;
using namespace std;

bool Ismoving(Mat previous, Mat current);	
void Show_Avg(Mat image,Mat B_image);	//not used
bool Ischanged(Mat previous, Mat current);
void CallBackFunc(int event, int x, int y, int flags, void* userdata);
int Find_CG(Mat Binary_image);	//not used
Point rook_points[5];	// 5 points To draw filled pollygonal to show Lane counts

/*These detail will taken from rectangles drawn by*/
int *w,			// width of the rect
	*h,			// hieght of the rect
	*x_cord,     // X cord of first point
	*y_cord;     // Y cord of first point

Mat image,temp,crop;
Mat previous;
bool *Moving_flag; // Flag will be true if something is moving in respective Lane
bool *Man_Move;		//not used
bool temp_flag=false;
bool proccess_start=false;	// Flag will be true after proccess start
bool Isclicked=false;
bool Isclicked2=false;
bool First_mouse_click_done=false;
int Number_Of_Vehicles=0;	//Vehicle count
int *Lane_count;
int Lane=0;			// Current Lane number wich the proccess is doing

/* NOT USED*/
static class RGB
{
public: int R,G,B;
};

/* NOT USED*/
RGB *Colours;

static class CG
{
public: int Last_x,
			Current_x,
			Distance;
		
};
CG *Move_Along_X;

int main(int argc, char* argv[])
{
	CvCapture* cap = cvCreateFileCapture("D:\\Image_Processing\\Project\\00037.MTS");	//Open video.Video will be reopend Later
	//VideoCapture capp=VideoCapture("D:\\Image_Processing\\Project\\7-53-4.MTS");
	
	bool flag=false;
	char String_to_show[20];
	int hours,
		minutes,
		seconds;

	int Start_Hour,
		Start_Minute,
		Start_Second;

	int No_Lanes=4;
	
	VideoWriter Video;
	Video.open("D:\\Image_Processing\\Project\\Results\\Video1.avi", CV_FOURCC('M','P','4','3'),30,Size(1440,1080),true);
	if (!Video.isOpened())
    {
        cout  << "Could not open the output video for write\n";
        return 0;
    }
	
	cout<<"Starting Time(HH MM SS) :";
	cin>>Start_Hour>>Start_Minute>>Start_Second;
	

	cout<<"Number Of Lanes=";
	cin>>No_Lanes;

	Moving_flag=new bool[No_Lanes];
	Man_Move=new bool[No_Lanes];
	
	Lane_count=new int[No_Lanes];
	for(int i=0;i<No_Lanes;i++){
		Moving_flag[i]=Man_Move[i]=false;
		Lane_count[i]=0;
	}

	Colours=new RGB[No_Lanes];
	Move_Along_X=new CG[No_Lanes];
	w=new int[No_Lanes]; 
	h=new int[No_Lanes];
	x_cord=new int[No_Lanes];
	y_cord=new int[No_Lanes];

	namedWindow( "Video", WINDOW_NORMAL );
	

	previous=cvQueryFrame(cap);

	imshow("Video",previous);
	waitKey(1);

	/*Allow user two draw Rectangles*/
	for(Lane=0;Lane<No_Lanes;Lane++){
		cout<<"Click On The First Point:\n";
		while(!Isclicked2){

			if(First_mouse_click_done)
				cout<<"Cancelled......................\n\nClick On The First Point:\n";
			First_mouse_click_done=false;

			while(!Isclicked){
				setMouseCallback("Video", CallBackFunc, 0);
				waitKey(0);
				if(Isclicked){
					First_mouse_click_done=true;
					break;
				}

			}


			cout<<"\nClick On The Second Point:\n";
			if(!Isclicked2){
				setMouseCallback("Video", CallBackFunc, 0);
				waitKey(0);
			}
		}

		Isclicked=false;
		Isclicked2=false;
		First_mouse_click_done=false;
		if(w[Lane]<0)
		{
			x_cord[Lane]+=w[Lane];
			w[Lane]*=-1;
		}

		if(h[Lane]<0)
		{
			y_cord[Lane]+=h[Lane];
			h[Lane]*=-1;
		}
		rectangle(previous,Point(x_cord[Lane],y_cord[Lane]),Point(x_cord[Lane]+w[Lane],y_cord[Lane]+h[Lane]),Scalar(255,0,0),5,8,0);

	}
	/*****************************************************************************/

	
	proccess_start=true;
	
	
	cap = cvCreateFileCapture("D:\\Image_Processing\\Project\\00037.MTS");	//reopen video for proccess
	previous=cvQueryFrame(cap);


	

	for(int j=0;j<27000;j++)	//27000 frames for 15 minutes(Frame rate=30)
	{

		cout<<j<<")  ";
		image = crop= cvQueryFrame(cap);	//capture Frame
		if(image.empty())
		{
			cout<<"\n**********END OF VIDEO*********";
			return 0;
		}
		temp=image.clone();
		
		if(image.empty())
			return 0;
		
		for(Lane=0;Lane<No_Lanes;Lane++){
		
			bool moving=Ismoving(previous(Rect(x_cord[Lane],y_cord[Lane],w[Lane],h[Lane])),image(Rect(x_cord[Lane],y_cord[Lane],w[Lane],h[Lane])));

			/*Draw the rectangle on the Lane and print the Lane number in the rectangle*/
			Point point_1(x_cord[Lane],y_cord[Lane]);
			Point point_2(x_cord[Lane]+w[Lane],y_cord[Lane]+h[Lane]);
			rectangle(temp,point_1,point_2,cvScalar(255,0,0),6,8,0);
			sprintf(String_to_show, "%d", Lane+1);
			putText(temp,String_to_show,Point(x_cord[Lane]+w[Lane]/2-17,y_cord[Lane]+h[Lane]/2+20),FONT_HERSHEY_SIMPLEX,1.5,Scalar(255,0,0),4,8,false);
			/***********************************************************/

			
			
		}

		cout<<'\n';
		previous=image.clone();

		/*Draw filled pollygonals to show vehicle counts*/
		const Point* ppt[1] = { rook_points };
		int npt[] = { 5 };
		for(int i=0;i<No_Lanes;i++){
			rook_points[0] = Point( 10, 30+42*(i-1)+13 );
			rook_points[1] = Point( 250, 30+42*(i-1)+13 );
			rook_points[2] = Point( 250, 30+42*i+5 );
			rook_points[3] = Point( 10,  30+42*i+5);
			rook_points[4] = Point( 10, 30+42*(i-1)+13 );
			fillPoly( temp, ppt, npt, 1, Scalar( 175, 0, 150 ), 8 );
		}
		/********************************************************************/

		/*print vehice count*/
		for(Lane=0;Lane<No_Lanes;Lane++){
			sprintf(String_to_show, "Lane %d=%d", Lane+1,Lane_count[Lane]);
			putText(temp,String_to_show,Point(25,30+42*Lane),FONT_HERSHEY_SIMPLEX,1,Scalar(0,0,255),2,8,false);
		}
		/*********************************************************************/

		/*calculate and print time*/
		seconds=((j+2)/30+Start_Second)%60;
		minutes=((j+2)/1800+Start_Minute)%60;
		hours=Start_Hour+((j+2)/1800+Start_Minute)/60;
		
		sprintf(String_to_show, "Time=%d.%d.%d",hours,minutes,seconds);
		putText(temp,String_to_show,Point(1000,38),FONT_ITALIC,1.2,Scalar(0,0,255),2,8,false);
		/**********************************************************************/


		imshow("Video",temp);	//show video
		Video.write(temp);		//write video
		
		while(!waitKey(5))
			
		
		flag=false;
		
		
			
	}
	
	return 0;
}








/* pass two cropped images of same size to function,use Imagename=Imagename(X,Y,Width,Hieght); to crop and 
previous = crrent.clone() to save the previous frame */

bool Ismoving(Mat previous, Mat current)
{
	Mat temp;
	int thresh=6,	//if any R,G,B value in a pixel is changed more that 'thresh' it will be detected
		percentage=30	;	//if 'current' image chnaged more than 'percentage'% respect to 'previous' image, funtion will return true
	int Thresh_Along_X=85;		//not used
	char window_name[10];
	int threshold_sum=(previous.cols*previous.rows*3*255*percentage)/100; //6% 
	int sum=0;

	if(Moving_flag[Lane])	
		percentage=6;

	sprintf(window_name,"Lane_%d",Lane+1);
	namedWindow(window_name,WINDOW_NORMAL);

	/*create binary image*/
	absdiff(previous,current,temp);
	blur(temp,temp,Size(5,5));
	erode(temp,temp,Mat ());
	threshold(temp,temp,thresh,255,CV_THRESH_BINARY);
	/**********************************************************/

	imshow(window_name,temp);
	waitKey(1);
	
	
	for(int x=0;x<temp.rows;x++)
		for (int y=0;y<temp.cols;y++)
			sum+=(int)temp.at<Vec3b>(x,y)[0]+	(int)temp.at<Vec3b>(x,y)[1]+	(int)temp.at<Vec3b>(x,y)[2];
		
	bool changed=Ischanged(previous,current);	//check whethe colours are changed
	


	if(sum>threshold_sum&&changed&&!Moving_flag[Lane])
	{
		cout<<"Moving  ";
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
		
		Moving_flag[Lane]=true;
		return true;

	}
	
	else if(sum>threshold_sum&&Moving_flag[Lane])
	{
		cout<<"Moving  ";
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

		
		Moving_flag[Lane]=true;
		return true;
	}

	cout<<"Not_Moving  ";

	if(Moving_flag[Lane]&&!Man_Move[Lane]){      //Man move is not using for now
		Number_Of_Vehicles++;
		Lane_count[Lane]++;
	}

	Moving_flag[Lane]=Man_Move[Lane]=false;
	return false;


}



/*Check whether there's a considerable colour change between two adjacent frames*/

bool Ischanged(Mat previous, Mat current)
{
	int Prev_sum=0,
		Cur_sum=0;
	int Percentage_thresh=3;	//Function will return true if current image's colour is changed more than 'Percentage_thresh'%
	
	for(int x=0;x<previous.rows;x++)
		for (int y=0;y<previous.cols;y++)
			Prev_sum+=(int)previous.at<Vec3b>(x,y)[0]+	(int)previous.at<Vec3b>(x,y)[1]+	(int)previous.at<Vec3b>(x,y)[2];
	

	for(int x=0;x<current.rows;x++)
		for (int y=0;y<current.cols;y++)
			Cur_sum+=(int)current.at<Vec3b>(x,y)[0]+	(int)current.at<Vec3b>(x,y)[1]+	(int)current.at<Vec3b>(x,y)[2];

	

	int percentage;
	
	if(Cur_sum>Prev_sum)
	{
		percentage=(Cur_sum-Prev_sum)*100;
		percentage/=Prev_sum;
	}
	
		
	if(Cur_sum<=Prev_sum)
	{
		percentage=(Prev_sum-Cur_sum)*100;
		percentage/=Prev_sum;
	}

	cout<<percentage<<" ";		//percentage will be print on console,we can observe percentages when there's a vehicle and adjust it if not detecting

	if(percentage>Percentage_thresh)
		return true;

	return false;

}




/*Detect mouse moves and events of keyboard*/

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	if(!proccess_start){
		
		if(event==EVENT_RBUTTONDOWN){
			Isclicked=false;
			Isclicked2=false;
			namedWindow( "Video", WINDOW_NORMAL );
			imshow("Video",previous);

		}

		else if  ( event == EVENT_LBUTTONDOWN )
		{
			 
		Isclicked=true; 
		if(First_mouse_click_done)
			Isclicked2=true;
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\t- Clicked on (" << x << ", " << y << ")\t  --> PRESS ANY KEY TO CONFIRM\n" ;
		if(!First_mouse_click_done)
		{
			x_cord[Lane]=x;
			y_cord[Lane]=y;
		}

		temp=previous.clone();
		circle(temp,Point(x,y),4,Scalar(0,0,255),5,8,0);
		namedWindow( "Video", WINDOW_NORMAL );
		imshow("Video",temp);

		if(First_mouse_click_done)
		{
			w[Lane]=x-x_cord[Lane];
			h[Lane]=y-y_cord[Lane];

		}
		}
    

		 else if ( event == EVENT_MOUSEMOVE&&Isclicked )
		 {
			 temp=previous.clone();
			 //cout << "["<< x << ", " << y<<"]    \n";
			 rectangle(temp,Point(x_cord[Lane],y_cord[Lane]),Point(x,y),Scalar(255,0,0),5,8,0);
			 circle(temp,Point(x_cord[Lane],y_cord[Lane]),4,Scalar(0,0,255),5,8,0);
			 namedWindow( "Video", WINDOW_NORMAL );
			 imshow("Video",temp);
			 waitKey(1);

		 }

		 if ( event == EVENT_MOUSEMOVE && flags == EVENT_FLAG_SHIFTKEY )
		 {
			 cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b["<< x << ", " << y<<"]";
			 temp_flag=true;

		 }


		 else if ( event == EVENT_MOUSEMOVE )
		 {
		
			 if(temp_flag)
			 {
				  cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                     ";
				  temp_flag=false;
			 }

		 }
	}

	else
	{
		return;
	}
}



/*Following functions are not using*/

void Show_Avg(Mat image,Mat B_image)
{
	Colours[Lane].B=Colours[Lane].G=Colours[Lane].R=0;
	for(int x=0;x<(image.rows)/5;x++)
		for (int y=0;y<(image.rows)/5;y++){
			Colours[Lane].B+=(int)image.at<Vec3b>(x,y)[0];
			Colours[Lane].G+=(int)image.at<Vec3b>(x,y)[1];
			Colours[Lane].R+=(int)image.at<Vec3b>(x,y)[2];
		}
	cout<< Colours[Lane].B<<"   "<<Colours[Lane].G<<"   "<<Colours[Lane].R<<"   ";
	
}



int Find_CG(Mat Binary_image)
{
	int Sigma_Ax=0,
		Sigma_A=0;
	return 0;
	for(int x=y_cord[Lane];x<y_cord[Lane]+h[Lane];x++)
	{
		
		for (int y=x_cord[Lane];y<x_cord[Lane]+w[Lane];y++){
			Sigma_Ax+=(y-x_cord[Lane])*((int)image.at<Vec3b>(x,y)[0]+(int)image.at<Vec3b>(x,y)[1]+(int)image.at<Vec3b>(x,y)[2]);
			Sigma_A+=(int)image.at<Vec3b>(x,y)[0]+(int)image.at<Vec3b>(x,y)[1]+(int)image.at<Vec3b>(x,y)[2];
			
			
		}
		
		
	}

	
	
	if (Sigma_A<=0)
	{
		cout<<"Image is Fully Black"<<Sigma_A<<"  ";
		return -1;
	}
	
	return Sigma_Ax/Sigma_A;

}