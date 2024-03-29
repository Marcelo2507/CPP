#include <iostream>
using namespace std;

//Classe base
class myC{
    public:
    void myF(){
        cout << "Algum conteudo na classe pai.";
    }
};

//Classe derivada (Filha)
class myChild: public myC{};

//Classe derivada (Neta)
class myGrandChild: public myChild{};

int main(){
    myGrandChild obj;
    obj.myF();
    return 0;
}