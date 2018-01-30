#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


using namespace cv;
using namespace std;
int
main(int argc, char **argv)
{
	Mat img = imread(argv[1],1);	
	if(img.empty()) return -1;

	float angle = 0.0, scale = 0.5;

	//画像の中心
	Point2f center(img.cols*1/2, img.rows*0.5);
	
	cout << "center:" << center << endl;
	Mat affine_matrix = cv::getRotationMatrix2D(center, angle, scale);

	cout << "affin_matrix" << affine_matrix << std::endl;

	Mat after;
	warpAffine(img, after, affine_matrix, img.size());

	cv::namedWindow("src", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
  	cv::namedWindow("dst", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
  	cv::imshow("src", img);
 	cv::imshow("dst", after);
  	cv::waitKey(0);	


	return(0);
}
