#pragma once

#include <string>

using namespace std;

void log_debug(const string& msg);
void log_error(const string& msg);
void log_info(const string& msg);
void log_warning(const string& msg);

string to_data_type(int macro_constant);
