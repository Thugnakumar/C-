// CPP file for Nodes class in Linked Lists Part 1 Project
// Author: Shudhant Gautam
// Date: 16 January 2022

#include <iostream>
#include <cstring>

#include "Node.h"

using namespace std;

// Constructor
Node::Node(Student* newStudent) {
  student = newStudent;
  nextNode = NULL;
}

// (De)constructor
Node::~Node() {
  delete &student;
  nextNode = NULL;
}

// setStudent
void Node::setStudent(Student* newStudent) {
  student = newStudent;
}

// setNext
void Node::setNext(Node* newNext) {
  nextNode = newNext;
}

// getStudent
Student* Node::getStudent() {
  return student;
}

Node* Node::getNext() {
  return nextNode;
}
