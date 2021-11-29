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
  while (true){
    cout << "Type a commmand to continue. 'ADD' adds media, 'RM' to deletes media from your directory, 'SEARCH' allows you to look for a specific media item in your directory, and 'QUIT'exits the program." << endl;
    cin.getline(command, 5);
    for (int i = 0; i < strlen(command); i++){
      command[i] = toupper(command[i]);
    }

    if (strcmp(command, "ADD") == 0){
      cout << "What type of media would you like to add? Type 'MUSIC' to add music, 'MOVIE' to add movies, 'VG' to add video games, or 'QUIT' to go back. ";
      cin.getline(command, 5);

      while (true){
	
	for (int i = 0; i < strlen(command); i++){
	  command[i] = toupper(command[i]);
	}

	if (strcmp(command, "MUSIC") == 0){
	  Music *music = new Music();
	  vect.push_back(music);
	  break;
	}

	else if (strcmp(command, "MOVIE") == 0){
	  Movie *movie = new Movie();
	  vect.push_back(movie)
	    break;
	}

	else if (strcmp(command, "VG") == 0) {
	  VG *vg = new VG();
	  vect.push_back(vg);
	  break;
	}

	else if (strcmp(command, "QUIT") == 0) {
	  for (int i = 0; i < strlen(command); i++){
	    command[i] = '\0'
	  }
	  break;
	}

	else {
	  cout << "Not a valid command!" << endl;
	}
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
