//header guards
#ifndef MUSIC_H
#define MUSIC_H
//libraries
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Music: public Media{
  //class declaration
public: //determines what functions are public
  Music(); //constructor
  char* getArtist(); //gets artist name
  float time(); //gets song duration
  char* getPublisher(); //gets publisher name
  virtual void print(); //virtual print function
  virtual ~Music(); //virtual destructor
private: //determines all private variables
  char name[80];
  float duration;
  char publisher[80];
  char* nameIndex;
  char* publisherIndex;
};

#endif
