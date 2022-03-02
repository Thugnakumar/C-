/*
Name: Varun Krishnakumar
Date: 3/1/22
This is the shunting yard algorithm. It reads in a user equation that's inputted in infix notation, converts it to postfix notation, then converts postfix notation to a binary tree. Using the binary tree, the program can then read the equation and report it back in either prefix, postfix, or infix notation.
 */

//all the libaries
#include <iostream>
#include <cstring>
#include <cctype>
#include "stack.h"
#include "node.h"
#include "queue.h"
#include "btree.h"

using namespace std;

//function prototypes for main
void createQueueNode(node * &head, queue * &queue, char input);
bool shuntingYard(char * arr, queue * &outputQueue, node * &outputHead);
void binaryTree( node * oqHead, queue * outputQueue);
void postfixNotation(node * treeNode);
void prefixNotation(node * treeNode);
void infixNotation(node * treeNode);

int main() {
  //where everything happens
  
  queue * outputQueue = new queue(); //queue to store the equation converted to postfix notation
  node * outputHead = NULL; //node pointer pointing to the head of outputQueue (initially set to NULL)
    
  char input[100]; //char array for storing user input (the equation that they type in)
  cout << "Enter an equation in infix notation." << endl; //prompts the user to enter an equation
  cout << "Infix notation is standard equation notation, written as you would see on a math problem (e.g. (2+3)*4)." << endl;
  cout << "Use '+' for addition, '-' for subtraction, '*' for multiplication, '/' for division, and '^' to raise a value to a certain power. Make sure to match parentheses appropriately!" << endl;
  cin.getline(input, 100);//gets and stores the input
  cout << input << endl;
  
  shuntingYard(input, outputQueue, outputHead);//calls the shunting yard method and passes in the character array containing the entered equation, the queue which stores the equation in postfix notation, and the head pointer to the output queue
  if (shuntingYard(input, outputQueue, outputHead) == true) {
    //if the shunting yard algorithm works without an error...
    binaryTree(outputHead, outputQueue); //calls the function that creates the binary tree and passes in the queue containing the initial equation in postfix notation and the node pointer pointing to the head of that queue.
  }
}

void createQueueNode(node * &head, queue * &queue, char input){
  //creates a node for the queue and pushes it to the queue
  node * newNode = new node(); //creates a blank node

  newNode->data = input; //sets the char input (passed into the function) as the data for the node
  newNode->next = NULL; //sets the next node to be NULL
  newNode->right = NULL; //sets the node on the right to be NULL
  newNode->left = NULL; //sets the node on the left to be NULL

  queue->enqueue(head,newNode); //adds the created node to the top of the queue that's passed in
}

bool shuntingYard(char * arr, queue * &outputQueue, node * &outputHead) {
  //this function converts the user's input (infix notation) to postfix notation
  
  queue * inputQueue = new queue(); //creates a queue for storing/rearranging the user's input (infix notation)
  stack * operatorStack = new stack(); //creates a stack to store the operators in the function in order to convert infix to postfix notation
  node * inputHead = NULL; //a node pointer pointing to the head of the input queue
  node * operatorStackHead = NULL; //a node pointer pointing to the top of the operator stack
  node * temp = NULL; //a temporary node for storing the 
  node * top = NULL; //a node for temporarily storing the top/head value of the input queue

  for (int i = 0; i < strlen(arr); i++){
    if (arr[i] != ' '){
      //goes through the entire character array with the user input and converts each character in the input to a node, provided that character isn't a space
      createQueueNode(inputHead, inputQueue, arr[i]);
    }
  }

  while (inputQueue->isEmpty(inputHead) == false){
    //while there's stuff in the input queue...
    top = inputQueue->dequeue(inputHead); //store the value of the top of the input queue to node "top"

    if (top->data >= '0' && top->data <= '9'){
      //if the top node of the input queue is a number, add it to the output queue directly
      outputQueue->enqueue(outputHead, top);
    }

    else if (top->data == '+') {
      //if the top node of the input queue is a '+' operator...
      if (operatorStack->peek(operatorStackHead) != NULL) {
	//if there's something in the operator stack
	while (operatorStack->peek(operatorStackHead) != NULL) {
	  if (operatorStack->peek(operatorStackHead)->data != '(') {
	    //if the top node of the operator stack is higher or same precedence than '+', then pop all operators off the stack until the top operator of the stack is of lower precedence than '+'. Since this is impossible, pop everything off the stack until there is nothing in it. Add those popped off nodes to the end of the output queue
	    temp = operatorStack->pop(operatorStackHead);
	    outputQueue->enqueue(outputHead, temp);
	  }

	  else {
	    //if the top of the operator stack is a '(' character, then push the '+' operator to the top of the operator stack automatically
	    break;
	  }
	}
      }
      //push the '+' sign to cleaned off operator stack
      operatorStack->push(operatorStackHead, top);
    }

    else if (top->data == '-') {
      //if the top node of the input queue is a '-' operator...
      if (operatorStack->peek(operatorStackHead) != NULL) {
	//if there's something in the operator stack
	while (operatorStack->peek(operatorStackHead) != NULL) {
	  if (operatorStack->peek(operatorStackHead)->data != '(') {
	    //if the top node of the operator stack is higher or same precedence than '+', then pop all operators off the stack until the top operator of the stack is of lower precedence than '+'. Since this is impossible, pop everything off the stack until there is nothing in it. Add those popped off nodes to the end of the output queue
	    temp = operatorStack->pop(operatorStackHead);
	    outputQueue->enqueue(outputHead, temp);
	  }

	  else {
	    //if the top of the operator stack is a '(' character, then push the '+' operator to the top of the operator stack automatically
	    break;
	  }
	}
      }
      //push the '+' sign to cleaned off operator stack
      operatorStack->push(operatorStackHead, top);
    }

    else if (top->data == '*') {
      //if the top of the operator stack is a '*' operator...
      if (operatorStack->peek(operatorStackHead) != NULL){
	//if there's something in the operator stack...
	while (operatorStack->peek(operatorStackHead) != NULL) {
	  if (operatorStack->peek(operatorStackHead)->data != '+' && operatorStack->peek(operatorStackHead)->data != '-'&& operatorStack->peek(operatorStackHead)->data != '(') {
	    //if the top node of the operator stack is higher or same precedence than '*', then pop all operators off the stack until the top node of the stack contains an operator that is lower precedence than '*' and add those popped off nodes to the end of the output queue
	    temp = operatorStack->pop(operatorStackHead);	
	    outputQueue->enqueue(outputHead, temp);
	  }

	  else {
	    //if the top node of the operator stack contains a '(' or an operator of lower precedence than '*', then break out of the while loop
	    break;
	  }
	}
      }
      //push the '*' sign to the top of the operator stack
      operatorStack->push(operatorStackHead, top);
    }

    else if (top->data == '/') {
      //if the top of the operator stack is a '*' operator...
      if (operatorStack->peek(operatorStackHead) != NULL){
	//if there's something in the operator stack...
	while (operatorStack->peek(operatorStackHead) != NULL) {
	  if (operatorStack->peek(operatorStackHead)->data != '+' && operatorStack->peek(operatorStackHead)->data != '-'&& operatorStack->peek(operatorStackHead)->data != '(') {
	    //if the top node of the operator stack is higher or same precedence than '*', then pop all operators off the stack until the top node of the stack contains an operator that is lower precedence than '*' and add those popped off nodes to the end of the output queue
	    temp = operatorStack->pop(operatorStackHead);	
	    outputQueue->enqueue(outputHead, temp);
	  }

	  else {
	    //if the top node of the operator stack contains a '(' or an operator of lower precedence than '*', then break out of the while loop
	    break;
	  }
	}
      }
      //push the '/' sign to top of the operator stack
      operatorStack->push(operatorStackHead, top);
    }

    else if (top->data == '(') {
      //if the top of the input queue contains the character '(', then immediately push it the top of the operator stack, regardless of what is currently at the top
      operatorStack->push(operatorStackHead, top);
    }

    else if (top->data == ')') {
      //if the top of the input queue is the '(' character...
      while (operatorStack->peek(operatorStackHead) != NULL){
	//while there's something in the operator stack to evaluate...
	if (operatorStack->peek(operatorStackHead)->data!='(') {
	  //keep popping off operators from the operator stack and sticking them onto the output queue until you hit the '(' character
	  temp = operatorStack->pop(operatorStackHead);
	  outputQueue->enqueue(outputHead, temp);	  
	}
      }

      if (operatorStack->peek(operatorStackHead) == NULL) {
	//if you go through the entire operator stack without hitting a corresponding '(' character, then you have mismatched parentheses
	cout << "Parentheses don't match!" << endl;
	return false;
      }
      else {
	//pop the '(' character node from the top of the operator stack and don't do anything with it
	operatorStack->pop(operatorStackHead);
      }
    }

    else if (top->data == '^') {
      //if the top node of the input queue is a '^', add it to the output stack provided that the top node of the output stack isn't a '^'
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
      //if the character in the top node of the input queue is anything else, print the following message and stop reading things from the input queue
      cout << "Not a valid input!" << endl;
      return false;
    }
  }

  while (operatorStack->peek(operatorStackHead) != NULL) {
    //while there are things remaining in the output stack after finishing reading things from the input queue, keep popping those nodes from the top of the operator stack and adding them to the end of the output queue
    if (operatorStack->peek(operatorStackHead) == '(') {
      //if there's a '(' character reamining in the stack after everything has been read from the input queue, that means that the user never inputted a ')', so there are mismatch parentheses
      cout << "Mismatched parentheses!" << endl;
      return false;
    }
    
    temp = operatorStack->pop(operatorStackHead);
    outputQueue->enqueue(outputHead, temp);
  }

  return true;
}

void binaryTree(node * oqHead, queue * outputQueue) {
  //creates a binary tree using the output queue and its head
  char notation[20] = "monkey"; //char array for storing input on what type of notation the user wants to display their equation in
  btree * tree = new btree(outputQueue, oqHead); //creates a binary tree
  while (strcmp(notation, "quit") != 0){
    //while the char array for user input doesn't say "quit", keep taking in input and evaluating it
    cout << "What notation would you like to view this in? (Infix, Prefix, Postfix). Type 'Quit' to quit: "; //prompts the user for the type of notation they want to express their equation in
    cin >> notation;
    for (int i = 0; i < strlen(notation); ++i){
      //converts the user's input to all caps
      notation[i] = toupper(notation[i]);
    }

    if (strcmp(notation, "INFIX") == 0){
      //if the user types in "INFIX", then call the infixNotation function and print equation in infix notation
      infixNotation(tree->returnRoot());
      cout << endl;
    }

    else if (strcmp(notation, "PREFIX") == 0){
      //if the user types in "PREFIX", then call the prefixNotation function and print equation in prefix notation
      prefixNotation(tree->returnRoot());
      cout << endl;
    }

    else if (strcmp(notation, "POSTFIX") == 0){
      //if the user types in "PREFIX", then call the prefixNotation function and print equation in prefix notation
      postfixNotation(tree->returnRoot());
      cout << endl;
    }

    else if (strcmp(notation, "QUIT") == 0) {
      //if the user types in quit, then the program is terminated/exited
      cout << "Thanks for using this program! Goodbye!" << endl;
      break;
    }

    else {
      //if the user enters something else, prints "Not a valid input!"
      cout << "Not a valid input!" << endl;
    }
  }
}

void prefixNotation(node * treeNode) {
  //goes through the binary tree and prints the equation in prefix notation
  if (treeNode != NULL){
    //if the current node is not NULL, then print the data of the current node, then recursively call the prefixNotation function on the left side of the tree, then the right side of the tree
    cout << treeNode->data;
    prefixNotation(treeNode->left);
    prefixNotation(treeNode->right);
  }
}

void postfixNotation(node * treeNode){
  //goes through the binary tree and prints the equation in postfix notation
  if (treeNode != NULL) {
    //if the current node is not NULL, then recursively call the postfixNotation function on the left side of the tree, then the right side of the tree, then print the data of the current node
    postfixNotation(treeNode->left);
    postfixNotation(treeNode->right);
    cout << treeNode->data;
  }
}

void infixNotation(node * treeNode){
  //goes through the binary tree and prints the equation in infix notation
  if (treeNode != NULL) {
    //if the current node is not NULL...
    if (treeNode->data == '+' || treeNode->data == '-' || treeNode->data == '*' || treeNode->data == '/' || treeNode->data == '^'){
      //if the data of the current node is an operator, print a '('
      cout << "(";
    }
    infixNotation(treeNode->left); //recursively calls the infixNotation function on the left side of the tree
    cout << treeNode->data; //prints the data of the current node
    infixNotation(treeNode->right); //recursively calls the infixNotation function on the right side of the tree
    if (treeNode->data == '+' || treeNode->data == '-' || treeNode->data == '*' || treeNode->data == '/' || treeNode->data == '^'){
      //if the data of the current node is an operator, print a ')'
      cout << ")";
    }
  }
}
