/*
Name: Varun Krishnakumar
Date: 3/28/22
This is the heap program! It takes in input from either a file or through user input and orders all the different numbers inputted from largest to smallest.
 */

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

struct bnode {
  bnode * right;
  bnode * left;
  int data;
};

void createAndAdd(int number);

int main() {
  int input = 0;
  char arr[2];
  int inputNums[100];
  //  int heap[];

  for (int i = 0; i < 100; ++i) {
    inputNums[i] = -1;
  }
  
  cout << "Would you like to input numbers manually (M) or using a file (F)? ";
  cin >> arr;
  if (arr == "M" || arr == "m") {
    cout << "How many numbers would you like to input?";
    cin >> input;
    for (int i = 0; i < input; ++i) {
      cout << "Enter a number: ";
      cin >> input;
      for (int i = 0; i < 100; ++i) {
	if (inputNums[i] == -1) {
	  inputNums[i] = input;
	  break;
	}
      }
    }
    for (int i = 0; i < 100; ++i) {
      if (inputNums[i] != -1) {
	cout << inputNums[i];
      }
    }
  }
  while (true) {
    cout << "Enter a number: ";
    cin >> input;
    createAndAdd(input);
  }
}

void createAndAdd(int number) {
  bnode * newBnode = new bnode();
  newBnode->right = NULL;
  newBnode->left = NULL;
  newBnode->data = number;
}
