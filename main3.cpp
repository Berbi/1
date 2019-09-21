#include <iostream>
#include <tuple>
#include <typeinfo>
#include <cstring>
using namespace std;

template<typename T>
void Add(tuple<int, double>, T t) {}

void Add(tuple<int, double> &tuple1, int t) {
  get<int>(tuple1) += t;
}

void Add(tuple<int, double> &tuple1, double t) {
  get<double>(tuple1) += t;
}

// Base case
void FindSums(tuple<int, double> &tuple1) {}

// Recursive case
template<typename T, typename... Rest>
void FindSums(tuple<int, double> &tuple1, T t, Rest... rest) {
  FindSums(tuple1, rest...);
  Add(tuple1, t);
}

template<typename... Args>
tuple<int, double> Sum(Args... args) {
  auto result = make_tuple(0, 0.0);
  FindSums(result, args...);
  return result;
}

int main() {
  short a = 33;
  auto sx2 = Sum(10.6, 2, 4.7, a, "fdk", '3');
  cout << "sx2 =";
  std::cout << " " << std::get<int>(sx2);
  std::cout << " " << std::get<double>(sx2);
  cout << endl;
}