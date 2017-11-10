/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 08 Nov 2017 15:46:08
 *
 */
#ifndef FASTER_READER_CSV_FLOAT_MODE_READER
#define FASTER_READER_CSV_FLOAT_MODE_READER

#include "./csv_reader.h"

namespace faster_reader {

class CSVFloatModeReader : public CSVReader
{
public:
  CSVFloatModeReader();
  virtual ~CSVFloatModeReader();

  int read();

  void export_data(float *data);

private:
  std::vector<float> data;
};

}

#endif // FASTER_READER_CSV_FLOAT_MODE_READER
