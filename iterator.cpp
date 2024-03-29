#include <iostream>
#include <vector>

using namespace std;

    int main(){

        vector<string> produtos = {"mouse", "teclado", "monitor", "gabinete", "cx.som"};
        vector<string>::iterator it;

        it = produtos.begin();

        advance(it, 3); 
        //vai para o quarto elemento (0 é o primeiro)

        cout << *it << endl;

        return 0;
    }