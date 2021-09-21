/*
Name: Varun Krishnakumar
Date last worked: 9/21/21
Description: This program allows users to try guessing the number for as long as they want. Then, when they finally guess the number, the program prints the number of guesses that it took the user to guess the number. After that, the user is asked if they want to play the game again. If yes, the program resets with a completely new number. Otherwise, the user leaves the program. The user can play as many times as they wish.
 */
#include <iostream>
#include <time.h>

using namespace std;

int main(){
  //This is where all of the code sits
  
  bool isRunning = true;

  while (isRunning == true){
    //while the isRunning boolean evaluates to true, the entire program keeps running
    
    int input = 101;//this variable tracks the user's input. it is initialized to 101 so that the input can never be equal to the random number initially

    int counter = 0; //this variable tracks the number of guesses it takes the user to guess the number

    char running = 'p';//this variable takes in the input for whether or not a user wants to play again or exit the program
    
    srand (time(NULL));
    int randomNum = rand() % 100; //picks a random number between 0 and 100

    while (input != randomNum){
      //keeps running until the user guesses the number
      
      cout << "Please enter your guess: ";
      cin >> input;
      counter ++;

      if (input > randomNum){
	//Tells the user if their guess is too high
	cout << "Your guess is too high!" << endl;
      }

      else if (input < randomNum){
	//Tells the user if their guess is too low
	cout << "Your guess is too low!" << endl;
      }
    }

    cout << "You guessed the number! It took you " << counter << " guesses!"<< endl;
    //tells the user that they guessed the number

    while (running != 'y' && running != 'Y'&& running != 'n' && running != 'N'){
      cout << "Play again? (y/n)" << endl;
      cin >> running;
      //Asks the user to type y or n for if they want to play again, and keeps asking them until they type either y or n
    }
    
    
    if (running == 'y' || running == 'Y'){
      isRunning = true;
      //if the user types y, then the program loops back to the start and runs again with a different random number
    }

    else {
      isRunning = false;
      //if the user types n, then the code exits the program and prints the message "Goodbye!"
    }
  }

  cout << "Goodbye!" << endl;
}
