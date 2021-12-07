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
  cin.ignore(80, '\n');
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
  cin >> rating[0];
  cout << endl << "What is the rating out of? (e.g. 3 out of 5): ";
  cin >> rating[1];
  cin.ignore(10, '\n');
  cout << endl;
  ratings = rating;
  return ratings;
}

void Movies::print(){
  cout << "Type of media: Movie ; ";
  Media::print();
  cout << "Director: " << director << " ; " << "Duration: " << time << " ; " << "Rating: " << rating[1] << "/" << rating[2] << endl;
}

Movies::~Movies(){
  delete[] director;
  delete[] rating;
}
