/*
Name: Varun Krishnakumar
Date: 3/1/22
This is the cpp file for making a binary tree. It uses the left and right pointers of nodes rather than the next pointer
 */
#include <iostream>
#include <cstring>
#include "btree.h"
#include "node.h"
#include "stack.h"
#include "queue.h"

using namespace std;

btree::btree(queue * outputQueue, node * oqHead){
  while (outputQueue->isEmpty(oqHead) == false){
    //while there's stuff in the output queue...
    
    node * outputNode = new node();//create a new node
    outputNode->data = outputQueue->dequeue(oqHead)->data; //set its data equal to the data of the top node of the output queue
    outputNode->next = NULL; //set next to NULL
    outputNode->right = NULL; //set right to NULL
    outputNode->left = NULL; //set left to NULL
    if (outputNode->data == '+' || outputNode->data == '-' || outputNode->data == '*' || outputNode->data == '/' || outputNode->data == '^'){
      //if the value of the node is an operator, pop the previous two nodes off the stack and have the current node point to both of them
      outputNode->right = treePtr->pop(sHead);
      outputNode->left = treePtr->pop(sHead);
    }
    treePtr->push(sHead, outputNode); //push a pointer to the newly-formed tree to the top of the stack
  }
}

node * btree::returnRoot(){
  //returns the node at the very top of a tree
  return(treePtr->peek(sHead));
}

btree::~btree(){
  //destructor
}
