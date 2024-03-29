#include <iostream>
#include <fstream>
using namespace std;

int main(){
    //Crie uma string de texto, que é usada para gerar o arquivo de texto
    string myText;

    //Ler do arquivo de texto
    ifstream MyReadFile("filename.txt");

    //Use um loop while junto com a função getline() para ler o arquivo linha por linha
    while (getline (MyReadFile, myText)){
        //Produza o texto do arquivo
        cout << myText;
    }

    //Fecha o arquivo
    MyReadFile.close();

    return 0;
}