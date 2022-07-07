//Integrantes: Arthur Pereira, Eike F. Carlin, Paulo Hermans e Thyago Magalhães do Nascimento
#include <iostream>

using namespace std;

#include <time.h>
#include <stdlib.h>

#define n 4

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char matriz_principal[][n] = {'1','4','5','2',
                                  '7','2','8','7',
                                  '3','6','1','4',
                                  '6','5','3','8'};

    char matriz_gabarito[n][n];
    char matriz_jogo[n][n] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
    int num_pares = n * n / 2;
    int pares_formados=0;
    int num_max_jogadas = num_pares * 3;
    int num_jogadas=0;
    int pos_w, pos_x, pos_y, pos_z;
    int peca_1, peca_2;

     cout << endl << endl;

    srand(time(NULL)); // Comando para adicionar aleatoriedade na escolha do jogo.
    int numero_aleatorio;
    numero_aleatorio = rand()%4; // "Formula" de aleatoriedade para escolha do jogo.

    switch(numero_aleatorio) // Casos possíveis do jogo.
    {
        case 0:
            // SEM MODIFICAÇAO
            for(int i=0; i < n; i++)
            {
                for(int j=0; j < n; j++)
                    matriz_gabarito[i][j] = matriz_principal[i][j];
            }
            break;

        case 1:
            // MATRIZ TRANSPOSTA

            for(int i=0; i < n; i++)
            {
                for(int j=0; j < n; j++)
                    matriz_gabarito[j][i] = matriz_principal[i][j];
            }
            break;

        case 2:
            // MATRIZ INVERTIDA POR LINHA

            for(int i=0; i < n; i++)
            {
                for(int j=0; j < n; j++)
                    matriz_gabarito[i][j] = matriz_principal[n-1-i][j];
            }
            break;

        case 3:
            // MATRIZ INVERTIDA POR COLUNA

            for(int i=0; i < n; i++)
            {
                for(int j=0; j < n; j++)
                    matriz_gabarito[i][j] = matriz_principal[i][n-1-j];
            }
            break;
    }

    while(num_jogadas != num_max_jogadas && pares_formados != num_pares) // Laço para delimitar o jogo.
    {
        system("cls");
        cout << "\nN° de jogadas " << num_jogadas << " / " << num_max_jogadas; // Contador de jogadas.
        cout << "\nN° de pares formados " << pares_formados << " / " << num_pares; // Contador de pares formados.

        cout << "\n\n----MATRIZ JOGO----\n";
        for(int i=0; i < n; i++)
        {
            for(int j=0; j < n; j++)
                cout << matriz_jogo[i][j] << " ";
            cout << endl;
        }
            if (n>3 || n<0)
                cout << "Digite um número entre 0 e 3";

        cout << endl << endl;

        cout << "Escolha uma posição: "; // Escolha de posições da 1° peça.
        cin >> pos_w >> pos_x;
        peca_1 = matriz_gabarito[pos_w][pos_x];
        cin.clear(); // Reseta o estado do cin para o padrão.

        if(matriz_jogo[pos_w][pos_x] == ' ') // se a peça 1 escolhida é uma peça válida (ainda não foi formado seu par).
        {
            matriz_jogo[pos_w][pos_x] = peca_1;
            cout << "----MATRIZ JOGO----\n";
            for(int i=0; i < n; i++)
            {
                for(int j=0; j < n; j++)
                    cout << matriz_jogo[i][j] << " ";
                cout << endl;
            }
            cout << endl << endl;

            cout << "Escolha outra posição: "; // Escolha de posições da 1° peça.
            cin >> pos_y >> pos_z;
            peca_2 = matriz_gabarito[pos_y][pos_z];
            cin.clear(); // Reseta o estado do cin para o padrão.

            if(matriz_jogo[pos_y][pos_z] == ' ')// se a peça 2 escolhida é uma peça válida (ainda não foi formado seu par)
            {
                matriz_jogo[pos_y][pos_z] = peca_2;
                cout << "----MATRIZ JOGO----\n";
                for(int i=0; i < n; i++)
                {
                    for(int j=0; j < n; j++)
                        cout << matriz_jogo[i][j] << " ";
                    cout << endl;
                }
                cout << endl << endl;

                if(peca_1 == peca_2) // par encontrado.
                {
                    matriz_jogo[pos_w][pos_x] = peca_1; // Mostra a peça 1.
                    matriz_jogo[pos_y][pos_z] = peca_2; // Mostra a peça 2.
                    pares_formados++; // Adiciona 1 no contador de pares.
                    num_jogadas++; // Adiciona 1 ao numero de jogadas.
                    cout << "JOGADA OK";
                    cout << "\nPressione enter para continuar ...";
                    system("pause");
                }

                else // par não encontrado
                {
                    matriz_jogo[pos_w][pos_x] = ' '; // Não mostra a peça pois ela não é igual a outra.
                    matriz_jogo[pos_y][pos_z] = ' '; // Não mostra a peça pois ela não é igual a outra.
                    num_jogadas++; // Adiciona 1 ao numero de jogadas.
                    cout << "JOGADA NOK";
                    cout << "\nPressione enter para continuar ...";
                    system("pause");
                }
            }

            else // Comando para reiniciar pois o jogador selecionou uma peça ja virada para cima na 1° tentativa.
            {
                matriz_jogo[pos_w][pos_x] = ' ';
                cout << "\nPeça escolhida inválida!";
            }
        }

        else // Comando para reiniciar pois o jogador selecionou uma peça ja virada para cima na 2° tentativa.
        {
            cout << "\nPeça escolhida inválida!";
        }
    }

    if(pares_formados == num_pares)
        cout << "Todos os pares foram formados. PARABÉNS VOCÊ VENCEU!" << endl;
    else // num_jogadas == num_max_jogadas
        cout << "Número de jogadas máximas alcançado. VOCÊ PERDEU!" << endl;
        for(int i=0; i < n; i++) { // Comando para mostrar a matriz gabarito caso perca.
   for(int j=0; j < n; j++) { // Comando para mostrar a matriz gabarito caso perca.
      cout << matriz_gabarito[i][j] << " "; // Comando para mostrar a matriz gabarito caso perca.
   }
   cout << endl;
}
}
