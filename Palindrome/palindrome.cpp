#include <iostream>
#include <cstring>

using namespace std;

int main() {
  char str[80]; //this array is for reading in the user's input
  char str2[80];//this array is where the reversed input (output) goes

  cout << "Type stuff!" << endl;//tells the user to input something from their keyboard

  //the following 2 lines of code get the input from the user
  cin.get(str, 80);
  cin.get();

  int counter = 0;//this variable keeps track of the number of non-alphanumeric characters in the user's input
  for (int i = 0; i < strlen(str); i++){//this for loop iterates through each character in the "str" array
    str[i] = toupper(str[i]);//turns all characters into uppercase characters
    if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')){
      str[i - counter] = str[i];//if the character is alphanumeric, move this character to the same position in the string, minus the number of non-alphanumeric characters
    }
    else {
      counter++;//counter gets incremented if the character is not alphanumeric
    }
  }
  str[strlen(str) - counter] = '\0';//manually adds the null terminating character to the end of the array

  int str2_count = 0;//keeps count of the index of the second array (str2)
  for (int i = strlen(str) - 1; i >= 0; i--){//iterates through each spot in the str array backwards
    str2[str2_count] = str[i];//reverses the characters in the str array by flipping the order
    str2_count++;//increments the current index of the str2 array
  }

  str2[strlen(str)] = '\0';//manually adds the null terminating character to the end of the str2 array

  cout << str << endl;//prints the initial input, all caps, minus any non-alphanumeric characters
  cout << str2 << endl;//prints the reverse of the initial input

  if (strcmp(str, str2) == 0) {
    cout << "It's a palindrome!" << endl;//compares the "initial input" to the reversed string, and if they are the same, prints that it's a palindrome
  }

  else{
    cout << "Not a palindrome" << endl;//compares the "initial input" to the reversed string, and if they aren't the same, prints that it isn't a palindrome
  }

  
  return 0; 
}
