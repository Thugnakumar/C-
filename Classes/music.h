#ifndef MUSIC_H
#define MUSIC_H
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Music: public Media{
public:
  Music();
  char* getArtist();
  float time();
  char* getPublisher();
  virtual void print();
  virtual ~Music();
private:
  char name[80];
  float duration;
  char publisher[80];
  char* nameIndex;
  char* publisherIndex;
};

#endif
