#include "image_io.hpp"
#include "log.hpp"

namespace image_io
{
    filesystem::path join_path(
        string_view folder_path,
        string_view file_name,
        string_view file_extension
    ) {
        if (folder_path.empty()) {
            throw runtime_error("Folder path is empty. (config.hpp)");
        }
        if (file_name.empty()) {
            throw runtime_error("File name is empty. (config.hpp)");
        }
        if (file_extension.empty()) {
            throw runtime_error("File extension is empty. (config.hpp)");
        }
        
        return (filesystem::path(folder_path) / file_name).replace_extension(file_extension);
    }

    cv::Mat load(const filesystem::path& img_path, int flag) {
        cv::Mat image = cv::imread(img_path.string(), flag);
        if (image.empty()) {
            throw runtime_error("Empty image can't be read. -> " + img_path.string());
        }

        log_debug(img_path.filename().string() + " image loaded");
        log_info(img_path.filename().string() + ":");
        log_info("    - size: " + to_string(image.cols) + " x " + to_string(image.rows));
        log_info("    - depth: " + to_string(image.depth()));
        log_info("    - channels: " + to_string(image.channels()));
        log_info("    - type: " + to_data_type(image.type()));
        return image;
    }

    bool save(const filesystem::path& img_path, const cv::Mat& img) {
        if (img.empty()) {
            log_error("empty image can't be saved");
            return false;
        }

        filesystem::path folder_path = img_path.parent_path();

        if (filesystem::exists(folder_path) == false) {
            try {
                filesystem::create_directories(folder_path);
                log_info(folder_path.filename().string() + " folder created");
            }
            catch (const filesystem::filesystem_error& e) {
                log_error(string("failed to create directory: ") + e.what());
                return false;
            }
        }

        return cv::imwrite(img_path.string(), img);
    }
}
