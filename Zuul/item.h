//header guards
#ifndef ITEM_H
#define ITEM_H
//libraries
#include <iostream>
#include <cstring>

using namespace std;

class item {
 public: //all public functions
  item(); //constructor
  void setDescription(char description[20]); //creates a description for the item
  char* returnDescription(); //gets the item's description to print out
  ~item(); //destructor
 private: //private variables
  char itemDescription[20]; //array for item description
  char* descriptionPtr; //description pointer
};

#endif
