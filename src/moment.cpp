#include "./moment.h"

using namespace moment_lib;

/*
 * NOTE: 默认构造函数
 * 返回当前事件的 moment 对象
 */
moment::moment() { this->init(); }

// 目前最高精度为秒 seconds，因此参数形如 1605606780
moment::moment(time_t timestamp) { this->init(timestamp); }

/*
 * NOTE: 参数应该形如 "2020/11/17 19:01:00" 或者是 "1605606780"
 */
moment::moment(std::string time_str) {
  const std::regex TIME_REG(
      "([0-9]{4})[-|/]([0-9]{1,2})[-|/]([0-9]{1,2}) "
      "([0-9]{1,2}):([0-9]{1,2}):([0-9]{1,2})");
  time_t t;

  if (std::regex_match(time_str, TIME_REG)) {
    t = moment_lib::utils::stod(time_str);
  } else {
    t = std::stoi(time_str);
  }

  this->init(t);
}

moment::moment(moment& m) { this->init(m._timestamp); }

moment& moment::operator=(moment& m) {
  this->init(m._timestamp);

  return *this;
}

// NOTE: time_t 是以秒为单位
void moment::init(time_t timestamp) {
  if (timestamp < 0) {
    timestamp = moment::now();
  }

  std::tm* tm_ptr = localtime(&timestamp);

  this->_timestamp = timestamp;
  this->_year = tm_ptr->tm_year + 1900;
  this->_month = tm_ptr->tm_mon + 1;
  this->_day = tm_ptr->tm_wday;
  this->_date = tm_ptr->tm_mday;
  this->_hour = tm_ptr->tm_hour;
  this->_minute = tm_ptr->tm_min;
  this->_second = tm_ptr->tm_sec;
}

/*
 * 静态方法：返回当前时间戳 time_t long
 */
time_t moment::now() {
  using namespace std::chrono;
  return system_clock::to_time_t(system_clock::now());
}

std::string moment::to_string() {
  std::string moment_str = "";

  moment_str += "" + std::to_string(this->_year);
  moment_str += "/" + std::to_string(this->_month);
  moment_str += "/" + std::to_string(this->_date);
  moment_str += " " + std::to_string(this->_hour) + ":";

  if (this->_minute < 10) {
    moment_str += "0";
  }
  moment_str += std::to_string(this->_minute) + ":";

  if (this->_second < 10) {
    moment_str += "0";
  }
  moment_str += std::to_string(this->_second);

  return moment_str;
}
