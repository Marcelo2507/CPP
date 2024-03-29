#include <iostream>
#include <string>
using namespace std;

class Car{         //classe
    public:          //Especificação de acesso
        string brand;//atributo
        string model;//atributo
        int year;    //atributo
        Car(string x, string y, int z); //declaração de Construtor
};

//Construtor definido fora da classe
Car::Car(string x, string y, int z){
    brand = x;
    model = y;
    year = z;
}

int main(){

    //Criar o objeto e chamar o construto com diferentes valores
    Car carObj1("BMW", "X5", 1999);
    Car carObj2("Ford", "Mustang", 1969);

    //Printando os valores
    cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << "\n";

    cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << "\n";
    return 0;
}