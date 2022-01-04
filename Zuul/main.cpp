//all the libraries
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"

using namespace std;

//function declarations
void initializeRooms(vector <Room*> &layout);

int main(){
  vector <Room*> layout;
  initializeRooms(layout);
  char instructions[500];
  strcpy(instructions, "You are a senior in high school and an arsonist. The college application process has nearly killed you and you want to get revenge by burning every college you see to the ground. You decide to send a message by starting with your local university: Stanford. You've brought matches but nothing to burn. Find the bottle of alcohol, set it on fire, and drop it on the generator to blow up the university!");
  cout << instructions << endl;
  Room* currentRoom = layout[0];
  currentRoom -> returnDescription();
  cout << "There are exits;" << endl;
  currentRoom -> getExits();
  /*for (vector <Room*>::iterator it = layout.begin(); it != layout.end(); ++it){
    (*it) -> returnDescription();
    cout << "There are exits:" << endl;
    (*it) -> getExits();
    }*/
}

void initializeRooms(vector <Room*> &layout){
  char description[80];
  strcpy(description, "You're outside. There is a nice, cool breeze. ");
  Room* outside = new Room();
  outside -> setDescription(description);
  layout.push_back(outside);

  strcpy(description, "You're in the cafeteria. I wonder what the special is? ");
  Room* cafeteria = new Room();
  cafeteria -> setDescription(description);
  layout.push_back(cafeteria);

  char direction [10];
  strcpy(direction, "WEST");
  outside -> setExits(direction, cafeteria);
  strcpy(direction, "EAST");
  cafeteria -> setExits(direction, outside);
}

//Room* movement(
