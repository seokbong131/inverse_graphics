#pragma once

#include <opencv2/opencv.hpp>

namespace validity
{
void validate_pixel_diff(const cv::Mat& image_a, const cv::Mat& image_b);
}
