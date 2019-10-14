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
#include "array/uint8.h"
#include "array/int16.h"
#include "array/float32.h"

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
    
    // Возвращание нулеового значения. Индикатор того, что программа завершилась успешно.
    return 0;
}