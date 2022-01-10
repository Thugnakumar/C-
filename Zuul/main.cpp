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
#include "item.h"

using namespace std;

//function declarations
void initializeRooms(vector <Room*> &layout, vector <item*> &inventory);
void movement(Room* &currentRoom, int direction);

int main(){//where all the action happens
  
  vector <Room*> layout;//vector storing all of the rooms
  vector <item*> inventory; //vector storing all of the items
  initializeRooms(layout, inventory);
  char instructions[500]; //character array containing game instructions/goal
  char input[50]; //for taking in user input
  bool detonated = false; //checks if the user has set fire to the school yet
  strcpy(instructions, "You are a senior in high school and an arsonist. The college application process has nearly killed you and you want to get revenge by burning every college you see to the ground. You decide to send a message by starting with your local university: Stanford. You've brought matches but nothing to burn. Find the bottle of alcohol, set it on fire, and drop it on the generator to blow up the university!");
  cout << instructions << endl;
  Room* currentRoom = layout[0]; //sets the initial room to "outside" at the start of the game
  while (true){ //runs forever
    if (detonated == true){//if you've set off the bomb, the instructions change and if you're outside, then the loop breaks and you've won the game!
      strcpy(instructions, "You blew up the generator! Now go outside to safety!");
      if (currentRoom == layout[0]){
	cout << "You made it and won the game! Now, what college to blow up next...?" << endl;
	break;
      }
    }
    
    currentRoom -> returnDescription(); //gets the description of the current room you're in
    cout << "There are exits:" << endl;
    currentRoom -> getExits(); //prints out all of the exits in the room the user is currently in
    cout << "There are items:" << endl;
    currentRoom -> getItems(); //prints all items in the room
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
      //if the user types "INVENTORY" then the program goes through and prints out all items in the inventory
      cout << "The current items are in your inventory (" << inventory.size() << "): " << endl;
      for (vector <item*>:: iterator it = inventory.begin(); it != inventory.end(); ++it){
	cout << (*it) -> returnDescription() << endl;
      }
    }

    else if (strcmp(input, "DROP") == 0){
      //if the user types "DROP", the program then asks the user what item in their inventory to drop and drops it
      cout << "Which item would you like to drop?" << endl;
      cin >> input; //takes in user input
      for (int i = 0; i < strlen(input); ++i){
	//converts all characters of the user's input to uppercase
	input[i] = toupper(input[i]);
      } 
      for (vector <item*>:: iterator it = inventory.begin(); it != inventory.end(); ++it){
	if (strcmp(input, (*it) -> returnDescription()) == 0){
	  //if an item in the inventory matches the user's search, one of the following happens
	  if (strcmp("GRENADE", input) == 0 && currentRoom != layout[12]){
	    //if the user tries to drop the grenade before reaching the generator, the program doesn't let them do that
	    cout << "Whoops! Almost dropped that in the wrong place!" << endl;
	    break;
	  }

	  else if (strcmp("GRENADE", input) == 0 && currentRoom == layout[12]){
	    //if the user drops the grenade in the generator room, the program drops the grenade and deletes it from the inventory and sets "detonated" to true (setting up the end of the game), and changes the generator room's description
	    cout << "BOOM! You blew up the generator! Now go back outside and get to safety!" << endl;
	    delete (*it);
	    inventory.erase(it);
	    detonated = true;
	    strcpy(input, "Get out of here! This room is burning!");
	    currentRoom -> setDescription(input);
	    break;
	  }

	  else {
	    //if the user drops any other item, it removes that item from their inventory and adds it to the room
	    currentRoom -> setItems(*it);
	    inventory.erase(it);
	    break;
	  }
	}

	else {
	  //if the user input doesn't match the name of the item then the following message prints
	  cout << "No item in your inventory matches your search!" << endl;
	}
      }
    }

    else {
      //if the user input doesn't match any of the aforementioned fields...
      if (currentRoom -> checkForItemInRoom(input) == true){
	//checks to see if the user typed in the name of an item
	bool matchesPresent = false;
	bool alcoholPresent = false;
	inventory.push_back(currentRoom -> getItemInRoom(input)); //adds the item to the user's inventory
	for (vector <item*>:: iterator it = inventory.begin(); it != inventory.end(); ++it){
	  //iterates through all the items in the inventory to see if the user is carrying both matches and alcohol, and if they are, turns those two items into a single grenade
	  if (strcmp("MATCHES", (*it) -> returnDescription()) == 0){
	    matchesPresent = true;
	  }
	  if (strcmp("ALCOHOL", (*it) -> returnDescription()) == 0){
	    alcoholPresent = true;
	  }
	}

	if (matchesPresent == true && alcoholPresent == true){
	  bool matchesDeleted = false;
	  bool alcoholDeleted = false;
	  for (vector <item*>:: iterator it = inventory.begin(); it != inventory.end(); ++it){
	    if (strcmp("MATCHES", (*it) -> returnDescription()) == 0){
	      delete (*it);
	      inventory.erase(it);
	      matchesDeleted = true;
	    }
	    if (strcmp("ALCOHOL", (*it) -> returnDescription()) == 0){
	      delete (*it);
	      inventory.erase(it);
	      alcoholDeleted = true;
	    }

	    if (matchesDeleted == true && alcoholDeleted == true){
	      break;
	    }
	  }


	  char description[20];
	  strcpy(description, "GRENADE");
	  item* grenade = new item();
	  grenade -> setDescription(description);
	  inventory.push_back(grenade);

	  //prints the following message once the grenade is made
	  cout << "You picked up the bottle of alcohol with matches in hand! You combined the two to make a grenade! Now time to detonate it in the generator room!" << endl;
	}
      }

      //if none of the above are valid then the following message prints
      else {
	cout << "Not a valid input!" << endl;
      }
    }	  
  }
}

  void initializeRooms(vector <Room*> &layout, vector <item*> &inventory){//sets the position, exits, items, and descriptions of all rooms

  char description[150];//used to create room descriptions
  char itemDescription[20];//used to create item descriptions

  //matches item creation code
  strcpy(itemDescription, "MATCHES");
  item* matches = new item();
  matches -> setDescription(itemDescription);
  inventory.push_back(matches);

  //crowbar item creation code
  strcpy(itemDescription, "CROWBAR");
  item* crowbar = new item();
  crowbar -> setDescription(itemDescription);

  //banana item creation code
  strcpy(itemDescription, "BANANA");
  item* moldy_banana = new item();
  moldy_banana -> setDescription(itemDescription);

  //pencil item creation code
  strcpy(itemDescription, "PENCIL");
  item* pencil = new item();
  pencil -> setDescription(itemDescription);

  //alcohol item creation code
  strcpy(itemDescription, "ALCOHOL");
  item* alcohol = new item();
  alcohol -> setDescription(itemDescription);

  //frappuccino item creation code
  strcpy(itemDescription, "FRAPPUCCINO");
  item* frappe = new item();
  frappe -> setDescription(itemDescription);

  //outside room creation code
  strcpy(description, "You're outside. There is a nice, cool breeze. ");
  Room* outside = new Room();
  outside -> setDescription(description);
  outside -> setItems(crowbar);
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
  closet -> setItems(alcohol);
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
  physics_class -> setItems(pencil);
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
  cafeteria -> setItems(moldy_banana);
  layout.push_back(cafeteria);

  //starbucks room creation code
  strcpy(description, "Hi welcome to Starbucks! What would you like to drink today? ");
  Room* starbucks = new Room();
  starbucks -> setDescription(description);
  starbucks -> setItems(frappe);
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
