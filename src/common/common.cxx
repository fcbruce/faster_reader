/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 10 Nov 2017 11:51:01
 *
 */

#include <cctype>

#include "common/common.h"

static inline bool check_maybe_float(const char *s)
{
  while (isspace(*s)) s++;
  if (*s == '\0') return false;
  if (isdigit(*s) || (*s) == '-' || (*s) == '+' || (*s) == '.') return true;
  return false;
}

static float str2float_impl(const char *s, float def=NAN)
{
  float r = 0;
  bool neg = false;
  bool has_digit = false;

  while (isspace(*s)) s++;

  if (*s == '-')
  {
    neg = true;
    s++;
  }
  else if (*s == '+') s++;

  while (isdigit(*s))
  {
    r = (r * 10.) + (*s - '0');
    s++;
    has_digit = true;
  }

  if (*s == '.')
  {
    float f = 0;
    int e = 0;
    ++s;
    while (isdigit(*s))
    {
      f = (f * 10.) + (*s - '0');
      s++;
      e++;
      has_digit = true;
    }
    r = r + f / pow(10, e);
  }

  if (!has_digit) return def; // ., .e2, etc

  if (*s == 'e' || *s == 'E')
  {
    int e = 0;
    bool neg = false;
    s++;
    if (*s == '-')
    {
      neg = true;
      s++;
    }
    else if (*s == '+') s++;

    if (!isdigit(*s)) return def; // 1e, .e, etc

    while (isdigit(*s))
    {
      e = (e * 10) + (*s - '0');
      s++;
      if (e > 1000) return def;
    }
    if (neg) e = -e;
    r = r * pow(10, e);
  }

  while (*s != '\0')
  {
    if (isspace(*s)) s++;
    else return def;
  }

  if (neg) r = -r;
  return r;
}

float str2float(const char *s, float def)
{
  float data = check_maybe_float(s) ? str2float_impl(s, def) : def;
  return data;
}