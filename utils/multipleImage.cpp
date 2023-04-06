#include "utils.h"


/**
 * void multipleImage(std::vector<cv::Mat> imgVector, cv::Mat &dst, int imgCols)
 * @param imgVector  图片 vector
 * @param dst        整合后的大图片
 * @param imgCols    列数
 * @note             该函数要求图片类型一致都是灰度或者彩色否则报错👏
 *                   代码来自网络
 */
void utils::multipleImage(std::vector<cv::Mat> imgVector, cv::Mat &dst, int imgCols)  //参数为列
{
    const int MAX_PIXEL = 300;
    // 选择图片最大的一边 将最大的边按比例变为300像素

    int imgNum = imgVector.size();  // 图片个数
    cv::Size imgOriSize = imgVector[0].size();  // 图片大小
    int imgMaxPixel = std::max(imgOriSize.height, imgOriSize.width);  // 行列最大值

    // 获取最大像素变为 MAX_PIXEL 的比例因子  三目运算符 还转了 double
    double prop = imgMaxPixel < MAX_PIXEL ?
                  1. * imgMaxPixel / MAX_PIXEL :
                  1. * MAX_PIXEL / imgMaxPixel;
    cv::Size imgStdSize(imgOriSize.width * prop, imgOriSize.height * prop);  // 窗口显示的标准图像的Size

    cv::Mat imgStd; // 标准图片
    cv::Point2i location(0, 0);  // 坐标点(从0,0开始)
    // 构建窗口大小 通道与imageVector[0]的通道一样
    cv::Mat imgWindow(
            imgStdSize.height * ((imgNum + imgCols - 1) / imgCols), // 行大小 向上取整
            imgStdSize.width * imgCols,  // 列大小
            imgVector[0].type()
    );

    for (int i = 0; i < imgNum; i++) {
        location.x = (i % imgCols) * imgStdSize.width;
        location.y = (i / imgCols) * imgStdSize.height;
        resize(imgVector[i], imgStd, imgStdSize, prop, prop, cv::INTER_LINEAR); //设置为标准大小
        imgStd.copyTo(imgWindow(cv::Rect(location, imgStdSize)));
    }
    dst = imgWindow;
}









