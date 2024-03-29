#include <iostream>
#include <string>
using namespace std;

//Classe básica
class Veiculo{
    public:
        string brand = "Ford";
        void honk() {
            cout << "vrum, vrum \n";
        }
};

//Classe derivada
class Carro: public Veiculo {
    public:
        string model = "Mustang";
};

int main(){
    Carro myCar;
    myCar.honk();
    cout << myCar.brand + " " + myCar.model;
    return 0;
}