#pragma once

#include <opencv2/opencv.hpp>

namespace iqm_config::color
{
// attention, BGR order
// clang-format off
const cv::Vec3b BLACK   = {   0,   0,   0 };
const cv::Vec3b GRAY    = { 127, 127, 127 };
const cv::Vec3b RED     = {   0,   0, 255 };
const cv::Vec3b GREEN   = {   0, 255,   0 };
const cv::Vec3b BLUE    = { 255,   0,   0 };
const cv::Vec3b CYAN    = { 255, 255,   0 };
const cv::Vec3b MAGENTA = { 255,   0, 255 };
const cv::Vec3b YELLOW  = {   0, 255, 255 };
const cv::Vec3b WHITE   = { 255, 255, 255 };
// clang-format on
}

namespace iqm_config::io
{
// filename extension
constexpr const char* FILE_EXTENSION = "png";

// I/O folder path
constexpr const char* INPUT_FOLDER  = "input";
constexpr const char* OUTPUT_FOLDER = "output";

// input file name
constexpr const char* INPUT_FILE_BEFORE = "before";
constexpr const char* INPUT_FILE_AFTER  = "after";

// output file name
constexpr const char* OUTPUT_FILE = "diff";
}

constexpr const uint8_t PIXEL_DIFF_THRESHOLD = 0;
