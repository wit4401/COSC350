/*
  arrayTest.cpp
  For use in gdb demo
  Thomas Anastasio
  Created: October 17, 2002
  Current: October 17, 2002
*/


#include <iostream>

const int MAX_ARR_SIZE = 5;

int computeVal(int[], int);

int main()
{
  using namespace std;

  int arr[MAX_ARR_SIZE];
  int index;
  int val;

  cout << "Enter an array index: ";
  cin >> index;

  val = computeVal(arr, index);

  cout << "arr[" << index << "] = " << val << endl;

  return 0;
}


int computeVal(int A[], int numb)
{
  return A[numb];
}
