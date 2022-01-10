#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>
#include <vector>

class Student{
 public:
  Student();
  void printName();
  void printID();
  void printGPA();
  Student* getStudent();
  ~Student();
 private:
  Student* currentStudent;
  char firstName[20];
  char lastName[20];
  int id;
  float gpa;
};

#endif
