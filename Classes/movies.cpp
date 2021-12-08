//libraries
#include <iostream>
#include <cstring>
#include <math.h>
#include "movies.h"

using namespace std;

Movies::Movies(){
  //constructor
  getDirector();
  getDuration();
  getRating();
}

char* Movies::getDirector(){
  //asks the user to input the director's name
  cout << "Please enter the name of the movie director: ";
  cin.getline(director, 80, '\n');
  cout << endl;
  directorName = director;
  return directorName;
}

float Movies::getDuration(){
  //asks the user to input the run time of the movie
  cout << "Please enter the duration of the movie in minutes (to the nearest tenth of a minute): ";
  cin >> time;
  cin.ignore(80, '\n');
  time = round(time * 10)/10;
  cout << endl;
  return time;
}

float* Movies::getRating(){
  //asks the user to input the rating of the movie
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
  //prints everything to do with the movie that the user inputted
  cout << "Type of media: Movie ; ";
  Media::print();
  cout << "Director: " << director << " ; " << "Duration: " << time << "minutes ; " << "Rating: " << rating[0] << "/" << rating[1] << endl << "----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

Movies::~Movies(){
  //virtual destructor
  delete[] director;
  delete[] rating;
}
