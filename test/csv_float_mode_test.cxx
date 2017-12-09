/**
 * 
 * Author: fcbruce <fcbruce8964@gmail.com>
 * 
 * Time: Sat 9 Dec 2017 08:51:15
 * 
 */

#include <cmath>

#include "gtest/gtest.h"

#include "reader/csv_float_mode_reader.h"

using faster_reader::CSVFloatModeReader;

class CSVFloatModeTest : public ::testing::Test
{
protected:
  CSVFloatModeTest() {}
  virtual ~CSVFloatModeTest() {}

  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST_F(CSVFloatModeTest, test_file)
{
  CSVFloatModeReader *reader = new CSVFloatModeReader("../test/data/file.csv");
  int ret = reader->read();
  ASSERT_EQ(ret, 0);

  size_t ncol = reader->get_ncol();
  size_t nrow = reader->get_nrow();
  ASSERT_EQ(ncol, 3);
  ASSERT_EQ(nrow, 4);

  const float *values = reader->export_data();
  float std_values[] = {0, 1, 2, 0.1, 1000, 4, 5, 3.14, 2.718, NAN, 1024, 0.618};
  for (size_t i = 0; i < ncol * nrow; i++) 
  {
    if (isnan(std_values[i])) ASSERT_TRUE(isnan(values[i]));
    else ASSERT_FLOAT_EQ(values[i], std_values[i]);
  }

  const char **cols = reader->export_columns_name();
  char const *std_cols[] = {"col0", "col1", "col2"};
  for (size_t i = 0; i < ncol; i++) ASSERT_STREQ(cols[i], std_cols[i]);
  

}

