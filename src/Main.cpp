#include <iostream>

#include "CompileTimeRandom.h"

using namespace std;

int main() {
  cout << "Main calling CompileTimeRandom.Do() ... " << endl;
  CompileTimeRandom compiletimerandom;
  compiletimerandom.Do();
  return 0;
}
