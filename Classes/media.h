#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <cstring>

using namespace std;

class Media{
 public:
  Media();
  ~Media();
  virtual char* getTitle();
  virtual int getYear();
protected:
  char title[80];
  int year;
  char* firstIndex;
};

#endif
