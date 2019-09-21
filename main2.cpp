#include <iostream>
#include <string>
#include <sstream>

using namespace std;
template<typename T1, typename T2>
double cmp(T1 a, T2 b) {
  stringstream s1, s2 = stringstream();
  s1 << a;
  s2 << b;
  if (s1.str() <= s1.str()) {
    return a;
  } else {
    return b;
  }
}
template<typename T1, typename T2>
double find_min(T1 a, T2 b) {
  return cmp(a, b);
}
template<typename T, typename... Rest>
T find_min(T t, Rest... rest) {
  return cmp(t, find_min(rest...));
}
int main() {
  int a = 323;
  std::cout << find_min(3, 5.32, 'a', a);
}
