//header guards
#ifndef ROOM_H
#define ROOM_H
//libraries
#include <iostream>
#include <cstring>
//#include <map>

using namespace std;

class Room {
 public: //all public functions
  Room();//constructor
  void setDescription(char description[80]);//sets the room description
  void returnDescription();//returns the description of the room
  //void setExit(char exit[4], char adjacent[10]);
  void getExits();//gets/returns the exits of the current room
  ~Room();//destructor
 private: //all private variables
  char roomDescription[80];
  bool exits[4]; //array of booleans determining whether or not there are exits
  //bool* exitPtr; //points to the first index of the boolean array
};

#endif
