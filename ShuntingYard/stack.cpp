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

bool stack::pop(node * &head, node * current){
  current = head;
  head = head->next;
  delete current;
  return true;
}

char stack::peek(node * head){
  return head->data;
}

void stack::print(node * head){
  while (head->data != '\0'){
    cout << head->data;
    head = head->next;
  }
}   

stack::~stack(){
}
