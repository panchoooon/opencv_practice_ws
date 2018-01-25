#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;

int main(int argc, char* argv[])
{

    Mat im = imread("../images/makibao.png");		/* 画像の取得 */
    Mat hsv, lab, ycr;
    if(!im.data) return -1;			/* エラー処理 */

    std::cout <<" Usage: display_image ImageToLoadAndDisplay" << std::endl;

    Mat roi(im, Rect(90, 0, 150, 130));	/*トリミング */
    /* 結果表示 */
    imshow("Original", im);
    imshow("ROI", roi);
    waitKey(0);						/* 入力待機 */
    
    return 0;

}
