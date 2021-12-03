#include <iostream>
#include <cstring>
#include <vector>
#include "media.h"
#include "music.h"
#include "movies.h"
#include "vg.h"

using namespace std;

int main(){
  vector<Media*> vect;
  char command[5];
  char command2[80];
  while (true){
    cout << "Type a commmand to continue. 'ADD' adds media, 'RM' to deletes media from your directory, 'SEARCH' allows you to look for a specific media item in your directory, and 'QUIT'exits the program." << endl;
    cin.getline(command, 5);
    for (int i = 0; i < strlen(command); i++){
      command[i] = toupper(command[i]);
    }

    if (strcmp(command, "ADD") == 0){

      while (true){
	
	cout << "What type of media would you like to add? Type 'MUSIC' to add music, 'MOVIE' to add movies, 'VG' to add video games, or 'QUIT' to go back. ";
	cin.getline(command2, 6);
	//cin.ignore();
	
	for (int i = 0; i < strlen(command2); i++){
	  command2[i] = toupper(command2[i]);
	}

	if (strcmp(command2, "MUSIC") == 0){
	  Music *music = new Music();
	  vect.push_back(music);
	  break;
	}

	else if (strcmp(command2, "MOVIE") == 0){
	  Movies *movie = new Movies();
	  vect.push_back(movie);
	  break;
	}

	else if (strcmp(command2, "VG") == 0) {
	  VG *vg = new VG();
	  vect.push_back(vg);
	  break;
	}

	else if (strcmp(command2, "QUIT") == 0) {
	  for (int i = 0; i < strlen(command); i++){
	    command2[i] = '\0';
	  }
	  break;
	}

	else {
	  cout << "Not a valid command!" << endl;
	  for (int i = 0; i < strlen(command); i++){
	    command2[i] = '\0';
	  }
	}
      }
    }

    else if (strcmp(command, "SEARCH")){
      if (!vect.empty()){
	cout << "Would you like to search by title or by year? ";
	cin.getline(command2, 5);
	for (int i = 0; strlen(command2); i++){
	  command2[i] = toupper(command2[i]);
	}

	if (strcmp(command2, "TITLE") == 0){
	  int increment = 0;
	  cout << "Please type the title of the media you want to find: ";
	  cin.getline(command2, 80);
	  cout << endl;
	  for (vector <Media*> :: iterator it = vect.begin(); it != vect.end(); ++it) {
	    if (strcmp(command2, (*it) -> getTitle()) == 0){
	      (*it) -> print();
		++increment;
	      }
	  }

	  if (increment == 0) {
	    cout << "No item in the list matches your search!";
	  }
	}

	else if (strcmp(command2, "YEAR") == 0){
	  int year;
	  cout << "Please type the year of the media you want to find: ";
	  cin >> year;
	  
	}

	else {
	  cout << "Not a valid input!";
	}
      }

      else {
	cout << "You have nothing in your list to delete!";
      }
    }

    else if (strcmp(command, "QUIT") == 0) {
      break;
    }

    else {
      cout << "Not a valid command!" << endl;
    }
  }

  cout << "Thanks for using this program! I'm struggling with this C++ class and could really use your help!";
  return 0;
}
