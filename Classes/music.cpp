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
  cin.getline(name, 80);
  cin.ignore(80, '\n');
  cout << endl;
  nameIndex = name;
  return nameIndex;
}

float Music::time(){
  cout << "Please enter the duration of the song in seconds (to the nearest tenth of a second): ";
  cin >> duration;
  cin.ignore(80, '\n');
  cout << endl;
  return duration;
}

char* Music::getPublisher(){
  cout << "Please enter the name of the publisher (type N/A if you don't know): ";
  cin.getline(publisher, 80);
  cout << endl;
  publisherIndex = publisher;
  return publisherIndex;
}

void Music::print(){
  cout << "Type of media: Music ; ";
  Media::print();
  cout << "Artist: " << name << " ; " << "Time: " << duration << "Publisher: " << publisher << endl;
}

Music::~Music(){
  delete[] name;
  delete[] publisher;
}
