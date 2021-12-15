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
  char* returnDescription(char arr[]);//returns the description of the room
  bool* setExits();//sets the exits of the room
  void getExits(bool* help);//gets/returns the exits of the current room
  ~Room();//destructor
 private: //all private variables
  map<Room*>; //map to keep track of room locations
  char name[30]; //name of the room
  char description[80]; //stores the description
  char* descriptionPtr; //points to the first index of the description array
  bool exits[4]; //array of booleans determining whether or not there are exits
  bool* exitPtr; //points to the first index of the boolean array
};
