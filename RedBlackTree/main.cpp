/*
Name: Varun Krishnakumar
Date: 5/3/22
This is the red black tree program! It takes in input from the user or from a file and turns it into a binary search tree! Each node of the tree has a color associated with it and the colors can only occur in certain patterns. The tree restructures itself until those pattern requirements are fulfilled.
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
  node * parent;
  char color;
};

void addToTree(node * current, node * &root, node * newNode);
void removeFromTree(node * current, node * parent, node * &root, int deleteNum);
void searchTree(node * current, int searchNum, bool &found);
void printTree(node * current, int treeDepth);
void insertionBalance(node * current, node * parent, node * grandparent, node * &root);
void deletionBalance(node * current, node * parent, node * grandparent, node * &root);

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
    cout << "Would you like to Add (A) a data value, Print (P) the tree, Remove (R) a number from the tree, Search (S) the tree for a number, or Quit (Q)? ";
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
	  newNode->parent = NULL;
	  cout << "What number would you like to input? ";
	  cin >> newNode->data;
	  newNode->color = 'R';

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
	  newNode->color = 'R';
	  
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
      removeFromTree(root, NULL, root, numInput);
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
    newNode->color = 'B';
  }
  
  else {
    //if there's something in the tree...
    bool entered = false; //boolean for seeing if the node was entered in the tree

    while (entered == false) {
      //if the node has not yet been entered in the tree...
      if (newNode->data > current->data) {
	//if the newly inserted node's data is larger than the current node's data...
	if (current->right != NULL) {
	  //if there is a right node, then traverse to the right
	  current = current->right;
	}

	else {
	  //if there is no right node, then set the new node to be the right of the current node and set "entered" to true since we have just entered the node into the tree
	  current->right = newNode;
	  entered = true;
	}
      }

      else {
	//if the newly inserted node's data is less than or equal to the current node's data...
	if (current->left != NULL) {
	  //if there is a left node, then traverse to the left
	  current = current->left;
	}

	else {
	  //if there is no left node, then set the new node to be the left of the current node andset "entered" to true since we have just entered the node into the tree
	  current->left = newNode;
	  entered = true;
	}
      }
    }

    newNode->parent = current; //set the just entered node's parent to be the current node that you're on
  }

  if (newNode->parent != NULL && newNode->parent->parent != NULL) {
    //if the recently entered node has both a parent and grandparent, run the balance function
    insertionBalance(newNode, newNode->parent, newNode->parent->parent, root);
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

void removeFromTree(node * current, node * parent, node * & root, int deleteNum) {

  while (current->data != deleteNum) {
    //if the current node's data is not equal to the number we're searching for...
    if (current->data > deleteNum) {
      //if the current node's data is larger than the number we're searching for and the node to the left has an actual value, then traverse to the left
      if (current->left != NULL) {
	parent = current;
	current = current->left;
      }
    }

    else if (current->data < deleteNum) {
      //if the current node's data is smaller than the number we're searching for and the node to the right has an actual value, then traverse to the right
      if (current->right != NULL) {
	parent = current;
	current = current->right;
      }
    }
  }
                                                                                                                                  
  //if the current node's data is equal to the number we're looking for, check the number of children it has
  if (current->right != NULL || current->left != NULL) {
    //if it even has children...
    if (current->right != NULL && current->left == NULL) {
      //if there's only a right child, delete the current node and set the previous node's next to be the right child
      if (parent->left == current) {
	//if the "to be deleted" node is the left child of the parent, then set the right child of the current node to be the left child of the parent node
	parent->left = current->right;

	if (current->color == 'B' && parent->left != NULL) {
	  parent->left->color = 'B';
	}
	  
	delete current;
      }

      else if (parent->right == current) {
	//if the "to be deleted" node is the right child of the parent, then set the left child of the current node to be the right child of the parent node
	parent->right = current->right;

	if (current->color == 'B' && parent->right != NULL) {
	  parent->right->color = 'B';
	}
	  
	delete current;
      }
    }

    else if (current->left != NULL && current->right == NULL) {
      //if there's only a left child, delete the current node and set the previous node's next to be the left child
      if (parent->left == current) {
	//if the "to be deleted" node is the left child of the parent, then set the right child of the current node to be the left child of the parent node
	parent->left = current->left;

	if (current->color == 'B' && parent->left != NULL) {
	  parent->left->color = 'B';
	}
	
	delete current;
      }

      else if (parent->right == current) {
	//if the "to be deleted" node is the right child of the parent, then set the left child of the current node to be the right child of the parent node
	parent->right = current->left;

	if (current->color == 'B' && parent->right != NULL) {
	  parent->left->color = 'B';
	}
	
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

      deletionBalance(current, parent, parent->parent, root);
      
      if (numLeft > 0) {
	parent->left = current->right; //resets the parent pointer
      }

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
  cout << current->data << "--" << current->color << endl;

  if (current->left != NULL) {
    //continuously checks to the left of the current node and updates the tree depth and current index each time IF we're not at the \
    end of the tree and the current index isn't NULL
    printTree(current->left, treeDepth + 1);
  }
}

void insertionBalance(node * current, node * parent, node * grandparent, node * &root) {
  if (current != NULL && parent != NULL && grandparent != NULL) {
    //double check to make sure that the current node exists and it has a parent and grandparent
    
    if (grandparent != NULL && grandparent->left != NULL && grandparent->right != NULL) {
      //case 3
      //if the grandparent node actually exists and it has 2 children...
      if (grandparent->right == parent) {
	//check to see if the grandparent's right node is the parent node
	if (parent->color == 'R' && grandparent->left != parent && grandparent->left->color == 'R') {
	  //if both the parent and uncle are red, then change the uncle's color to black
	  grandparent->left->color = 'B';
	  grandparent->color = 'R';
	  parent->color = 'B';
	}
      }

      else if (grandparent->left == parent) {
	//if the grandparent's left child is the parent node...
	if (parent->color == 'R' && grandparent->right != parent && grandparent->right->color == 'R') {
	  //if both the parent and uncle are red again, then change the uncle to black
	  grandparent->right->color = 'B';
	  grandparent->color = 'R';
	  parent->color = 'B';
	}
      }

      if (grandparent->parent != NULL && grandparent->parent->parent != NULL) {
	//recursively call this function on the grandparent until the grandparent's parent and/or grandparent aren't NULL
	insertionBalance(grandparent, grandparent->parent, grandparent->parent->parent, root);
      }

      current->parent = parent; //resets the parent pointer in case the above recursive call messes up the order of things
      current->parent->parent = grandparent; //resets the grandparent pointer in case the above recursive call messes up the order of things
    }

    if (parent != NULL && grandparent != NULL) {
      //case 4
      //double-check to make sure parent and grandparent actually exist (since recursive case 3 call might alter the parent and grandparent)
      if (parent->color == 'R' && parent->right == current && current->color == 'R' && (grandparent->right == NULL || grandparent->right->color=='B')) {
	//if the current node is to the right of the parent and the uncle is black then engage tree rotation
	grandparent->left = current;//sets the grandparent's left to be current (instead of parent)
	current->parent = grandparent; //set the current node's parent to be the grandparent
	parent->right = current->left; //set the parent's right to be the left subtree of the current node
	current->left = parent; //set the current's left to be the parent node
	parent->parent = current; //set the parent's new parent to be the current node
	node * temp = current;
	current = parent;
	parent = temp;
      }

      else if (parent->color == 'R' && parent->left == current && current->color == 'R' && (grandparent->left == NULL || grandparent->left->color=='B')) {
	//if the current node is to the right of the parent and the uncle is black then engage tree rotation
	grandparent->right = current;//sets the grandparent's right to be current (instead of parent)
	current->parent = grandparent; //set the current node's parent to be the grandparent
	parent->left = current->right; //set the parent's left to be the right subtree of the current node
	current->right = parent; //set the current's right to be the parent node
	parent->parent = current; //set the parent's new parent to be the current node
	node * temp = current;
	current = parent;
	parent = temp;
      }
    }

    if (grandparent != NULL) {
      //case 5
      bool case5Done = false;
      //if the grandparent exists (i.e. the parent isn't the root)
      node * greatGrandparent = grandparent->parent; //create a greatGrandparent pointer (can be NULL)

      if (parent->color == 'R' && grandparent->left == parent && parent->left == current && (grandparent->right == NULL || grandparent->right->color == 'B')) {
	//if the grandparent's left is the parent and the parent's left is the current node (basically what case 4 set up), then change pointers
	grandparent->left = parent->right; //set the grandparent's left subtree to be the parent's right subtree
	parent->right = grandparent; //set the parent's right to be the grandparent now
	grandparent->parent = parent; //set the grandparent's new parent to be the original parent

	if (grandparent->left != NULL) {
	  //if grandparent's new left isn't NULL, then set its parent to be the grandparent
	  grandparent->left->parent = grandparent;
	}

	if (greatGrandparent != NULL) {
	  //if the great grandparent exits...
	  if (greatGrandparent->left == grandparent) {
	    //if the grandparent is the left child of the great grandparent, then set the parent to be the left child of the great grandparent
	    greatGrandparent->left = parent;
	  }

	  else if (greatGrandparent->right == grandparent){
	    //if the grandparent is the right child of the great grandparent, then set the parent to be the right child of the great grandparent
	    greatGrandparent->right = parent;
	  }
	  //if the parent isn't the root now, then set parent's parent to be the great grandparent
	}

	parent->parent = greatGrandparent;
	case5Done = true;
      }

      else if (parent->color == 'R' && grandparent->right == parent && parent->right == current && (grandparent->left == NULL || grandparent->left->color == 'B')) {
	//if the grandparent's right is the parent and the parent's right is the current node (also a setup of case 4) then change pointers
	grandparent->right = parent->left; //grandparent's right becomes the parent's left node
	parent->left = grandparent; //the parent's left node becomes the grandparent
	grandparent->parent = parent; //the grandparent's parent is now the original parent node
	if (grandparent->right != NULL) {
	  //if the grandparent's new right isn't a NULL leaf, then set its parent to be grandparent
	  grandparent->right->parent = grandparent;
	}

	if (greatGrandparent != NULL) {
	  //if the great grandparent exits...
	  if (greatGrandparent->left == grandparent) {
	    //if the grandparent is the left child of the great grandparent, then set the parent to be the left child of the great grandparent
	    greatGrandparent->left = parent;
	  }

	  else if (greatGrandparent->right == grandparent){
	    //if the grandparent is the right child of the great grandparent, then set the parent to be the right child of the great grandparent
	    greatGrandparent->right = parent;
	  }
	  //if the parent isn't the root now, then set parent's parent to be the great grandparent
	}

	parent->parent = greatGrandparent;
	case5Done = true;
      }

      
      if (case5Done == true) {
	if (grandparent == root) {
	  root = parent;
	}

	parent->color = 'B';
	grandparent->color = 'R';
      }
    }
  }

  if (root != NULL) {
    //change the root's color to black every single time
    //checks this case last because previous cases might alter color of the root
    //case 1
    root->color = 'B';
  }
}

void deletionBalance(node * current, node * parent, node * grandparent, node * &root) {
  if (current->color == 'R') {
    //this accounts for the case in which you have a black parent that gets deleted and is replaced with a red child. The child becomes black as it takes on the parent's place
    current->color = 'B';
    return;
  }

  else if (parent->color == 'B' && current->color == 'B') {

    node* sibling;
    
    if (current = parent->left) {
      sibling = parent->right;
    }

    else if (current = parent->right) {
      sibling = parent->left;
    }
    
    if (current == parent->left && parent->right->color == 'R') {
      //case 2
      //first case of case 2 where the child node is the left node of the parent and the child's sibling is red
      parent->right = sibling->left; //set the parent's right node to be the sibling's left node
      parent->right->parent = parent; //set the parent's new right's parent
      sibling->left = parent; //set the sibling's left node to be the parent

      sibling->parent = grandparent; //set the sibling's parent to be the parent's old parent

      parent->parent = sibling; //set the parent's parent to be the sibling

      parent->color = 'R'; //change the color of the parent to red
      sibling->color = 'B'; //change the color of the sibling to black
    }

    else if (current == parent->right && parent->left->color == 'R') {
      //case 2
      //second case of case 2 where the child node is the right node of the parent and the child's sibling is red
      parent->right = sibling->left; //set the parent's left node to be the sibling's right node
      parent->right->parent = parent; //set the parent's new left's parent
      sibling->left = parent; //set the sibling's right node to be the parent

      sibling->parent = grandparent; //set the sibling's parent to be the parent's old parent

      parent->parent = sibling; //set the parent's parent to be the sibling

      parent->color = 'R'; //change the color of the parent to red
      sibling->color = 'B'; //change the color of the sibling to black
    }

    if (current == parent->right && (sibling->color == 'B' || sibling == NULL) && sibling->left->color != 'R') {
      //case 3
      //if the current node is to the right of the parent and it's sibling is black, then recolor the sibling
      sibling->color == 'R';
      if (grandparent->parent != NULL) {
	//as long as the great grandparent exists, call this same function up the tree
	deletionBalance(parent, grandparent, grandparent->parent, root);
      }
    }

    else if (current == parent->left && (sibling->color == 'B' || sibling == NULL) && sibling->right->color != 'R') {
      //case 3
      //if the current node is to the right of the parent and it's sibling is black, then recolor the sibling
      sibling->color == 'R';
      if (grandparent->parent != NULL) {
	//as long as the great grandparent exists, call this same function up the tree
	deletionBalance(parent, grandparent, grandparent->parent, root);
      }
    }

    if (parent->color == 'R' && parent->right == current && sibling != NULL && (sibling->left == NULL || sibling->left->color == 'B') && (sibling->right == NULL || sibling->right->color == 'B')) {
      //case 4
      //if the left sibling has 2 black children and the parent is black then recolor the parent to be black and the left sibling to be red
      parent->color = 'B';
      sibling->color = 'R';
    }

    else if (parent->color == 'R' && parent->left == current && sibling != NULL && (sibling->left == NULL || sibling->left->color == 'B') && (sibling->right == NULL || sibling->right->color == 'B')) {
      //case 4
      //if the right sibling has 2 black children and the parent is black then recolor the parent to be black and the right sibling to be red
      parent->color = 'B';
      parent->right->color = 'R';
    }

    if (parent->right == current && sibling != NULL && sibling->color == 'B' && (sibling->left->color == 'B' || sibling->left == NULL) && sibling->right != NULL && sibling->right->color == 'R'){
      //case 5
      //if the node is to the left of the parent and the sibling is black, the sibling's left is black, and the sibling's right is red, recolor and reset pointers
      sibling->right->color = 'B'; //change the sibling's right node's color to be black
      sibling->color = 'R'; //change the sibling's color to be red
      parent->left = sibling->right; //set the parent's left to be the sibling's right node
      sibling->right->parent = parent; //set the sibling's right node's parent to be the parent node
      sibling->right = parent->left->left; //set the sibling's right to be the new left node's left node
      sibling->right->parent = sibling; //set the sibling's right node's parent to be the sibling
      parent->left->left = sibling; //set the new left node of the parent's left node to be the sibling
      sibling->parent = parent->left; //set the parent of the sibling to now be the new left node of the parent
    }

    else if (parent->left == current && sibling != NULL && sibling->color == 'B' && (sibling->right->color == 'B' || sibling->right == NULL) && sibling->left != NULL && sibling->left->color == 'R'){
      //case 5
      //if the node is to the right of the parent and the sibling is black, the sibling's right is black, and the sibling's left is red, recolor and reset pointers
      sibling->left->color = 'B'; //change the sibling's right node's color to be black
      sibling->color = 'R'; //change the sibling's color to be red
      parent->right = sibling->left; //set the parent's right to be the sibling's left node
      sibling->left->parent = parent; //set the sibling's left node's parent to be the parent node
      sibling->left = parent->right->right; //set the sibling's left to be the new right node's right node
      sibling->left->parent = sibling; //set the sibling's left node's parent to be the sibling
      parent->right->right = sibling; //set the new right node of the parent's right node to be the sibling
      sibling->parent = parent->right; //set the parent of the sibling to now be the new right node of the parent
    }

    if (current == parent->right && sibling != NULL && sibling->color == 'B' && sibling->left->color == 'R') {
      //case 6
      //if the current node is the right of the parent and the sibling exists and is black, and the sibling has a left node with a red color, then recolor and rotate
      
      sibling->color = parent->color; //change the sibling's color to be the parent's current color
      parent->color = 'B'; //change the parent's color to be black
      sibling->left->color = 'B'; //change the sibling's left node's color to be black
      parent->left = sibling->right; //set the parent's left node to be the sibling's right node
      parent->left->parent = parent; //set the parent's new left node's parent to be the parent
      sibling->right = parent; //set the sibling's right node to be the parent
      parent->parent = sibling; //set the parent's parent to be the sibling

      if (grandparent != NULL) {
	//if the parent is not the root, then set sibling's parent to be the grandparent
	sibling->parent = grandparent;
      }      
    }

    if (current == parent->left && sibling != NULL && sibling->color == 'B' && sibling->right->color == 'R') {
      //case 6
      //if the current node is the left of the parent and the sibling exists and is black, and the sibling has a right node with a red color, then recolor and rotate
      
      sibling->color = parent->color; //change the sibling's color to be the parent's current color
      parent->color = 'B'; //change the parent's color to be black
      sibling->right->color = 'B'; //change the sibling's right node's color to be black
      parent->right = sibling->left; //set the parent's right node to be the sibling's left node
      parent->right->parent = parent; //set the parent's new right node's parent to be the parent
      sibling->left = parent; //set the sibling's left node to be the parent
      parent->parent = sibling; //set the parent's parent to be the sibling

      if (grandparent != NULL) {
	//if the parent is not the root, then set sibling's parent to be the grandparent
	sibling->parent = grandparent;
      } 
    }
  }
}
