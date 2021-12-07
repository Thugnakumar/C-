#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <cstring>

using namespace std;

class Media{
 public:
  Media();
  virtual ~Media();
  virtual char* getTitle();
  virtual char* returnTitle();
  virtual int getYear();
  virtual int returnYear();
  virtual void print();
protected:
  char title[80];
  int year;
  char* firstIndex;
};

#endif
