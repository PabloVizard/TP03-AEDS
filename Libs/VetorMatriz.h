#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/ItemMatriz.h"
#include "../Libs/MatrizVoos.h"

#ifndef VETORMATRIZ_H
#define VETORMATRIZ_H

typedef struct{
  TipoMatriz *Matriz;
}TipoVetor;

void VetorAleatorio(int *VetorIndex, int Tamanho, int Preenchido);

void SetIdentificador(TipoVetor *Vetor, int a);

void AlocaVetor(TipoVetor *Vetor, int Tamanho);

void PreencheVetor(TipoVetor *Vetor, int cenario, int Tamanho);

void vooAleatorio(TipoMatriz *itemMatriz);

void BubbleSort(TipoVetor *Vetor, int Tamanho);

void SelectionSort(TipoVetor *Vetor, int Tamanho);

void InsertionSort(TipoVetor *Vetor, int Tamanho);

void ShellSort(TipoVetor *Vetor, int Tamanho);

void Particao(int Esq, int Dir, int *i, int *j, TipoVetor *Vetor, long int *Comparacao, long int *Movimentacao);

void Ordena(int Esq, int Dir, TipoVetor *Vetor, long int *Comparacao, long int *Movimentacao);

void QuickSort(TipoVetor *Vetor, int Tamanho);

void Refaz(int Esq, int Dir, TipoVetor *Vetor, long int *Comparacao, long int *Movimentacao);

void Constroi(TipoVetor *Vetor, int *Tamanho, long int *Comparacao, long int *Movimentacao);

void Heapsort(TipoVetor *Vetor, int *Tamanho);

#endif
