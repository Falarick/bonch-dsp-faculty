/*!
 * \file uint8.h
 * \author Дмитрий Караваев
 */
#ifndef DSP_ARRAY_UINT8_H_
#define DSP_ARRAY_UINT8_H_

#include "../types.h"
#include "../array/common.h"


/*!
 * \struct DSP_array_info
 * \brief Метаданные для массива, содержащего любые значения.
 */
typedef struct DSP_array_uint8
{
    DSP_array_info info;   ///< Метаданные.
    uint8_t*       values; ///< Значения. 
} DSP_array_uint8;

/*!
 * Создать массив c заданными параметрами.
 * \param[in] shape - размерность.
 * \param[in] dim - число измерений.
 * \return !NULL - успех, NULL неудача. 
 */
DSP_array_uint8* DSP_array_uint8_create(size_t* shape, DSP_ARRAY_DIM dim);
/*!
 * Создать массив из бинарного файла.
 * \param[out] info - метаданные массива.
 * \param[out] values - значение.
 * \param[in]  filename - имя файла.
 * \return 0 - успех, < 0 неудача. 
 */
DSP_array_uint8* DSP_array_uint8_from_file(const char* filename);
/*!
 * Сохранить массив в бинарный файл.
 * \param[in] array - массив.
 * \param[in] filename - имя файла.
 * \return 0 - успех, < 0 неудача. 
 */
int DSP_array_uint8_to_file(const DSP_array_uint8* array, const char* filename);
/*!
 * Удалить массив.
 * \param[in] array - массив.
 */
void DSP_array_uint8_delete(DSP_array_uint8* array);
/*!
 * Получить указатель на элемент массива по индексу.
 * \param[in] info - метаданные массива.
 * \param[in] values - элементы массива.
 * \param[in] index - индекс элемента.
 * \return В случае успеха - ненулевой указатель, в противном случае нулевой указатель.
 * \warning Число элементов в index должно быть равным info->dim.
 */
uint8_t* DSP_array_uint8_at(DSP_array_uint8* array, size_t* index);

#endif // DSP_ARRAY_UINT8_H_