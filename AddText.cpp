#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<stdlib.h>
using namespace cv;
using namespace std;
int main(int argc, char *argv[])
{
if(argc!=5)
{
cout<<"Usage : [AddText   image_file.jpg/png   Text  x  y]"<<endl;
return 0;
}
Mat  m;
m=imread(argv[1]);
if(!m.data)
{
cout<<"Unable to load"<<argv[1]<<endl;
return 0;
}
int x=atoi(argv[3]);
int y=atoi(argv[4]);
// atoi means alphanumeric to integer 
if(x>m.cols || y>m.rows || x<0 || y<0)
{
cout<<"Invalid xy"<<endl;
return 0;
}
int fontSize=2;
auto color=CV_RGB(255,120,101);
int fontweight=10;
putText(m,argv[2],Point(x,y),FONT_HERSHEY_SIMPLEX, fontSize, color, fontweight);
imshow("Image Processing Studio 1.0",m);
waitKey(0);
return 0;
}