//
//  main.cc
//  TimeString
//

#include <iostream>
#include <cstdlib>

#include "time_string.h"

int main(int argc, const char * argv[])
{
  std::cout << TimeString::nowTimeString() << std::endl;
  std::cout << "(" << TimeString::nowDayOfWeek() << ")" << std::endl;
  return EXIT_SUCCESS;
}
