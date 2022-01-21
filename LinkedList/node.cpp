//all the libraries
#include <iostream>
#include "node.h"

using namespace std;

Node::Node(Student* student){
  //constructor that takes in a student pointer and copies it into the "kid" student pointer and sets the next node to null
  kid = student;
  next = NULL;
}

void Node::setNext(Node* node){
  //sets the next node to be equal to the node passed in as a parameter
  next = node;
}

Node* Node::getNext(){
  //gets the next node in the sequence
  return next;
}

Student* Node::getStudent(){//returns a pointer to the student associated with the particular node
  return kid;
}

Node::~Node(){
  //destructor
}

