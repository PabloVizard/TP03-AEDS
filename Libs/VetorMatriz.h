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

#endif
