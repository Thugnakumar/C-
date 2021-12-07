#ifndef MOVIES_H
#define MOVIES_H
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Movies: public Media {
 public:
  Movies();
  char* getDirector();
  float getDuration();
  float* getRating();
  virtual void print();
  virtual ~Movies();
 private:
  char director[80];
  float time;
  float rating[2];
  char* directorName;
  float* ratings;
};

#endif
