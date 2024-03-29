#include <iostream>
#include <string>
using namespace std;

void myFunction(int myNumbers[]) {
  for (int i = 0; i < 5; i++) {
    cout << myNumbers[i] << "\n";
  }
}

int main() {
  int myNumbers[] = {10, 20, 30, 40, 50};
  myFunction(myNumbers);
  return 0;
}