/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 10 Nov 2017 11:50:52
 *
 */
#ifndef FASTER_READER_COMMON_H
#define FASTER_READER_COMMON_H

#include <cmath>
#include <string>

float str2float(const char *str, float def=NAN);

inline char *get_begin_ptr(std::string &s)
{
  if (s.length() == 0) return nullptr;
  return &s[0];
}

inline const char *get_begin_ptr(const std::string &s)
{
  if (s.length() == 0) return nullptr;
  return &s[0];
}

#endif // FASTER_READER_COMMON_H