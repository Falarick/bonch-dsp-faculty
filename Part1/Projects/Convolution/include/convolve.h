#ifndef DSP_CONVOLVE_H_
#define DSP_CONVOLVE_H_

#include "types.h"


int DSP_convolve(const float* xh, float* y, size_t N, 
                 const float* h, size_t T);

int DSP_convolve_decimate(const float* xh, float* y, size_t N, 
                          const float* h, size_t T, size_t D);

int DSP_convolve_complex_int(const int16_t* xh, int16_t* y, size_t N, 
                             const int16_t* h,  size_t T);

int DSP_convolve_2D(const uint8_t** x, uint8_t** y, size_t Nh, size_t Nw, 
                    const int8_t**  h, size_t Th,   size_t Tw);

#endif // DSP_CONVOLVE_H_