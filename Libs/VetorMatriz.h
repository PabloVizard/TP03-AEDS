#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/ItemMatriz.h"
#include "../Libs/MatrizVoos.h"

#ifndef VETORMATRIZ_H
#define VETORMATRIZ_H

typedef struct{
  TipoMatriz *Matriz;
}TipoVetor;

//Criando um vetor com valores aleatórios para preencher a matriz aleatoriamente
void VetorAleatorio(int *VetorIndex, int Tamanho, int Preenchido);

//Criando os Id aleatoriamente de forma que eles não se repitam
void SetIdentificador(TipoVetor *Vetor, int a);

//Iniciando o vetor de matrizes
void AlocaVetor(TipoVetor *Vetor, int Tamanho);

//Criando os voos aleatórios
void vooAleatorio(TipoMatriz *itemMatriz);

//preenchendo o vetor
void PreencheVetor(TipoVetor *Vetor, int cenario, int Tamanho);

//Algoritmos de ordenação

void BubbleSort(TipoVetor *Vetor, int Tamanho);

void SelectionSort(TipoVetor *Vetor, int Tamanho);

void InsertionSort(TipoVetor *Vetor, int Tamanho);

void ShellSort(TipoVetor *Vetor, int Tamanho);

void Particao(int Esq, int Dir, int *i, int *j, TipoVetor *Vetor, long int *Comparacao, long int *Movimentacao);

void Ordena(int Esq, int Dir, TipoVetor *Vetor, long int *Comparacao, long int *Movimentacao);

void QuickSort(TipoVetor *Vetor, int Tamanho);

void heapsort(TipoVetor a[], int n);

#endif
