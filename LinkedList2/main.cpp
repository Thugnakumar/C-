/*Name: Varun Krishnakumar
Date: 1/25/2022
This is the Linked List project. In this project, the user will be able to add, remove, and print students in a list. They can QUIT the code at any time. The entire project uses the Linked List data structure to make all the students.
*/

#include <iostream>
#include <cstring>

#include "Node.h"
#include "Student.h"

void add(Node* current, Node* node, Node* &head);
void traverse(Node* current);
void remove(Node* current, Node* &head, int ID);
void average(Node* current, float avg, int counter);

using namespace std;

int main(){
  Node* head = NULL; //empty head node which will be updated later
  bool prev = NULL; //boolean to check if I'm at the head;
  float avg = 0; //variable to store sum/average of GPAs
  int counter = 0; //counts the number of GPAs in the linked list
  char message[300]; //character array that stores the message detailing the purpose of the program
  char input[10]; //character array to store input
  cout << "Welcome to the Student List program!";
  strcpy(message, "Type 'ADD' to add a student, 'DELETE' to delete a student, 'PRINT' to print all the students in the list, 'AVERAGE' to find the average of all the students' GPAs, and 'QUIT' to exit the program. Type 'HELP' if you're stuck.");
  while (true){ //runs forever
    cout << message << endl;

    cin >> input;

    for (int i = 0; i < strlen(input); i++){
      //converts all input to uppercase
      input[i] = toupper(input[i]);
    }

    if (strcmp(input, "ADD") == 0){
      //calls the add function to add a student to the list
      Node* node = new Node(new Student());
      add(head, node, head);
    }

    else if (strcmp(input, "DELETE") == 0){
      //calls the delete function to delete a student from the list
      int id = -1;
      cout << "Enter the ID of the student you wish to delete: ";
      cin >> id;
      cout << endl;
      remove(head, head, id);
    }

    else if (strcmp(input, "PRINT") == 0){
      //calls the traverse function to print through all the students in the list
      traverse(head);
    }

    else if (strcmp(input, "AVERAGE") == 0){
      //calls the average function to print the average of all the students' GPAs
      average(head, avg, counter);
    }

    else if (strcmp(input, "QUIT") == 0){
      //quits the program
      break;
    }

    else if (strcmp(input, "HELP") == 0){
      //prints the message from the start
      cout << message << endl;
    }

    else {
      //prints the following message if what the user typed in isn't valid
      cout << "Not a valid input!" << endl;
    }
  }
}

void add(Node* current, Node* node, Node* &head){

  if (current == NULL){
    //if the linked list is empty, set the added node to be the head
    head = node;
  }

  else {
    //if the linked list isn't empty...
    if (current -> getStudent() -> returnID() >= node -> getStudent() -> returnID() && (current == head)){
      //if we're evaluating the head node and the ID of the node is smaller than the ID of the head, then make the passed in node the new head
      node -> setNext(current);
      head = node;
    }

    else if (current -> getStudent() -> returnID() < node -> getStudent() -> returnID()){
      //if the student ID is less than the ID of the currently evaluated node...
      if (current -> getNext() == NULL){
	//if we're at the end of the list, set the next node of the currently evaluated node to be the node that's passed in
	current -> setNext(node);
      }

      else if (current -> getNext() -> getStudent() -> returnID() >= node -> getStudent() -> returnID()){
	//if the student ID of the passed in node is less than or equal to the ID of the next node, then set the node's next node to be the next node of the currently evaluated node, then set the currently evaluated node's next node to be the node that's passed in
	node -> setNext(current -> getNext());
	current -> setNext(node);
      }

      else {
	//if the passed in node's ID is larger than both the currently evaluated node AND the next node, then keep traversing through the linked list
	add (current -> getNext(), node, head);
      }
    }
  }
}

void traverse(Node* current){
  //goes through the linked list and prints out the details of each node
  
  if (current == NULL){
    //if the current node has no contents, then stop going through this function
    return;
  }

  //print the name, ID, and GPA of each node
  cout << "Name: ";
  current -> getStudent() -> printName();
  cout  << '\t' << "ID: " << current -> getStudent() -> returnID() << '\t' << "GPA: " << current -> getStudent() -> returnGPA() << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

  //uses recursion to go through the linked list
  traverse(current -> getNext());
}

void remove(Node* current, Node* &head, int ID) {
  //goes through the linked list and removes the specified node
  
  if (current == NULL){
    //if the current node has no contents, then it's the end of the list and there were no matching results
    cout << "Nothing in the list matched the search!" << endl;
    return;
  }

  if (current == head && current -> getStudent() -> returnID() == ID){
    //if the current node is the head and if the ID is the same then set the next node in the list to be the head and delete the head
    head = current -> getNext();
    delete current;
  }

  else {
    //if the current node isn't the head or the head ID doesn't match

    if (current -> getNext() == NULL) {
      //if the program makes it to the end of the list and none of the numbers match then the following message prints
      cout << "Nothing in the list matched the search!" << endl;
    }
    
    else if (current -> getNext() -> getStudent() -> returnID() == ID){
      //if the next node has the ID we are looking for, then transfer the contents of the next node to a temporary node, have the current node point to the node two nodes down the list, and delete the temporary node
      Node* temp = current -> getNext();
      current -> setNext(temp -> getNext());
      delete temp;
    }

    else {
      //if none of the above are true, keep traversing through the list until one of the above become true
      remove(current -> getNext(), head, ID);
    }
  }
}

void average(Node* current, float avg, int counter){
  //averages all of the GPAs
  
  if (current == NULL){
    //if we're at the end of the list, calculate the average and print it out, then exit the function
    avg = avg/counter;
    cout << "The average of all GPAs is: " << avg << endl;
    return;
  }

  avg += current -> getStudent() -> returnGPA();//sums up the averages
  counter++;//increments the count of GPAs every time the sum is updated

  average(current -> getNext(), avg, counter); //uses recursion to traverse through the linked list until we reach the end
}
