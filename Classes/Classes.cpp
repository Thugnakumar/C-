#include <iostream>
#include <cstring>
#include <vector>
#include "media.h"

using namespace std;

int main(){
  vector<Media*> vect;
  Media* temp = new Media();
  vect.push_back(temp);
  return 0;
}
