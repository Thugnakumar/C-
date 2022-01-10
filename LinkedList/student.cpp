#include <iostream>
#include <cstring>
#include "student.h"
#include <math.h>

using namespace std;

Student::Student(){
  cout << "Enter the student's first name: ";
  cin >> firstName;
  cout << endl;
  cout << "Enter the student's last name: ";
  cin >> lastName;
  cout << endl;
  cout << "Enter the student's ID number: ";
  cin >> id;
  cout << endl;
  cout << "Enter the student's GPA: ";
  cin >> gpa;
  gpa == round(gpa * 100)/100;
  cout << endl;
}

void Student::printName(){
  cout << "Name: " << firstName << " " << lastName << endl;
}

void Student::printID(){
  cout << "ID: " << id << endl;
}

void Student::printGPA(){
  cout << "GPA: " << gpa << endl;
}

Student* Student::getStudent(){
  return currentStudent;
}

Student::~Student(){
  delete [] firstName;
  delete [] lastName;
}
