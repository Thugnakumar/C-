/*
Name: Varun Krishnakumar
Date: 2/11/22
This is the header file for the stack. This has 5 main classes (apart from the constructor and destructor): push, pop, peek, isEmpty, and isFull. 
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

struct node {
  char data;
  node * next;
};

class stack {
 public:
  stack();
  ~stack();
  bool push(node * &head, node * node);
  bool pop(node * &head, node * current);
  char peek(node * head);
  bool isEmpty(node * head);
  bool isFull(node * head);
  void print(node * head);

 private:
  bool test;
};

#endif
