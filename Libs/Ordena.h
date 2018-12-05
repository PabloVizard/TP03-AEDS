#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/ItemMatriz.h"
#include "../Libs/MatrizVoos.h"

#ifndef BOLHA_H
#define BOLHA_H

void Bolha (Item * v, int n, long int comparacao, long int movimentacao);

void selection(int *v,int n, long int comparacao, long int movimentacao);

void insertion(int *v,int n, long int comparacao, long int movimentacao);

void shellsort(int v[], int n, long int comparacao, long int movimentacao);

void particao(int esq,int dir,int* i, int* j, int * a);
void ordena(int e, int d,int *A);
void quicksort(int *v, int n);

void Constroi(Item *A, int *n);
void Refaz(int Esq, int Dir, Item *A);
void Heapsort(Item *A, Indice *n);

#endif
