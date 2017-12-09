/**
 * 
 * Author: fcbruce <fcbruce8964@gmail.com>
 * 
 * Time: Mon 13 Nov 2017 10:51:32
 * 
 */
#ifndef FASTER_READER_C_API_H
#define FASTER_READER_C_API_H

#include "reader/csv_float_mode_reader.h"

#ifdef __cplusplus
# define FR_EXTERN_C extern "C"
#else
# define FR_EXTERN_C
#endif

#if defined(_MSC_VER) || defined(_WIN32)
# define FR_DLL FR_EXTERN_C __declspec(dllexport)
#else
# define FR_DLL FR_EXTERN_C
#endif

FR_DLL int fr_csv_float_mode(const char *filepath, 
                             const float **data, 
                             uint64_t *nrow, 
                             uint64_t *ncol, 
                             const char ***column_name);

#endif // FASTER_READER_C_API_H