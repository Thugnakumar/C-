/*
Name: Varun Krishnakumar
Date: 2/9/22
This is the header file for the stack. This has 5 main classes (apart from the constructor and destructor): push, pop, peek, isEmpty, and isFull. 
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

class stack {
 public:
  stack();
  ~stack();
  bool push(node * &node);
  bool pop(node * &node);
  bool peek(node node);
  bool isEmpty(node node);
  bool isFull(node node);

 private:
  bool test;
  struct node {
    char * data;
    node * next;
  };
};

#endif
