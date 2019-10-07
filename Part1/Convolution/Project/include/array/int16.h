/*!
 * \file int16.h
 * \author Дмитрий Караваев
 */
#ifndef DSP_ARRAY_INT16_H_
#define DSP_ARRAY_INT16_H_

#include "../types.h"
#include "../array/common.h"


/*!
 * \struct DSP_array_info
 * \brief Метаданные для массива, содержащего любые значения.
 */
typedef struct DSP_array_int16
{
    DSP_array_info info;   ///< Метаданные.
    int16_t*       values; ///< Значения. 
} DSP_array_int16;

/*!
 * Создать массив c заданными параметрами.
 * \param[in] shape - размерность.
 * \param[in] dim - число измерений.
 * \return !NULL - успех, NULL неудача. 
 */
DSP_array_int16* DSP_array_int16_create(size_t* shape, DSP_ARRAY_DIM dim);
/*!
 * Создать массив из бинарного файла.
 * \param[out] info - метаданные массива.
 * \param[out] values - значение.
 * \param[in]  filename - имя файла.
 * \return 0 - успех, < 0 неудача. 
 */
DSP_array_int16* DSP_array_int16_from_file(const char* filename);
/*!
 * Сохранить массив в бинарный файл.
 * \param[in] array - массив.
 * \param[in] filename - имя файла.
 * \return 0 - успех, < 0 неудача. 
 */
int DSP_array_int16_to_file(const DSP_array_int16* array, const char* filename);
/*!
 * Удалить массив.
 * \param[in] array - массив.
 */
void DSP_array_int16_delete(DSP_array_int16* array);
/*!
 * Получить указатель на элемент массива по индексу.
 * \param[in] info - метаданные массива.
 * \param[in] values - элементы массива.
 * \param[in] index - индекс элемента.
 * \return В случае успеха - ненулевой указатель, в противном случае нулевой указатель.
 * \warning Число элементов в index должно быть равным info->dim.
 */
int16_t* DSP_array_int16_at(DSP_array_int16* array, size_t* index);

#endif // DSP_ARRAY_INT16_H_