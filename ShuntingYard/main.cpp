/*
Name: Varun Krishnakumar
Date: 2/11/22
This is the shunting yard algorithm. Update the description of this algorithm as you go!
 */

#include <iostream>
#include <cstring>
#include <cctype>
#include "stack.h"
#include "node.h"
#include "queue.h"

using namespace std;

void createStackNode(node * &head, stack * &stack);
void createQueueNode(node * &head, queue * &queue);

int main() {
  node * head = new node();
  head->data = '\0';
  head->next = NULL;

  stack * newStack = new stack();
  queue * newQueue = new queue();
  
  /*  createStackNode(head, newStack);
  createStackNode(head, newStack);
  createStackNode(head, newStack);

  newStack->pop(head, head);
  newStack->print(head);
  cout << endl;
  newStack->pop(head, head);
  newStack->print(head);
  cout << endl;
  newStack->pop(head, head);
  newStack->print(head);
  cout << endl;
  */

  createQueueNode(head, newQueue);
  createQueueNode(head, newQueue);
  createQueueNode(head, newQueue);

  newQueue->dequeue(head);
  newQueue->print(head);
  cout << "dequeued" << endl;
  newQueue->dequeue(head);
  newQueue->print(head);
  cout << "dequeued" << endl;
  newQueue->dequeue(head);
  newQueue->print(head);
  cout << "dequeued" << endl;
}

void createStackNode(node * &head, stack * &stack){
  node * newNode = new node();

  cin >> newNode->data;
  newNode->next = NULL;

  stack->push(head,newNode);
  stack->print(head);
  cout << endl;
}

void createQueueNode(node * &head, queue * &queue){
  node * newNode = new node();

  cin >> newNode->data;
  newNode->next = NULL;

  queue->enqueue(head,newNode);
  queue->print(head);
  cout << endl;
}
