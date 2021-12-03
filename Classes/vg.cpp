#include <iostream>
#include <cstring>
#include "vg.h"

using namespace std;

VG::VG(){
  getTitle();
  getRating();
}

char* VG::getTitle(){
  cout << "Enter the publisher of your video game: ";
  cin.getline(publisher, 80);
  cout << endl;
  publisherName = publisher;
  return publisherName;
}

float* VG::getRating(){
  cout << "Enter the rating for the video game: ";
  cin >> vgRatings[1];
  cout << endl << "What is the rating out of (e.g. 3 out of 5): ";
  cin >> vgRatings[2];
  cout << endl;
  vgRating = vgRatings;
  return vgRating;
}

void VG::print(){
  Media::print();
  cout << "Publisher: " << publisher << " ; " << "Rating: " << vgRatings[1] << "/" << vgRatings[2] << endl;
}

VG::~VG(){
  delete[] title;
  delete[] vgRatings;
}
