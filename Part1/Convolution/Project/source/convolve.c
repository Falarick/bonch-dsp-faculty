#include "convolve.h"


int DSP_convolve(const float* xh, float* y, size_t N, const float* f, size_t T)
{
    const float* x = xh + (T - 1);

    for (size_t n = 0; n < N; ++n)
    {
        y[n] = 0.0;
        for (size_t k = 0; k < T; ++k)
        {
            y[n] += f[k] * x[n - k]; 
        }
    }

    return 0;
}


int DSP_convolve_decimate(const float* xh, float* y, size_t N, const float* f, size_t T, size_t D)
{
    const float* x = xh + (T - 1);

    for (size_t n = 0; n < N; n += D)
    {
        float value = 0.0;
        for (size_t k = 0; k < T; ++k)
        {
            value += f[k] * x[n - k]; 
        }
        y[n / D] = value;
    }

    return 0;
}