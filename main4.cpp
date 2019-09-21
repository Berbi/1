#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
void Push(vector<string> &str, T t) {
  str.emplace_back(to_string(t));
}

void Push(vector<string> &str, char t) {
  str.emplace_back(1, t);
}
void ToString1(vector<string> &str) {}

template<typename T, typename... Ts>
void ToString1(vector<string> &str, T t, Ts...ts) {
  ToString1(str, ts...);
  Push(str, t);
}

template<typename... Ts>
string ToString(const string &delimiter, Ts...ts) {
  vector<string> str;
  ToString1(str, ts...);
  reverse(str.begin(), str.end());
  string result;
  for (auto i: str) {
    while (true) {
      if (i.back() != '0') {
        break;
      } else {
        if (i.size() == 1) break;
        i.pop_back();
      }
    }
    result = i + ";" + result;
  }
  return result;
}

int main() {
  int n = 17;
  double x = 6.75;
  short a = 21;
  cout << ToString(";", 3.7, n, x, 'a');
}