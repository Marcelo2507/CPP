#include <iostream>
#include <string>
using namespace std;

int main(){
    char playAgain;

    do{
        bool ships[4][4] = {
            { 0, 1, 0, 0},
            { 1, 0, 0, 0},
            { 0, 0, 0, 1},
            { 0, 0, 1, 0}
        };

        //Acompanhe quantos acertos o jogador tem e quantos turnos ele jogou nessas variáveis
        int hits = 0;
        int numOfTurns = 0;

        //Permita que o jogador continue até atingir todos os quatro navios
        while (hits < 4){
            int row, column;

            cout << "Selecionando coordenadas\n";

            // Peça uma linha ao jogador
            cout << "Escolha uma linha entre 0 e 3: ";
            cin >> row;

            //Peça uma coluna ou jogador
            cout << "Escolha uma coluna entre 0 e 3: ";
            cin >> column;

            //Cheque se existe um navio nesta coordenada
            if (ships[row][column]) {
                // se o player acertou um navio, remova-o e configure o valor para zero.
                ships[row][column] = 0;

                //Incremente o acerto ao contador
                hits++;

                //Diga ao jogador que ele atingiu um navio e quantos navios restam
                cout << "Acertou! Faltam " << (4-hits) << ".\n\n";
            } else {
                // Avise que o jogador errou.
                cout << "Errou.\n\n";
            }

            //Conte quantos turnos o jogador fez
            numOfTurns++;
        }

        cout << "Vitoria!\n";
        cout << "Voce jogou " << numOfTurns << " turnos";

        
        cout << "\n\tQuer jogar de novo? (S/N) \n";
        cin >> playAgain;
    }while(playAgain == 'S');
    return 0;
}