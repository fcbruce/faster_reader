/**
 * 
 * Author: fcbruce <fcbruce8964@gmail.com>
 * 
 * Time: Mon 13 Nov 2017 10:38:59
 * 
 */

#include "c_api/c_api.h"

FR_DLL int fr_csv_float_mode(const char *filepath, 
                             const float **data, 
                             uint64_t *nrow, 
                             uint64_t *ncol, 
                             const char ***column_name)
{
  faster_reader::CSVFloatModeReader *reader = new faster_reader::CSVFloatModeReader(filepath);
  if (reader->read() != 0) return -1;
  
  *data = reader->export_data();

  *ncol = static_cast<uint64_t>(reader->get_ncol());
  *nrow = static_cast<uint64_t>(reader->get_nrow());

  *column_name = reader->export_columns_name();

  return 0;
}
