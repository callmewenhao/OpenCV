#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

#include "../utils/utils.h"

/*
 * 直方图均衡化
 * 自直方图适应均衡化
 */

int main() {

    cv::Mat img = cv::imread("pollen1.tif");
    if (img.empty()) {
        std::cout << "could not find this image!";
        return -1;
    }
    // 进行直方图均衡化
    cv::Mat grey, img_after_equalizeHist;
    //原图可能不是灰度图，这里先转一下
    cv::cvtColor(img, grey, cv::COLOR_BGR2GRAY);
    // 使用灰度图进行直方图均衡化
    cv::equalizeHist(grey, img_after_equalizeHist);
    // 自适应直方图均衡化
    cv::Mat img_after_CLAHE;
    cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE();
    clahe->apply(grey, img_after_CLAHE);

    // 显示
    std::vector<cv::Mat> imags;
    imags.emplace_back(grey);
    imags.emplace_back(img_after_equalizeHist);
    imags.emplace_back(img_after_CLAHE);

    cv::Mat dst;
    utils::multipleImage(imags, dst, 3);
    cv::imshow("img", dst);
    cv::waitKey(0);  // 等待

    return 0;
}
