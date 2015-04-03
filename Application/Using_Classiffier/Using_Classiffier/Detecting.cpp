#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
//#include <opencv2\objdetect\objdetect.hpp>

using namespace cv;
using namespace std;
bool Ismoving(Mat previous, Mat current);
void Show_Avg(Mat image,Mat B_image);
bool Ischanged(Mat previous, Mat current);
void CallBackFunc(int event, int x, int y, int flags, void* userdata);


int *w,    
	*h,   
	*x_cord,     
	*y_cord;     

Mat image,temp,crop;
Mat previous;
bool *Moving_flag;
bool temp_flag=false;
bool proccess_start=false;
bool Isclicked=false;
bool Isclicked2=false;
bool First_mouse_click_done=false;
bool *Moving_Start;
int Number_Of_Vehicles=0;
int *Lane_count;
int Lane=0;
static class RGB
{
public: int R,G,B;
};

RGB *Colours;



int main(int argc, char* argv[])
{
	//CascadeClassifier My_cascade;
	//ofstream file; 
	//file.open("D:\\Image_Processing\\Project\\Results\\Detect.txt");
	//char filename[100];
	CvCapture* cap = cvCreateFileCapture("D:\\Image_Processing\\Project\\7-30-58.MTS"); //VideoCapture cap("D:\\Image_Processing\\Project\\7-53-4.MTS");//
	VideoCapture a("D:\\Image_Processing\\Project\\7-30-58.MTS");
	//cout<<(int)a.get(CV_CAP_PROP_FOURCC)<<"  "<<CV_FOURCC('M','P','4','3');
	//Mat gray_img;
	bool flag=false;
	char String_to_show[20];
	int minutes,
		seconds;
	int No_Lanes=4;
	
	VideoWriter Video;
	Video.open("D:\\Image_Processing\\Project\\Results\\Video.avi", CV_FOURCC('M','P','4','3'),30,Size(1440,1080),true);
	if (!Video.isOpened())
    {
        cout  << "Could not open the output video for write\n";
        return 0;
    }
	//int w2=350,
	//	h2=150,
	//	x_cord2=1090,
	//	y_cord2=600;




/*	if(!My_cascade.load("D:\\Image_Processing\\Project\\Successed\\Data1\\cascade_1.xml"))
	{
		printf("Error\n");
		return 1;
	}*/
	cout<<"Number Of Lanes=";
	cin>>No_Lanes;
	Moving_flag=new bool[No_Lanes];
	Moving_Start=new bool[No_Lanes];
	Lane_count=new int[No_Lanes];
	for(int i=0;i<No_Lanes;i++){
		Moving_flag[i]=false;
		Moving_Start[i]=false;
		Lane_count[i]=0;
	}

	Colours=new RGB[No_Lanes];
	
	w=new int[No_Lanes]; 
	h=new int[No_Lanes];
	x_cord=new int[No_Lanes];
	y_cord=new int[No_Lanes];

	namedWindow( "Video", WINDOW_NORMAL );
	

	previous=cvQueryFrame(cap);

	imshow("Video",previous);
	waitKey(1);
	
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
		//previous=temp.clone();
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


	
	proccess_start=true;
	
	
	cap = cvCreateFileCapture("D:\\Image_Processing\\Project\\7-30-58.MTS");
	previous=cvQueryFrame(cap);


	

	for(int j=0;j<11000;j++)
	{
		//vector<Rect> object;
		//vector<Rect> object2;
		cout<<j<<")  ";
		image = crop= cvQueryFrame(cap);
		temp=image.clone();
		
		if(image.empty())
			return 0;
		//crop=crop(Rect(x_cord2,y_cord2,w2,h2));
		for(Lane=0;Lane<No_Lanes;Lane++){
		
			bool moving=Ismoving(previous(Rect(x_cord[Lane],y_cord[Lane],w[Lane],h[Lane])),image(Rect(x_cord[Lane],y_cord[Lane],w[Lane],h[Lane])));	
			//Ischanged(previous,image);	
			//Show_Avg(image);
			Point point_1(x_cord[Lane],y_cord[Lane]);
			Point point_2(x_cord[Lane]+w[Lane],y_cord[Lane]+h[Lane]);
			rectangle(temp,point_1,point_2,cvScalar(255,0,0),6,8,0);

			
			
		}

		cout<<'\n';
		previous=image.clone();

		//resize(image,image,cvSize((w*4)/19,(h*2)/7));
		//resize(crop,crop,cvSize((w2*4)/19,(h2*2)/7));

		
			
		/*Point point_3(x_cord2,y_cord2);
		Point point_4(x_cord2+w2,y_cord2+h2);
		rectangle(temp,point_3,point_4,cvScalar(0,0,255),6,8,0);
		*/

		/*cvtColor(image,gray_img,CV_BGR2GRAY);
		cv::equalizeHist(gray_img,gray_img);

		My_cascade.detectMultiScale(gray_img,object,1.1, 5, 0|CV_HAAR_SCALE_IMAGE, cvSize(36,18),cvSize(46,23));
		
		int x,y;
		for(int i=0;i<object.size();i++)
		{
			flag=true;
			
			x=x_cord+(int)((19*(object[i].x+object[i].width))/4);
			y=y_cord+(int)((7*(object[i].y+object[i].height))/2);
			Point point_1(x,y);

			x=x_cord+(int)((19*(object[i].x))/4);
			y=y_cord+(int)((7*(object[i].y))/2);
			Point point_2(x,y);

			rectangle(temp,point_1,point_2,cvScalar(0,0,0),2,8,0);

			Point point_3(object[i].x+object[i].width,object[i].y+object[i].height);
			Point point_4(object[i].x,object[i].y);
			rectangle(image,point_3,point_4,cvScalar(0,0,0),1,8,0);

				
		}

		if(!moving)
			flag=false;

		cvtColor(crop,gray_img,CV_BGR2GRAY);
		cv::equalizeHist(gray_img,gray_img);
		My_cascade.detectMultiScale(gray_img,object2,1.1, 5, 0|CV_HAAR_SCALE_IMAGE, cvSize(36,18),cvSize(46,23));

		for(int i=0;i<object2.size();i++)
		{
			//flag=true;
			//if(i==0)file <<"1 "<<j+1 <<'\n';
			
			x=x_cord2+(int)((19*(object2[i].x+object2[i].width))/4);
			y=y_cord2+(int)((7*(object2[i].y+object2[i].height))/2);
			Point point_1(x,y);

			x=x_cord2+(int)((19*(object2[i].x))/4);
			y=y_cord2+(int)((7*(object2[i].y))/2);
			Point point_2(x,y);

			rectangle(temp,point_1,point_2,cvScalar(0,0,0),2,8,0);

			Point point_3(object2[i].x+object2[i].width,object2[i].y+object2[i].height);
			Point point_4(object2[i].x,object2[i].y);
			rectangle(crop,point_3,point_4,cvScalar(0,0,0),1,8,0);

		}

	

		if(!moving)
		{
		//	file <<"0 "<<j+1 <<'\n';
			cout<<'\n';
		}
		else
		{
		//	file <<"1 "<<j+1 <<'\n';
			cout<<"   Vehicle"<<'\n';
		}

		//resize(image,image,cvSize(300,100));
		//sprintf(filename, "D:\\Image_Processing\\Project\\Results\\Result_Image%d.jpg", j+1);
		//imwrite(filename,image);*/
			
		minutes=(j+2)/1800;
		seconds=((j+2)/30)%60;
		sprintf(String_to_show, "Count=%d   Time=%d.%d", Number_Of_Vehicles,minutes,seconds);
		putText(temp,String_to_show,Point(50,70),FONT_HERSHEY_SIMPLEX,2,Scalar(0,0,255),4,8,false);
		for(Lane=0;Lane<No_Lanes;Lane++){
			sprintf(String_to_show, "Lane %d=%d", Lane+1,Lane_count[Lane]);
			putText(temp,String_to_show,Point(75,70+40*(Lane+1)),FONT_HERSHEY_SIMPLEX,1,Scalar(0,0,255),2,8,false);
		}

		for(Lane=0;Lane<No_Lanes;Lane++){
			sprintf(String_to_show, "%d", Lane+1);
			putText(temp,String_to_show,Point(x_cord[Lane]+w[Lane]/2-17,y_cord[Lane]+h[Lane]/2+20),FONT_HERSHEY_SIMPLEX,1.5,Scalar(255,0,0),4,8,false);
		}
		//rectangle(temp,Point(40,90),Point(440,10),Scalar(0,0,255),5,8,0);
		imshow("Video",temp);
		Video.write(temp);
		
		while(!waitKey(5))
			
		
		flag=false;
		
		
			
	}
	
	//file.close();
	return 0;
}








/* pass to cropped images of same size to function,use Imagename=Imagename(X,Y,Width,Hieght); to crop and 
previous = crrent.clone() to save the previous frame */

bool Ismoving(Mat previous, Mat current)
{
	Mat temp;
	int thresh=8,	//if any R,G,B value in a pixel is changed more that 'thresh' it will be detected
		percentage=12;	//if 'current' image chnaged more than 'percentage'% respect to 'previous' image, funtion will return true
	char window_name[10];

	sprintf(window_name,"Lane_%d",Lane+1);
	namedWindow(window_name,WINDOW_NORMAL);
	int threshold_sum=(previous.cols*previous.rows*3*255*percentage)/100; //6% 
	int sum=0;
	absdiff(previous,current,temp);
	blur(temp,temp,Size(5,5));
	erode(temp,temp,Mat ());
	threshold(temp,temp,thresh,255,CV_THRESH_BINARY);
	imshow(window_name,temp);
	waitKey(1);
	
		
	for(int x=0;x<temp.rows;x++)
		for (int y=0;y<temp.cols;y++)
			sum+=(int)temp.at<Vec3b>(x,y)[0]+	(int)temp.at<Vec3b>(x,y)[1]+	(int)temp.at<Vec3b>(x,y)[2];
		
		
	bool changed=Ischanged(previous,current);



	if(sum>threshold_sum&&changed&&!Moving_flag[Lane])
	{
		cout<<"Moving  ";
		if(!Moving_flag[Lane])
			Show_Avg(current,temp);
		Moving_flag[Lane]=true;
		return true;

	}
	
	else if(sum>threshold_sum&&Moving_flag[Lane])
	{
		cout<<"Moving  ";
		if(!Moving_flag[Lane])
			Show_Avg(current,temp);
		Moving_flag[Lane]=true;
		return true;
	}

	cout<<"Not_Moving  ";

	if(Moving_flag[Lane]){
		Number_Of_Vehicles++;
		Lane_count[Lane]++;
	}

	Moving_flag[Lane]=false;
	return false;


}


bool Ischanged(Mat previous, Mat current)
{
	int Prev_sum=0,
		Cur_sum=0;
	int Percentage_thresh=4;

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

	cout<<percentage<<"\t";

	if(percentage>Percentage_thresh)
		return true;

	return false;

}


/*static void onMouse( int event, int x, int y, int f, void* ){
    cout << x << " " << y << endl;
    //putText(image, "point", Point(x,y), CV_FONT_HERSHEY_PLAIN, 1.0, CV_RGB(255,0,0));
}*/


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
    
		 /*else if  ( event == EVENT_MBUTTONDOWN )
		 {
			  cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
		 }
	 
		 else if  ( event == EVENT_MBUTTONDOWN )
		 {
			  cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
		 }*/
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

void Show_Avg(Mat image,Mat B_image)
{
	
	for(int x=0;x<(image.rows)/5;x++)
		for (int y=0;y<(image.rows)/5;y++){
			Colours[Lane].B=(int)image.at<Vec3b>(x,y)[0];
			Colours[Lane].G=(int)image.at<Vec3b>(x,y)[1];
			Colours[Lane].R=(int)image.at<Vec3b>(x,y)[2];
		}
	cout<< sum<<"   ";
	
	cout<<'\n';
}

