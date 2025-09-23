#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<stdlib.h>
using namespace cv;
using namespace std;
int main(int argc, char *argv[])
{
if(argc!=3)
{
cout<<"Usage : [BlurImage   Image_file1.jpg/png   kernel_size(1-50) ]"<<endl;
return 0;
}
int kernelSize=atoi(argv[2]);
Mat m;
m=imread(argv[1], IMREAD_COLOR);
Mat blurImage;
//applying blur filter:
blur(m,blurImage,Size(kernelSize, kernelSize));
cout<<" Blurred image is generated "<<endl;
imshow("ImageViewer 1.0",blurImage);
waitKey(0);
return 0;
}

