#ifndef DSP_CONVOLVE_H_
#define DSP_CONVOLVE_H_

#include "types.h"


int DSP_convolve(const float* xh, float* y, size_t N, const float* f, size_t T);

int DSP_convolve_decimate(const float* xh, float* y, size_t N, const float* f, size_t T, size_t D);

#endif // DSP_CONVOLVE_H_