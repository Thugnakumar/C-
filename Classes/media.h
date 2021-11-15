#include <iostream>

using namespace std;

class Media{
 public:
  Media();
  char[] title();
  int year();
  ~Media();
  char title[80];
  int year;
};
