#include <iostream>
#include <cstring>
#include <vector>
#include "media.h"

using namespace std;

int main(){
  vector<Media*> vect;
  char command[5];
  while (true){
    cout << "Please enter the category of media that you want to enter. Type 'MUSIC' to enter new music videos, 'MOVIE' to enter a new movie, and 'VG' to enter a new video game. Type 'RM' to delete a media from your directory and 'PRINT' to print out your list of current media. Type'QUIT' to exit the program.";
    cin >> command;
    for (int i -= 0; i < strlen(command); i++){
      command[i] = toupper(command[i]);
    }

    if (command == "MUSIC"){
      //get music commands
    }

    else if (command == "MOVIE"){
      //get movie info
    }

    else if (command == "VG") {
      //get video game info
    }

    else if (command == "QUIT") {
      break;
    }

    else {
      cout << "Not a valid command!" << endl;
    }
  }

  cout << "Thanks for using this program! I'm struggling with this C++ class and could really use your help!"
  Media* temp = new Media();
  vect.push_back(temp);
  return 0;
}
