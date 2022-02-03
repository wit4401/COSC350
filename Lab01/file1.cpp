  // file1.cpp
  // Contains the main function
  // Demo file COSC350 Lab1
  //
  // Will Townsend
  // Created: 02/03/2022
  // Current: 02/03/2022

  #include <iostream>
  #include "file2.h"

  int main()
  {
    using namespace std;
    int i = 3;
    int sq;

    sq = SquareIt(i);
    cout << "Square of " << i << " is " << sq << endl;
    return 0;
  }
