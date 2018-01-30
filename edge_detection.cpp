#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>//imshowなど
#include <opencv2/imgproc/imgproc.hpp> //resizeなど

using namespace cv;

int
main(int argc, char  *argv[])
{
	//display makibao original
	Mat im;
	im = imread(argv[1],1);
	//imshow("original",im);
	waitKey(1000);
/*
	//display Gream Image
	Mat im2(Size(300,600), CV_8UC3, Scalar(0,100,0));
	imshow("my_grean_image",im2);
	waitKey(1000);
*/
/*	//display triming makibao
	int x, y, width, height;
	x = im.cols/2.0; //真ん中を基準にする
	y = im.rows/2.5; 
	width = 100;
	height = 100;
	Mat roi(im, Rect(x, y, width, height)); //左上の原点からx,yの位置を基準に 幅width, 高さheight
	imshow("triming",roi);
	waitKey(1000);
*/
/*	
	//Resize
	Mat big, small;

	resize(im, big, Size(), 3,3);
	resize(im, small,Size(), 0.5,0.5);
	//imshow("big",big);
	//imshow("small",small);
	waitKey(1000);
*/
	//RGBそれぞれに分解し、sobelを用いたエッジ検出を行う
	Mat sobel_x, sobel_y;
	Mat sobel, sobel_r, sobel_g, sobel_b, sobel2;
	Mat channels[3];	
	split(im, channels);
	//red
	Sobel(channels[2], sobel_x,CV_32F,1,0);
	Sobel(channels[2], sobel_y,CV_32F,0,1);
	sobel_r = (abs(sobel_x) + abs(sobel_y))/2.0;
	//grean
	Sobel(channels[1], sobel_x,CV_32F,1,0);
	Sobel(channels[1], sobel_y,CV_32F,0,1);
	sobel_g = (abs(sobel_x) + abs(sobel_y))/2.0;
	//blue
	Sobel(channels[0], sobel_x,CV_32F,1,0);
	Sobel(channels[0], sobel_y,CV_32F,0,1);
	sobel_b = (abs(sobel_x) + abs(sobel_y))/2.0;
	//r,g,bの最大値を採用する
	sobel = max(max(sobel_r,sobel_g),sobel_b);
	threshold(sobel, sobel2, 180, 255, THRESH_BINARY_INV);
	namedWindow("makibao-cute");
	imwrite("makibao2-cute.jpg", sobel2);
	imshow("RGB-split_sobel",sobel2);
	waitKey(0);

	destroyAllWindows();

	

	return(0);

}
