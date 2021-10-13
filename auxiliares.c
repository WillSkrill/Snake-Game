#include "jogo_cobra.h"

//////////////////////////////////////
/////////////DEFINE CORES/////////////
//////////////////////////////////////

void red ()
{
  printf("\033[1;31m");
}

void green ()
{
  printf("\033[0;32m");
}

void yellow()
{
  printf("\033[1;33m");
}

void reset ()
{
  printf("\033[0m");
}


//////////////////////////////////////
////////////FILTRA INTEIRO////////////
//////////////////////////////////////

int filtraInteiro()
{
    char triagem [50];
    int inteiro;

    while (fgets(triagem, sizeof triagem, stdin))
    {
        if (sscanf(triagem, "%d", &inteiro))
        {
            return inteiro;
        }
        else
        {
            return -1;
        }
    }
    return -1;
}
