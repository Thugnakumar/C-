//header guards
#ifndef STUDENT_H
#define STUDENT_H

//all the libraries
#include <iostream>
#include <cstring>

class Student{//class declaration
public: //all public functions
  Student(); //constructor
  void printName(); //prints the name
  int returnID(); //returns the ID
  void printGPA(); //prints the GPA
  Student* getStudent(); //returns a pointer to the current student
  ~Student(); //destructor
private: //private variables
  Student* currentStudent; //a student pointer pointing to the current student
  char firstName[20]; //a character array for inputting the first name
  char lastName[20]; //a character array for inputting the last name
  int id; //an integer for storing the ID
  float gpa; //a float for storing the GPA
};

#endif
