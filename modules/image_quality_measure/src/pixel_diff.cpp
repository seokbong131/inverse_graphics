#include "pixel_diff.hpp"

#include "log.hpp"
#include "utils.hpp"

using namespace iqm_config::color;

cv::Mat PixelDiff::compare(const cv::Mat& image_a, const cv::Mat& image_b) const {
    switch (image_b.channels()) {
            // clang-format off
        case 1:  return compare_GRAY(image_a, image_b);
        case 3:  return compare_RGB(image_a, image_b);
        case 4:  return compare_RGBA(image_a, image_b);
        default: throw std::runtime_error("Need to check the number of channels.");
            // clang-format on
    }
}

cv::Mat PixelDiff::compare_GRAY(const cv::Mat& image_a, const cv::Mat& image_b) const {
    cv::Mat dst;
    cv::absdiff(image_a, image_b, dst);

    cv::Mat diff;
    cv::compare(dst, m_threshold, diff, cv::CMP_GT);

    cv::Mat result(dst.size(), dst.type(), 0);
    result.setTo(255, diff);

    log_debug("GRAY pixel_diff comparison completed");
    return result;
}

cv::Mat PixelDiff::compare_RGB(const cv::Mat& image_a, const cv::Mat& image_b) const {
    cv::Mat dst;
    cv::absdiff(image_a, image_b, dst);

    cv::Mat gray;
    cv::cvtColor(dst, gray, cv::COLOR_BGR2GRAY);

    cv::Mat diff;
    cv::compare(gray, m_threshold, diff, cv::CMP_GT);

    cv::Mat result(dst.size(), dst.type(), BLACK);
    result.setTo(YELLOW, diff);

    log_debug("RGB pixel_diff comparison completed");
    return result;
}

cv::Mat PixelDiff::compare_RGBA(const cv::Mat& image_a, const cv::Mat& image_b) const {
    cv::Mat dst;
    cv::absdiff(image_a, image_b, dst);

    cv::Mat gray;
    cv::cvtColor(dst, gray, cv::COLOR_BGRA2GRAY);

    cv::Mat diff;
    cv::compare(gray, m_threshold, diff, cv::CMP_GT);

    cv::Mat result(dst.size(), dst.type(), to_vec4b(BLACK));
    result.setTo(to_vec4b(YELLOW), diff);

    log_debug("RGBA pixel_diff comparison completed");
    return result;
}
