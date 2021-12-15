#include <iostream>
#include <cstring>
#include <map>
#include "room.h"

using namespace std;

Room::Room(){
  cout << "Please enter a description for the room: ";
  cin >> description;
  cout << endl;
}

char* Room::returnDescription(){
  descriptionPtr = description;
  return descriptionPtr;
}

bool* setExits(){
  
}
