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
#include <random>

using namespace std;

struct node {
  //the blueprint for creating a new student struct
  char firstName[20];
  char lastName[20];
  int id;
  float gpa;
  node * next;
};

int hashFunction(node * student, int tableSize);
void createStudent(node ** &hashTable, int &tableSize);
void insert(node * student, node ** &hashTable, int &tableSize);
void rehash(node ** &hashTable, int &tableSize);

int main(){
  char input[20];
  int size = 100;
  node ** hashTable = new node * [size];


  for (int i = 0; i < size; ++i) {
    hashTable[i] = NULL;
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
      createStudent(hashTable, size);
    }

    else if (strcmp(input, "DELETE") == 0){
      //refers to the remove function if the user types "remove"
    }

    else if (strcmp(input, "CLEAR") == 0){
      //clears the vector if the user types "clear"
    }

    else if (strcmp(input, "PRINT") == 0){
      //refers to the print function if the user types print
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

int hashFunction(node * student, int tableSize) {
  return student->id % tableSize;
}

void createStudent(node ** &hashTable, int &tableSize){
  //replace with random student generator code
  //passes the vector in by reference and prompts the user to input all of the parameters that make up a student (as defined by the s \truct at the top)
  node * newStudent = new node();
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
  insert(newStudent, hashTable, tableSize);
}

void insert(node * student, node ** &hashTable, int &tableSize) {
  node * current = NULL;

  bool needToRehash = false;

  int arraySlot = hashFunction(student, tableSize);

  if (hashTable[arraySlot] != NULL) {
    current = hashTable[arraySlot];
    int collisionCount = 1;
    while (current->next != NULL) {
      collisionCount++;
      current = current->next;
    }
    
    if (collisionCount > 3) {
      //set the next node in the linked list to be the student and then call the rehash function if there are more than 3 nodes in one array index
      current->next = student;
      needToRehash = true;
    }

    else {
      current->next = student;
    }
  }

  else {
    //if the current slot is empty, put that student in the empty slot
    hashTable[arraySlot] = student;
  }
  
  if (needToRehash == true) {
    rehash(hashTable, tableSize);
  }
}

void rehash(node ** &hashTable, int &tableSize) {
  tableSize = tableSize * 2; //doubles the table size for rehashing

  node ** newHashTable = new node * [tableSize]; //creates a new array with that table size

  node * current = NULL; //node with no value for going through a linked list

  node * temp = NULL;

  bool needToRehash = false;//bool that checks if we need to rehash again

  for (int i = 0; i < tableSize; ++i) {
    //sets all of the indices within the new array to the null character
    newHashTable[i] = NULL;
  }

  cout << "Size of table is now: " << tableSize << endl;
  
  for (int i = 0; i < tableSize/2; ++i) {
    //iterates through each index of the old array
    //temp = hashTable[i];
    while (hashTable[i] != NULL) {
      cout << "There is a node in the " << i << " index of the array" << endl;
      //if the current index is not a null character (has a node), then checks to see what index it should go in in the new array
      int arraySlot = hashFunction(hashTable[i], tableSize);
      cout << "This node should go in the " << arraySlot << " index of the new array" << endl;
      if (newHashTable[arraySlot] != NULL) {
	cout << "There is already a node in the " << arraySlot << " index of the new array" << endl;
	//if that index in the new array already has a node, go through the linked list to see if that linked list has 3+ elements. If so, make a note to rehash the table and continue transferring data, otherwise just add the node to the end of the linked list
	current = newHashTable[arraySlot];
	int collisionCount = 1;
	while (current->next != NULL) {
	  collisionCount++;
	  current = current->next;
	}

	if (collisionCount > 3) {
	  needToRehash = true;
	}

	current->next = hashTable[i];
	hashTable[i] = hashTable[i]->next;
	current->next->next = NULL;
      }

      else {
	//if that new array index is empty, transfer the node from the previous array to this new array index. If there's now nothing in that slot in the old array, then set that array slot to be the null character
	newHashTable[arraySlot] = hashTable[i];
	cout << "ID of new Hash Table Node: " << newHashTable[arraySlot]->id << endl;
	hashTable[i] = newHashTable[arraySlot]->next;
	if (hashTable[i] != NULL) {
	  cout << "ID of first index of old Hash Table node: " << hashTable[i]->id << endl;
	}
	newHashTable[arraySlot]->next = NULL;
      }
    }
  }

  hashTable = newHashTable;
  
  if (needToRehash == true) {
    rehash(newHashTable, tableSize);
  }

  for (int i = 0; i < tableSize; ++i) {
    cout << i << " " ;
    if (newHashTable[i] != NULL) {
      cout << "Array index: " << i << endl;
      node * current = NULL;
      current = newHashTable[i];
      while (current != NULL) {
	cout << "Name: " << current->firstName << " " << current->lastName << '\t' << "ID: " << current->id << '\t' << "GPA: " << current->gpa << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	current = current->next;
      }
    }
  }
}
