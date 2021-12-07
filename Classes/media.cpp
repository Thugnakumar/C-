#include <iostream>
#include <cstring>
#include "media.h"


using namespace std;

Media::Media(){
  getTitle();
  getYear();
}

char* Media::getTitle(){
  cout << "What is the title? ";
  cin.getline(title, 80, '\n');
  firstIndex = title;
  return firstIndex;
}

char* Media::returnTitle(){
  char* titlePtr = firstIndex;
  return titlePtr;
}

int Media::getYear(){
  cout << endl << "What year was it published? ";
  cin >> year;
  cin.ignore(4, '\n');
  cout << endl;
  return year;
}

int Media::returnYear(){
  int yearNum = year;
  return yearNum;
}

void Media::print(){
  cout << "Title: " << title << " ; " << "Year: " << year << " ; ";
}

Media::~Media(){
  delete[] title;
}

