/*Name: Varun Krishnakumar
Date: 1/21/2022
This is the Linked List project. In this project, the user will be able to add, remove, and print students in a list. They can QUIT the code at any time. The entire project uses the Linked List data structure to make all the students.
*/

#include <iostream>
#include <cstring>

#include "Node.h"
#include "Student.h"

using namespace std;

int main(){
  Node* head = NULL; //empty head node which will be updated later
  bool prev = NULL; //boolean to check if I'm at the head;
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
      add(head, node);
    }

    else if (strcmp(input, "DELETE") == 0){
      //calls the delete function to delete a student from the list
    }

    else if (strcmp(input, "PRINT") == 0){
      //calls the traverse function to print through all the students in the list
    }

    else if (strcmp(input, "AVERAGE") == 0){
      //calls the average function to print the average of all the students' GPAs
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

void add(Node* &current, Node* &node, bool &prev){
  if (current == head){
    prev = true;
  }

  else {
    prev = false;
  }
  
  if (current == NULL){
    head = node;
  }

  else {
    if (current -> getStudent() -> returnID() >= node -> getStudent() -> returnID()){
      node -> setNext(current);

      if (prev == true){
	head = node;
      }
    }

    else if (head -> getStudent() -> returnID() < node -> getStudent() -> returnID()){
      
    }
  }
}
