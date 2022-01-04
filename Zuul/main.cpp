//all the libraries
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"

using namespace std;

//function declarations
void initializeRooms(vector <Room*> &layout);
void movement(Room* &currentRoom, char direction[10]);

int main(){
  vector <Room*> layout;
  initializeRooms(layout);
  char instructions[500];
  char input[20];
  strcpy(instructions, "You are a senior in high school and an arsonist. The college application process has nearly killed you and you want to get revenge by burning every college you see to the ground. You decide to send a message by starting with your local university: Stanford. You've brought matches but nothing to burn. Find the bottle of alcohol, set it on fire, and drop it on the generator to blow up the university!");
  cout << instructions << endl;
  Room* currentRoom = layout[0];
  while (true){
      currentRoom -> returnDescription();
      cout << "There are exits;" << endl;
      currentRoom -> getExits();
      cout << endl << "Type in the name of an exit to move. Type in 'HELP' if you're stuck." << endl;
      cin >> input;
      for (int i = 0; i < strlen(input); ++i){
	input[i] = toupper(input[i]);
      }

      if (strcmp(input, "HELP") == 0){
	cout << instructions << endl;
      }

      else if (strcmp(input, "WEST") == 0){
	movement(currentRoom, input);
      }

      else if (strcmp(input, "EAST") == 0){
	movement(currentRoom, input);
      }

      else if (strcmp(input, "NORTH") == 0){
	movement(currentRoom, input);
      }

      else if (strcmp(input, "SOUTH") == 0){
	movement(currentRoom, input);
      }

      else {
	cout << "Not a valid input!" << endl;
      }

	  
    }
}

void initializeRooms(vector <Room*> &layout){
  char description[80];
  strcpy(description, "You're outside. There is a nice, cool breeze. ");
  Room* outside = new Room();
  outside -> setDescription(description);
  layout.push_back(outside);

  strcpy(description, "You're in the lobby. It's pretty nice in here... ");
  Room* lobby = new Room();
  lobby -> setDescription(description);
  layout.push_back(lobby);

    strcpy(description, "You're in the Janitor's Closet. Looks like he has a drinking problem... ");
  Room* closet = new Room();
  closet -> setDescription(description);
  layout.push_back(closet);

    strcpy(description, "You're in the gym. Have time for a quick workout? ");
  Room* gym = new Room();
  gym -> setDescription(description);
  layout.push_back(gym);

    strcpy(description, "Welcome to the hallway! This hallway leads to all the different classes! ");
  Room* hallway = new Room();
  hallway -> setDescription(description);
  layout.push_back(hallway);

  strcpy(description, "You're in the physics classroom. E = MC^2. ");
  Room* physics_class = new Room();
  physics_class -> setDescription(description);
  layout.push_back(physics_class);

    strcpy(description, "You're in the chemistry class. Mixing the right chemicals can make the campus go boom... ");
  Room* chem_class = new Room();
  chem_class -> setDescription(description);
  layout.push_back(chem_class);

  strcpy(description, "You're in the biology class. There are lots of interesting specimens here! ");
  Room* bio_class = new Room();
  bio_class -> setDescription(description);
  layout.push_back(bio_class);

    strcpy(description, "You're in the physics lab. There's a lot of interesting equipment here. ");
  Room* physics_lab = new Room();
  physics_lab -> setDescription(description);
  layout.push_back(physics_lab);

    strcpy(description, "You're in the chemistry lab. There's a lot of weird-smelling chemicals in here. ");
  Room* chem_lab = new Room();
  chem_lab -> setDescription(description);
  layout.push_back(chem_lab);

    strcpy(description, "You're in the biology lab. What's a biology lab??? ");
  Room* bio_lab = new Room();
  bio_lab -> setDescription(description);
  layout.push_back(bio_lab);

    strcpy(description, "Finally some fresh air! You're in the courtyard. ");
  Room* courtyard = new Room();
  courtyard -> setDescription(description);
  layout.push_back(courtyard);

    strcpy(description, "You found the generator! Time to set it on fire! ");
  Room* generator = new Room();
  generator -> setDescription(description);
  layout.push_back(generator);

    strcpy(description, "You're in the cafeteria. What's the special? ");
  Room* cafeteria = new Room();
  cafeteria -> setDescription(description);
  layout.push_back(cafeteria);

    strcpy(description, "Hi welcome to Starbucks! What would you like to drink today? ");
  Room* starbucks = new Room();
  starbucks -> setDescription(description);
  layout.push_back(starbucks);

    strcpy(description, "Hi welcome to Chipotle! What would you like to eat today? ");
  Room* chipotle = new Room();
  chipotle -> setDescription(description);
  layout.push_back(chipotle);
  
  char direction [10];
  strcpy(direction, "WEST");
  outside -> setExits(direction, lobby);
  strcpy(direction, "EAST");
  lobby -> setExits(direction, outside);
  strcpy(direction, "NORTH");
  lobby -> setExits(direction, closet);
  strcpy(direction, "SOUTH");
  lobby -> setExits(direction, gym);
  strcpy(direction, "WEST");
  lobby -> setExits(direction, hallway);
  strcpy(direction, "EAST");
  hallway -> setExits(direction, lobby);
  strcpy(direction, "NORTH");
  hallway -> setExits(direction, physics_class);
  strcpy(direction, "SOUTH");
  hallway -> setExits(direction, chem_class);
  strcpy(direction, "WEST");
  hallway -> setExits(direction, bio_class);
  strcpy(direction, "SOUTH");
  physics_class -> setExits(direction, hallway);
  strcpy(direction, "NORTH");
  physics_class-> setExits(direction, physics_lab);
  strcpy(direction, "NORTH");
  chem_class -> setExits(direction, hallway);
  strcpy(direction, "SOUTH");
  chem_class -> setExits(direction, chem_lab);
  strcpy(direction, "NORTH");
  chem_lab -> setExits(direction, chem_class);
  strcpy(direction, "SOUTH");
  physics_lab -> setExits(direction, physics_class);



}

void movement(Room* &currentRoom, char direction[10]){
  map<char*, Room*> roomMap = currentRoom -> returnMap();
  for (map<char*, Room*>::iterator it = roomMap.begin(); it != roomMap.end(); ++it){
    if (strcmp(direction, it -> first) == 0){
      currentRoom = it -> second;
    }

    else {
      cout << "No room in this direction!" << endl;
    }
  }
}
