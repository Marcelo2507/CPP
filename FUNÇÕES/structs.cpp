#include <iostream>
#include <string>
using namespace std;

int main(){

    /* Ao contrário de um array,
    uma estrutura pode conter muitos tipos de dados diferentes
    (int, string, bool, etc.).*/

// Cria uma variável de estrutura chamada myStructure
struct {
int myNum;
string myString;
} myStructure;

// Atribuir valores aos membros de myStructure

myStructure.myNum = 1;
myStructure.myString = "Hello World!";

// Imprimir membros de myStructure
cout << myStructure.myNum << "\n";
cout << myStructure.myString << "\n";
}