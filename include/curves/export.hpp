#pragma once

#if defined(_WIN32) || defined(_WIN64)
  #if defined(CURVES_EXPORTS)
    #define CURVES_API __declspec(dllexport)
  #else
    #define CURVES_API __declspec(dllimport)
  #endif
#else
  #define CURVES_API
#endif