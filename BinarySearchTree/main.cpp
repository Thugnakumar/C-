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
};

void addToTree();
void removeFromTree();
void searchTree();
void printTree();

int main() {
  //where everything happens
  char arr[2];
  
  
  
}
