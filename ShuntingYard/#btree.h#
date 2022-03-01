/*
Name: Varun Krishnakumar
Date: 3/1/22
This is the header file for the binary expression tree class. It has two functions: a constructor and a destructor
 */

#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include "node.h"
#include "stack.h"
#include "queue.h"
#include "bnode.h"

using namespace std;

class btree {
 public:
  btree(queue * outputQueue, node * oqHead);
  ~btree();
  bnode * returnRoot();

 private:
  stack * treePtr = new stack();
  node * sHead = NULL;
};

#endif
