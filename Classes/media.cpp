#include <iostream>
#include <cstring>
#include "media.h"


using namespace std;

Media::Media(){
  getTitle();
  getYear();
}

char* Media::getTitle(){
  char* firstIndex;
  cout << "What is the title? ";
  cin >> title;
  cin.ignore(80,'\n');
  firstIndex = title;
  return firstIndex;
}

int Media::getYear(){
  cout << endl << "What year was it published? ";
  cin >> year;
  return year;
}

Media::~Media(){
  delete[] title;
}

