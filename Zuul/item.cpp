//all the libraries
#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;

item::item(){
  //constructor
}

void item::setDescription(char description[20]){
  //creates the item description
  strcpy(itemDescription, description);
}

char* item::returnDescription(){
  //returns a pointer pointing to the first index of the item description
  descriptionPtr = itemDescription;
  return descriptionPtr;
}

item::~item(){
  //destructor
}
