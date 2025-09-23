#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<stdlib.h>
using namespace std;
using namespace cv;
int main(int argc, char *argv[])
{
if(argc!=4)
{
cout<<"Usage : [ResizeImage  image_file.jpg/png  width  height]"<<endl;
return 0;
}
Mat m;
m=imread(argv[1]);
int width=atoi(argv[2]);
int height=atoi(argv[3]);
Mat resizedImage;
resize(m, resizedImage, Size(width, height), INTER_LINEAR);
imshow("Image Processing Studio 1.0", resizedImage);
waitKey(0);
return 0;
}