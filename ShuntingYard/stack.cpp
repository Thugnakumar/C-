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
  
  if (node != head){
    node->next = head;
    head = node;
  }
  
  return true;
}

node* stack::pop(node * &head){
  if (head != NULL) {
      return head;
  }

  else {
    cout << "There is nothing in the stack!" << endl;
    return NULL;
  }
}

node* stack::peek(node * head){
  return head;
}

void stack::deleteHead(node* &head){
  node * current = head;  
  head = head->next;
  delete current;
}

void stack::print(node * head){
  while (head->data != '\0'){
    cout << head->data;
    head = head->next;
  }
}   

stack::~stack(){
}
