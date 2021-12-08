//header guards
#ifndef VG_H
#define VG_H
//libraries
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class VG: public Media {
  //class declaration
public: //declares what functions are public
  VG(); //constructor
  char* getTitle(); //gets video game title
  float* getRating(); //gets video game rating
  virtual void print(); //virtual print function
  virtual ~VG(); //virtual destructor
private: //declares private variables
  char publisher[80];
  float vgRatings[2];
  char* publisherName;
  float* vgRating;
};

#endif
