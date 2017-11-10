#ifndef FASTER_READER_CSV_READER_H
#define FASTER_READER_CSV_READER_H

#include <vector>
#include <fstream>
#include <string>

namespace faster_reader {

class CSVReader //: public Reader
{
public:
  CSVReader();
  virtual ~CSVReader();

  virtual int read();

  void export_column_name(char **name);

protected:
  void read_header();

  std::vector<std::string> column_name;
  std::string filepath;
  std::ifstream ifs;
};

} // namespace faster_reader

#endif // FASTER_READER_CSV_READER_H
