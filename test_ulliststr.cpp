#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  std::cout << "Checking" << std::endl;

  ULListStr dat;
  std::cout << "test constructor" << std::endl;

  dat.push_back("7");
  std::cout << "test push back" << std::endl;
  dat.push_front("8");
  std::cout << "test push front" << std::endl;

  dat.push_back("9");
  std::cout << "test push back" << std::endl;

  std::cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << std::endl;
  std::cout << "test get" << std::endl;
  // should print 8 7 9

  std::cout << "test size" << std::endl;
  std::cout << dat.size() << std::endl;
  //should print 3 for 3 strings stored

  dat.pop_back();
  std::cout << "test pop back, checking size" << std::endl;
  std::cout << dat.size() << std::endl;
  std::cout << "should print 8 7" << std::endl;
  std::cout << dat.get(0) << " " << dat.get(1) << std::endl;

  dat.pop_front();
  std::cout << "test pop front, checking size" << std::endl;
  std::cout << dat.size() << std::endl;

  std::cout << "should print 7" << std::endl;
  std::cout << dat.get(0) << std::endl;

  dat.push_front("hello");
  dat.push_back("my friend");
  std::cout << "should print hello my friend" << std::endl;
  std::cout << dat.front() << " " << dat.back() << std::endl;

}
