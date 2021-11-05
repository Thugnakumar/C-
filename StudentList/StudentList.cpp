/*
Name: Varun Krishnakumar
Date Last Modified: 11/5/21
This program is titled Student List. It allows the user to do one of 4 things: add students to the list, delete students from the list, print the list, and quit the program. To add students, the user types "ADD". When this happens, the user can add a student to the list by adding their first and last name, id, and gpa. To delete students, the user types "DELETE". When this happens, the user can delete a specific student from their list by entering that student's ID number, then the program searches for that particular ID number in the list and deletes that student. When the user types "PRINT", the program prints the student names, id numbers, and gpas in the particular order that they were added. When the user types "QUIT", they quit the program.
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

struct student {
  //the blueprint for creating a new student struct
  char firstName[20];
  char lastName[20];
  int id;
  float gpa;
};

//function declarations
void add(vector <student*> &v);
void remove(vector <student*> &v);
void print(vector <student*> &v);

int main() {
  //where all the action happens
  vector <student*> list;//creates a new list of student pointers
  char input[10];//reads in the user's input to determine what command they give
  while (true) {//keeps running forever
    cout << "Please enter a command: "; //prompts the user for a command
    cin >> input;//reads in the command
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
      //if none of the above inputs are the same as what the user typed in, then it's an invalid command and the following message prints on the screen
      cout << "Not a valid command! Please type 'ADD' to add a new student to the list, 'DELETE' to remove a student from the list, 'PRINT' to print all the students in the list, or 'QUIT' to exit the program" << endl;
    }
  }

  cout << "Thank you for using this very complicated program! Goodbye!";
  return 0;
}

void add(vector <student*> &v){
  //passes the vector in by reference and prompts the user to input all of the parameters that make up a student (as defined by the struct at the top)
  student* newStudent = new student();
  cout << "Enter the student's first name: ";
  cin >> newStudent -> firstName;
  cout << endl << "Enter the student's last name: ";
  cin >> newStudent -> lastName;
  cout << endl << "Enter the student's ID number: ";
  cin >> newStudent -> id;
  cout << endl << "Enter the student's GPA: ";
  cin >> newStudent -> gpa;
  newStudent -> gpa = round(newStudent -> gpa * 100)/100;
  v.push_back(newStudent); //actually pushes out the newly created student to the vector/list
  cout << "New student added!" << endl; //prints a confirmation message when a student is successfully added
}

void remove(vector <student*> &v){
  //removes a particular student based on what ID the user types in
  int studentID = -1;
  if (!v.empty()){
    //the program first checks to see if there is an actual student in the list first, before it deletes anything
    cout << "Please type the ID of the student you wish to delete. Here are the current students in your list:" << endl; //prompts the user to type the ID of the student they wish to delete
    print(v); //prints out the list of current students so that the user can reference what students they have and their properties before deleting
    cin >> studentID; //reads in the user's input for ID
    for (vector <student*> :: iterator it = v.begin(); it != v.end(); ++it){
      //iterates through each element in the vector
      if (studentID == (*it) -> id){
	//compares the user input ID and the ID of each student until they match, then removes that student from the vector and deletes it completely
	v.erase(it);
	delete *it;
	cout << "Deleted!" << endl;
	break;
      }

      else {
	//if the ID doesn't match with any of the IDs of the students, the following message prints
	cout << "Not a valid ID!" << endl;
      }
    }
  }

  else {
    //if there's nothing in the list, the following message prints
    cout << "There is nothing in your list to delete!" << endl;
  }
}

void print(vector <student*> &v){
  //this function prints all of the students in the vector, along with their properties
  if (!v.empty()){
    //makes sure that the vector isn't empty first
    for (vector <student*> :: iterator it = v.begin(); it != v.end(); ++it){
      //iterates through each element in the vector and prints each of the students' properties
      cout << "First Name: " << (*it) -> firstName << " | Last Name: " << (*it) -> lastName << " | ID: " << (*it) -> id << " | GPA: " << (*it) -> gpa << endl;
    }
  }

  else {
    //if the list is empty, the following message prints
    cout << "There is nothing in your list to print!" << endl;
  }
}
