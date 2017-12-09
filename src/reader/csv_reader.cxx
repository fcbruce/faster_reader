/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 08 Nov 2017 15:28:57
 *
 */

#include <string>
#include <boost/tokenizer.hpp>

#include "common/common.h"
#include "reader/csv_reader.h"

namespace faster_reader {

CSVReader::~CSVReader()
{

}

void CSVReader::read_header()
{
  typedef boost::tokenizer<boost::escaped_list_separator<char>> Tokenizer;
  std::string buffer;
  std::getline(ifs, buffer);
  Tokenizer headers(buffer);
  for (const auto &header : headers) this->columns_name.push_back(header);

  for (const auto &col : this->columns_name) this->columns_name_char_ptr.push_back(get_begin_ptr(col));
}

size_t CSVReader::get_ncol() 
{
  return columns_name.size();
}

size_t CSVReader::get_nrow()
{
  return 0;
}

const char **CSVReader::export_columns_name()
{
  if (columns_name_char_ptr.size() == 0) return nullptr;
  return &columns_name_char_ptr[0];
}

} // namespace faster_reader
