//following code is used to crop the image
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<stdlib.h>
using namespace cv;
using namespace std;
int main(int argc, char *argv[])
{
if(argc!=7)
{
cout<<"Usage : [CropImage  Image_file.jpg/png  topX  topY  width  height  Image_file2.jpg]"<<endl;
return 0;
}
int topX=atoi(argv[2]);
int topY=atoi(argv[3]);
int width=atoi(argv[4]);
int height=atoi(argv[5]);
Mat m;
m=imread(argv[1]);
if(topX<0 || topX>=m.cols)
{
cout<<"Invalid topX"<<endl;
return 0;
}
if(topY<0 || topY>=m.rows)
{
cout<<"Invalid topY"<<endl;
return 0;
}
if(width>=topX+m.cols)
{
cout<<"Invalid width"<<endl;
return 0;
}
if(height>=topY+m.rows)
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
imwrite(argv[6], croppedImage);
cout<<"Cropper image has been generated"<<endl;
waitKey(0);
return 0;
}