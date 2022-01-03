//all the libraries
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"

using namespace std;

//function declarations
void initializeRooms(vector <Room*> &layout);

int main(){
  vector <Room*> layout;
  initializeRooms(layout);
  for (vector <Room*>::iterator it = layout.begin(); it != layout.end(); ++it){
    (*it) -> returnDescription();
  }
}

void initializeRooms(vector <Room*> &layout){
  char description[80];
  strcpy("Welcome to Scotland!", description);
  Room* place = new Room();
  place -> setDescription(description);
  layout.push_back(place);
}
