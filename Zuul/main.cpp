/*
Name: Varun Krishnakumar
Date Last Modified: 1/5/22
This is the zuul project. The theme of this zuul game is "The John Wick of Colleges". You're trying to break into Stanford University and burn it to the ground because you hate colleges so much (the application process nearly killed you). The will see a message on the screen alerting them of the room that they are in, all exits in that room, and any items inside the room. The user has the option to pick up items, drop them, and also leave the room through one of the exits by typing any of the above. When the user drops their flaming bottle of alcohol in  the generator room and makes it back outside, they've won the game!
 */

//all the libraries
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"

struct item {
  //basic blueprint for an item
  char description[20];
};

using namespace std;

//function declarations
void initializeRooms(vector <Room*> &layout);
void movement(Room* &currentRoom, int direction);

int main(){//where all the action happens
  
  vector <Room*> layout;//vector storing all of the rooms
  vector <item*> inventory; //vector storing all of the items
  initializeRooms(layout);
  char instructions[500]; //character array containing game instructions/goal
  char input[20]; //for taking in user input
  strcpy(instructions, "You are a senior in high school and an arsonist. The college application process has nearly killed you and you want to get revenge by burning every college you see to the ground. You decide to send a message by starting with your local university: Stanford. You've brought matches but nothing to burn. Find the bottle of alcohol, set it on fire, and drop it on the generator to blow up the university!");
  cout << instructions << endl;
  Room* currentRoom = layout[0]; //sets the initial room to "outside" at the start of the game
  while (true){ //runs forever
    currentRoom -> returnDescription(); //gets the description of the current room you're in
    cout << "There are exits:" << endl;
    currentRoom -> getExits(); //prints out all of the exits in the room the user is currently in
    cout << endl << "Type in the name of an exit to move. Type in the name of an object to pick it up. Type 'INVENTORY' to see what items you currently have. Type in 'DROP' to drop an item and then type in its name to drop it. Type in 'HELP' if you're stuck." << endl; //tells the user what all they can do
    cin >> input; //takes in user input
    for (int i = 0; i < strlen(input); ++i){
      //converts all characters of the user's input to uppercase
      input[i] = toupper(input[i]);
    }

    if (strcmp(input, "HELP") == 0){
      //prints out the instructions if user types in "HELP"
      cout << instructions << endl;
    }

    else if (strcmp(input, "WEST") == 0){
      //goes to the room to the west if the user types "WEST"
      movement(currentRoom, 3);
    }

    else if (strcmp(input, "EAST") == 0){
      //goes to the room to the east if the user types "EAST"
      movement(currentRoom, 2);
    }

    else if (strcmp(input, "NORTH") == 0){
      //goes to the room to the north if the user types "NORTH"
      movement(currentRoom, 0);
    }

    else if (strcmp(input, "SOUTH") == 0){
      //goes to the room to the south if the user types "SOUTH"
      movement(currentRoom, 1);
    }

    else if (strcmp(input, "INVENTORY") == 0){
      //iterate through the entire list of items and print each of them out
    }

    else if (strcmp(input, "DROP") == 0){
      cout << "Which item would you like to drop?" << endl;
      cin >> input;
      //iterate through all of the items until the name of the user's specified item matches one in the inventory, then drop that item. Make sure to remove that item from the vector and add it to the room the user is currently in at the same time. If no item in the inventory matches the specified item the user wants to drop, print "Can't find item!". If the user tries to drop the burning bottle of alcohol in any room besides the generator room, print "Whew! That almost slipped out of your hands at the wrong place!" and keep it in the inventory.

    else {
      //cross-check the user's input with the name of the item currently in the room to see if the user wants to pick up that item. If so, pick up the item and remove it from the room simultaneously. If not, display the message below.
      //if none of the above are valid then the following message prints
      cout << "Not a valid input!" << endl;
    }

	  
  }
}

void initializeRooms(vector <Room*> &layout){//sets the position, exits, items, and descriptions of all rooms

  char description[150];//used to create room descriptions
  char itemDescription[20];
  
  strcpy("Matches", itemDescription);
  item* matches = new item();
  
  strcpy("Crowbar", itemDescription);
  item* crowbar = new item();

  strcpy("Moldy banana", itemDescription);
  item* moldy_banana = new item();

  strcpy("Pencil", itemDescription);
  item* pencil = new item();

  strcpy("Bottle of alcohol", itemDescription);
  item* alcohol = new item();

  strcpy("Frappuccino", itemDescription);
  item* frappe = new item();
  
  //outside room creation code
  strcpy(description, "You're outside. There is a nice, cool breeze. ");
  Room* outside = new Room();
  outside -> setDescription(description);
  layout.push_back(outside);

  //lobby room creation code
  strcpy(description, "You're in the lobby. It's pretty nice in here... ");
  Room* lobby = new Room();
  lobby -> setDescription(description);
  layout.push_back(lobby);

  //janitor's closet room creation code
  strcpy(description, "You're in the Janitor's Closet. Looks like he has a drinking problem... ");
  Room* closet = new Room();
  closet -> setDescription(description);
  layout.push_back(closet);

  //gym room creation code
  strcpy(description, "You're in the gym. Have time for a quick workout? ");
  Room* gym = new Room();
  gym -> setDescription(description);
  layout.push_back(gym);

  //hallway room creation code
  strcpy(description, "Welcome to the hallway! This hallway leads to all the different classes! ");
  Room* hallway = new Room();
  hallway -> setDescription(description);
  layout.push_back(hallway);

  //physics classroom creation code
  strcpy(description, "You're in the physics classroom. E = MC^2. ");
  Room* physics_class = new Room();
  physics_class -> setDescription(description);
  layout.push_back(physics_class);

  //chemistry classroom creation code
  strcpy(description, "You're in the chemistry class. Mixing the right chemicals can make the campus go boom... ");
  Room* chem_class = new Room();
  chem_class -> setDescription(description);
  layout.push_back(chem_class);

  //biology classroom creation code
  strcpy(description, "You're in the biology class. There are lots of interesting specimens here! ");
  Room* bio_class = new Room();
  bio_class -> setDescription(description);
  layout.push_back(bio_class);

  //physics lab room creation code
  strcpy(description, "You're in the physics lab. There's a lot of interesting equipment here. ");
  Room* physics_lab = new Room();
  physics_lab -> setDescription(description);
  layout.push_back(physics_lab);

  //chemistry lab room creation code
  strcpy(description, "You're in the chemistry lab. There's a lot of weird-smelling chemicals in here. ");
  Room* chem_lab = new Room();
  chem_lab -> setDescription(description);
  layout.push_back(chem_lab);

  //biology lab room creation code
  strcpy(description, "You're in the biology lab. What's a biology lab??? ");
  Room* bio_lab = new Room();
  bio_lab -> setDescription(description);
  layout.push_back(bio_lab);

  //courtyard room creation code
  strcpy(description, "Finally some fresh air! You're in the courtyard. ");
  Room* courtyard = new Room();
  courtyard -> setDescription(description);
  layout.push_back(courtyard);

  //generator room creation code
  strcpy(description, "You found the generator! Time to set it on fire! ");
  Room* generator = new Room();
  generator -> setDescription(description);
  layout.push_back(generator);

  //cafeteria room creation code
  strcpy(description, "You're in the cafeteria. What's the special? ");
  Room* cafeteria = new Room();
  cafeteria -> setDescription(description);
  layout.push_back(cafeteria);

  //starbucks room creation code
  strcpy(description, "Hi welcome to Starbucks! What would you like to drink today? ");
  Room* starbucks = new Room();
  starbucks -> setDescription(description);
  layout.push_back(starbucks);

  //chipotle room creation code
  strcpy(description, "Hi welcome to Chipotle! What would you like to eat today? ");
  Room* chipotle = new Room();
  chipotle -> setDescription(description);
  layout.push_back(chipotle);

  //all exits for outside
  outside -> setExits(3, lobby);

  //all exits for lobby
  lobby -> setExits(2, outside);
  lobby -> setExits(0, closet);
  lobby -> setExits(1, gym);
  lobby -> setExits(3, hallway);

  //all exits for the janitor's closet
  closet -> setExits(1, lobby);

  //all exits for gym
  gym -> setExits(0, lobby);
  
  //all exits for hallway
  hallway -> setExits(2, lobby);
  hallway -> setExits(0, physics_class);
  hallway -> setExits(1, chem_class);
  hallway -> setExits(3, bio_class);

  //all exits for the physics classroom
  physics_class -> setExits(1, hallway);
  physics_class-> setExits(0, physics_lab);

  //all exits for the chem classroom
  chem_class -> setExits(0, hallway);
  chem_class -> setExits(1, chem_lab);

  //all exits for the chem lab
  chem_lab -> setExits(0, chem_class);

  //all exits for the physics lab
  physics_lab -> setExits(1, physics_class);
  physics_lab -> setExits(3, courtyard);

  //all exits for the biology classroom
  bio_class -> setExits(2, hallway);
  bio_class -> setExits(0, bio_lab);

  //all exits for the biology lab
  bio_lab -> setExits(1, bio_class);
  bio_lab -> setExits(0, courtyard);

  //all exits for the courtyard
  courtyard -> setExits(1, bio_lab);
  courtyard -> setExits(2, physics_lab);
  courtyard -> setExits(3, generator);
  courtyard -> setExits(0, cafeteria);

  //all exits for the cafeteria
  cafeteria -> setExits(1, courtyard);
  cafeteria -> setExits(2, starbucks);
  cafeteria -> setExits(3, chipotle);

  //all exits for the generator room
  generator -> setExits(2, courtyard);

  //all exits for Chipotle
  chipotle -> setExits(2, cafeteria);

  //all exits for Starbucks
  starbucks -> setExits(3, cafeteria);

}

void movement(Room* &currentRoom, int direction){//moves the user to the room that they want to move to
  
  bool noRoom = true;//boolean for checking to see if a room matches the user's description
  map<int, Room*> roomMap = currentRoom -> returnMap();//copies the user's current room's map
  for (map<int, Room*>::iterator it = roomMap.begin(); it != roomMap.end(); ++it){
    if (direction == it -> first){
      //iterates through each exit until one of them matches the user's input, then changes the room to the room found adjacent to the user's current room in that direction. Then sets noRoom to false since there is a room that matches the user's specified description
      currentRoom = it -> second;
      noRoom = false;
    }
  }

  if (noRoom == true){
    //if no room matches the description/direction the user specified, the following message prints
    cout << "No room in this direction!" << endl;
  }
}
