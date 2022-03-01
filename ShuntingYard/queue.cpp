#include <iostream>
#include <cstring>
#include "queue.h"
#include "node.h"

using namespace std;

queue::queue(){
}

bool queue::enqueue(node * &head, node * &myNode){
  //adds the node to the end of the queue
  node * current = head;
  if (head == NULL){
    head = myNode;
  }

  else {
    while (current->next != NULL){
      current = current->next;
    }
    current->next = myNode;
  }

  return true;
}

node* queue::dequeue(node * &head){
  //returns the node at the front end of the queue

  if (head != NULL) {
    node * retNode = head;
    head = retNode->next;
    retNode->next = NULL;
    return retNode;
  }

  else {
    cout << "There's nothing in the queue!" << endl;
    return NULL;
  }
}

bool queue::isEmpty(node * head) {
  if (head == NULL){
    return true;
  }
  return false;
}

void queue::print(node * head){
  while (head != NULL){
    cout << head->data;
    head = head->next;
  }
}

node * queue::returnHead (node * head) {
  return head;
}

queue::~queue(){
}





