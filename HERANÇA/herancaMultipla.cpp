#include <iostream>
using namespace std;

//Classe base
class myClass{
    public:
        void myFun(){
            cout << "Algum conteudo na classe pai.";
        }
};

//Outra classe base
class myOtherClass {
    public:
        void myOtherFun(){
            cout << "Alguma coisa sobre a outra funcao";
        }
};

//Classe derivada
class myChildClass: public myClass, 
public myOtherClass{};

int main(){
    myChildClass obj;
    obj.myFun();
    obj.myOtherFun();
    return 0;
}