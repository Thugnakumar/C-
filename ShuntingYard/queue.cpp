#include <iostream>
#include <cstring>
#include "queue.h"
#include "node.h"

using namespace std;

queue::queue(){
}

bool queue::enqueue(node * &head, node * &node){
  if (head == NULL){
    head = node;
  }

  else {
    node->next = head;
    head = node;
  }

  return true;
}

bool queue::dequeue(node * &head){
  node * current = head;
  while (current->next->next != NULL){
    cout << current->data;
    cout << current->next->data << endl;
    current = current->next;
  }
  cout << "out of the while loop" << endl;
  cout << current->data << endl;
  cout << current->next->data << endl;
  cout << current->next->next->data << endl;
  node * temp = current->next;
  current->next = temp->next;
  delete temp;
  return true;
}

void queue::print(node * head){
  while (head != NULL){
    cout << head->data;
    head = head->next;
  }
}

queue::~queue(){
}





