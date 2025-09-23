#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main(int argc, char *argv[])
{
if(argc!=2)
{
cout<<"Usage [Imageviewer  file_name.jpg/png]"<<endl;
return 0;
}
Mat i;
i=imread(argv[1],IMREAD_COLOR);
imshow("Imageviewer - 1.0",i);
waitKey(0);
return 0;
}