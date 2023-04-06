//
// Created by wenhao on 2023/4/4.
//
#pragma once
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

namespace utils {
    void multipleImage(std::vector<cv::Mat>, cv::Mat &, int);  // 合并图片
}
