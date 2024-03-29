#include <iostream>
#include <string>
using namespace std;

int main(){
    // string food = "Pizza";
    // string &meal = food;

    // cout << &food << "\n";
    // cout << meal << "\n";

    //  Referências e ponteiros
//  (sobre os quais você aprenderá no próximo capítulo) 
//  são importantes em C++, 
//  porque oferecem a capacidade de manipular os dados 
//  na memória do computador - o que pode reduzir o código 
//  e melhorar o desempenho 

//     string food = "Pizza";  // A food variable of type string
// string* ptr = &food;    // A pointer variable, with the name ptr, that stores the address of food

// // Output the value of food (Pizza)
// cout << food << "\n";

// // Output the memory address of food (0x6dfed4)
// cout << &food << "\n";

// // Output the memory address of food with the pointer (0x6dfed4)
// cout << ptr << "\n";


string food = "Pizza";  // Variable declaration
string* ptr = &food;    // Pointer declaration

// Reference: Output the memory address of food with the pointer (0x6dfed4)
cout << ptr << "\n";

// Dereference: Output the value of food with the pointer (Pizza)
cout << *ptr << "\n";

// Change the value of the pointer
*ptr = "Hamburger";

// Output the new value of the pointer (Hamburger)
cout << *ptr << "\n";

// Output the new value of the food variable (Hamburger)
cout << food << "\n";
}

