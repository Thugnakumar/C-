/*
Name: Varun Krishnakumar
Date last modified: 10/14/21
This program enables 2 users to play TicTacToe. The game starts by having X play first, followed by O. The turns alternate until one of the users wins the game - as determined by the separate win conditions of 3 in a row, 3 in a column, or 3 diagonally - or there is a tie. When a user wins, the program prints out a message saying which user has won and prints out the number of times each user has won the game. After that, it asks if the user(s) want to play the game again. If the answer is no, then the program terminates. If it's yes, then the board clears and the game resets.
 */
#include <iostream>

using namespace std;

const int BLANK = 0;
const int XMOVE = 1;
const int OMOVE = 2;

//The following is a declaration of each function I use (besides main)
void clearBoard(int(&board)[3][3]);
void printBoard(int (&board)[3][3]);
void playerMove(int (&board)[3][3], int playerMove);
bool checkWin(int (&board)[3][3], int player);
bool boardFull(int (&board)[3][3]);

int main() {
  bool isPlaying = true; //checks if the user is still playing
  int playerTurn = 1; //checks which player's turn (X or O) it is
  int xWins = 0; //counts the number of times X has won
  int oWins = 0;//counts the number of times O has won
  int board[3][3]; //creates the board/int array
  clearBoard(board);
  printBoard(board);

  while (isPlaying == true){
    char playAgain = 'a'; //sets the isPlaying character to "a" so that it doesn't trigger the "y/n" function at the end
    
    playerMove(board, playerTurn); //activates playerMove() by passing in the board and the integer defining which player's turn it is
    if (playerTurn == 1){
      //switches the player's turn to O if it's currently X
      playerTurn = 2;
    }
    else if (playerTurn == 2){
      //switches the player's turn to X if it's currently O
      playerTurn = 1;
    }

    if (boardFull(board) == true || checkWin(board, XMOVE) == true || checkWin(board, OMOVE) == true){
      //the following code only activates if the board has no empty slots remaining (likely a tie) or if a player has won

      if (checkWin(board, XMOVE) == true){
	//checks if X has won, if X has won, then prints out the celebratory message and the number of times each player has won
	cout << "Player X wins!" << endl;
	xWins++;
	cout << "X wins: " << xWins << " O wins: " << oWins << endl;
      }

      else if (checkWin(board, OMOVE) == true){
	//checks if O has won, if O has won, then prints out the celebratory message and the number of times each player has won
	cout << "Player O wins!" << endl;
	oWins++;
	cout << "X wins: " << xWins << " O wins: " << oWins << endl;
      }
      
      else {
	//if neither of the above statements are true, it is a tie and the according message prints out
	cout << "Tie" << endl;
	cout << "X wins: " << xWins << " O wins: " << oWins << endl;
      }

      while (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N'){
	//keeps asking the player to enter y or n for whether or not they want to play again until they enter y or n
	cout << "Play again? (y/n) ";
	cin >> playAgain;
	cout << playAgain << endl;
      }

      if (playAgain == 'n' || playAgain == 'N'){
	//terminates the program if the user doesn't want to play again
	cout << "Goodbye!";
	isPlaying = false;
      }

      else {
	//resets the game if the user wants to play again
	clearBoard(board);
	printBoard(board);
	playerTurn = 1;
	continue;
      }
    }
  }
  return 0;
}

void printBoard(int (&board)[3][3]){
  //prints the board after each turn

  cout << "\t1\t2\t3  "<< endl; //the top of the grid
  for (int i = 0; i < 3; i++){
    cout << char('a'+ i) << '\t'; //the left end of grid
    for (int j = 0; j < 3; j++) {
      //iterates through each slot in the 2D array
      if (board[i][j] == XMOVE){
	//if the specific slot in the 2D array is XMOVE, it prints an X in the corresponding part of the grid
	cout << 'X';
      }

      else if (board[i][j] == OMOVE){
	//if the specific slot in the 2D array is OMOVE, it prints an O in the corresponding part of the grid
	cout << 'O';
      }

      else {
	//if the specific slot in the 2D array is BLANK, it prints a space in the corresponding part of the grid
	cout << ' ';
      }

      if (j < 2) {
	//prints the bars between columns to make the grid
	cout << char(board[i][j]) << "   " << '|' << "   ";
      }

      else {
	//enters a carriage return at the end of the line
	cout << char(board[i][j]) << '\n';
      }
      
    }
    if (i < 2) {
      //prints out the dividers between each row
      cout << " " << '\t' << "----+-------+----" << '\n';
    }
  }
}
void playerMove(int (&board)[3][3], int playerMove){
  //reads in where the player wants to place their marker, checks if it's a valid move, and places it on the board
  char row = 'f';//this character keeps track of the current row
  char column = '0';//this character keeps track of the current column
  char realRow = 88;//this character finds the specific row in the array (uses ASCII)
  char realColumn = 88;//this character finds the specific column in the array (uses ASCII)
  bool openSlot = false;//registers whether or not a specific slot is open

  while (openSlot == false){
    //keeps running until the user enters an input in a valid spot
    while (!(realRow >= 0 && realRow <= 2) && !(realColumn >= 0 && realColumn <= 2)) {
      //runs until the user inputs a valid row and column
      if (playerMove == 1){
	//prints "X turn: " if it's X's turn
	cout << "X turn: ";
      }

      else if (playerMove == 2){
	//prints "X turn: " if it's X's turn
	cout << "O turn: ";
      }
      
      cin >> row;//reads in user input for the row
      cin >> column;//reads in user input for the column
      cin.ignore(80,'\n');//removes any extra/unecessary characters

      row = toupper(row);//converts the column letter to an uppercase

      realRow = row - 65;//converts the row number to an ASCII value between 0 and 2
      realColumn = column - 49;//converts the column number to an ASCII value between 0 and 2

      if (!(realRow >= 0 && realRow <= 2) && !(realColumn >= 0 && realRow <= 2)) {
	//prints the following message if the input doesn't fall within the 0-2 boundary for row or column (after doing ASCII math)
	cout << "Please enter 'a', 'b', or c' for the row and '1', '2', or '3' for the column. No spaces please!" << endl;
      }
    }

    if (board[realRow][realColumn] != BLANK){
      //if there's already something in that specific array slot, print the following message and reset realRow and realColumn
      cout << "This spot is already taken!" << endl;
      realRow = 88;
      realColumn = 88;
      openSlot = false;
    }

    else {
      //if the current space is a BLANK, then openSlot is true, allowing it to be filled in with an X or O
      openSlot = true;
    }
  }

  if (playerMove == 1){
    //registers the user-specified slot as an XMOVE if it's X's turn
    board[int(realRow)][int(realColumn)] = XMOVE;
  }

  else {
    //registers the user-specified slot as an OMOVE if it's O's turn
    board[int(realRow)][int(realColumn)] = OMOVE;
  }

  printBoard(board);//prints the board after each turn with the updated markers
}

void clearBoard(int (&board)[3][3]){
  //goes through each index of the 2D array and sets the value to 0 (BLANK), thereby clearing the array of all markers
  for (int i = 0; i < 3; i ++) {
    for (int j = 0; j < 3; j++){
      board[i][j] = BLANK;
    }
  }
}

bool checkWin(int (&board)[3][3], int player){
  //checks all the win conditions for the specific player passed in and checks to see if any of those win conditions are met. If they are, then the function returns true. Otherwise, it returns false.
  if ((board[0][0] == player && board [0][1] == player && board[0][2] == player) || (board[1][0] == player && board[1][1] == player && board[1][2] == player) || (board[2][0] == player && board[2][1] == player && board[2][2] == player) || (board[0][0] == player && board[1][0] == player && board[2][0] == player) || (board[0][1] == player && board[1][1] == player && board[2][1] == player) || (board[0][2] == player && board[1][2] == player && board[2][2] == player) || (board[0][0] == player && board[1][1] == player && board[2][2] == player) || (board[0][2] == player && board[1][1] == player && board[2][0] == player)){
    return true;
  }

  return false;
}

bool boardFull(int (&board)[3][3]){
  //goes through each index of the board/array to see if any of them are spaces. If so, the program returns false. Otherwise, it returns true
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if (board[i][j] == BLANK){
	return false;
      }
    }
  }

  return true;
}
