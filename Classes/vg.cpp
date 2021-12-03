#include <iostream>
#include <cstring>
#include "vg.h"

using namespace std;

VG::VG(){
  getTitle();
  getRating();
}

char* VG::getTitle(){
  cout << "Enter the title of your video game: ";
  cin.getline(title, 80);
  cout << endl;
  titleName = title;
  return titleName;
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

VG::~VG(){
  delete[] title;
  delete[] vgRatings;
}
