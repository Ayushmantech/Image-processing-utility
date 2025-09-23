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
cout<<"Usage : [ResizeImagePercent   image_file.jpg/png   Percentage   image_file2.jpg/png ]"<<endl;
return 0;
}
int percentage=atoi(argv[2]);
Mat m=imread(argv[1]);
int width=(m.cols*percentage)/100;
int height=(m.rows*percentage)/100;
Mat resizedImage;
resize(m, resizedImage, Size(width, height), INTER_LINEAR);
imwrite(argv[3], resizedImage);
cout<<"Resized Image has been generated"<<endl;
waitKey(0);
return 0;
}