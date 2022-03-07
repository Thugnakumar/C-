/*
Date: 3/7/22
Name: Varun Krishnakumar
This is the Hash Table project. It allows users to input a first and last name, ID number, and GPA to create a student which is then stored in a node. Those nodes are then pushed into a specific array index; the index is derived by finding the modulus of the ID number and the size of the array. Upon insertion, the program checks to see how many nodes are in that particular array slot (collisions). If there are 3 nodes in that index, then the size of the table is changed and the indices of the nodes are altered according to the size of the table/array.
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <cstring>
#include <math.h>
#include <iomanip>

using namespace std;

struct node {
  //the blueprint for creating a new student struct
  char firstName[20];
  char lastName[20];
  int id;
  float gpa;
  node * next;
};

void add(node * &hashTable, int &tableSize);

int main(){
  int size = 100;
  node hashTable[size];

  for (i = 0; i < size; ++i) {
    hashTable[i] = '\0';
  }
  
  while (true) {//keeps running forever
    cout << endl << "Please type 'ADD' to add a new student to the list, 'DELETE' to remove a student from the list, 'PRINT' to print\
 all the students in the list, or 'QUIT' to exit the program: "; //prompts the user for a command
    cin >> input;//reads in the command
    cout << endl;
    for (int i = 0; i < strlen(input); i++){
      //changes the user's input to purely uppercase characters
      input[i] = toupper(input[i]);
    }

    if (strcmp(input, "ADD") == 0){
      //resorts to the add function if the user types "add"
      add(list);
    }

    else if (strcmp(input, "DELETE") == 0){
      //refers to the remove function if the user types "remove"
      remove(list);
    }

    else if (strcmp(input, "CLEAR") == 0){
      //clears the vector if the user types "clear"
      list.clear();
    }

    else if (strcmp(input, "PRINT") == 0){
      //refers to the print function if the user types print
      print(list);
    }
    
    else if (strcmp(input, "QUIT") == 0){
      //exits the program if the user types quit
      break;
    }

    else {
      //if none of the above inputs are the same as what the user typed in, then it's an invalid command and the following message pr \
      ints on the screen
      cout << "Not a valid command!" << endl;
    }
   }
   
   cout << "Thank you for using this program! Goodbye!";
   return 0;
}

void add(node * &hashTable, int &tableSize){
  //passes the vector in by reference and prompts the user to input all of the parameters that make up a student (as defined by the s \truct at the top)
  node * newStudent = new student();
  node * current = NULL;
  cout << "Enter the student's first name: ";
  cin >> newStudent->firstName;
  cout << endl << "Enter the student's last name: ";
  cin >> newStudent->lastName;
  cout << endl << "Enter the student's ID number: ";
  cin >> newStudent->id;
  cout << endl << "Enter the student's GPA: ";
  cin >> newStudent->gpa;
  newStudent->gpa = round(newStudent->gpa * 100)/100;
  newStudent->next = NULL;
  int arraySlot = newStudent->id % 100;
  if (hashTable[arraySlot] != '\0') {
    current = hashTable[arraySlot];
    int collisionCount = 0;
    while (current != NULL) {
      collisionCount++;
      current = current->next;
    }
    
    if (collisionCount >= 2) {
      //call the rehash function if there are more than 2 nodes in one array index
    }

    else {
      current->next = newStudent;
    }
  }
  cout << "New student added!" << endl; //prints a confirmation message when a student is successfully added
}
