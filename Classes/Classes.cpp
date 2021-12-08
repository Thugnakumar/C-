//libraries
#include <iostream>
#include <cstring>
#include <vector>
#include "media.h"
#include "music.h"
#include "movies.h"
#include "vg.h"

using namespace std;

//function declarations
void add(vector <Media*> &vect);
void search(vector <Media*> &vect);
void remove(vector <Media*> &vect);

int main(){
  //where everything happens
  vector<Media*> vect; //creation of the vector of media pointers
  char command[10]; //the character array that takes in user input
  while (true){
    //runs forever or until it hits a break statement
    cout << "Type a commmand to continue. 'ADD' adds media, 'RM' to deletes media from your directory, 'SEARCH' allows you to look for a specific media item in your directory, and 'QUIT'exits the program." << endl;
    cin.getline(command, 10, '\n'); //takes in input
    for (int i = 0; i < strlen(command); i++){
      //converts all input to uppercase
      command[i] = toupper(command[i]);
    }

    if (strcmp(command, "ADD") == 0){
      //if the user types in "ADD", go to the add function
      add(vect);
    }

    else if (strcmp(command, "SEARCH") == 0){
      //if the user types in "SEARCH" go to the search function
      search(vect);
    }

    else if (strcmp(command, "RM") == 0){
      //if the user types in "RM", go to the remove function
      remove(vect);
    }
    
    else if (strcmp(command, "QUIT") == 0) {
      //quit the program
      break;
    }

    else {
      //prints the following message if the user types in an invalid command
      cout << "Not a valid command!" << endl;
    }
  }

  cout << "Thanks for using this program!";
  return 0;
}

void add(vector <Media*> &vect){
  //add function
  char command2[80]; //character array to take in user input
  
  while (true){
    //runs until it hits a break
	
    cout << "What type of media would you like to add? Type 'MUSIC' to add music, 'MOVIE' to add movies, 'VG' to add video games, or 'QUIT' to go back. ";
    cin.getline(command2, 6, '\n'); //takes in user input
	
    for (int i = 0; i < strlen(command2); i++){
      //converts all input to uppercase
      command2[i] = toupper(command2[i]);
    }

    if (strcmp(command2, "MUSIC") == 0){
      //makes a new music item and adds it to the vector if the user types in "MUSIC"
      Music *music = new Music();
      vect.push_back(music);
      break;
    }

    else if (strcmp(command2, "MOVIE") == 0){
      //makes a new movie item and adds it to the vector if the user type in "MOVIE"
      Movies *movie = new Movies();
      vect.push_back(movie);
      break;
    }

    else if (strcmp(command2, "VG") == 0) {
      //makes a new movie item and adds it to the vector if the user types in "VG"
      VG *vg = new VG();
      vect.push_back(vg);
      break;
    }

    else if (strcmp(command2, "QUIT") == 0) {
      //leaves the "add" function if the user doesn't want to add anything
      break;
    }

    else {
      //if the user types an invalid command, the following message prints and the user input field is cleared
      cout << "Not a valid command!" << endl;
      for (int i = 0; i < strlen(command2); i++){
	command2[i] = '\0';
      }
    }
  }
}

void search(vector <Media*> &vect){
  //the search function
  char command2[80]; //character array containing user's input
  if (!vect.empty()){
    //checks to make sure the vector has items in it before searching
    int increment = 0;
    cout << "Would you like to search by title or by year? "; //asks the user how they want to search
    cin.getline(command2, 6, '\n'); //takes in user input
    for (int i = 0; i < strlen(command2); i++){
      //capitalizes all user input
      command2[i] = toupper(command2[i]);
    }

    if (strcmp(command2, "TITLE") == 0){
      //if the user wants to search by title, the program asks them to type in the title, then checks the title with all other titles in the list. If there are no matching titles in the list, the user gets an output message saying so
      cout << "Please type the title of the media you want to find: ";
      cin.getline(command2, 80, '\n');
      cout << endl;
      for (vector <Media*> :: iterator it = vect.begin(); it != vect.end(); ++it) {
	if (strcmp(command2, (*it) -> returnTitle()) == 0){
	  (*it) -> print();
	  ++increment;
	}
      }

      if (increment == 0) {
	cout << "No item in the list matches your search!" << endl;;
      }
    }

    else if (strcmp(command2, "YEAR") == 0){
      //same thing as title above except with the year instead
      int year;
      cout << "Please type the year of the media you want to find: ";
      cin >> year;
      cin.ignore(4, '\n');
      for (vector <Media*> :: iterator it = vect.begin(); it != vect.end(); ++it) {
	if (year == (*it) -> returnYear()){
	  (*it) -> print();
	  ++increment;
	}
      }

      if (increment == 0) {
	cout << "No item in the list matches your search!" << endl;
      }
    }

    else {
      //if the input is not a valid input the following message prints
      cout << "Not a valid input!" << endl;
    }
  }

  else {
    //if there's nothing in the list then this message prints
    cout << "You have nothing in your list!" << endl;
  }
}

void remove(vector <Media*> &vect){
  //remove function

  //basically the same thing as the search function, except that this time the user is given a confirmation message asking whether or not they want to delete that particular item. If they do, then they can type in the affirmation message and that item will be deleted
  char command2[80];
  char agree = 'a';
  int increment = 0;
  
  if (!vect.empty()){
    cout << "Would you like to search by title or by year? ";
    cin.getline(command2, 6, '\n');
    for (int i = 0; i < strlen(command2); i++){
      command2[i] = toupper(command2[i]);
    }

    if (strcmp(command2, "TITLE") == 0){
      cout << "Please type the title of the media you want to delete: ";
      cin.getline(command2, 80, '\n');
      cout << endl;
      for (vector <Media*> :: iterator it = vect.begin(); it != vect.end(); ++it) {
	if (strcmp(command2, (*it) -> returnTitle()) == 0){
	  (*it) -> print();
	  ++increment;
	}
      }

      if (increment == 0) {
	cout << "No item in the list matches your search!" << endl;;
      }

      else {
	//prints out a confirmation message to make sure the user is okay with the following items being deleted. All items matching the user's search are deleted
	cout << "The above items will be deleted. Is this okay? [Y/N]";
	cin >> agree;
	cin.ignore(1, '\n');
	if (agree == 'Y' || agree == 'y'){
	  //if the user agrees, goes through the vector the same number of times as there are items in the list that match the user's search and deletes them all
	  for (int i = 0; i < increment; i++){
	    for (vector <Media*> :: iterator it = vect.begin(); it != vect.end(); ++it) {
	      if (strcmp(command2, (*it) -> returnTitle()) == 0){
		(*it) -> ~Media();
		vect.erase(it);
		break;
	      }
	    }
	  }
	}

	else if (!(agree == 'Y') || !(agree == 'y') || !(agree == 'N') || !(agree == 'n')){
	  //if the user types something else then that's not a valid command
	  cout << "Not a valid input!" << endl;
	}
      }
    }

    else if (strcmp(command2, "YEAR") == 0){
      int year;
      cout << "Please type the year of the media you want to find: ";
      cin >> year;
      cin.ignore(4, '\n');
      for (vector <Media*> :: iterator it = vect.begin(); it != vect.end(); ++it) {
	if (year == (*it) -> returnYear()){
	  (*it) -> print();
	  ++increment;
	}
      }

      if (increment == 0) {
	cout << "No item in the list matches your search!" << endl;
      }

      
      else {
	//prints out a confirmation message to make sure the user is okay with the following items being deleted. All items matching the user's search are deleted
	cout << "The above items will be deleted. Is this okay? [Y/N]";
	cin >> agree;
	cin.ignore(1, '\n');
	if (agree == 'Y' || agree == 'y'){
	  //if the user agrees, goes through the vector the same number of times as there are items in the list that match the user's search and deletes them all
	  for (int i = 0; i< increment; i++){
	    for (vector <Media*> :: iterator it = vect.begin(); it != vect.end(); ++it) {
	      if (year == (*it) -> returnYear()){
		(*it) -> ~Media();
		vect.erase(it);
		break;
	      }
	    }
	  }
	}

	else if (!(agree == 'Y') || !(agree == 'y') || !(agree == 'N') || !(agree == 'n')){
	  cout << "Not a valid input!" << endl;
	}
      }
    }
    else {
      cout << "Not a valid input!" << endl;
    }
  }

  else {
    cout << "You have nothing in your list!" << endl;
  }
}
