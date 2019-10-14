#include <stdio.h>
#include <string.h>

#include "array/common.h"


int DSP_array_create(DSP_array_info* info, void** values, size_t* shape, DSP_ARRAY_DIM dim, 
                     DSP_DATA_TYPE type)
{
    info->type = type;
    info->dim = dim;

    info->length = 1;
    for (size_t i = 0; i < DSP_SHAPE_SIZE; ++i)
    {
        if (i < dim)
        {
            info->shape[i] = shape[i];
        }
        else
        {
            info->shape[i] = 1;
        }

        info->length *= info->shape[i];
    }
    info->bytes = DSP_sizeof(type) * info->length;

    (*values) = malloc(info->bytes);
    if ((*values) == NULL)
    {
        return -1;
    }
    memset((*values), 0, info->bytes);

    return 0;
}

int DSP_array_from_file(DSP_array_info* info, void** values, const char* filename)
{
    FILE* file = fopen(filename, "rb");
    if (file == NULL)
    {
        return -1;
    }

    fread(&(info->type), sizeof(info->type), 1, file);
    fread(&(info->dim),  sizeof(info->dim),  1, file);
    info->length = 1;
    for (size_t i = 0; i < info->dim; ++i)
    {
        fread(info->shape + i, sizeof(info->shape[i]), 1, file);
        info->length *= info->shape[i];
    }
    info->bytes = info->length * DSP_sizeof(info->type);

    (*values) = malloc(info->bytes);
    if ((*values) == NULL)
    {
        return -1;
    }
    fread((*values), DSP_sizeof(info->type), info->length, file);

    return 0;
}

int DSP_array_to_file(const DSP_array_info* info, const void* values, const char* filename)
{
    FILE* file = fopen(filename, "wb");
    if (file == NULL)
    {
        return -1;
    }

    fwrite(&(info->type), sizeof(info->type), 1, file);
    fwrite(&(info->dim),  sizeof(info->dim),  1, file);
    for (size_t i = 0; i < info->dim; ++i)
    {
        fwrite(info->shape + i, sizeof(info->shape[i]), 1, file);
    }
    
    fwrite(values, DSP_sizeof(info->type), info->length, file);
 }

void DSP_array_delete(void* values)
{
    if (values != NULL)
    {
        free(values);
    }
}

static inline size_t DSP_flat_index(const DSP_array_info* info, size_t* index)
{
    switch (info->dim)
    {
        case DSP_ARRAY_DIM_ONE:
        {
            return index[0];
        }
        case DSP_ARRAY_DIM_TWO:
        {
            return info->shape[1] * index[0] + index[1];
        }
        case DSP_ARRAY_DIM_THREE:
        {
            return info->shape[1] * info->shape[2] * index[0] + 
                   info->shape[2] * index[1] + index[2];
        }
    }
}

void* DSP_array_at(DSP_array_info* info, void* values, size_t* index)
{
    uint8_t* bytes = (uint8_t*)values;
    return (void*)(bytes + DSP_sizeof(info->type) * DSP_flat_index(info, index));
}