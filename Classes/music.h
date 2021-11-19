#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Music: public Media{
public:
  Music();
  ~Music();
  char* getArtist();
  float time();
  char* getPublisher();
private:
  char name[80];
  int duration;
  char publisher[80];
  char* nameIndex;
  char* publisherIndex;
};
