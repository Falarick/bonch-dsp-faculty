#include "types.h"
#include "array/float32.h"


DSP_array_float32* DSP_array_float32_create(size_t* shape, DSP_ARRAY_DIM dim)
{
    DSP_array_float32* array = malloc(sizeof(DSP_array_float32));
    
    int ret = DSP_array_create(&(array->info), (void**)&(array->values), shape, dim, DSP_FLOAT32);
    if (ret < 0)
    {
        return NULL;
    }

    return array;
}

DSP_array_float32* DSP_array_float32_from_file(const char* filename)
{
    DSP_array_float32* array = malloc(sizeof(DSP_array_float32));
       
    int ret = DSP_array_from_file(&(array->info), (void**)&(array->values), filename);
    if (ret < 0)
    {
        return NULL;
    }

    return array;
}

int DSP_array_float32_to_file(const DSP_array_float32* array, const char* filename)
{
    return DSP_array_to_file(&(array->info), array->values, filename);
}

void DSP_array_float32_delete(DSP_array_float32* array)
{
    DSP_array_delete(array->values);

    free(array);
}

float* DSP_array_float32_at(DSP_array_float32* array, size_t* index)
{
    return (float*)DSP_array_at(&(array->info), array->values, index);
}