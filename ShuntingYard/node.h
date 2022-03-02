/*
Name: Varun Krishnakumar
Date: 3/1/22
This is a header file containing a node struct with a character value for data, and node pointers pointing to the next, right, and left nodes
 */
#ifndef NODE_H
#define NODE_H

struct node {
  char data;
  node * next;
  node * right;
  node * left;
};

#endif
