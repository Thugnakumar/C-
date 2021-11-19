#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;

Music::Music(){
  getArtist();
  time();
  getPublisher();
}

char* Music::getArtist(){
  cout << "Please enter the name of the artist: ";
  cin >> name;
  cout << endl;
  nameIndex = name;
  return nameIndex;
}

float Music::time(){
  cout << "Please enter the duration of the song in seconds (to the nearest tenth of a second): ";
  cin >> duration;
  cout << endl;
  return duration;
}

char* Music::getPublisher(){
  cout << "Please enter the name of the publisher (type N/A if you don't know): ";
  cin >> publisher;
  publisherIndex = publisher;
  return publisherIndex;
}

Music::~Music(){
  delete[] name;
  delete[] publisher;
}
