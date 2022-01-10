//header guards
#ifndef NODE_H
#define NODE_H

//all the libararies
#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

class Node{//class declaration
 public: //all public functions
  Node(Student* student); //constructor
  void setNext(Node* node); //sets the next node
  Node* getNext(); //returns the next node
  ~Node(); //destructor
 private: //all private variables
  Node* next; //the next node
};

#endif
