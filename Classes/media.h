//header guards
#ifndef MEDIA_H
#define MEDIA_H
//libraries
#include <iostream>
#include <cstring>

using namespace std;

class Media{
  //class declaration
public: //all public variables
  Media(); //constructor
  char* getTitle();//gets the title from the user
  char* returnTitle(); //returns the title
  int getYear(); //gets the year from the user
  int returnYear(); //returns the user
  virtual void print(); //virtual print function
  virtual ~Media(); //virtual destructor
protected: //variables that only parent and child classes can use
  char title[80];
  int year;
  char* firstIndex;
};

#endif
