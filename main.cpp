#include <algorithm>
#include <vector>
#include <iostream>
#include <tuple>
#include <math.h>
#include <sstream>

using namespace std;// я знаю, что так лучше не делать, но так быстрее

// The base case: we just have a single number.
template <typename T>
double sum(T t) {
    return t;

}
// The recursive case: we take a number, alongside
// some other numbers, and produce their sum.
template <typename T, typename... Rest>
double sum(T t, Rest... rest) {
    return t + sum(rest...);
}
int main()
{
    short m = 13;
    int n1 = 17, n2 = 23;
    double x = 12.8;
cout<< sum(3, 'a', 2.3, '2',m,n1,x);
}
