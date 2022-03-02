/*
Name: Varun Krishnakumar
Date: 3/1/22
This is the .cpp file for the queue
 */

//all the libraries/.h files
#include <iostream>
#include <cstring>
#include "queue.h"
#include "node.h"

using namespace std;

queue::queue(){
  //constructor
}

bool queue::enqueue(node * &head, node * &myNode){
  node * current = head; //copies the node head to a temporary node called current which is used to traverse the queue

  if (head == NULL){
    //if it's an empty queue, makes the passed in node the head of the queue
    head = myNode;
  }

  else {
    //adds the node to the end of the queue
    while (current->next != NULL){
      current = current->next;
    }
    current->next = myNode;
  }

  return true;
}

node* queue::dequeue(node * &head){

  if (head != NULL) {
    //returns the node at the front end of the queue provided that there is something within the queue
    node * retNode = head;
    head = retNode->next;
    retNode->next = NULL;
    return retNode;
  }

  else {
    //if there's nothing in the queue, then the following message prints
    cout << "There's nothing in the queue!" << endl;
    return NULL;
  }
}

bool queue::isEmpty(node * head) {
  if (head == NULL){
    //if there's nothing in the queue, then returns true since the queue is empty
    return true;
  }
  return false;
}

node * queue::returnHead (node * head) {
  //returns the head of the queue
  return head;
}

queue::~queue(){
  //destructor
}





