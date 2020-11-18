#include <chrono>
#include <iostream>
#include <ratio>

using namespace std::chrono;

// duration
void duration_test() {
  seconds s_oneday(60 * 60 * 24);
  minutes m_oneday(60 * 24);
  hours h_oneday(24);

  seconds s_onehour(60 * 60);
  // ERROR
  // hours h_onehour(s_onehour);
  hours h_onehour(duration_cast<hours>(s_onehour));

  std::cout << s_oneday.count() << "s in 1day" << std::endl;
}

// time_point
void time_point_test() {
  time_point<system_clock, duration<int>> tp_seconds(duration<int>(1));

  system_clock::time_point tp(tp_seconds);

  std::cout << "1 second since system_clock epoch = ";
  std::cout << tp.time_since_epoch().count();
  std::cout << " system_clock periods." << std::endl;

  // display time_point:
  std::time_t tt = system_clock::to_time_t(tp);
  std::cout << "time_point tp is: " << ctime(&tt);
}

void clock_test() {
  std::chrono::duration<int, std::ratio<60 * 60 * 24>> one_day(1);
  system_clock::time_point today = system_clock::now();
  system_clock::time_point tomorrow = today + one_day;
  std::time_t tt;

  tt = system_clock::to_time_t(today);
  std::cout << "today is: " << ctime(&tt);

  tt = system_clock::to_time_t(tomorrow);
  std::cout << "tomorrow will be: " << ctime(&tt);
}

void printNowMilliseconds() {
  std::cout << time_point_cast<milliseconds>(system_clock::now())
                   .time_since_epoch()
                   .count()
            << " days since epoch" << std::endl;
}

void getTime() {
  auto tt = system_clock::to_time_t(system_clock::now());
  std::tm* tm = localtime(&tt);
  std::cout << tm << std::endl;
}

void duration_tc() { duration_test(); }
void time_point_tc() { time_point_test(); }
void clock_tc() { clock_test(); }