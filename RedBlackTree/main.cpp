/*
Name: Varun Krishnakumar
Date: 4/18/22
This is the binary search tree program! It takes in input from the user or from a file and turns it into a binary search tree! The user can then search for a particular number, delete a particular number, or print a visual representation of the tree. If the user wants to delete a number, then the tree updates.
 */

//all the libraries
#include <iostream>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <fstream>

using namespace std;

struct node {
  //node struct with data and left and right node pointers
  int data;
  node * left;
  node * right;
  char color;
};

void addToTree(node * current, node * &root, node * newNode);
void removeFromTree(node * current, node * parent, int deleteNum);
void searchTree(node * current, int searchNum, bool &found);
void printTree(node * current, int treeDepth);
void parentAndUncleRed(node * current, node * parent, node * grandparent);

int main() {
  //where everything happens
  char arr[2]; //character array for storing user command input
  int numOfNums = 0; //variable to keep track of the number of numbers in the file
  int numInput; //variable for reading in a number from a file (one at a time)
  bool found = false; //boolean for searching
  node * root = NULL; //root node
  
  cout << "Welcome to the Binary Search Tree program!" << endl;
  while (true) {
    cout << "What would you like to do?" << endl;
    cout << "Would you like to Add (A) a data value, Remove (R) a data value, Search (S) for a data value, Print (P) the tree, or Quit (Q)? ";
    cin >> arr; //reads in user command
    for (int i = 0; i < strlen(arr); ++i) {
      //converts user input to uppercase
      arr[i] = toupper(arr[i]);
    }

    if (strcmp(arr, "A") == 0) {
      //adds a node if that is the user command
      cout << "Would you like to add in manually (M) or through a file (F)? ";
      cin >> arr;

      for (int i = 0; i < strlen(arr); ++i) {
	//converts user input to uppercase
	arr[i] = toupper(arr[i]);
      }
      
      if (strcmp(arr, "M") == 0) {
	cout << "How many numbers would you like to input? ";
	cin >> numOfNums;
	for (int i = 0; i < numOfNums; ++i) {
	  //creates a new node with the number inputted as data
	  node * newNode = new node();
	  newNode->right = NULL;
	  newNode->left = NULL;
	  cout << "What number would you like to input? ";
	  cin >> newNode->data;
	  newNode->color = "R";

	  addToTree(root, root, newNode);
	}
      }

      else if (strcmp(arr, "F") == 0) {
	//if the user wants to input using a file, it specifies the file name and stores each of the numbers in the file to the tree
        ifstream numInput;
        numInput.open("numList.txt");

        while (!numInput.eof()) {
	  node * newNode = new node();
	  newNode->right = NULL;
	  newNode->left = NULL;
	  numInput >> newNode->data;
	  newNode->color = "R";
	  
	  if (newNode->data != 0) {
	    addToTree(root, root, newNode);
	  }
        }
      }

      else {
        cout << "Not a valid input!" << endl;
      }
    }

    else if (strcmp(arr, "R") == 0) {
      //removes a node if that is the user command
      cout << "What number would you like to remove? ";
      cin >> numInput;
      removeFromTree(root, NULL, numInput);
    }

    else if (strcmp(arr, "S") == 0) {
      //searches for a node if that is the user command
      cout << "What number would you like to search for? ";
      cin >> numInput;
      found = false;
      searchTree(root, numInput, found);
      if (found == true) {
	cout << numInput << " is in the tree!" << endl;
      }

      else {
	cout << numInput << " isn't in the tree!" << endl;
      }
    }

    else if (strcmp(arr, "P") == 0) {
      //prints the tree if that is the user command
      printTree(root, 0);
    }

    else if (strcmp(arr, "Q") == 0){
      //exits the program if that is the user command
      break;
    }

    else {
      cout << "Not a valid input!" << endl;
    }
  }
}

void addToTree(node * current, node * &root, node * newNode) {    
  if (current == root && current == NULL) {
    //if there's currently nothing in the tree, then sets the first node made to be the head
    root = newNode;
    newNode->color = "B";
  }
  
  else {
    //if there's something in the tree...
    if (newNode->data > current->data) {
      //if the new node's data is larger than the current node's data, move to the right node provided it isn't NULL
      if (current->right != NULL) {
	addToTree(current->right, root, newNode);
      }

      else {
	//if the right node is NULL, set this node to be the right node
	current->right = newNode;
      }
    }

    else if (newNode->data <= current->data) {
      //if the new node's data is less than the current node's data, move to the left node provided it isn't NULL
      if (current->left != NULL) {
	addToTree(current->left, root, newNode);
      }

      else {
	//if the left node is NULL, set this tnode to be the left node
	current->left = newNode;
      }
    }
  }
}

void searchTree(node * current, int searchNum, bool &found) {
  if (found == true) {
    //if the number has already been found, stop traversing the tree
    return;
  }

  if (current->data != searchNum) {
    //if the current node's data is not equal to the number we're searching for...
    if (current->data > searchNum) {
      //if the current node's data is larger than the number we're searching for and the node to the left has an actual value, then traverse to the left
      if (current->left != NULL) {
	searchTree(current->left, searchNum, found);
      }
    }

    else if (current->data < searchNum) {
      //if the current node's data is smaller than the number we're searching for and the node to the right has an actual value, then traverse to the right
      if (current->right != NULL) {
	searchTree(current->right, searchNum, found);
      }
    }
  }

  else {
    //if the current node's data is equal to the number we're looking for, set the "found" boolean to true to signal that the number has been found
    found = true;
  }
}

void removeFromTree(node * current, node * parent, int deleteNum) {
  if (current->data != deleteNum) {
    //if the current node's data is not equal to the number we're searching for...
    if (current->data > deleteNum) {
      //if the current node's data is larger than the number we're searching for and the node to the left has an actual value, then traverse to the left
      if (current->left != NULL) {
	removeFromTree(current->left, current, deleteNum);
      }
    }

    else if (current->data < deleteNum) {
      //if the current node's data is smaller than the number we're searching for and the node to the right has an actual value, then traverse to the right
      if (current->right != NULL) {
	removeFromTree(current->right, current, deleteNum);
      }
    }
  }

  else {
    //if the current node's data is equal to the number we're looking for, check the number of children it has
    if (current->right != NULL || current->left != NULL) {
      //if it even has children...
      if (current->right != NULL && current->left == NULL) {
	//if there's only a right child, delete the current node and set the previous node's next to be the right child
	if (parent->left == current) {
	  //if the "to be deleted" node is the left child of the parent, then set the right child of the current node to be the left child of the parent node
	  parent->left = current->right;
	  delete current;
	}

	else if (parent->right == current) {
	  //if the "to be deleted" node is the right child of the parent, then set the left child of the current node to be the right child of the parent node
	  parent->right = current->right;
	  delete current;
	}
      }

      else if (current->left != NULL && current->right == NULL) {
	//if there's only a left child, delete the current node and set the previous node's next to be the left child
	if (parent->left == current) {
	  //if the "to be deleted" node is the left child of the parent, then set the right child of the current node to be the left child of the parent node
	  parent->left = current->left;
	  delete current;
	}

	else if (parent->right == current) {
	  //if the "to be deleted" node is the right child of the parent, then set the left child of the current node to be the right child of the parent node
	  parent->right = current->left;
	  delete current;
	}
      }

      else {
	//if there are 2 children...
	int numLeft = 0; //integer for keeping track of how many times it goes left in the right-left-left-left... sequence
	node * toBeDeleted = current; //stores the node that needs to be deleted in a separate pointer
	parent = current; //sets parent equal to the current node
	current = current->right; //moves the current node one over to the right

	cout << "Current: " << current->data << endl;

	while (current->left != NULL) {
	  //continuously moves both the parent and child left until there's no next left node
	  parent = current;
	  current = current->left;
	  numLeft++;
	  cout << "Current: " << current->data << endl;
	}

	cout << "Node to be deleted: " << toBeDeleted->data << endl;

	toBeDeleted->data = current->data; //changes the "to be deleted" node's data to equal that of the current node
	/*if (numLeft > 0) {
	  parent->left = current->right; //resets the parent pointer
	  }*/

	if (numLeft == 0) {
	  //if there's no left node in the right-left-left-left... sequence, then set the parent's right to be equal to current's right
	  parent->right = current->right;
	}
	delete current; //delete current
	
      }
    }

    else {
      //set previous node's next to be NULL and delete the current node since there are no children
      if (parent->left == current) {
	//if the "to be deleted" node is to the left of its parent, then set the parent node's next to be NULL and delete the current node
	parent->left = current->right;
	delete current;
      }

      else if (parent->right == current) {
	//if the "to be deleted" node is to the right of its parent, then set the parent node's next to be NULL and delete the current node
	parent->right = current->right;
	delete current;
      }
    }
  }
}

void printTree(node * current, int treeDepth) {
  //function to print the tree
  if (current->right != NULL) {
    //continuously checks to the right of the current node and updates the tree depth and current index each time IF we're not at the\
 end of the tree and the current index isn't NULL
    printTree(current->right, treeDepth + 1);
  }

  for (int i = 0; i < treeDepth; ++i) {
    //prints the appropriate number of tabs
    cout << '\t';
  }

  //prints the value of the current index of the tree
  cout << current->data << endl;

  if (current->left != NULL) {
    //continuously checks to the left of the current node and updates the tree depth and current index each time IF we're not at the \
end of the tree and the current index isn't NULL
    printTree(current->left, treeDepth + 1);
  }
}

void parentAndUncleRed(node * current, node * parent, node * grandparent) {
  if (grandparent->left != NULL && grandparent->right != NULL) {
    if (grandparent->right == parent) {
      if (parent->color == "R" && grandparent->left == "R") {
      }
    }

    else if (grandparent->left == parent) {
      if (parent->color == "R" && grandparent->right == "R") {
      }
    }
}
