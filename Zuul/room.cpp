#include <iostream>
#include <cstring>
#include <map>
#include "room.h"

using namespace std;

Room::Room(){
}

void Room::setDescription(char description[80]){
  strcpy(roomDescription, description);
}

void Room::returnDescription(){
  cout << roomDescription << endl;
}

void Room::setExits(char exit[10], Room* adjacentRoom){
  strcpy(exit2, exit);
  exitPtr = exit2;
  roomLayout.insert(pair<char*, Room*> (exitPtr, adjacentRoom));
}

void Room::getExits(){
  for (map<char*, Room*>::iterator it = roomLayout.begin(); it != roomLayout.end(); ++it){
    cout << it -> first << endl;
  }
}

Room::~Room() {
  
}
