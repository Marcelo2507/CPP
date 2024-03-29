#include <iostream>
#include <string>
using namespace std;

class myClass{          //A classe
    public:             //Especificação de acesso
        int Num;        //Atributo
        string txt;     //Atributo
};

int main(){
    myClass myObj;      //Instancia da Classe

    //Acessando atributos e "setando"  valores para eles
    myObj.Num = 15;
    myObj.txt = "Somente texto";

    //printando valores e atributos
    cout << myObj.Num << endl;
    cout << myObj.txt;
    return 0;
}