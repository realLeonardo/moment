#ifndef MOMENT_LIB_MOMENT_H
#define MOMENT_LIB_MOMENT_H

#include <chrono>
#include <iostream>
#include <regex>
#include <string>

#include "moment_utils.h"

namespace moment_lib {

/*
 * moment
 */
class moment {
 public:
  moment();
  moment(time_t t);
  moment(std::string s);
  moment(moment &m);
  ~moment() = default;

  moment &operator=(moment &m);

  bool operator>(moment &m) { return this->_timestamp > m._timestamp; }
  bool operator<(moment &m) { return this->_timestamp < m._timestamp; }
  bool operator==(moment &m) { return this->_timestamp == m._timestamp; }

  static time_t now();

  time_t get_time() const { return this->_timestamp; }
  int get_year() const { return this->_year; }
  int get_month() const { return this->_month; }
  int get_date() const { return this->_date; }
  int get_hour() const { return this->_hour; }
  int get_minute() const { return this->_minute; }
  int get_second() const { return this->_second; }
  // NOTE: get the weekday
  int get_day() const { return this->_day; }

  std::string to_string();

 private:
  void init(time_t ts = -1);

  time_t _timestamp;
  int _year;
  int _month;
  // NOTE: 表示星期数
  int _day;
  int _date;
  int _hour;
  int _minute;
  int _second;
};

}  // namespace moment_lib

#endif
