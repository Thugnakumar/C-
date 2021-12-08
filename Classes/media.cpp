#include <iostream>
#include <cstring>
#include "media.h"


using namespace std;

Media::Media(){
  //main class for media
  getTitle();
  getYear();
}

char* Media::getTitle(){
  //asks the user to input the title and returns a char pointer pointing to the first index of the char array
  cout << "What is the title? ";
  cin.getline(title, 80, '\n');
  firstIndex = title;
  return firstIndex;
}

char* Media::returnTitle(){
  //returns the char pointer only so that the user doesn't have to type in the title again
  char* titlePtr = firstIndex;
  return titlePtr;
}

int Media::getYear(){
  //prompts the user for the year in which the media was published and then returns that number
  cout << endl << "What year was it published? ";
  cin >> year;
  cin.ignore(4, '\n');
  cout << endl;
  return year;
}

int Media::returnYear(){
  //returns the year in which the media was published so that the user doesn't have to input that again
  int yearNum = year;
  return yearNum;
}

void Media::print(){
  //prints the title and year of publication of the media
  cout << "Title: " << title << " ; " << "Year: " << year << " ; ";
}

Media::~Media(){
  //media destructor
  delete[] title;
}

