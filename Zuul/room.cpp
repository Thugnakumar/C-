#include <iostream>
#include <cstring>
#include <map>
#include "room.h"

using namespace std;

Room::Room(){
  for (int i = 0; i < 4; ++i){
    exits[i] = false;
  }
}

void Room::setDescription(char description[80]){
  strcpy(description, roomDescription);
}

void Room::returnDescription(){
  cout << roomDescription << endl;
}

void Room::getExits(){
  /*exitPtr = exits;
  if (exits[0] == true){
    cout << "There is a North exit. ";
  }

  if (exits[1] == true){
    cout << "There is a South exit. ";
  }

  if (exits[2] == true){
    cout << "There is an East exit. ";
  }

  if (exits[3] == true){
    cout << "There is a West exit. ";
    }*/
}
