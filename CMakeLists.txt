cmake_minimum_required(VERSION 3.23)
project(OpenCVProj)

set(CMAKE_CXX_STANDARD 20)

set(OpenCV_DIR D:/opencv/opencv-4.7.0/build_mingw64/install)
find_package(OpenCV REQUIRED)
#set(OpenCV_FOUND 1)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(OpenCVProj "equalizeHist and CLAHE/main.cpp" utils/multipleImage.cpp utils/utils.h)

target_link_libraries(OpenCVProj ${OpenCV_LIBS})
