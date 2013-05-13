#include "stdafx.h"


struct A {
  int a;
  int b;
};

struct B {
  int a;
  double b;
};


void Test_Reinterpre_cast() {
  int n = 9;
  int *pn = &n;

  // Wrong result.
  // This copy the bits in 'n' to 'd'.
  double d = reinterpret_cast<double&>(n);

  // Compile Error.
  // error C2440: 'reinterpret_cast' : cannot convert from 'int' to 'double'
  // double d2 = reinterpret_cast<double>(n);

  // OK.
  unsigned long l = reinterpret_cast<long&>(n);
  // The exactly same function with pre-one, but more explicit.
  unsigned long l2 = *reinterpret_cast<long*>(&n);

  // OK.
  double d3 = static_cast<double>(n);

  A a;
  a.a = 1;
  a.b = 2;
  B b = reinterpret_cast<B&>(a);
}