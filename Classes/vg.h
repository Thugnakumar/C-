#ifndef VG_H
#define VG_H
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class VG: public Media {
 public:
  VG();
  char* getTitle();
  float* getRating();
  virtual void print();
  virtual ~VG();
 private:
  char publisher[80];
  float vgRatings[2];
  char* publisherName;
  float* vgRating;
};

#endif
