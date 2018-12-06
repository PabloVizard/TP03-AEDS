#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/ItemMatriz.h"
#include "../Libs/MatrizVoos.h"
#include "../Libs/VetorMatriz.h"

#ifndef BOLHA_H
#define BOLHA_H

void Bolha (TipoVetor* v, int Tamanho, long int comparacao, long int movimentacao);

void selection(TipoVetor* v, int Tamanho, long int comparacao, long int movimentacao);

void insertion(TipoVetor *v,int n, long int comparacao, long int movimentacao);

void shellsort(TipoVetor *v,int tamanho, long int comparacao, long int movimentacao);

void particao(int esq,int dir,int* i, int* j, int * a);
void ordena(int e, int d,int *A);
void quicksort(TipoVetor *v,int tamanho, long int *comparacao, long int *movimentacao);


void Constroi(TipoMatriz *A, int *tamanho);
void Refaz(int Esq, int Dir, TipoMatriz *A);
void Heapsort(TipoVetor *v,int *tamanho);

#endif
