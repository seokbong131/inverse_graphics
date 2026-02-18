#include "utils.hpp"

cv::Vec4b to_vec4b(const cv::Vec3b& color, uchar alpha) {
	return cv::Vec4b(color[0], color[1], color[2], alpha);
}
