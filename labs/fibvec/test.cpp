#include "FibVec.h"
#include <iostream>

// Use this file to test your FibVec class!
// This file won't be graded - do whatever you want.

int main() {
  FibVec fibvec;

  /*fibvec.insert(90, 0);
  fibvec.insert(80, 1);
  fibvec.insert(70, 2);
  fibvec.insert(60, 3);
  fibvec.insert(50, 4);
  fibvec.insert(40, 5);
  fibvec.insert(30, 6);
  fibvec.insert(20, 7);
  fibvec.insert(10, 8);

  int x = fibvec.count();

  cout << fibvec.remove(4) << endl;
  for (int i = 0; i < x - 1; i++){
    cout << fibvec.lookup(i) << " ";
  }
  cout << endl;*/
  fibvec.push(3);
  cout << fibvec.lookup(0);


  return 0;
}
