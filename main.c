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

        printf("Escolha uma das op��es abaixo:\n\n");

        green();
        printf("(1) ");
        reset();
        printf("Definir obst�culos / Resetar\n");

        green();
        printf("(2) ");
        reset();
        printf("Definir posi��o inicial\n");

        green();
        printf("(3) ");
        reset();
        printf("Definir n�mero de movimentos\n");

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

        // Recebe intput do usu�rio e filtra (caso o usu�rio digite algo que n�o seja um inteiro)
        menu = filtraInteiro(tabuleiro);
        system("cls");

        switch (menu)
        {
          // Chama fun��o para criar obst�culos
          case 1:
            setObstaculos(tabuleiro);
           break;

          // Chama fun��o para escolher ponto inicial da cobra
          case 2:
            cobra = setPosicao(tabuleiro);
           break;

          // Define o n�mero de movimentos da cobra
          case 3:
            movimentos = setMovimentos(tabuleiro);
           break;

          // Caso o n�mero de movimentos n�o tenha sido definido
          case 4:
            if (movimentos == 0)
            {
               printTabuleiro(tabuleiro, 0);
               red();
               printf("N�mero de movimentos ainda n�o foi definido!\n\n");
               reset();

               system("pause");
               system("cls");
            }

            // Caso a cobra ainda n�o tenha sido gerada
            else if (cobra == 0)
            {
               printTabuleiro(tabuleiro, 0);
               red();
               printf("Cobra ainda n�o foi gerada!\n\n");
               reset();

               system("pause");
               system("cls");
            }

            // Caso tudo j� tenha sido definido
            else
            {
               iniciar(tabuleiro, movimentos);
            }
           break;

          // Fecha programa
          case 5:
             return 0;
           break;

          // Caso usu�rio digite um n�mero inexistente nas op��es
          default:
             printTabuleiro(tabuleiro, 0);
             red();
             printf("Digite um n�mero que corresponda a uma op��o existente!\n\n");
             reset();

             system("pause");
             system("cls");
           break;
        }
    }
}



