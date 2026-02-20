#include "validity.hpp"

#include "log.hpp"

namespace validity
{
void validate_pixel_diff(const cv::Mat& image_a, const cv::Mat& image_b) {
    if (image_a.size() != image_b.size()) {
        log_error("image size mismatch");
        throw std::runtime_error("Input images must have the same size (resolution).");
    }

    if (image_a.type() != image_b.type()) {
        log_error("image type mismatch");
        throw std::runtime_error("Input images must have the same type (depth & channels).");
    }

    log_debug("pixel_diff validation passed");
}
}
