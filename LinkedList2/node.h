// Header file for Nodes class in Linked Lists Part 1 Project
// Author: Shudhant Gautam
// Date: 16 January 2022

#ifndef NODE_H
#define NODE_H

#include "Student.h"

using namespace std;

class Node {
 public:
  Node(Student*);
  ~Node();

  // setStudent function
  void setStudent(Student*);
  // setNext function
  void setNext(Node*);

  // getStudent function
  Student* getStudent();
  // getNext function
  Node* getNext();

 private:
  Student* student;
  Node* nextNode;
};

#endif
