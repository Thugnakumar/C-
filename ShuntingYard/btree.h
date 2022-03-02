/*
Name: Varun Krishnakumar
Date: 3/1/22
This is the header file for the binary expression tree class. It has two functions: a constructor, a destructor, and a function that returns a pointer to the "head" of a binary tree
 */

#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include "node.h"
#include "stack.h"
#include "queue.h"

using namespace std;

class btree {
 public:
  btree(queue * outputQueue, node * oqHead);
  ~btree();
  node * returnRoot();

 private:
  stack * treePtr = new stack(); //stack containing the pointers to operands and the heads of binary trees
  node * sHead = NULL; //node pointer that points to the head of the stack
};

#endif
