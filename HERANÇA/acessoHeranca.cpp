#include <iostream>
using namespace std;

//Classe base
class Empregado {
    protected: //Especificação de acesso Protegido
    int salario;
};

//Classe derivada
class Programador: public Empregado{
    public:
        int bonus;
        void setSalario(int s){
            salario = s;
        }
        int getSalario(){
            return salario;
        }
};

int main(){
    Programador obj;
    obj.setSalario(50000);
    obj.bonus = 1500;
    cout << "Salario: " << obj.getSalario() << "\n";
    cout << "Bonus: " << obj.bonus << "\n";
    return 0;
}