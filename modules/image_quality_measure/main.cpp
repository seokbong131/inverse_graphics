#include "image_io.hpp"
#include "log.hpp"
#include "pixel_diff.hpp"
#include "validity.hpp"

using namespace iqm_config::io;

int main(int argc, char** argv) {
    filesystem::path input_before_path = image_io::join_path(INPUT_FOLDER, INPUT_FILE_BEFORE, FILE_EXTENSION);
    filesystem::path input_after_path = image_io::join_path(INPUT_FOLDER, INPUT_FILE_AFTER, FILE_EXTENSION);
    filesystem::path output_path = image_io::join_path(OUTPUT_FOLDER, OUTPUT_FILE, FILE_EXTENSION);

    try {
        // Load
        cv::Mat before_img = image_io::load(input_before_path);
        cv::Mat after_img = image_io::load(input_after_path);

        // Validate
        validity::validate_pixel_diff(before_img, after_img);

        // Compare
        PixelDiff pixel_diff;
        cv::Mat result = pixel_diff.compare(before_img, after_img);

        // Save
        if (image_io::save(output_path, result)) {
            log_debug("output image saved");
        }
        else {
            log_error("failed to save image");
            return EXIT_FAILURE;
        }
    }
    catch (const exception& e) {
        log_error(e.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
