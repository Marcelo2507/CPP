#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ofstream arquivoS;

    arquivoS.open("cfbCursos.txt");

    arquivoS << "CFB Cursos\n";
    arquivoS << "Curso de C++\n";

    arquivoS.close();

    ifstream arquivoE;
    string linha;
    arquivoE.open("cfbCursos.txt");
    if(arquivoE.is_open()){
        while(getline(arquivoE, linha)){
cout << linha << endl;
        }
        arquivoE.close();
    } else {
        cout << "Não foi possivel abrir o arquio" << endl;
    }

    return 0;
}