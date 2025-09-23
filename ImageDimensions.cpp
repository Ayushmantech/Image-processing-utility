#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main(int argc, char *argv[])
{
if(argc!=2)
{
cout<<"Usage : [ImageDimensions  Image_file.png/jpg]"<<endl;
return 0;
}
Mat m;
m=imread(argv[1], 	IMREAD_COLOR);
int width=m.cols;
int height=m.rows;
cout<<"Dimensions of "<<argv[1]<<" are as follows"<<endl;
cout<<"Width is : "<<width<<" Pixels"<<endl;
cout<<"Height is : "<<height <<" Pixels"<<endl;
return 0;
}