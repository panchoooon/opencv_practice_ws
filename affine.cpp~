#include <iostream>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

const char* WINDOW_NAME = "Affine Transform Demo";
Mat img, tmp;
Point2f srcTri[3], dstTri[3];
int ptr = 0;
Scalar circleColors[] = {
    Scalar(255, 0, 0),
    Scalar(0, 255, 0),
    Scalar(0, 0, 255)
};

void applyAfineTransform() {

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Affine Transform begin." << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << srcTri[i] << " is mapped to " << dstTri[i] << std::endl;
    }

    /// Get Affine matrix from mapping info
    Mat affine_mat = getAffineTransform(srcTri, dstTri);

    /// Apply Affine transform
    warpAffine(img, img, affine_mat, img.size());
        
    tmp = img.clone();
    imshow(WINDOW_NAME, img);

    std::cout << "Affine Transform end." << std::endl << std::endl;

}

void mouseClick(int event, int x, int y, int flags, void* userdata) {

    if (event != EVENT_LBUTTONDOWN) 
        return;

    Point2f point(x, y);
    
    if (ptr % 2 == 0)
        srcTri[ptr/2] = point;
    else
        dstTri[ptr/2] = point;

    circle(tmp, point, 6, circleColors[ptr/2], -1, 8, 0);
    imshow(WINDOW_NAME, tmp);

    if (++ptr >= 6) {
        ptr = 0;
        applyAfineTransform();
    }

}

int main( int, char** argv ) {

    img = imread(argv[1], 1);
    tmp = img.clone();

    namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);
    setMouseCallback(WINDOW_NAME, mouseClick, NULL);
    imshow(WINDOW_NAME, img);

    waitKey(0);

    return 0;
}
