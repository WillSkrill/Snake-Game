#include "jogo_cobra.h"

//////////////////////////////////////
//////////CRIA DO TABULEIRO///////////
//////////////////////////////////////

void setTabuleiro(char tabuleiro[TAM][TAM])
{

    int i = 0;

    // Criação do tabuleiro
    for (int x=0; x<TAM; x++)
    {
        for (int y=0; y<TAM; y++)
        {
            // Definindo espaço em branco inicial
            if (x == 0 && y == 0)
            {
               tabuleiro[x][y] = ' ';
            }

            // Definindo números nas bordas em y
            if (x == 0 && y > 0)
            {
               tabuleiro[x][y] = i + '0';
               i++;
            }

            // Definindo números nas bordas em x
            if (y == 0 && x > 0)
            {
               if (i == 10)
               {
                  i = 0;
               }
               tabuleiro[x][y] = i + '0';
               i++;
            }

            // Definindo espaços vazios
            if (x != 0 && y != 0)
              {
                tabuleiro[x][y] = 'x';
              }
         }
     }
    system("cls");
}


//////////////////////////////////////
////////PRINTA DO TABULEIRO///////////
//////////////////////////////////////

void printTabuleiro(char tabuleiro[TAM][TAM], int iniciar)
{
    // Impressão do tabuleiro
    yellow();
    printf("      TABULEIRO\n\n");
    reset();
    for (int x=0; x<TAM; x++)
    {
      for (int y=0; y<TAM; y++)
      {
         switch (tabuleiro[x][y])
         {
            case 'O':
                red();
                printf ("%c ", tabuleiro[x][y]);
                reset();
             break;
            case 'C':
                green();
                printf ("%c ", tabuleiro[x][y]);
                reset();
             break;
            case 'd':
                green();
                printf ("* ", tabuleiro[x][y]);
                reset();
             break;
            case 'e':
                green();
                printf ("* ", tabuleiro[x][y]);
                reset();
             break;
            case 'f':
                green();
                printf ("* ", tabuleiro[x][y]);
                reset();
             break;
            case 'g':
                green();
                printf (". ");
                reset();
             break;
            case 'x':
                if (iniciar == 1) // Caso iniciar = 1, printa o tabuleiro sem os "x"
                {
                   printf ("  ");
                }
                else
                {
                   printf ("x "); // Caso iniciar = 0, printa o tabuleiro com os "x"
                }
             break;
            default:
                yellow();
                printf ("%c ", tabuleiro[x][y]);
                reset();
             break;
          }
      }
      printf ("\n");
    }
    printf ("\n");
}


//////////////////////////////////////
////////CRIAÇÃO DE OBSTÁCULOS/////////
//////////////////////////////////////

void setObstaculos(char tabuleiro[TAM][TAM])
{
    // Reseta o tabuleiro (para quando o usuário já tiver setado obstáculos anteriormente)
    setTabuleiro(tabuleiro);

    int o1, o2, num, obstaculo=1;

    do
    {
       printTabuleiro(tabuleiro, 0);

       // Input do usuário
       printf("Quantos obstáculos deseja utilizar? (0 a 10):\n");
       num = filtraInteiro(tabuleiro);

       system("cls");

         // Caso o usuário digite um número inválido
       if ((num < 0) || (num > 10))
       {
          printTabuleiro(tabuleiro, 0);

          red();
          printf("Número de obstáculos inválido! Tente novamente.\n\n");
          reset();

          system("pause");
          system("cls");
       }

    } while ((num < 0) || (num > 10)); // Repete até que o usuário digite um número válido


    for (;obstaculo < num + 1;)
    {
       do
       {

          system("cls");
          printTabuleiro(tabuleiro, 0);

          printf("Defina a linha do obstáculo número %i (0 a 9):\n", obstaculo); // Input de linha
          o1 = filtraInteiro(tabuleiro);

          printf("Defina a coluna do obstáculo número %i (0 a 9):\n", obstaculo); // Input de coluna
          o2 = filtraInteiro(tabuleiro);

          // Caso usuário digite números inexistentes na tabela
          if (((o1 < 0) || (o1 > 9)) || ((o2 < 0) || (o2 > 9)))
             {
                system("cls");
                printTabuleiro(tabuleiro, 0);

                red();
                printf("Números inválidos! Tente novamente.\n\n");
                reset();

                system("pause");
                system("cls");
             }

          // Caso a posição já esteja ocupada com um obstáculo
          else if (tabuleiro[o1 + 1][o2 + 1] == 'O')
             {
                system("cls");
                printTabuleiro(tabuleiro, 0);

                red();
                printf("Posição já está ocupada! Tente novamente.\n\n");
                reset();

                system("pause");
                system("cls");
             }

          // Caso a posição esteja válida
          else
             {
                obstaculo++;
                system("cls");
                tabuleiro[o1 + 1][o2 + 1] = 'O';
                system("cls");
             }

        } while (((o1 < 0) || (o1 > 9)) || ((o2 < 0) || (o2 > 9))); // Repete até utilizar uma posição existente no tabuleiro
    }


    printTabuleiro(tabuleiro, 0); // Printa tabuleiro

    green();
    printf("Obstáculos definidos com sucesso!.\n\n");
    reset();

    system("pause");
    system("cls");

}


//////////////////////////////////////
////////BACKUP DO TABULEIRO///////////
//////////////////////////////////////

void backup(char tabuleiro_backup[TAM][TAM], char tabuleiro[TAM][TAM], int tipo)
{
    // Backup de tabuleiro anterior caso "tipo = 0"
    if (tipo == 0)
    {
      for (int x=0; x<TAM; x++)
      {
        for (int y=0; y<TAM; y++)
        {
          if ((tabuleiro[x][y] == 'C') || (tabuleiro[x][y] == 'd') || (tabuleiro[x][y] == 'e') || (tabuleiro[x][y] == 'f') || (tabuleiro[x][y] == 'g'))
          {
             tabuleiro_backup [x][y] = 'x';
          }
          else
          {
             tabuleiro_backup[x][y] = tabuleiro[x][y];
          }
        }
      }
    }

    // Reseta tabuleiro principal caso "tipo = 1"
    else
    {
      for (int x=0; x<TAM; x++)
      {
        for (int y=0; y<TAM; y++)
          {
            tabuleiro[x][y] = tabuleiro_backup[x][y];
          }
      }
    }

}
