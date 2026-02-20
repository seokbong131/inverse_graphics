#pragma once

#include <filesystem>

#include <opencv2/opencv.hpp>

using namespace std;

namespace image_io
{
// folder path + file name + file extension
filesystem::path join_path(string_view folder_path,
                           string_view file_name,
                           string_view file_extension);
cv::Mat          load(const filesystem::path& img_path, int flag = cv::IMREAD_COLOR);
bool             save(const filesystem::path& img_path, const cv::Mat& img);
}
