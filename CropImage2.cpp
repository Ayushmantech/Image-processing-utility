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
cout<<"Usage : [CropImage2  Image_file.jpg/png   width  height  Image_file2.jpg]"<<endl;
return 0;
}
int width=atoi(argv[2]);
int height=atoi(argv[3]);

Mat m;
m=imread(argv[1]);
int centerX=m.cols/2;
int centerY=m.rows/2;
int topX=centerX-(width/2);
int topY=centerY-(height/2);
if(topX<0) topX=0;
if(topY<0)topY=0;
if(topX+width>=m.cols)
{
cout<<"Invalid width"<<endl;
return 0;
}
if(topY+height>=m.rows)
{
cout<<"Invalid height"<<endl;
return 0;
}
Rect r;
r.x=topX;
r.y=topY;
r.width=width;
r.height=height;
Mat croppedImage=m(r);
imwrite(argv[4], croppedImage);
cout<<"Cropper Image has been generated"<<endl;
waitKey(0);
return 0;
}