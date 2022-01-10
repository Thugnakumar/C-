#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

Node::Node(Student* student){
  next = NULL;
}

void Node::setNext(Node* node){
  next = node;
}

Node* Node::getNext(){
  return next;
}

Node::~Node(){
}

