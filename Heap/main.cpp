/*
Name: Varun Krishnakumar
Date: 3/28/22
This is the heap program! It takes in input from either a file or through user input and orders all the different numbers inputted from largest to smallest.
 */

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
  int input1 = 0;
  int input2 = 0;
  char arr[2];
  int inputNums[100];
  int tree[100];

  for (int i = 0; i < 100; ++i) {
    inputNums[i] = -1;
  }
  
  cout << "Would you like to input numbers manually (M) or using a file (F)? ";
  cin >> arr;
  if (strcmp(arr, "M") == 0 || strcmp(arr, "m") == 0) {
    cout << "How many numbers would you like to input? ";
    cin >> input1;
    for (int i = 0; i < input1; ++i) {
      cout << "Enter a number: ";
      cin >> input2;
      for (int i = 0; i < 100; ++i) {
	if (inputNums[i] == -1) {
	  inputNums[i] = input2;
	  cout << inputNums[i] << endl;
	  break;
	}
      }
    }
  }

  for (int i = 1; i < 100; ++i) {
    
  }
}

int makeTree(int * unorderedList, int * &orderedList) {
  //look at each element in the unordered list and recursively create a tree with it somehow
  int largest = 0;
  
  for (int i = 0; i < 100; ++i) {
    if (unorderedList[i] != -1 && unorderedList[i-1] != -1) {
      if 
    }
  }

  return largest;
}
