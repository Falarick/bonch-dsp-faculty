/*!
 * \file common.h
 * \author Дмитрий Караваев
 */
#ifndef DSP_ARRAY_COMMON_H_
#define DSP_ARRAY_COMMON_H_

#include <stdlib.h>
#include <stdint.h>

#include "../types.h"


/// Возможные измерения для массива
typedef enum DSP_ARRAY_DIM
{
    DSP_ARRAY_DIM_ONE   = 1, // Одно.
    DSP_ARRAY_DIM_TWO   = 2, // Два.
    DSP_ARRAY_DIM_THREE = 3, // Три.
} DSP_ARRAY_DIM;

#define DSP_SHAPE_SIZE DSP_ARRAY_DIM_THREE

/*!
 * \struct DSP_array_info
 * \brief Метаданные для массива, содержащего любые значения.
 */
typedef struct DSP_array_info
{
    DSP_DATA_TYPE type;                  ///< Тип значений.
    DSP_ARRAY_DIM dim;                   ///< Число измерений.
    size_t        shape[DSP_SHAPE_SIZE]; ///< Размерность.
    size_t        length;                ///< Длинна (линейная).
    size_t        bytes;                 ///< Число байт.
} DSP_array_info;

/*!
 * Создать массив c заданными параметрами.
 * \param[out] info - метаданные массива.
 * \param[out] values - элементы массива.
 * \param[in]  shape - размерность.
 * \param[in]  dim - число измерений.
 * \return 0 - успех, < 0 неудача. 
 */
int DSP_array_create(DSP_array_info* info, void** values, size_t* shape, DSP_ARRAY_DIM dim, 
                     DSP_DATA_TYPE type);
/*!
 * Создать массив из бинарного файла.
 * \param[out] info - метаданные массива.
 * \param[out] values - элементы массива.
 * \param[in]  filename - имя файла.
 * \return 0 - успех, < 0 неудача. 
 */
int DSP_array_from_file(DSP_array_info* info, void** values, const char* filename);
/*!
 * Сохранить массив в бинарный файл.
 * \param[in] info - метаданные массива.
 * \param[in] values - элементы массива.
 * \param[in] filename - имя файла.
 * \return 0 - успех, < 0 неудача. 
 */
int DSP_array_to_file(const DSP_array_info* info, const void* values, const char* filename);
/*!
 * Удалить массив.
 * \param[in] info - метаданные массива.
 * \param[in] values - элементы массива.
 */
void DSP_array_delete(void* values);
/*!
 * Получить указатель на элемент массива по индексу.
 * \param[in] info - метаданные массива.
 * \param[in] values - элементы массива.
 * \param[in] index - индекс элемента.
 * \return В случае успеха - ненулевой указатель, в противном случае нулевой указатель.
 * \warning Число элементов в index должно быть равным info->dim.
 */
void* DSP_array_at(DSP_array_info* info, void* values, size_t* index);

#endif // DSP_ARRAY_COMMON_H_