#include <iostream>

#include "common.h"

using namespace std;

// The type specifier is a Reference or Pointer, but not a Universal Reference.

TEMPLATE_TYPE_ID(T, const T&, f)
TEMPLATE_TYPE_ID(T, const T*, g)

void Case1() {
  auto x = 27;
  const auto &rx = x;

  TYPE_ID(decltype(rx));
  f(x);

  const auto *px = &x;

  TYPE_ID(decltype(px));
  g(&x);
}

// The type specifier is a Universal Reference.

TEMPLATE_TYPE_ID(T, T &&, h);

void Case2() {
  auto x = 27;
  const auto cx = x;
  const auto &rx = x;

  auto &&uref1 = x;
  auto &&uref2 = cx;
  auto &&uref3 = rx;
  auto &&uref4 = 27;

  h(x);
  h(cx);
  h(rx);
  h(27);
}

// The type specifier is Neither a Pointer nor a Reference.

TEMPLATE_TYPE_ID(T, T, l);
TEMPLATE_TYPE_ID(T, const T, o);

void Case3() {
  auto x = 27;
  auto cx = x;

  TYPE_ID(decltype(cx));
  l(x);

  const auto ptr = "Fun with pointers";

  TYPE_ID(decltype(ptr));
  o("Fun with pointers");
}

// Array Arguments.

TEMPLATE_TYPE_ID(T, T, fa)
TEMPLATE_TYPE_ID(T, T &, ga)

void Case4() {
  const char name[] = "J. P. Briggs";
  const char *ptr = name;

  auto name1 = name;
  auto ptr1 = ptr;

  TYPE_ID(decltype(name1));
  fa(name);

  TYPE_ID(decltype(ptr1));
  fa(ptr);

  auto &name2 = name;
  auto &ptr2 = ptr;

  TYPE_ID(decltype(name2));
  ga(name);

  TYPE_ID(decltype(ptr2));
  ga(ptr);
}

// Function Arguments.

TEMPLATE_TYPE_ID(T, T, ff)
TEMPLATE_TYPE_ID(T, T &, gf)

void F(int a, double b) {}

void Case5() {
  auto f1 = F;

  TYPE_ID(decltype(f1));
  ff(F);

  auto &f2 = F;

  TYPE_ID(decltype(f2));
  gf(F);
}

// Uniform Initialization

void Case6() {
  auto x1 = 27;
  auto x2(27);
  auto x3 = {27};
  auto x4{27};

  TYPE_ID(decltype(x1));
  TYPE_ID(decltype(x2));
  TYPE_ID(decltype(x3));
  TYPE_ID(decltype(x4));
}

int main() {
  cout << "Case 1: The type specifier is a Reference or Pointer, but not a Universal Reference" << endl;
  Case1();

  cout << "Case 2: The type specifier is a Universal Reference" << endl;
  Case2();

  cout << "Case 3: The type specifier is Neither a Pointer nor a Reference" << endl;
  Case3();

  cout << "Case 4: Array Arguments" << endl;
  Case4();

  cout << "Case 5: Function Arguments" << endl;
  Case5();

  cout << "Case 6: Uniform Initialization" << endl;
  Case6();

  return 0;
}
