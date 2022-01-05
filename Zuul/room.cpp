//all the libraries
#include <iostream>
#include <cstring>
#include <map>
#include "room.h"

using namespace std;

//constant integers used to determine direction of exits and the direction the user wants to travel in
const int NORTH = 0;
const int SOUTH = 1;
const int EAST = 2;
const int WEST = 3;

Room::Room(){
  //constructor class
}

void Room::setDescription(char description[80]){
  //makes the room description
  strcpy(roomDescription, description);
}

void Room::returnDescription(){
  //prints the room description
  cout << roomDescription << endl;
}

void Room::setExits(int direction, Room* adjacentRoom){
  //sets the exits of the room
  roomLayout.insert(pair<int, Room*> (direction, adjacentRoom));
}

void Room::getExits(){
  //gets the exits of the room
  for (map<int, Room*>::iterator it = roomLayout.begin(); it != roomLayout.end(); ++it){
    //iterates through all the exits before printing out which exits are there
    if (it -> first == NORTH) {
      cout << "NORTH" << endl;
    }

    else if (it -> first == SOUTH) {
      cout << "SOUTH" << endl;
    }

    else if (it -> first == EAST) {
      cout << "EAST" << endl;
    }

    else {
      cout << "WEST" << endl;
    }
  }
}

map<int, Room*> Room::returnMap(){
  //returns the map
  return roomLayout;
}

Room::~Room() {
  //destructor class
}
