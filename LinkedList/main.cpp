//all the libraries
#include <iostream>
#include <cstring>
#include <vector>
#include "student.h"
#include "node.h"

using namespace std;

int main(){
  //test code that creates two students and stores them in nodes
  Node* student1 = new Node(new Student());
  Node* student2 = new Node(new Student());
  cout << student2 -> getStudent()-> returnID() << endl;
}
