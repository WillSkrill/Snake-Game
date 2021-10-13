#ifndef JOGO_COBRA_H_INCLUDED
#define JOGO_COBRA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

// Define o tamanho da matriz do tabuleiro
#define TAM 11

// Funções do tabuleiro
void setTabuleiro();
void setObstaculos();
void printTabuleiro();
void backup();

// Funções da cobra
int setPosicao();
int setCorpocobra();
int setMovimentos();
void iniciar();
void swap();

// Funções de auxílio
int filtraInteiro();
void red();
void green();
void yellow();
void reset();

#endif // JOGO_COBRA_H_INCLUDED
