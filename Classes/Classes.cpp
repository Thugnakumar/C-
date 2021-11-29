#include <iostream>
#include <cstring>
#include <vector>
#include "media.h"
#include "music.h"

using namespace std;

int main(){
  vector<Media*> vect;
  char command[10];
  while (true){
    cout << "Please enter the category of media that you want to enter. Type 'MUSIC' to enter new music videos, 'MOVIE' to enter a new movie, and 'VG' to enter a new video game. Type 'RM' to delete a media from your directory and 'PRINT' to print out your list of current media. Type'QUIT' to exit the program." << endl;
    cin >> command;
    for (int i = 0; i < strlen(command); i++){
      command[i] = toupper(command[i]);
    }

    if (strcmp(command, "MUSIC") == 0){
      Music *temp = new Music();
      vect.push_back(temp);
    }

    else if (strcmp(command, "MOVIE") == 0){
      //get movie info
    }

    else if (strcmp(command, "VG") == 0) {
      //get video game info
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
