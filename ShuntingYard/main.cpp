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
void shuntingYard(stack * &stack, queue * &queue);

int main() {
  node * head = NULL;

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
  cout << "Current order of nodes: ";
  newQueue->print(head);
  cout << endl;
  cout << "dequeued" << endl;
  newQueue->dequeue(head);
  cout << "Current order of nodes: ";
  newQueue->print(head);
  cout << endl;  
  cout << "dequeued" << endl;
  newQueue->dequeue(head);
  cout << "Current order of nodes: ";
  newQueue->print(head);
  cout << endl;
  cout << "dequeued" << endl;
  newQueue->dequeue(head);
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

void shuntingYard(stack * &stack, queue * &queue) {
  
  /*while there are tokens to be read:
    read a token
    if the token is:
    - a number:
        put it into the output queue
    - a function:
        push it onto the operator stack 
    - an operator o1:
        while (
            there is an operator o2 other than the left parenthesis at the top
            of the operator stack, and (o2 has greater precedence than o1
            or they have the same precedence and o1 is left-associative)
        ):
            pop o2 from the operator stack into the output queue
        push o1 onto the operator stack
    - a left parenthesis (i.e. "("):
        push it onto the operator stack
    - a right parenthesis (i.e. ")"):
        while the operator at the top of the operator stack is not a left parenthesis:
            {assert the operator stack is not empty}
            /* If the stack runs out without finding a left parenthesis, then there are mismatched parentheses. */
  /*      pop the operator from the operator stack into the output queue
        {assert there is a left parenthesis at the top of the operator stack}
        pop the left parenthesis from the operator stack and discard it
        if there is a function token at the top of the operator stack, then:
            pop the function from the operator stack into the output queue
/* After the while loop, pop the remaining items from the operator stack into the output queue. */
  /*while there are tokens on the operator stack:
    /* If the operator token on the top of the stack is a parenthesis, then there are mismatched parentheses. */
  /*{assert the operator on top of the stack is not a (left) parenthesis}
    pop the operator from the operator stack onto the output queue*/
}
