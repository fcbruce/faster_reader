/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 10 Nov 2017 14:12:10
 *
 */

#include "gtest/gtest.h"

#include "common/common.h"

class Str2FloatTest : public ::testing::Test
{
protected:
  Str2FloatTest()
  {}

  virtual ~Str2FloatTest()
  {}

  virtual void SetUp()
  {}

  virtual void TearDown()
  {}
};

TEST_F(Str2FloatTest, test_normal_float)
{
  ASSERT_FLOAT_EQ(str2float("1", NAN), 1.0f);
  ASSERT_FLOAT_EQ(str2float("1.0", NAN), 1.0f);
  ASSERT_FLOAT_EQ(str2float("1.", NAN), 1.0f);
  ASSERT_FLOAT_EQ(str2float(".1", NAN), .1f);
  ASSERT_FLOAT_EQ(str2float("0.1", NAN), .1f);
  ASSERT_FLOAT_EQ(str2float("1.1", NAN), 1.1f);
  ASSERT_FLOAT_EQ(str2float("1.11", NAN), 1.11f);
  ASSERT_FLOAT_EQ(str2float("3.14", NAN), 3.14f);
  ASSERT_FLOAT_EQ(str2float("0.618", NAN), 0.618f);
  ASSERT_FLOAT_EQ(str2float(".618", NAN), 0.618f);

  ASSERT_FLOAT_EQ(str2float("-1", NAN), -1.0f);
  ASSERT_FLOAT_EQ(str2float("-1.0", NAN), -1.0f);
  ASSERT_FLOAT_EQ(str2float("-1.", NAN), -1.0f);
  ASSERT_FLOAT_EQ(str2float("-.1", NAN), -.1f);
  ASSERT_FLOAT_EQ(str2float("-0.1", NAN), -.1f);
  ASSERT_FLOAT_EQ(str2float("-1.1", NAN), -1.1f);
  ASSERT_FLOAT_EQ(str2float("-1.11", NAN), -1.11f);
  ASSERT_FLOAT_EQ(str2float("-3.14", NAN), -3.14f);
  ASSERT_FLOAT_EQ(str2float("-0.618", NAN), -0.618f);
  ASSERT_FLOAT_EQ(str2float("-.618", NAN), -0.618f);
}

TEST_F(Str2FloatTest, test_exp_float)
{
  ASSERT_FLOAT_EQ(str2float("1e2", NAN), 1e2f);
  ASSERT_FLOAT_EQ(str2float("1.0e2", NAN), 1.0e2f);
  ASSERT_FLOAT_EQ(str2float("1.e2", NAN), 1.e2f);
  ASSERT_FLOAT_EQ(str2float(".1e-2", NAN), .1e-2f);
  ASSERT_FLOAT_EQ(str2float("0.1e3", NAN), .1e3f);
  ASSERT_FLOAT_EQ(str2float("1.1e10", NAN), 1.1e10f);
  ASSERT_FLOAT_EQ(str2float("1.11e-5", NAN), 1.11e-5f);
  ASSERT_FLOAT_EQ(str2float("3.14e-15", NAN), 3.14e-15f);
  ASSERT_FLOAT_EQ(str2float("0.618e12", NAN), 0.618e12f);
  ASSERT_FLOAT_EQ(str2float(".618e6", NAN), .618e6f);

  ASSERT_FLOAT_EQ(str2float("-1e2", NAN), -1e2f);
  ASSERT_FLOAT_EQ(str2float("-1.0e2", NAN), -1.0e2f);
  ASSERT_FLOAT_EQ(str2float("-1.e2", NAN), -1.e2f);
  ASSERT_FLOAT_EQ(str2float("-.1e-2", NAN), -.1e-2f);
  ASSERT_FLOAT_EQ(str2float("-0.1e3", NAN), -.1e3f);
  ASSERT_FLOAT_EQ(str2float("-1.1e10", NAN), -1.1e10f);
  ASSERT_FLOAT_EQ(str2float("-1.11e-5", NAN), -1.11e-5f);
  ASSERT_FLOAT_EQ(str2float("-3.14e-15", NAN), -3.14e-15f);
  ASSERT_FLOAT_EQ(str2float("-0.618e12", NAN), -0.618e12f);
  ASSERT_FLOAT_EQ(str2float("-.618e6", NAN), -.618e6f);
}