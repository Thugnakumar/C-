//header guards
#ifndef ROOM_H
#define ROOM_H
//libraries
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

class Room {
 public: //all public functions
  Room();//constructor
  void setDescription(char description[80]);//sets the room description
  void returnDescription();//returns the description of the room
  void setExits(char exit[10], Room* adjacentRoom);
  void getExits();//gets/returns the exits of the current room
  ~Room();//destructor
 private: //all private variables
  char roomDescription[80];
  map <char*, Room*> roomLayout;
  char exit2 [10];
  char* exitPtr;
};

#endif
