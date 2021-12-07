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
  cin.getline(publisher, 80, '\n');
  cout << endl;
  publisherName = publisher;
  return publisherName;
}

float* VG::getRating(){
  cout << "Enter the rating for the video game: ";
  cin >> vgRatings[0];
  cout << endl << "What is the rating out of (e.g. 3 out of 5): ";
  cin >> vgRatings[1];
  cin.ignore(10, '\n');
  cout << endl;
  vgRating = vgRatings;
  return vgRating;
}

void VG::print(){
  cout << "Type of media: Video Game ; ";
  Media::print();
  cout << "Publisher: " << publisher << " ; " << "Rating: " << vgRatings[0] << "/" << vgRatings[1] << endl << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

VG::~VG(){
  delete[] title;
  delete[] vgRatings;
}
