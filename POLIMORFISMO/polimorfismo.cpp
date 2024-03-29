#include <iostream>
using namespace std;

//Classe base
class Animal{
    public:
        void animalSound(){
            cout << "O animal faz um som \n";
        }
};

//Classe derivada
class Pig : public Animal{
    public:
        void animalSound(){
            cout << "O porco diz: wee wee \n";
        }
};

//Classe derivada
class Dog : public Animal {
    public:
        void animalSound(){
            cout << "O cachorro diz: bow bow \n";
        }
};

int main(){
    Animal animal;
    Pig pig;
    Dog dog;

    animal.animalSound();
    pig.animalSound();
    dog.animalSound();
    return 0;
}