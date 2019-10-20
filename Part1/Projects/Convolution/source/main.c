/*!
 * \file main.c
 * \author Дмитрий Караваев
 * \brief Основной файл исходного кода
 */
// Подключение функционала стандартной библиотеки (для работы с файлами).
#include <stdlib.h>
// Подключение функционала ввода-вывода.
#include <stdio.h>

#include "array/common.h"
#include "array/int8.h"
#include "array/uint8.h"
#include "array/int16.h"
#include "array/float32.h"
#include "array/2D.h"

#include "convolve.h"


void DSP_run_convolve( )
{
    // Загружаем сигнал из файла.
    DSP_array_float32* signal = DSP_array_float32_from_file("../data/signal.bin");
    // Загружаем фильтр из файла.
    DSP_array_float32* filter = DSP_array_float32_from_file("../data/filter.bin");
    // Создаём филтьтрованный сигнал.
    size_t length = signal->info.shape[0] - (filter->info.shape[0] - 1);
    DSP_array_float32* result = DSP_array_float32_create(&length, signal->info.dim);

    // Запускам свётку.
    int ret = DSP_convolve(signal->values, result->values, length, filter->values, filter->info.shape[0]);
    if (ret == 0)
    {
        // Записываем результат в файл.
        DSP_array_float32_to_file(result, "../data/filtered.bin");
        printf("1. Run regular convolution!\n");
    }

    // Удаляем сигнал и фильтр из памяти.
    DSP_array_float32_delete(signal);
    DSP_array_float32_delete(filter);
    DSP_array_float32_delete(result);
}

void DSP_run_convolve_decimate( )
{
    // Фактор децимирования.
    size_t D = 4; 
    // Загружаем сигнал из файла.
    DSP_array_float32* signal = DSP_array_float32_from_file("../data/signal.bin");
    // Загружаем фильтр из файла.
    DSP_array_float32* filter = DSP_array_float32_from_file("../data/filter.bin");
    // Создаём филтьтрованный сигнал.
    size_t length = signal->info.shape[0] - (filter->info.shape[0] - 1);
    size_t shape  = length / 4;
    DSP_array_float32* result = DSP_array_float32_create(&shape, signal->info.dim);

    // Запускам свётку.
    int ret = DSP_convolve_decimate(signal->values, result->values, length, filter->values, filter->info.shape[0], D);
    if (ret == 0)
    {
        // Записываем результат в файл.
        DSP_array_float32_to_file(result, "../data/decimated.bin");
        printf("2. Run convolution with decimation!\n");
    }

    // Удаляем сигнал и фильтр из памяти.
    DSP_array_float32_delete(signal);
    DSP_array_float32_delete(filter);
    DSP_array_float32_delete(result);
}

void DSP_run_convolve_complex_int( )
{
    // Загружаем сигнал из файла.
    DSP_array_int16* signal = DSP_array_int16_from_file("../data/signal_16bit.bin");
    // Загружаем фильтр из файла.
    DSP_array_int16* filter = DSP_array_int16_from_file("../data/filter_16bit.bin");
    // Создаём филтьтрованный сигнал.
    size_t shape[2] = {signal->info.shape[0] - (filter->info.shape[0] - 1), signal->info.shape[1]};
    DSP_array_int16* result = DSP_array_int16_create(shape, signal->info.dim);

    // Запускам свётку.
    int ret = DSP_convolve_complex_int(
        signal->values, result->values, 
        shape[0], filter->values, filter->info.shape[0]
    );
    if (ret == 0)
    {
        // Записываем результат в файл.
        DSP_array_int16_to_file(result, "../data/filtered_16bit.bin");
        printf("3. Run complex integer convolution!\n");
    }

    // Удаляем сигнал и фильтр из памяти.
    DSP_array_int16_delete(signal);
    DSP_array_int16_delete(filter);
    DSP_array_int16_delete(result);
}

void DSP_run_convolve_2D(const char* image_fn, const char* filter_fn, const char* result_fn)
{
    // Загружаем сигнал из файла.
    DSP_array_uint8* signal = DSP_array_uint8_from_file(image_fn);
    // Загружаем фильтр из файла.
    DSP_array_int8* filter = DSP_array_int8_from_file(filter_fn);
    // Создаём филтьтрованный сигнал.
    DSP_array_uint8* result = DSP_array_uint8_create(signal->info.shape, signal->info.dim);

    uint8_t** signal_2D = DSP_linear22D_uint8(signal->values, signal->info.shape[0], signal->info.shape[1]);
    uint8_t** result_2D = DSP_linear22D_uint8(result->values, result->info.shape[0], result->info.shape[1]);
    int8_t**  filter_2D = DSP_linear22D_int8(filter->values, filter->info.shape[0], filter->info.shape[1]);

    // Запускам свётку.
    int ret = DSP_convolve_2D(
        signal_2D, result_2D, 
        signal->info.shape[0], signal->info.shape[1],
        filter_2D, filter->info.shape[0], filter->info.shape[1]
    );

    if (ret == 0)
    {
        free(result->values);
        result->values = DSP_2D2linear_uint8(result_2D, result->info.shape[0], result->info.shape[1]);
        // Записываем результат в файл.
        DSP_array_uint8_to_file(result, result_fn);
        printf("4. Run 2D integer convolution!\n");
    }

    // Удаляем сигнал и фильтр из памяти.
    DSP_array_uint8_delete(signal);
    DSP_array_int8_delete(filter);
    DSP_array_uint8_delete(result);
}

/*!
 * Точка начала исполнения программы.
 * \param[in] argc - число аргументов командной строки, переданных программе.
 * \param[in] argv - массив строк-аргументов командной строки, переданных программе.
 * \return 0 при успешном завершении, < 0 - в противном случае.
 */
int main(int argc, char** argv)
{
    // Вывод в терминал привествия и доп. информации.
    printf("Convolution task tesing util.\n");

    // Исполнение теста обычной свёртки.
    DSP_run_convolve( );

    // Исполнение свёртки с децимацией.
    DSP_run_convolve_decimate( );

    // Исполнение комплексной целочисленной свёртки.
    DSP_run_convolve_complex_int( );
    
    DSP_run_convolve_2D("../data/im_female.bin", "../data/gauss_2D.bin", "../data/fim_female.bin");

    // Возвращание нулеового значения. Индикатор того, что программа завершилась успешно.
    return 0;
}