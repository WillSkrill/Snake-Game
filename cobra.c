#include "jogo_cobra.h"

//////////////////////////////////////
///////DEFINE POSI��O INICIAL/////////
//////////////////////////////////////

int setPosicao(char tabuleiro[TAM][TAM])
{

    int p1, p2, verificador, tipo = 0;
    char tabuleiro_backup[TAM][TAM];

    backup(tabuleiro_backup, tabuleiro, tipo); // Reseta tabuleiro atual (Mant�m obst�culos)
    tipo = 1;

    backup(tabuleiro_backup, tabuleiro, tipo); // Faz backup do tabuleiro atual
    tipo = 0;


    do
    {

       system("cls");
       printTabuleiro(tabuleiro, 0); // Printa tabuleiro

       printf("Defina a linha inicial da cobra (0 a 9):\n"); // Input da linha
       p1 = filtraInteiro(tabuleiro);

       printf("Defina a coluna inicial da cobra (0 a 9):\n"); // Input da coluna
       p2 = filtraInteiro(tabuleiro);

       if ((p1 < 0 || p1 > 9) || (p2 < 0 || p2 > 9)) // Caso usu�rio digite n�meros inexistentes na tabela
         {
            system("cls");
            printTabuleiro(tabuleiro, 0);

            red();
            printf("N�meros inv�lidos! Tente novamente.\n\n");
            reset();

            system("pause");

         }

       else // Caso usu�rio escolha uma posi��o que j� tenha sido definida como obst�culo
       {
          if (tabuleiro[p1 + 1][p2 + 1] == 'O')
          {
            system("cls");
            printTabuleiro(tabuleiro, 0);

            red();
            printf("Posi��o j� est� ocupada! Tente novamente.\n\n");
            reset();

            system("pause");
          }
       }

    } while (((p1 < 0 || p1 > 9) || (p2 < 0 || p2 > 9)) || (tabuleiro[p1 + 1][p2 + 1] == 'O')); // Repete at� o usu�rio utilizar uma posi��o existente no tabuleiro


    system("cls");
    tabuleiro[p1 + 1][p2 + 1] = 'C';
    verificador = setCorpocobra(tabuleiro); // Tenta gerar a cobra

    // Verifica se cobra foi gerada pela outra fun��o

    if (verificador == 1) // Caso ela tenha sido gerada
    {
      printTabuleiro(tabuleiro, 0); // Printa tabuleiro

      green();
      printf("Posi��o inicial definida com sucesso!.\n\n");
      reset();

      system("pause");
      system("cls");
      return 1;
    }
    else // Caso ela n�o tenha sido gerada
    {
      tipo = 1;
      backup(tabuleiro_backup, tabuleiro, tipo); // Reseta o tabuleiro (apaga as partes da cobra)

      red();
      printf("N�o foi poss�vel gerar a cobra no ponto indicado! Tente outra posi��o inicial ou reposicione os obst�culos.\n\n");
      reset();

      system("pause");
      system("cls");
      return 0;
    }
}


//////////////////////////////////////
////////GERA O CORPO DA COBRA/////////
//////////////////////////////////////

int setCorpocobra(char tabuleiro[TAM][TAM])
{

   int x, y, i=0, j=0, teste=0, parte=0;

   // L� a matriz tabuleiro para descobrir onde foi definida a cabe�a da cobra
   for (x=1; x<TAM; x++)
   {
     for (y=1; y<TAM; y++)
     {
       if (tabuleiro[x][y] == 'C')
       {
         i = x;
         j = y;
       }
     }
   }

   x = 1;
   y = 1;

   do
   {

     if ((tabuleiro[i+x][j] != 'x') && (tabuleiro[i][j+y] != 'x') && (tabuleiro[i-x][j] != 'x') && (tabuleiro[i][j-y] != 'x')) // Caso n�o seja poss�vel gerar a cobra
     {
        return 0; // Retorna 0, caso a cobra n�o consiga ser gerada
     }

     // S�rie de "Ifs" para definir em que posi��o a cobra deve ser gerada

     // Gera para baixo
     if ((tabuleiro[i+x][j] == 'x') && (teste==0))
     {

        parte++;

        switch (parte)
        {
           case 1:
              tabuleiro[i+x][j] = 'd';
            break;
           case 2:
              tabuleiro[i+x][j] = 'e';
            break;
           case 3:
              tabuleiro[i+x][j] = 'f';
            break;
           case 4:
              tabuleiro[i+x][j] = 'g';
            break;
        }
        i = i + x;
        teste = 1;
      }

     // Gera para direita
     if ((tabuleiro[i][j+y] == 'x') && (teste==0))
     {

       parte++;

       switch (parte)
       {
         case 1:
            tabuleiro[i][j+y] = 'd';
          break;
         case 2:
            tabuleiro[i][j+y] = 'e';
          break;
         case 3:
            tabuleiro[i][j+y] = 'f';
          break;
         case 4:
          tabuleiro[i][j+y] = 'g';
          break;
       }

       j = j + y;
       teste = 1;
     }

     // Gera para cima
     if ((tabuleiro[i-x][j] == 'x') && (teste==0))
     {

        parte++;

        switch (parte)
        {
          case 1:
             tabuleiro[i-x][j] = 'd';
            break;
          case 2:
             tabuleiro[i-x][j] = 'e';
            break;
          case 3:
             tabuleiro[i-x][j] = 'f';
             break;
          case 4:
             tabuleiro[i-x][j] = 'g';
             break;
        }

         i = i - x;
         teste = 1;
       }

     // Gera para esquerda
     if ((tabuleiro[i][j-y] == 'x') && (teste==0))
     {

        parte++;

        switch (parte)
        {
          case 1:
            tabuleiro[i][j-y] = 'd';
           break;
          case 2:
            tabuleiro[i][j-y] = 'e';
           break;
          case 3:
            tabuleiro[i][j-y] = 'f';
           break;
          case 4:
            tabuleiro[i][j-y] = 'g';
           break;
          }

         j = j - y;
         teste = 1;
      }

      teste = 0;

   } while (parte < 4); // Repete at� gerar as 4 partes da cobra

   return 1; // Retorna 1, definindo que a cobra foi gerada

}


//////////////////////////////////////
/////DEFINE N�MERO DE MOVIMENTOS//////
//////////////////////////////////////

int setMovimentos(char tabuleiro[TAM][TAM])
{
    int num;

    do
    {

       printTabuleiro(tabuleiro, 0);

       printf("Quantos movimentos deseja realizar? (1 a 100):\n");
       num = filtraInteiro(tabuleiro); // Input do n�mero de movimentos

       system("cls");

        // Caso usu�rio digite um n�mero inv�lido
       if ((num < 1) || (num > 100))
       {
          printTabuleiro(tabuleiro, 0);

          red();
          printf("N�mero de movimentos inv�lido! Tente novamente.\n\n");
          reset();

          system("pause");
          system("cls");
       }

     } while ((num < 1) || (num > 100)); // Repete at� que o usu�rio digite um n�mero v�lido

    printTabuleiro(tabuleiro, 0);

    green();
    printf("N�mero de movimentos definido com sucesso!.\n\n");
    reset();

    system("pause");
    system("cls");

    return num; // Retorna n�mero de movimentos

}


//////////////////////////////////////
////////INICIA OS MOVIMENTOS//////////
//////////////////////////////////////

void iniciar(char tabuleiro[TAM][TAM], int movimentos)
{

   int x=1, y=1, cx, cy, dx, dy, ex, ey, fx, fy, gx, gy, p1, p2, cont=0, teste=0;

   // L� a matriz tabuleiro para descobrir onde foi gerada cada parte da cobra
   for (int x=1; x<TAM; x++)
   {
     for (int y=1; y<TAM; y++)
     {
       if (tabuleiro[x][y] == 'C')
       {
           cx = x;
           cy = y;
       }
       if (tabuleiro[x][y] == 'd')
       {
           dx = x;
           dy = y;
       }
       if (tabuleiro[x][y] == 'e')
       {
           ex = x;
           ey = y;
       }
       if (tabuleiro[x][y] == 'f')
       {
           fx = x;
           fy = y;
       }
       if (tabuleiro[x][y] == 'g')
       {
           gx = x;
           gy = y;
       }

     }
   }


   // Escolhe para onde a cobra deve se mover, evitando obst�culos e movendo a cabe�a
   do
   {

       // Caso a cobra fique presa em algum lugar
     if ((tabuleiro[cx+x][cy] != 'x') && (tabuleiro[cx][cy+y] != 'x') && (tabuleiro[cx-x][cy] != 'x') && (tabuleiro[cx][cy-y] != 'x'))
     {
       system("cls");
       printTabuleiro(tabuleiro, 1); // Printa tabuleiro

       red();
       printf("A cobra ficou presa! :p\n\n");
       reset();

       system("pause");
       system("cls");
       return;
     }

    // Cria aleatoriedade ao movimento da cabe�a
    for (;teste < 1;)
    {
      int r = (rand() % 4) + 1; // Adiciona aleatoriedade ao movimento

      // Movimenta cabe�a para cima
      if ((tabuleiro[cx-x][cy] == 'x') && (teste == 0) && (r == 1))
      {
          tabuleiro[cx-x][cy] = 'C';
          p1 = cx;
          p2 = cy;
          cx = cx - x;
          teste = 1;
      }

      // Movimenta cabe�a para esquerda
      if ((tabuleiro[cx][cy-y] == 'x') && (teste == 0) && (r == 2))
      {
          tabuleiro[cx][cy-y] = 'C';
          p1 = cx;
          p2 = cy;
          cy = cy - y;
          teste = 1;
      }

      // Movimenta cabe�a para baixo
      if ((tabuleiro[cx+x][cy] == 'x') && (teste == 0) && (r == 3))
      {
          tabuleiro[cx+x][cy] = 'C';
          p1 = cx;
          p2 = cy;
          cx = cx + x;
          teste = 1;
      }

      // Movimenta cabe�a para direita
      if ((tabuleiro[cx][cy+y] == 'x') && (teste == 0) && (r == 4))
      {
          tabuleiro[cx][cy+y] = 'C';
          p1 = cx;
          p2 = cy;
          cy = cy + y;
          teste = 1;
      }
    }

     teste = 0;

     // Move o resto do corpo atr�s da cobra
     // Usa p1 e p2 para salvar posi��o anterior atrav�s da fun��o swap()

     // Movimento do primeiro ponto da cobra
     swap(&p1,&dx);
     swap(&p2,&dy);
     tabuleiro[dx][dy] = 'd';

     // Movimento do segundo ponto da cobra
     swap(&p1,&ex);
     swap(&p2,&ey);
     tabuleiro[ex][ey] = 'e';

     // Movimento do terceiro ponto da cobra
     swap(&p1,&fx);
     swap(&p2,&fy);
     tabuleiro[fx][fy] = 'f';

     // Movimento do quarto ponto da cobra
     swap(&p1,&gx);
     swap(&p2,&gy);
     tabuleiro[gx][gy] = 'g';

     // Apagar �ltimo ponto
     tabuleiro[p1][p2] = 'x';

     cont++;
     printTabuleiro(tabuleiro, 1); // Printa tabuleiro
     system("cls");

   } while (cont < movimentos); // Repete at� o n�mero de movimentos digitado pelo usu�rio

   printTabuleiro(tabuleiro, 1); // Printa tabuleiro

   green();
   printf("A cobra completou todos os movimentos! B)\n\n");
   reset();

   system("pause");
   system("cls");

}


//////////////////////////////////////
///////TROCA POSI��Es DA COBRA////////
//////////////////////////////////////

void swap(int *x, int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
