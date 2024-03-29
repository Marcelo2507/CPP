#include <iostream>
#include <fstream>
using namespace std;

int main(){
    //Criar e abrir um arquivo de texto
    ofstream MyFile("filename.txt");

    //Escreve para o arquivo
    MyFile << "Os arquivos podem ser complicados, mas são bastante divertidos!";

    //Fecha o arquivo
    MyFile.close();
}