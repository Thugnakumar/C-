//header guards
#ifndef MOVIES_H
#define MOVIES_H
//libraries
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Movies: public Media {
  //class declaration
public: //declaring all public functions
  Movies(); //constructor
  char* getDirector();//gets director name
  float getDuration(); //gets movie run time
  float* getRating(); //gets rating of movie
  virtual void print(); //virtual print function
  virtual ~Movies(); //virtual destructor
private: //declaring private variables
  char director[80];
  float time;
  float rating[2];
  char* directorName;
  float* ratings;
};

#endif
