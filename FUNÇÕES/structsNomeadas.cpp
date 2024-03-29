#include <iostream>
#include <string>
using namespace std;

// Declare uma estrutura chamada "car"
struct car {
  string brand;
  string model;
  int year;
};

int main() {
  // Crie uma estrutura de "car" e armazene-a em myCar1;
  car myCar1;
  myCar1.brand = "BMW";
  myCar1.model = "X5";
  myCar1.year = 1999;

  // Crie outra estrutura de "car" e armazene-a em myCar2;
  car myCar2;
  myCar2.brand = "Ford";
  myCar2.model = "Mustang";
  myCar2.year = 1969;
 
  // Printa os membros da estrutura
  cout << myCar1.brand << " " << myCar1.model << " " << myCar1.year << "\n";
  cout << myCar2.brand << " " << myCar2.model << " " << myCar2.year << "\n";
 
  return 0;
}