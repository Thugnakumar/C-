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

void createStackNode(node * &head, stack * &stack, char input);
void createQueueNode(node * &head, queue * &queue, char input);
void shuntingYard(char arr[100]);

int main() {

  //  stack * newStack = new stack();
  //queue * newQueue = new queue();

  char input [100];
  cout << "Enter an equation: ";
  cin >> input;

  shuntingYard(input);
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

  /*createQueueNode(head, newQueue);
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
  newQueue->dequeue(head);*/
}

void createStackNode(node * &head, stack * &stack, char input){
  node * newNode = new node();

  newNode->data = input;
  newNode->next = NULL;

  stack->push(head,newNode);
  stack->print(head);
  cout << endl;
}

void createQueueNode(node * &head, queue * &queue, char input){
  node * newNode = new node();

  newNode->data = input;
  newNode->next = NULL;

  queue->enqueue(head,newNode);
  queue->print(head);
  cout << endl;
}

void shuntingYard(char arr[100]) {
  cout << "Entered Shunting Yard" << endl;
  
  queue * inputQueue = new queue();
  queue * outputQueue = new queue();
  stack * operatorStack = new stack();
  node * inputHead = NULL;
  node * outputHead = NULL;
  node * operatorStackHead = NULL;
  node * temp = NULL;

  cout << "Created things" << endl;
  
  for (int i = 0; i < strlen(arr); ++i){
    if (arr[i] != ' '){
      createQueueNode(inputHead, inputQueue, arr[i]);
    }
  }
  cout << "Removed spaces" << endl;

  while (inputQueue->isEmpty(inputHead) == false){
    cout << "There's stuff in the queue" << endl;
    //while there's stuff in the input queue...
    node * top = inputQueue->dequeue(inputHead); //store the value of the top of the input stack to node "top"
    inputQueue->deleteHead(inputHead); //delete the head of the input queue and reset the head
    if (top->data >= '0' && top->data <= '9'){
      //if the top node of the input queue is a number, add it to the output queue
      outputQueue->enqueue(outputHead, top);
    }

    else if (top->data == '+') {
      while (operatorStack->peek(operatorStackHead) != NULL || operatorStack->peek(operatorStackHead)->data != '(') {
	//if the top node of the operator stack is higher or same precedence than '+', then pop all operators off the stack until the stack is clean
	temp = operatorStack->pop(operatorStackHead);
	outputQueue->enqueue(outputHead, temp);
	operatorStack->deleteHead(operatorStackHead);
      }
      //push the '+' sign to cleaned off operator stack
      operatorStack->push(operatorStackHead, top);
    }

    else if (top->data == '-') {
      while (operatorStack->peek(operatorStackHead) != NULL|| operatorStack->peek(operatorStackHead)->data != '(') {
	//if the top node of the operator stack is higher or same precedence than '+', then pop all operators off the stack until the stack is clean
	temp = operatorStack->pop(operatorStackHead);
	outputQueue->enqueue(outputHead, temp);
	operatorStack->deleteHead(operatorStackHead);
      }
      //push the '+' sign to cleaned off operator stack
      operatorStack->push(operatorStackHead, top);
    }

    else if (top->data == '*') {
      while (operatorStack->peek(operatorStackHead) != NULL || operatorStack->peek(operatorStackHead)->data != '+' || operatorStack->peek(operatorStackHead)->data != '-'|| operatorStack->peek(operatorStackHead)->data != '(') {
	//if the top node of the operator stack is higher or same precedence than '+', then pop all operators off the stack until the stack is clean
	temp = operatorStack->pop(operatorStackHead);	
	outputQueue->enqueue(outputHead, temp);
	operatorStack->deleteHead(operatorStackHead);
      }
      //push the '+' sign to cleaned off operator stack
      operatorStack->push(operatorStackHead, top);
    }

    else if (top->data == '/') {
      while (operatorStack->peek(operatorStackHead) != NULL || operatorStack->peek(operatorStackHead)->data != '+' || operatorStack->peek(operatorStackHead)->data != '-'|| operatorStack->peek(operatorStackHead)->data != '(') {
	//if the top node of the operator stack is higher or same precedence than '+', then pop all operators off the stack until the stack is clean
	temp = operatorStack->pop(operatorStackHead);	
	outputQueue->enqueue(outputHead, temp);
	operatorStack->deleteHead(operatorStackHead);
      }
      //push the '+' sign to cleaned off operator stack
      operatorStack->push(operatorStackHead, top);
      
    }

    else if (top->data == '(') {
      operatorStack->push(operatorStackHead, top);
    }

    else if (top->data == ')') {
      while (operatorStack->peek(operatorStackHead)->data != '(') {
	temp = operatorStack->pop(operatorStackHead);
	outputQueue->enqueue(outputHead, temp);
	operatorStack->deleteHead(operatorStackHead);
      }
      operatorStack->deleteHead(operatorStackHead);
      delete top;
    }

    else if (top->data == '^') {
      //if the top node of the input queue is a '^', add it to the output stack provided that the top node of the output stack isn't an operator of higher precedence (excluding parentheses)
      if (operatorStack->peek(operatorStackHead)->data == '^') {
	outputQueue->enqueue(outputHead, top);
      }

      else {
	operatorStack->push(outputHead, top);
      }
    }

    else {
      cout << "Not a valid input!" << endl;
      break;
    }

  }

  outputQueue->print(outputHead);
  
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
