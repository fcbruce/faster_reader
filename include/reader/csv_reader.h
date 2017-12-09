#ifndef FASTER_READER_CSV_READER_H
#define FASTER_READER_CSV_READER_H

#include <vector>
#include <fstream>
#include <string>

namespace faster_reader {

class CSVReader //: public Reader
{
public:
  CSVReader(const std::string &filepath) : filepath(filepath) {}
  CSVReader(const char *filepath) : filepath(filepath) {}
  virtual ~CSVReader();

  virtual int read() = 0;

  const char **export_columns_name();

  virtual size_t get_ncol();
  virtual size_t get_nrow();

protected:
  void read_header();

  std::vector<std::string> columns_name;
  std::vector<const char *> columns_name_char_ptr;
  std::string filepath;
  std::ifstream ifs;
};

} // namespace faster_reader

#endif // FASTER_READER_CSV_READER_H
