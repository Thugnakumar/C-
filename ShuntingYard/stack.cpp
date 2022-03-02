/*
Name: Varun Krishnakumar
Date: 3/1/22
This is the .cpp file for the stack
 */

//all the libraries and .h files
#include <iostream>
#include <cstring>
#include "stack.h"
#include "node.h"

using namespace std;

stack::stack(){
  //constructor
}

bool stack::push(node * &head, node * node){
  if (head == NULL){
    //if the stack is empty, set the passed in node to be the head
    head = node;
  }
  
  else {
    //if there's already stuff in the stack, add the new node to the top of the stack
    node->next = head;
    head = node;
  }
  
  return true;
}

node* stack::pop(node * &head){
  if (head != NULL) {
    //if there's stuff in the stack, take the top node off the stack and return its value
    node * retNode = head;
    head = retNode->next;
    retNode->next = NULL;
    return retNode;
  }

  else {
    //if there's nothing in the stack, then print the following message
    cout << "There is nothing in the stack!" << endl;
    return NULL;
  }
}

node* stack::peek(node * head){
  //return the head node of the stack
  return head;
}

stack::~stack(){
}
