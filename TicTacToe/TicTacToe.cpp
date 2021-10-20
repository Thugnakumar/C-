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
void playerMove(int (&board)[3][3]);

int main() {
  int board[3][3];
  clearBoard(board);
  printBoard(board);
  playerMove(board);
  return 0;
}

void printBoard(int (&board)[3][3]){

  board[0][1] = XMOVE;
  cout << board[0][2] << endl;
  cout << "\t1\t2\t3  "<< endl;
  for (int i = 0; i < 3; i++){
    cout << char('a'+ i) << '\t';
    for (int j = 0; j < 3; j++) {
      //cout << board[i][j] << endl;
      if (board[i][j] == XMOVE){
	cout << 'X';
      }

      else if (board[i][j] == OMOVE){
	cout << 'O';
      }

      else {
	cout << ' ';
      }

      if (j < 2) {
	cout << char(board[i][j]) << "   " << '|' << "   ";
      }

      else {
	cout << char(board[i][j]) << '\n';
      }
      
    }
    if (i < 2) {
      cout << " " << '\t' << "----+-------+----" << '\n';
    }
  }
}
void playerMove(int (&board)[3][3]){
  int playerMove = 1;
  char row = 'f';
  char column = '0';
  char turn = 'X';
  char realRow = 88;
  char realColumn = 88;
  bool openSlot = false;

  while (openSlot == false){
    while (!(realRow > 47 && realRow < 51) && !(realColumn > 47 && realColumn < 51)) {
      if (turn == 'X'){
	cout << turn << " turn: ";
      }

      else if (turn == 'O'){
	cout << turn << " turn: ";
      }
      
      cin >> row;
      cin >> column;

      row = toupper(row);

      realRow = row - 17;
      realColumn = column - 1;

      if (!(realRow > 47 && realRow < 51) && !(realColumn > 47 && realRow < 51)) {
	cout << "Please enter 'a', 'b', or c' for the row and '1', '2', or '3' for the column. No spaces please!" << endl;
      }
    }

    if (board[realRow][realColumn] != BLANK){
      cout << "This spot is already taken!" << endl;
      openSlot = false;
    }

    else {
      openSlot = true;
    }
  }

  cout << realRow << realColumn << endl;

  if (turn == 'X'){
    turn = 'O';
  }

  else if (turn == 'O'){
    turn = 'X';
  }
  
  if (playerMove == 1){
    board[int(realRow)][int(realColumn)] = XMOVE;
    cout << "Xmove: " << board[int(realRow)][int(realColumn)] << endl;
    playerMove = 2;
  }

  else {
    board[int(realRow)][int(realColumn)] = OMOVE;
    playerMove = 1;
  }

  printBoard(board);
}

void clearBoard(int (&board)[3][3]){
  for (int i = 0; i < 3; i ++) {
    for (int j = 0; j < 3; j++){
      board[i][j] = BLANK;
    }
  }
}

