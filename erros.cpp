#include <iostream>
using namespace std;

int main(){
    try{
        int age = 15;
        if (age >= 18){
            cout << "Acesso garantido - voce é mais velho";
        } else {
            throw 505;
        }
    }
    catch (/*int myNum*/...){
        cout << "Acesso negado - Voce e muito novo precisa ter 18 anos.\n";
//        cout << "Erro numero: " << myNum;
    }
    return 0;
}