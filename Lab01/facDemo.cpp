/*
  factDemo.cpp
  Recursive factorial for use with gdb demo
  Thomas Anastasio
  Created: October 17, 2002
  Current: October 17, 2002
*/

#include "factorial.h"

#include <iostream>

int main()
{
  using namespace std;

  unsigned number;
  unsigned factNumb;  // number!

  cout << "Enter positive integer (0 < i < 10): ";
  cin >> number;

  factNumb = factorial(number);

  cout << number << "! = " << factNumb << endl;

  return 0;
}
