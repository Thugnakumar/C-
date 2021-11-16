#include <iostream>
#include <cstring>
#include "media.h"


using namespace std;

Media::Media(){
  cout << "What is the title? ";
  cin >> title;
  cout << endl << "What year was it published? ";
  cin >> year;
}
