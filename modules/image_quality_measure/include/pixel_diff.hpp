#pragma once

#include <opencv2/opencv.hpp>

#include "config.hpp"

class PixelDiff
{
   public:
    PixelDiff() = default;

    cv::Mat compare(const cv::Mat& image_a, const cv::Mat& image_b) const;

   private:
    uint8_t m_threshold = PIXEL_DIFF_THRESHOLD;

    cv::Mat compare_GRAY(const cv::Mat& image_a, const cv::Mat& image_b) const;
    cv::Mat compare_RGB(const cv::Mat& image_a, const cv::Mat& image_b) const;
    cv::Mat compare_RGBA(const cv::Mat& image_a, const cv::Mat& image_b) const;
};
