/*
Name: Varun Krishnakumar
Date: 2/11/22
This is the shunting yard algorithm. Update the description of this algorithm as you go!
 */

#include <iostream>
#include <cstring>
#include <cctype>
#include "stack.h"

using namespace std;

struct node {
  char data;
  node * next;
};

void createStackNode(node * &head, stack * &stack);

int main() {
  node * head = new node();
  head->data = NULL;
  head->next = NULL;

  stack * stack = new stack();

  createStackNode(head, stack);
}

void createStackNode(node * &head, stack * &stack){
  char input;
  node * node = new node();

  node->data = cin >> input;
  node->next = NULL;

  stack->push(head,node);

  cout << stack->peek(head);
}

