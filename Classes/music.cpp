//libraries
#include <iostream>
#include <cstring>
#include <math.h>
#include "music.h"

using namespace std;

Music::Music(){
  //constructor
  getArtist();
  time();
  getPublisher();
}

char* Music::getArtist(){
  //asks the user to input the name of the artist
  cout << "Please enter the name of the artist: ";
  cin.getline(name, 80, '\n');
  cout << endl;
  nameIndex = name;
  return nameIndex;
}

float Music::time(){
  //asks the user to input the length of the song
  cout << "Please enter the duration of the song in seconds (to the nearest tenth of a second): ";
  cin >> duration;
  cin.ignore(80, '\n');
  duration = round(duration * 10)/10;
  cout << endl;
  return duration;
}

char* Music::getPublisher(){
  //asks the user to input the name of the publisher
  cout << "Please enter the name of the publisher (type N/A if you don't know): ";
  cin.getline(publisher, 80, '\n');
  cout << endl;
  publisherIndex = publisher;
  return publisherIndex;
}

void Music::print(){
  //prints out everything related to the music
  cout << "Type of media: Music ; ";
  Media::print();
  cout << "Artist: " << name << " ; " << "Time: " << duration << " seconds ; " << "Publisher: " << publisher << endl << "----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

Music::~Music(){
  //virtual destructor
  Media::~Media();
  delete[] name;
  delete[] publisher;
}
