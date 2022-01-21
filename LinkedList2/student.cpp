//all the libraries
#include <iostream>
#include <cstring>
#include "student.h"
#include <math.h>

using namespace std;

Student::Student(){ //constructor
  //asks the user to enter the first name and stores it in the corresponding character array
  cout << "Enter the student's first name: ";
  cin >> firstName;
  cout << endl;

  //asks the user the enter the last name and stores it in the corresponding character array
  cout << "Enter the student's last name: ";
  cin >> lastName;
  cout << endl;

  //asks the user to enter the ID number and stores it in the corresponding integer
  cout << "Enter the student's ID number: ";
  cin >> id;
  cout << endl;

  //asks the user to enter the student's GPA and stores it in the corresponding float
  cout << "Enter the student's GPA: ";
  cin >> gpa;
  //rounds the GPA to the nearest hundredth
  gpa = round(gpa * 100)/100;
  cout << endl;
}

void Student::printName(){
  //prints the name of the student
  cout << "Name: " << firstName << " " << lastName << endl;
}

int Student::returnID(){
  //returns the ID of the student
  return id;
}

float Student::returnGPA(){
  //prints the GPA of the student
  return gpa;
}

Student* Student::getStudent(){
  //returns a pointer pointing to the current student
  return currentStudent;
}

Student::~Student(){
  //deletes all character arrays as it destroys the student object
  delete [] firstName;
  delete [] lastName;
}
