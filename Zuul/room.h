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
  map<char*, Room*> returnMap(); //returns the map
  ~Room();//destructor
 private: //all private variables
  char roomDescription[80]; //character array holding room description
  map <char*, Room*> roomLayout;//map showing where each exit is
  char exit2 [10]; //for N, S, E, W commands
  char* exitPtr; //the char pointer in the map
};

#endif
