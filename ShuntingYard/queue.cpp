#include <iostream>
#include <cstring>
#include "queue.h"
#include "node.h"

using namespace std;

queue::queue(){
}

bool queue::enqueue(node * &head, node * &node){
  //alternate solution: pass node in by value and set that equal to head instead of creating new node current (like 14 isn't working for some reason). CHECK WITH GALBRAITH
  //adds the node to the end of the queue
  node * current = head;
  if (head == NULL){
    head = node;
  }

  else {
    while (current->next != NULL){
      current = current->next;
    }
    head->next = node;
  }

  return true;
}

bool queue::dequeue(node * &head){
  //removes nodes from the front end of the queue
  node * current = head;

  if (head != NULL) {
    head = current->next;
    delete current;
    return true;
  }

  else {
    cout << "There's nothing in the queue!" << endl;
  }

  /*else if (head->next == NULL) {
    head = current->next;
    delete current;
    return true;
  }

  while (current->next->next != NULL){
    cout << current->data;
    cout << current->next->data << endl;
    current = current->next;
  }
  cout << "out of the while loop" << endl;
  cout << current->data << endl;
  cout << current->next->data << endl;
  node * temp = current->next;
  current->next = temp->next;
  delete temp;
  return true;*/
}

void queue::print(node * head){
  while (head != NULL){
    cout << head->data;
    head = head->next;
  }
}

queue::~queue(){
}





