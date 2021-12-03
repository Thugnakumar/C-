#include <iostream>
#include <cstring>
#include "movies.h"

using namespace std;

Movies::Movies(){
  getDirector();
  getDuration();
  getRating();
}

char* Movies::getDirector(){
  cout << "Please enter the name of the movie director: ";
  cin.getline(director, 80);
  cout << endl;
  directorName = director;
  return directorName;
}

float Movies::getDuration(){
  cout << "Please enter the duration of the movie in minutes (to the nearest tenth of a minute): ";
  cin >> time;
  cout << endl;
  return time;
}

float* Movies::getRating(){
  cout << "Enter the rating for the movie: ";
  cin >> rating[1];
  cout << endl << "What is the rating out of? (e.g. 3 out of 5): ";
  cin >> rating[2];
  cout << endl;
  ratings = rating;
  return ratings;
}

Movies::~Movies(){
  delete[] director;
  delete[] rating;
}
