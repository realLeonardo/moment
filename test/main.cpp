/*
 * 在这里写测试用例
 */
#include <iostream>

#include "../src/moment.h"

using namespace std;
int main() {
  auto m = moment_lib::moment("2020/1/1 10:9:1");
  cout << m.get_time() << endl;
  cout << m.to_string() << endl;

  moment_lib::moment mc = m;

  cout << mc.get_time() << endl;
  cout << mc.to_string() << endl;

  return 0;
}