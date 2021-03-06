/*
Name: Varun Krishnakumar
Date: 3/1/22
This is the header file for the queue. This has 4 main classes (apart from the constructor and destructor): enqueue, dequeue, and returnHead.
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
  bool enqueue(node * &head, node * &myNode);
  node* dequeue(node * &head);
  bool isEmpty(node * head);
  node * returnHead(node * head);

 private:
};

#endif
