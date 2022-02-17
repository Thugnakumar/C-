/*
Name: Varun Krishnakumar
Date: 2/11/22
This is the header file for the stack. This has 5 main classes (apart from the constructor and destructor): push, pop, peek, isEmpty,
 and isFull.
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "node.h"

using namespace std;

class queue {
 public:
  queue();
  ~queue();
  bool enqueue(node * &head, node * node);
  bool dequeue(node * &head);
  void print(node * head);

 private:
};

#endif
