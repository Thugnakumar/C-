/*
Name: Varun Krishnakumar
Date Last Modified: 10/28/21
This program is titled Student List. It allows the user to do one of 4 things: add students to the list, delete students from the list, print the list, and quit the program. To add students, the user types "ADD". When this happens, the user can add a student to the list by adding their first and last name, id, and gpa. To delete students, the user types "DELETE". When this happens, the user can delete a specific student from their list by entering that student's ID number, then the program searches for that particular ID number in the list and deletes that student. When the user types "PRINT", the program prints the student names, id numbers, and gpas in the particular order that they were added. When the user types "QUIT", they quit the program.
 */
#include <iostream>
#include <vector>

using namespace std;

struct student {
  char firstName[20];
  char lastName[20];
  int id;
  float gpa;
};

int main() {
  vector <student*>* list = new vector <student*> list;
  input char[10];
  while (true) {
    cout << "Please enter a command: ";
    cin >> input;
    for (int i = 0; i < strlen(input); i++){
      input[i] = toupper(input[i]);
    }
  }
  return 0;
}

void add(vector <student*> &v){
  student newStudent;
  cin >> newStudent.name;
  cout << "Enter the student's ID number: ";
  cin >> newStudent.id;

void clearInput((&input)char[10]){
  for (int i = 0; i < 10; i++){
    if (input[i] != '\0'){
      input[i] = 0;
    }
  }
}
