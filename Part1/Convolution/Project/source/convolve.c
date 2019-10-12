#include "convolve.h"


/*!
 * Функция для свёртки сигнала с ИХ.
 * \param[in]  xh - входной сигнал, дополненный T - 1 нулями.
 * \param[out] y - выходной сигнал.
 * \param[in]  N - длина исходного входной сигнала.
 * \param[in]  h - ИХ.
 * \param[in]  T - длина ИХ.
 * \return 0 - успех, -1 - нереализована.
 */
int DSP_convolve(const float* xh, float* y, size_t N, const float* h, size_t T)
{
    return -1;
}

/*!
 * Функция для свёртки с ИХ и децимации сигнала.
 * \param[in] xh - входной сигнал, дополненный T - 1 нулями.
 * \param[out] y - выходной сигнал.
 * \param[in] N - длина исходного входной сигнала.
 * \param[in] h - ИХ.
 * \param[in] T - длина ИХ.
 * \param[in] D - коэффициент децимации.
 * \return 0 - успех, -1 - нереализована.
 */
int DSP_convolve_decimate(const float* xh, float* y, size_t N, 
                          const float* h, size_t T, size_t D)
{
    return -1;
}