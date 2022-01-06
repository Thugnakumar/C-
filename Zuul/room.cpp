//all the libraries
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "room.h"
#include "item.h"

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

void Room::setItems(item* item){
  //adds items to the room vector
  vect.push_back(item);
}

void Room::getItems(){
  //prints out the descriptions of the items in the current room
  for (vector <item*>::iterator it = vect.begin(); it != vect.end(); ++it){
    cout << (*it) -> returnDescription() << endl;
  }
}

bool Room::checkForItemInRoom(char itemName[20]){
  //checks to see if a particular item is in a room
  for (vector <item*>::iterator it = vect.begin(); it != vect.end(); ++it){
    if (strcmp(itemName, (*it) -> returnDescription()) == 0){
      return true;
    }
  }

  return false;
}

item* Room::getItemInRoom(char itemName[20]){
  //gets the item in a room given that it's present
  item* temp;
  for (vector <item*>::iterator it = vect.begin(); it != vect.end(); ++it){
    if (strcmp(itemName, (*it) -> returnDescription()) == 0){
      temp = *it;
      vect.erase(it);
      return temp;
    }
  }

  return NULL;
}

Room::~Room() {
  //destructor class
}
