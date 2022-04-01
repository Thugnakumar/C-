/*
Name: Varun Krishnakumar
Date: 3/28/22
This is the heap program! It takes in input from either a file or through user input and orders all the different numbers inputted from largest to smallest.
 */

#include <iostream>
#include <cstring>
#include <cctype>
#include <math.h>

using namespace std;

void storeToTree(int * tree, int inputSlot);

int main() {
  int input1 = 0;
  int input2 = 0;
  char arr[2];
  int tree[100];

  for (int i = 0; i < 100; ++i) {
    tree[i] = -1;
  }
  
  cout << "Would you like to input numbers manually (M) or using a file (F)? ";
  cin >> arr;
  if (strcmp(arr, "M") == 0 || strcmp(arr, "m") == 0) {
    cout << "How many numbers would you like to input? ";
    cin >> input1;
    for (int i = 0; i < input1; ++i) {
      cout << "Enter a number: ";
      cin >> input2;
      for (int j = 1; j < 100; ++j) {
	if (tree[j] == -1) {
	  tree[j] = input2;
	  storeToTree(tree, j);
	  break;
	}
      }

      for (int k = 1; k < 100; ++k) {
	if (tree[k] != -1) {
	  cout << tree[k] << ", ";
	}
      }
    }
  }
}

void storeToTree(int * tree, int inputSlot) {
  if (inputSlot > 1) {
    if (tree[inputSlot] > tree[(int)(floor(inputSlot/2))]) {
      int temp = tree[inputSlot];
      tree[inputSlot] = tree[(int)(floor(inputSlot/2))];
      tree[(int)(floor(inputSlot/2))] = temp;
      storeToTree(tree, (int)(floor(inputSlot/2)));
    }
  }
}

void sink(int * tree, int numIndex) {
  if (tree[numIndex] != -1) {
    if (tree[numIndex] < tree[numIndex * 2] || tree[numIndex] < tree[numIndex * 2 + 1]) {
      int largerIndex = 0;
      if (tree[numIndex * 2] > tree[numIndex * 2 + 1]) {
	largerIndex = numIndex * 2;
      }
      
      else {
	largerIndex = numindex * 2 + 1;
      }

      int temp = tree[numIndex];

      tree[numIndex] = tree[largerIndex];
      tree[largerIndex] = temp;
      sink(tree, largerIndex);
    }
  }
}
