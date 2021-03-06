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

	// 変換前の三点
  	const Point2f src_pt[] = { Point2f(150, 150), Point2f(150, 190), Point2f(190, 200) };
 	// 変換後の三点
 	const Point2f dst_pt[] = { Point2f(100, 100), Point2f(100, 80), Point2f(50, 70) };
  	// これらから，アフィン変換行列を計算
  	const Mat affine_matrix = getAffineTransform(src_pt, dst_pt);

  	std::cout << "affine_matrix=\n" << affine_matrix << std::endl;

  	Mat dst_img;
 	warpAffine(im, dst_img, affine_matrix, im.size());
  
  	// 変換前後の座標を描画
 	line(im, src_pt[0], src_pt[1], Scalar(255,255,0), 2);
  	line(im, src_pt[1], src_pt[2], Scalar(255,255,0), 2);
  	line(im, src_pt[2], src_pt[0], Scalar(255,255,0), 2);
  	line(im, dst_pt[0], dst_pt[1], Scalar(255,0,255), 2);
  	line(im, dst_pt[1], dst_pt[2], Scalar(255,0,255), 2);
  	line(im, dst_pt[2], dst_pt[0], Scalar(255,0,255), 2);

  	namedWindow("src", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
  	namedWindow("dst", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
  	imshow("src", im);
  	imshow("dst", dst_img);
  	waitKey(0);

	return(0);

}
