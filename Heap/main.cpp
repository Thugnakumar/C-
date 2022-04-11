/*
Name: Varun Krishnakumar
Date: 3/28/22
This is the heap program! It takes in input from either a file or through user input and displays all of the numbers in a tree-like structure/format.
 */

#include <iostream>
#include <cstring>
#include <cctype>
#include <math.h>
#include <iomanip>
#include <fstream>

using namespace std;

//all the functions
void storeToTree(int * tree, int inputSlot);
void sink(int * tree, int numIndex);
void printRoot(int * tree);
void printTree(int * tree, int index, int treeDepth, int treeSize);

int main() {
  //where everything happens
  
  int input1 = 0; //for seeing how many numbers the user wants to input (if inputting manually)
  int input2 = 0; //for seeing the actual number the user inputs
  char arr[2]; //for taking in input for operations
  int tree[100]; //the tree...ooooooooh

  for (int i = 0; i < 100; ++i) {
    //sets all values in the tree to -1 (numerical version of NULL)
    tree[i] = -1;
  }
  while (true) {
    //runs forever
    cout << "Would you like to input numbers (I), print the tree (P), or print all numbers in the tree from largest to smallest (L)? "; //asks the user what they want to do
    cin >> arr;
    if (strcmp(arr, "I") == 0 || strcmp(arr, "i") == 0) { //if the user wants to input numbers...
      cout << "Would you like to input numbers manually (M) or using a file (F)? "; //asks the user if they want to input using their keyboard or a file
      cin >> arr;
      if (strcmp(arr, "M") == 0 || strcmp(arr, "m") == 0) { //if the user wants to input manually...
	cout << "How many numbers would you like to input? "; //asks how many numbers the user wants to input
	cin >> input1;
	for (int i = 0; i < input1; ++i) {
	  //asks the user to input a number until the number of numbers quota is reached
	  cout << "Enter a number: ";
	  cin >> input2;
	  for (int j = 1; j < 100; ++j) {
	    //for each element in the tree...
	    if (tree[j] == -1) {
	      //puts the inputted number into the first empty index, then orders it, then breaks
	      tree[j] = input2;
	      storeToTree(tree, j);
	      break;
	    }
	  }
	}
      }

      else if (strcmp(arr, "F") == 0 || strcmp(arr, "f") == 0) {
	//if the user wants to input using a file, it specifies the file name and stores each of the numbers in the file to the tree
	ifstream input2;
	input2.open("numList.txt");

	for (int i = 1; i < 100; ++i) {
	  input2 >> tree[i];
	  storeToTree(tree, i);
	}

	cout << "Inputted!" << endl;
      }

      else {
	cout << "Not a valid input!" << endl;
      }
    }

    else if (strcmp(arr, "P") == 0 || strcmp(arr, "p") == 0) {
      //if the user wants to print the tree...
      cout << endl;
      int treeSize = 1;
      while (tree[treeSize] != -1) {
	//constantly updates the size of the tree
	treeSize++;
      }

      printTree(tree, 1, 0, treeSize); //calls the function to print the tree
    }

    else if (strcmp(arr, "l") == 0 || strcmp(arr, "L") == 0) {
      //if the user wants to print out all the numbers in the tree from largest to smallest, the program asks the user for confirmation since it's a one-time operation. If the user wants to proceed, it recursively prints the root and destroys the tree. Otherwise, it goes back to the operations menu or tells the user that their input was invalid.
      cout << "This is a one-time operation. Are you sure you want to print everything in the tree from largest to smallest (Y/N)? ";
      cin >> arr;
      if (strcmp(arr, "Y") == 0 || strcmp(arr, "y") == 0) {
	printRoot(tree);
	break;
      }

      else if (strcmp(arr, "N") == 0 || strcmp(arr, "n") == 0) {
	cout << "What would you like to do?" << endl;
      }

      else {
	cout << "Not a valid input!" << endl;
      }
    }
  }
}

void storeToTree(int * tree, int inputSlot) {
  //function to organize things in the tree
  if (inputSlot > 1) {
    //if the entered slot isn't the first index of the array...
    if (tree[inputSlot] > tree[(int)(floor(inputSlot/2))]) {
      //if the inputted number is larger than it's current parent, then swap the inputted number and its parent
      int temp = tree[inputSlot];
      tree[inputSlot] = tree[(int)(floor(inputSlot/2))];
      tree[(int)(floor(inputSlot/2))] = temp;

      //follow the inputted number up the tree until it is smaller than its parent or is the root
      storeToTree(tree, (int)(floor(inputSlot/2)));
    }
  }
}

void sink(int * tree, int numIndex) {
  //function to reorganize the tree when the root node is deleted
  if (tree[numIndex] != -1) {
    //if the entered index doesn't have a NULL value associated with it...
    if (tree[numIndex] < tree[numIndex * 2] || tree[numIndex] < tree[numIndex * 2 + 1]) {
      //if the entered index is less than its child, then find the number that's larger and store it in a variable
      int largerIndex = 0;
      if (tree[numIndex * 2] > tree[numIndex * 2 + 1]) {
	largerIndex = numIndex * 2;
      }
      
      else {
	largerIndex = numIndex * 2 + 1;
      }

      int temp = tree[numIndex];

      //swap the current number and its child
      tree[numIndex] = tree[largerIndex];
      tree[largerIndex] = temp;

      //follow the current number down the tree until it is larger than its child
      sink(tree, largerIndex);
    }
  }
}

void printRoot(int * tree) {
  //function to print the currently largest number in the tree
  if (tree[1] != -1) {
    //if the first index of the tree is not "NULL"...
    cout << tree[1] << ", "; //print that number
    for (int i = 1; i < 100; ++i) {
      //iterate through the tree to the last index of the tree and then set the root of the tree to be the last index of the tree (smallest value)
      if (tree[i+1] == -1) {
	tree[1] = tree[i];
	tree[i] = -1;
	break;
      }
    }
    sink(tree, 1); //call sink to reorganize the tree
    printRoot(tree);//print the root and repeat the process again until all of the values in the tree have been printed
  }
}

void printTree(int * tree, int index, int treeDepth, int treeSize) {
  //function to print the tree
  if (index * 2 + 1 <= treeSize && tree[index * 2 + 1] != -1) {
    //continuously checks to the right of the current node and updates the tree depth and current index each time IF we're not at the end of the tree and the current index isn't NULL
    printTree(tree, index * 2 + 1, treeDepth + 1, treeSize);
  }

  for (int i = 0; i < treeDepth; ++i) {
    //prints the appropriate number of tabs
    cout << '\t';
  }

  //prints the value of the current index of the tree
  cout << tree[index] << endl;

  if (index * 2 <= treeSize && tree[index * 2] != -1) {
    //continuously checks to the left of the current node and updates the tree depth and current index each time IF we're not at the end of the tree and the current index isn't NULL
    printTree(tree, index * 2, treeDepth + 1, treeSize);
  }
}
