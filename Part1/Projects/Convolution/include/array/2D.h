#ifndef DSP_ARRAY_2D_H_
#define DSP_ARRAY_2D_H_

#include <stdint.h>
#include <stdlib.h>
#include <string.h>


uint8_t** DSP_linear22D_uint8(const uint8_t* linear, size_t H, size_t W)
{
    uint8_t** result = (uint8_t**)malloc(sizeof(uint8_t*) * H);
    for (size_t i = 0; i < H; ++i)
    {
        result[i] = (uint8_t*)malloc(sizeof(uint8_t) * W);
        memcpy(result[i], linear + (i * W), sizeof(uint8_t) * W);
    }

    return result;
}


int8_t** DSP_linear22D_int8(const int8_t* linear, size_t H, size_t W)
{
    int8_t** result = (int8_t**)malloc(sizeof(int8_t*) * H);
    for (size_t i = 0; i < H; ++i)
    {
        result[i] = (int8_t*)malloc(sizeof(int8_t) * W);
        memcpy(result[i], linear + (i * W), sizeof(int8_t) * W);
    }

    return result;
}

uint8_t* DSP_2D2linear_uint8(const uint8_t** TD, size_t H, size_t W)
{
    uint8_t* result = (uint8_t*)malloc(sizeof(uint8_t) * H * W);
    for (size_t i = 0; i < H; ++i)
    {
        memcpy(result + (i * W), TD[i], sizeof(uint8_t) * W);
    }

    return result;
}

int8_t* DSP_2D2linear_int8(const int8_t** TD, size_t H, size_t W)
{
    int8_t* result = (int8_t*)malloc(sizeof(int8_t) * H * W);
    for (size_t i = 0; i < H; ++i)
    {
        memcpy(result + (i * W), TD[i], sizeof(int8_t) * W);
    }

    return result;
}

void DSP_free2D_uint8(uint8_t** array, size_t H, size_t W)
{
    for (size_t i = 0; i < H; ++i)
    {
        free(array[i]);
    }

    free(array);
}

void DSP_free2D_int8(int8_t** array, size_t H, size_t W)
{
    for (size_t i = 0; i < H; ++i)
    {
        free(array[i]);
    }

    free(array);
}

#endif // DSP_ARRAY_2D_H_