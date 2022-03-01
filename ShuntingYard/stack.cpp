#include <iostream>
#include <cstring>
#include "stack.h"
#include "node.h"

using namespace std;

stack::stack(){
}

bool stack::push(node * &head, node * node){
  if (head == NULL){
    head = node;
  }
  
  else {
    node->next = head;
    head = node;
  }
  
  return true;
}

node* stack::pop(node * &head){
  if (head != NULL) {
    node * retNode = head;
    head = retNode->next;
    retNode->next = NULL;
    return retNode;
  }

  else {
    cout << "There is nothing in the stack!" << endl;
    return NULL;
  }
}

node* stack::peek(node * head){
  return head;
}

void stack::print(node * head){
  while (head != NULL){
    cout << head->data;
    head = head->next;
  }
}   

stack::~stack(){
}
