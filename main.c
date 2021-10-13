#include "jogo_cobra.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int menu, movimentos=0, cobra=0;
    char tabuleiro[TAM][TAM];

    // Cria o tabuleiro
    setTabuleiro(tabuleiro);
    system("cls");

    // Menu principal
    for (;;)
    {
        printTabuleiro(tabuleiro);

        printf("Escolha uma das opções abaixo:\n\n");

        green();
        printf("(1) ");
        reset();
        printf("Definir obstáculos / Resetar\n");

        green();
        printf("(2) ");
        reset();
        printf("Definir posição inicial\n");

        green();
        printf("(3) ");
        reset();
        printf("Definir número de movimentos\n");

        green();
        printf("(4) ");
        reset();
        printf("Iniciar\n");

        green();
        printf("(5) ");
        reset();
        red();
        printf("Sair\n\n");
        reset();

        // Recebe intput do usuário e filtra (caso o usuário digite algo que não seja um inteiro)
        menu = filtraInteiro(tabuleiro);
        system("cls");

        switch (menu)
        {
          // Chama função para criar obstáculos
          case 1:
            setObstaculos(tabuleiro);
           break;

          // Chama função para escolher ponto inicial da cobra
          case 2:
            cobra = setPosicao(tabuleiro);
           break;

          // Define o número de movimentos da cobra
          case 3:
            movimentos = setMovimentos(tabuleiro);
           break;

          // Caso o número de movimentos não tenha sido definido
          case 4:
            if (movimentos == 0)
            {
               printTabuleiro(tabuleiro, 0);
               red();
               printf("Número de movimentos ainda não foi definido!\n\n");
               reset();

               system("pause");
               system("cls");
            }

            // Caso a cobra ainda não tenha sido gerada
            else if (cobra == 0)
            {
               printTabuleiro(tabuleiro, 0);
               red();
               printf("Cobra ainda não foi gerada!\n\n");
               reset();

               system("pause");
               system("cls");
            }

            // Caso tudo já tenha sido definido
            else
            {
               iniciar(tabuleiro, movimentos);
            }
           break;

          // Fecha programa
          case 5:
             return 0;
           break;

          // Caso usuário digite um número inexistente nas opções
          default:
             printTabuleiro(tabuleiro, 0);
             red();
             printf("Digite um número que corresponda a uma opção existente!\n\n");
             reset();

             system("pause");
             system("cls");
           break;
        }
    }
}



