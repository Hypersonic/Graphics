#pragma once

#include <stdarg.h>
#include <stdio.h>
#include <string>

#define debug(format, args...) DEBUG_REAL(__FILE__, __LINE__, __PRETTY_FUNCTION__, format, ## args)
void DEBUG_REAL(std::string filename, int line, std::string function_name, std::string format, ...) {
  va_list args;
  va_start(args, format);
  fprintf(stderr, "[%s, %i] %s:\n\t", filename.c_str(), line, function_name.c_str());
  vfprintf(stderr, format.c_str(), args);
  va_end(args);
}
