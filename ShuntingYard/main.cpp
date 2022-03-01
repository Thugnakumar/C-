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
#include "bnode.h"
#include "btree.h"

using namespace std;

void createQueueNode(node * &head, queue * &queue, char input);
void shuntingYard(char * arr, queue * &outputQueue, node * &outputHead);
void binaryTree( node * oqHead, queue * outputQueue);

int main() {

  queue * outputQueue = new queue();  
  node * outputHead = NULL;
    
  char input[100];
  cout << "Enter an equation: ";
  cin.getline(input, 100);
  cout << input << endl;
  
  shuntingYard(input, outputQueue, outputHead);
  binaryTree(outputHead, outputQueue);
}

void createQueueNode(node * &head, queue * &queue, char input){
  node * newNode = new node();

  newNode->data = input;
  newNode->next = NULL;

  queue->enqueue(head,newNode);
  queue->print(head);
  cout << endl;
  //cout << "Made a node" << endl;
}

void shuntingYard(char * arr, queue * &outputQueue, node * &outputHead) {
  cout << "Entered Shunting Yard" << endl;

  queue * inputQueue = new queue();
  stack * operatorStack = new stack();
  node * inputHead = NULL;
  node * operatorStackHead = NULL;
  node * temp = NULL;
  node * top = NULL;

  cout << "Created things" << endl;
  
  for (int i = 0; i < strlen(arr); i++){
    if (arr[i] != ' '){
      //      cout << "Current character: " << arr[i] << endl;
      createQueueNode(inputHead, inputQueue, arr[i]);
    }
  }
  cout << "Removed spaces" << endl;

  while (inputQueue->isEmpty(inputHead) == false){
    cout << "There's stuff in the queue" << endl;
    //while there's stuff in the input queue...
    top = inputQueue->dequeue(inputHead); //store the value of the top of the input queue to node "top"
    cout << "Top of the queue: " << top->data << endl;

    if (top->data >= '0' && top->data <= '9'){
      //if the top node of the input queue is a number, add it to the output queue
      outputQueue->enqueue(outputHead, top);
      cout << "Output head data: " << outputHead->data << endl;
      cout << "Output queue: ";
      outputQueue->print(outputHead);
      cout << endl;
      cout << "Operator stack: ";
      operatorStack->print(operatorStackHead);
      cout << endl;
    }

    else if (top->data == '+') {
      if (operatorStack->peek(operatorStackHead) != NULL) {
	while (operatorStack->peek(operatorStackHead) != NULL) {
	  if (operatorStack->peek(operatorStackHead)->data != '(') {
	    //if the top node of the operator stack is higher or same precedence than '+', then pop all operators off the stack until the stack is clean
	    temp = operatorStack->pop(operatorStackHead);
	    outputQueue->enqueue(outputHead, temp);
	  }

	  else {
	    break;
	  }
	}
      }
      //push the '+' sign to cleaned off operator stack
      operatorStack->push(operatorStackHead, top);
    }

    else if (top->data == '-') {
      if (operatorStack->peek(operatorStackHead) != NULL) {
	while (operatorStack->peek(operatorStackHead) != NULL) {
	  if (operatorStack->peek(operatorStackHead)->data != '(') {
	    //if the top node of the operator stack is higher or same precedence than '+', then pop all operators off the stack until the stack is clean
	    temp = operatorStack->pop(operatorStackHead);
	    outputQueue->enqueue(outputHead, temp);
	  }

	  else {
	    break;
	  }
	}
      }
      //push the '+' sign to cleaned off operator stack
      operatorStack->push(operatorStackHead, top);
    }

    else if (top->data == '*') {
      operatorStack->print(operatorStackHead);
      if (operatorStack->peek(operatorStackHead) != NULL){
	while (operatorStack->peek(operatorStackHead) != NULL) {
	  if (operatorStack->peek(operatorStackHead)->data != '+' && operatorStack->peek(operatorStackHead)->data != '-'&& operatorStack->peek(operatorStackHead)->data != '(') {
	    cout << "You shouldn't be here..." << endl;
	    //if the top node of the operator stack is higher or same precedence than '+', then pop all operators off the stack until the stack is clean
	    temp = operatorStack->pop(operatorStackHead);	
	    outputQueue->enqueue(outputHead, temp);
	  }

	  else {
	    break;
	  }
	}
      }
      //push the '+' sign to cleaned off operator stack
      operatorStack->push(operatorStackHead, top);
    }

    else if (top->data == '/') {
      if (operatorStack->peek(operatorStackHead) != NULL){
	while (operatorStack->peek(operatorStackHead) != NULL) {
	  if (operatorStack->peek(operatorStackHead)->data != '+' && operatorStack->peek(operatorStackHead)->data != '-'&& operatorStack->peek(operatorStackHead)->data != '(') {
	    //if the top node of the operator stack is higher or same precedence than '+', then pop all operators off the stack until the stack is clean
	    temp = operatorStack->pop(operatorStackHead);	
	    outputQueue->enqueue(outputHead, temp);
	  }

	  else {
	    break;
	  }
	}
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
      }
      operatorStack->pop(operatorStackHead);
    }

    else if (top->data == '^') {
      //if the top node of the input queue is a '^', add it to the output stack provided that the top node of the output stack isn't an operator of higher precedence (excluding parentheses)
      operatorStack->print(operatorStackHead);
      cout << endl;
      if (operatorStack->peek(operatorStackHead) != NULL) {
	if (operatorStack->peek(operatorStackHead)->data == '^') {
	  outputQueue->enqueue(outputHead, top);
	}
      }

      else {
	operatorStack->push(operatorStackHead, top);
      }
    }

    else {
      cout << "Not a valid input!" << endl;
      break;
    }

    //inputQueue->deleteHead(inputHead); //delete the head of the input queue and reset the head

  }

  while (operatorStack->peek(operatorStackHead) != NULL) {
    temp = operatorStack->pop(operatorStackHead);
    outputQueue->enqueue(outputHead, temp);
  }

  outputQueue->print(outputHead);  
}

void binaryTree( node * oqHead, queue * outputQueue) {
  char notation[20] = "monkey";
  btree * tree = new btree(outputQueue, oqHead);
  while (strcmp(notation, "quit") != 0){
    cout << "What notation would you like to view this in? (Infix, Prefix, Postfix). Type 'Quit' to quit: ";
    cin >> notation;
    for (int i = 0; i < strlen(notation); ++i){
      notation[i] = toupper(notation[i]);
    }

    if (strcmp(notation, "INFIX") == 0){
      //print in infix notation
    }

    else if (strcmp(notation, "PREFIX") == 0){
      //print in prefix notation
    }

    else if (strcmp(notation, "POSTFIX") == 0){
      //print in postfix notation
    }

    else {
      cout << "Not a valid input!" << endl;
      break;
    }
  }
}

void prefixNotation(bnode * treeNode) {
  if (treeNode != NULL){
    cout << treeNode->data;
    prefixNotation(treeNode->left);
    prefixNotation(treeNode->right);
  }
}

void postfixNotation(bnode * treeNode){
  if (treeNode != NULL) {
    postfixNotation(treeNode->left);
    postfixNotation(treeNode->right);
    cout << treeNode->data;
  }
}
