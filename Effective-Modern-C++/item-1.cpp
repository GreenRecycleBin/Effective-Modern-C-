#include <array>
#include <iostream>

#include "common.h"

using namespace std;

// ParamType is a Reference or Pointer, but not a Universal Reference.

TEMPLATE_TYPE_ID(T, T &, f)

// Comment this to see changes to T deduction.
TEMPLATE_TYPE_ID(T, const T&, f)

TEMPLATE_TYPE_ID(T, T *, f)

void Case1() {
  int x = 27;
  const int cx = x;
  const int &rx = x;

  f(x);
  f(cx);
  f(rx);

  const int *px = &x;

  f(&x);
  f(px);
}

// ParamType is a Universal Reference.

TEMPLATE_TYPE_ID(T, T &&, g);

void Case2() {
  int x = 27;
  const int cx = x;
  const int &rx = x;

  g(x);
  g(cx);
  g(rx);
  g(27);
}

// ParamType is Neither a Pointer nor a Reference.

TEMPLATE_TYPE_ID(T, T, h);

void Case3() {
  int x = 27;
  const int cx = x;
  const int &rx = x;

  h(x);
  h(cx);
  h(rx);

  const char *const ptr = "Fun with pointers";

  h(ptr);
}

// Array Arguments.

TEMPLATE_TYPE_ID(T, T, fa)
TEMPLATE_TYPE_ID(T, T &, ga)

void Case4() {
  const char name[] = "J. P. Briggs";
  const char *ptr = name;

  fa(name);
  fa(ptr);

  ga(name);
  ga(ptr);
}

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T(&)[N]) noexcept {
  return N;
}

int keyVals[] = {1, 3, 7, 9, 11, 22, 35};
int mappedVals[arraySize(keyVals)];
std::array<int, arraySize(keyVals)> mappedVals2;

// Function Arguments.

TEMPLATE_TYPE_ID(T, T, ff)
TEMPLATE_TYPE_ID(T, T &, gf)

void F(int a, double b) {}

void Case5() {
  ff(F);
  gf(F);
}

int main() {
  cout << "Case 1: ParamType is a Reference or Pointer, but not a Universal Reference" << endl;
  Case1();

  cout << "Case 2: ParamType is a Universal Reference" << endl;
  Case2();

  cout << "Case 3: ParamType is Neither a Pointer nor a Reference" << endl;
  Case3();

  cout << "Case 4: Array Arguments" << endl;
  Case4();

  cout << "Case 5: Function Arguments" << endl;
  Case5();

  return 0;
}
