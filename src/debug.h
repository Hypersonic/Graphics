#pragma once

#include <stdarg.h>
#include <stdio.h>
#include <string>

#define debug(...) DEBUG_REAL(__FILE__, __LINE__, __PRETTY_FUNCTION__, __VA_ARGS__)
void DEBUG_REAL(std::string filename, int line, std::string function_name, std::string format, ...);
