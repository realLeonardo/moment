#include "moment_utils.h"

time_t moment_lib::utils::stod(std::string time_str) {
  std::regex TIME_REG(
      "([0-9]{4})[-|/]([0-9]{1,2})[-|/]([0-9]{1,2}) "
      "([0-9]{1,2}):([0-9]{1,2}):([0-9]{1,2})");
  time_t timestamp = 0;
  std::smatch reg_result;

  if (std::regex_match(time_str, reg_result, TIME_REG)) {
    if (reg_result.size() != 7) {
      return 0;
    }

    int year = std::stoi(reg_result[1]);
    if (year < 1970) {
      year = 1970;
    }

    int month = std::stoi(reg_result[2]);
    int date = std::stoi(reg_result[3]);
    int hours = std::stoi(reg_result[4]);
    int minutes = std::stoi(reg_result[5]);
    int seconds = std::stoi(reg_result[6]);

    struct tm* tm_ptr = localtime(&timestamp);

    tm_ptr->tm_year = year - 1900;
    tm_ptr->tm_mon = month - 1;
    tm_ptr->tm_mday = date;
    tm_ptr->tm_hour = hours;
    tm_ptr->tm_min = minutes;
    tm_ptr->tm_sec = seconds;

    // NOTE: convert tm structure to time_t
    // refer: http://www.cplusplus.com/reference/ctime/mktime/
    timestamp = mktime(tm_ptr);
  }

  return timestamp;
}
