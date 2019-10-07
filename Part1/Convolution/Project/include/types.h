/*!
 * \file types.h
 * \author Дмитрий Караваев
 */
#ifndef DSP_TYPES_H_
#define DSP_TYPES_H_

#include <stdlib.h>
#include <stdint.h>

/// Типы отсчётов
typedef enum DSP_DATA_TYPE
{
    DSP_UINT8   = 0, ///< int8_t
    DSP_INT16   = 1, ///< int16_t
    DSP_INT32   = 2, ///< int32_t
    DSP_FLOAT32 = 3, ///< float
    DSP_FLOAT64 = 4  ///< double
} DSP_DATA_TYPE;

/*!
 * Узнать число байт в типе ("перегрузка" sizeof).
 * \param[in] type - тип.
 * \return Число байт требуемое для хранения заданного типа.
 */
static inline size_t DSP_sizeof(DSP_DATA_TYPE type)
{
    switch (type)
    {
        case DSP_UINT8:
        {
            return sizeof(uint8_t);
        }
        case DSP_INT16:
        {
            return sizeof(int16_t);
        }
        case DSP_INT32:
        {
            return sizeof(int16_t);
        }
        case DSP_FLOAT32:
        {
            return sizeof(float);
        }
        case DSP_FLOAT64:
        {
            return sizeof(double);
        }
    }

    return 0;
}

#endif // DSP_TYPES_H_