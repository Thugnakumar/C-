#ifndef VG_H
#define VG_H
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class VG: public Media {
 public:
  VG();
  ~VG();
  char* getTitle();
  float* getRating();
 private:
  char title[80];
  float vgRatings[2];
  char* titleName;
  float* vgRating;
};

#endif
