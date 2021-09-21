#include <iostream>

using namespace std;

int main(){
  int input = 0;
  cin >> input;
  /*if (input == 3){
    cout << "You put in a 3!" << endl;
  }
  else {
    cout << "You didn't put in a 3!" << endl;
  } */

  switch(input){
  case 3: cout << "You put in a 3!" << endl;
    break;
  case 4: cout << "You put in a 4!" << endl;
    break;
  default: cout << "You entered something else!" << endl;
  }
  return 0;
}
