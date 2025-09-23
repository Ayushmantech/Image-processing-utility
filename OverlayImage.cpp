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
cout<<"Usage : [OverlayImage  image_file.jpg/png  overlay_image.jpg/png   topX  topY]"<<endl;
return 0;
}
int topX=atoi(argv[3]);
int topY=atoi(argv[4]);
Mat m=imread(argv[1], IMREAD_COLOR);
if(!m.data)
{
cout<<"Unable to load "<<argv[1]<<endl;
return 0;
}
Mat overlayImage=imread(argv[2], IMREAD_COLOR);
if(!overlayImage.data)
{
cout<<"Unable to load "<<argv[2]<<endl;
return 0;
}
if(topX<0 || topX>m.cols)
{
cout<<"Invalid topX"<<endl;
return 0;
}
if(topY<0 || topY>m.rows)
{
cout<<"Invalid topY"<<endl;
return 0;
}
if(topX+overlayImage.cols>=m.cols)
{
cout<<"Invalid topX, overlay image overflows"<<endl;
return 0;
}
if(topY+overlayImage.rows>=m.rows)
{
cout<<"Invalid topY, overlay image overflows"<<endl;
return 0;
}
Mat portion=m(Rect(topX, topY, overlayImage.cols,overlayImage.rows));
overlayImage.copyTo(portion);
imshow("Image Processing studio 1.0",m);
waitKey(0);
return 0;
}