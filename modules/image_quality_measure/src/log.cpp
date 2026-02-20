#include "log.hpp"

#include <iostream>

#include <opencv2/opencv.hpp>

void log_debug(const string& msg) { cout << "[DEBUG] " << msg << endl; }
void log_error(const string& msg) { cerr << "[ERROR] " << msg << endl; }
void log_info(const string& msg) { cout << "[INFO] " << msg << endl; }
void log_warning(const string& msg) { cout << "[WARNING] " << msg << endl; }

string to_data_type(int macro_constant) {
    string type;

    /*
    CV_8U     | 8-bit unsigned integers          | [ 0 ... 255 ]
    CV_8S     | 8-bit signed integers            | [ -128 ... 127 ]
    CV_16U    | 16-bit unsigned integers         | [ 0 ... 65535 ]
    CV_16S    | 16-bit signed integers           | [ -32768 ... 32767 ]
    CV_32S    | 32-bit signed integers           | [ -2147483648 ... 2147483647 ]
    CV_32F    | 32-bit floating-point numbers    | ( -FLT_MAX ... FLT_MAX, INF, NAN )
    CV_64F    | 64-bit floating-point numbers    | ( -DBL_MAX ... DBL_MAX, INF, NAN )
    */
    // depth -> string
    int depth = macro_constant & CV_MAT_DEPTH_MASK;
    switch (depth) {
            // clang-format off
        case CV_8U:  type = "CV_8U";  break;
        case CV_8S:  type = "CV_8S";  break;
        case CV_16U: type = "CV_16U"; break;
        case CV_16S: type = "CV_16S"; break;
        case CV_32S: type = "CV_32S"; break;
        case CV_32F: type = "CV_32F"; break;
        case CV_64F: type = "CV_64F"; break;
        case CV_16F: type = "CV_16F"; break;
        default:     type = "None_";  break;
            // clang-format on
    }

    // channels -> string
    int channels = 1 + (macro_constant >> CV_CN_SHIFT);
    type += "C" + to_string(channels);

    return type;
}
