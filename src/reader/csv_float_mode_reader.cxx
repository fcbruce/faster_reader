/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 08 Nov 2017 16:03:50
 *
 */

#include <boost/tokenizer.hpp>
#include <cmath>

#include "./csv_float_mode_reader.h"


namespace faster_reader {

CSVFloatModeReader::CSVFloatModeReader()
{
}

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
    for (const auto &data : datum) 
    {
      const char *c_data = data.c_str();
      float value = str2float(c_data, NAN);
    }

  }
  

  
}


} // faster_reader
