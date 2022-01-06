//header guards
#ifndef ROOM_H
#define ROOM_H
//libraries
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "item.h"

using namespace std;

class Room {
 public: //all public functions
  Room();//constructor
  void setDescription(char description[80]);//sets the room description
  void returnDescription();//returns the description of the room
  void setExits(int description, Room* adjacentRoom);
  void getExits();//gets/returns the exits of the current room
  map<int, Room*> returnMap(); //returns the map
  void setItems(item* item);
  void getItems();
  bool checkForItemInRoom(char itemName[20]);
  item* getItemInRoom(char itemName[20]);
  ~Room();//destructor
 private: //all private variables
  char roomDescription[80]; //character array holding room description
  map <int, Room*> roomLayout;//map showing where each exit is
  vector <item*> vect;
};

#endif
