/*
Name: Varun Krishnakumar
Date: 3/1/22
This is the header file for the stack. This has 3 main classes (apart from the constructor and destructor): push, pop, peek. 
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "node.h"

using namespace std;

class stack {
 public:
  stack();
  ~stack();
  bool push(node * &head, node * node);
  node* pop(node * &head);
  node* peek(node * head);

 private:
};

#endif
