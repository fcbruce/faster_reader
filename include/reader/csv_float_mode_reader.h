/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 08 Nov 2017 15:46:08
 *
 */
#ifndef FASTER_READER_CSV_FLOAT_MODE_READER_H
#define FASTER_READER_CSV_FLOAT_MODE_READER_H

#include "reader/csv_reader.h"

namespace faster_reader {

class CSVFloatModeReader : public CSVReader
{
public:
  CSVFloatModeReader(const std::string &filepath) : CSVReader(filepath) {}
  CSVFloatModeReader(const char *filepath) : CSVReader(filepath) {}
  virtual ~CSVFloatModeReader();

  virtual int read();
  const float *export_data();

  virtual size_t get_nrow();

private:
  std::vector<float> data;
};

}

#endif // FASTER_READER_CSV_FLOAT_MODE_READER_H