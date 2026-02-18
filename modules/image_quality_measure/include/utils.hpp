#pragma once

#include <opencv2/opencv.hpp>

cv::Vec4b to_vec4b(const cv::Vec3b& color, uchar alpha = 255);
