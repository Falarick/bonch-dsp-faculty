#include "types.h"
#include "array/uint8.h"


DSP_array_uint8* DSP_array_uint8_create(size_t* shape, DSP_ARRAY_DIM dim)
{
    DSP_array_uint8* array = malloc(sizeof(DSP_array_uint8));
    
    int ret = DSP_array_create(&(array->info), (void**)&(array->values), shape, dim, DSP_UINT8);
    if (ret < 0)
    {
        return NULL;
    }

    return array;
}

DSP_array_uint8* DSP_array_uint8_from_file(const char* filename)
{
    DSP_array_uint8* array = malloc(sizeof(DSP_array_uint8));
       
    int ret = DSP_array_from_file(&(array->info), (void**)&(array->values), filename);
    if (ret < 0)
    {
        return NULL;
    }

    return array;
}

int DSP_array_uint8_to_file(const DSP_array_uint8* array, const char* filename)
{
    return DSP_array_to_file(&(array->info), array->values, filename);
}

void DSP_array_uint8_delete(DSP_array_uint8* array)
{
    DSP_array_delete(array->values);

    free(array);
}

uint8_t* DSP_array_uint8_at(DSP_array_uint8* array, size_t* index)
{
    return (uint8_t*)DSP_array_at(&(array->info), array->values, index);
}