#include <iostream>
using namespace std;

/* Se quiser que outras pessoas leiam ou
 * modifiquem o valor de um membro 
 * privado, você pode fornecer métodos 
 * públicos get e set .
 * */

class Empregado{
    private: 
    //Atributo privado
    int salario;

    public:
    //Seter
    void setSalario(int s){
        salario = s;
    }

    //Geter
    int getSalario(){
        return salario;
    }
};

int main(){
    Empregado obj;
    obj.setSalario(500000);
    cout<<obj.getSalario();
    return 0;
}