/*
Date: 3/7/22
Name: Varun Krishnakumar
This is the Hash Table project. It randomly generates a student with a first and last name, ID number, and GPA which is then stored in a node. Those nodes are then pushed into a specific array index; the index is derived by finding the modulus of the ID number and the size of the array. Upon insertion, the program checks to see how many nodes are in that particular array slot (collisions). If there are 3 nodes in that index, then the size of the table is changed and the indices of the nodes are altered according to the size of the table/array.
 */

//all the libraries
#include <iostream>
#include <cstring>
#include <vector>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <fstream>

using namespace std;

struct node {
  //the blueprint for creating a new student struct
  char * firstName;
  char * lastName;
  int id;
  float gpa;
  node * next;
};

//all the functions
int hashFunction(int id, int tableSize);
void createStudent(node ** &hashTable, int &tableSize, char * firstName, char * lastName);
void insert(node * student, node ** &hashTable, int &tableSize);
void print(int id, node ** &hashTable, int tableSize);
void remove(int id, node ** &hashTable, int tableSize);
void rehash(node ** &hashTable, int &tableSize);

int main(){
  //where all the stuff happens
  srand(time(NULL));

  //code for getting all the first names from the txt file here
  char firstNameOptions[1000][15];
  ifstream firstName;
  firstName.open("firstnames.txt");

  for (int i = 0; i < 1000; ++i) {
    firstName >> firstNameOptions[i];
  }

  //code for getting all the last names from the txt files here
  char lastNameOptions[1000][15];
  ifstream lastName;
  lastName.open("lastnames.txt");

  for (int i = 0; i < 1000; ++i) {
    lastName >> lastNameOptions[i];
  }

  char input[20]; //character array for taking command input from the user
  int size = 100; //size of the hash table
  node ** hashTable = new node * [size]; //THE HASH TABLE
  int generalNum = -1; //general number for numerical stuff here in main


  for (int i = 0; i < size; ++i) {
    //sets all values of the table to NULL
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
      //asks how many students the user wants to add and then generates that many random students and adds them to the hash table if the user types "add"
      cout << "How many students would you like to add? ";
      cin >> generalNum;
      if (generalNum > 0) {
	for (int i = 0; i < generalNum; ++i) {
	  createStudent(hashTable, size, firstNameOptions[rand() % 100], lastNameOptions[rand() % 100]);
	  cout << "Created student" << endl;
	}
      }

      else {
	//if the user's input is a non-positive integer, the following message prints
	cout << "Not a valid input!" << endl;
      }
    }

    else if (strcmp(input, "DELETE") == 0){
      //refers to the remove function if the user types "delete" after asking the user for the ID of the student to be deleted
      cout << "Enter the ID of the student you wish to delete: ";
      cin >> generalNum;
      remove(generalNum, hashTable, size);
    }

    else if (strcmp(input, "PRINT") == 0){
      //refers to the print function if the user types "print" after asking the user for the ID of the student to be printed
      cout << "Enter the ID of the student you want to print: ";
      cin >> generalNum;
      print(generalNum, hashTable, size);
    }
    
    else if (strcmp(input, "QUIT") == 0){
      //exits the program if the user types quit
      break;
    }

    else {
      //if none of the above inputs are the same as what the user typed in, then it's an invalid command and the following message prints on the screen
      cout << "Not a valid command!" << endl;
    }
   }
   
   cout << "Thank you for using this program! Goodbye!";
   return 0;
}

int hashFunction(int id, int tableSize) {
  //hash function for determining slot of the array
  return id % tableSize;
}

void createStudent(node ** &hashTable, int &tableSize, char * firstName, char * lastName){
  //creates a new student pointer and randomizes the ID and GPA (names should be passed in)
  node * newStudent = new node();
  int id = rand() % 89999 + 10000;
  node * temp = hashTable[hashFunction(id, tableSize)];
  bool exists = false;
  newStudent->firstName = firstName;
  newStudent->lastName = lastName;

  do {
    while (temp != NULL) {
      if (temp->id == id) {
	id = rand() % 89999 + 10000;
	exists = true;
      }

      else {
	exists = false;
      }
      temp = temp->next;
    }
  } while (exists == true);
    
  newStudent->id = id;
  newStudent->gpa = (rand() % 400 + 100) / 100;
  newStudent->next = NULL;

  //prints the characteristics of the student as they are made
  cout << "Name: " << newStudent->firstName << " " << newStudent->lastName << endl;
  cout << "ID: " << newStudent->id << endl;
  cout << "GPA: " << newStudent->gpa << endl;
  insert(newStudent, hashTable, tableSize);
}

void insert(node * student, node ** &hashTable, int &tableSize) {
  //function for adding the student to the hash table
  node * current = NULL;

  bool needToRehash = false; //boolean for checking whether or not we need to rehash

  int arraySlot = hashFunction(student->id, tableSize); //the slot at which the student should be inputted

  if (hashTable[arraySlot] != NULL) {
    //if there's something in the array slot, then set "current" to be the first node in the array and declare a new int "collisionCount" to be 0
    current = hashTable[arraySlot];
    int collisionCount = 0;
    while (current != NULL) {
      //tracks the number of nodes in the array slot and increments collisionCount accordingly
      collisionCount++;
      current = current->next;
    }
    
    if (collisionCount > 3) {
      //set the next node in the linked list to be the student and then call the rehash function if there are more than 3 nodes in one array index
      needToRehash = true;
    }

    current->next = student;
  }

  else {
    //if the current slot is empty, put that student in the empty slot
    hashTable[arraySlot] = student;
  }
  
  if (needToRehash == true) {
    //if there are more than 3 collisions in an array slot, rehash the table
    rehash(hashTable, tableSize);
  }
}

void print(int id, node ** &hashTable, int tableSize) {
  //prints the name, ID, and GPA of the student that the user specifies
  int arraySlot = hashFunction(id, tableSize); //slot in the array where the student is located
  bool exists = false; //boolean for checking if this student exists
  node * temp = hashTable[arraySlot]; //temporary node pointer
  while (temp != NULL) {
    //while this array index isn't empty...
    if (temp->id == id) {
      //if this is the student that the user wants printed out, print out the student's info and set "exists" to true to show that the user exists
      cout << "Name: " << temp->firstName << " " << temp->lastName << endl;
      cout << "ID: " << temp->id << endl;
      cout << "GPA: " << temp->gpa << endl;
      exists = true;
      break;
    }
    temp = temp->next; //keep traversing along the linked list
  }

  if (exists == false) {
    //if the student doesn't exist, the following message prints
    cout << "Student doesn't exist!" << endl;
  }
}
void remove(int id, node ** &hashTable, int tableSize) {
  //function to remove the a student specified by the user from the array
  int arraySlot = hashFunction(id, tableSize); //slot in the array where the student is located
  bool exists = false; //boolean for checking if this student exists
  node * temp = hashTable[arraySlot]; //temporary node pointer
  if (temp != NULL) {
    //if the array slot where the student is supposed to exist isn't blank...
    if (temp->id == id) {
      //if the first node/student is the one that should be deleted, delete that student and set the next node in that index to be the first node in that array slot
      hashTable[arraySlot] = temp->next;
      delete temp;
      exists = true;
    }

    else {
      while (temp->next != NULL) {
	//if the head is not the student to be deleted, traverse through he rest of the nodes at that array slot
	if (temp->next->id == id) {
	  //if the next student is the one that should be deleted, make the current student point to the next next student and delete the next student
	  node * templeRun = temp->next;
	  temp->next = templeRun->next;
	  delete templeRun;
	  exists = true;
	  break;
	}
	temp = temp->next;
      }
    }
    
    if (exists == false) {
      //if the student doesn't exist, then the following message prints
	cout << "Student doesn't exist!" << endl;
    }
  }

  else {
    //if there's nothing in the array slot, then the following message prints
    cout << "Student doesn't exist!" << endl;
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
      int arraySlot = hashFunction(hashTable[i]->id, tableSize);
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

  //"updates" the size of the hash table and deletes the old one
  hashTable = newHashTable;
  delete hashTable;
  
  if (needToRehash == true) {
    //if there are more than 3 collisions when transferring from the old hash table, then the table is rehashed
    rehash(newHashTable, tableSize);
  }
}
