/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 08 Nov 2017 16:03:50
 *
 */

#include <boost/tokenizer.hpp>
#include <cmath>

#include "common/common.h"
#include "reader/csv_float_mode_reader.h"


namespace faster_reader {

CSVFloatModeReader::~CSVFloatModeReader()
{
}

int CSVFloatModeReader::read()
{
  ifs.open(filepath);
  if (!ifs.is_open()) return -1;

  read_header();

  typedef boost::tokenizer<boost::escaped_list_separator<char>> Tokenizer;
  std::string buffer;
  while (std::getline(ifs, buffer)) 
  {
    Tokenizer datum(buffer);
    size_t col_cnt = 0;
    for (const auto &data : datum) 
    {
      col_cnt++;
      if (col_cnt > get_ncol()) break;
      const char *c_data = data.c_str();
      float value = str2float(c_data, NAN);
      this->data.push_back(value);
    }
  }

  return 0;
}

const float *CSVFloatModeReader::export_data()
{
  if (data.size() == 0) return nullptr;
  return &data[0];
}

size_t CSVFloatModeReader::get_nrow()
{
  return data.size() / get_ncol();
}


} // faster_reader
