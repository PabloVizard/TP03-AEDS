#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/ItemMatriz.h"
#include "../Libs/MatrizVoos.h"

#ifndef VETORMATRIZ_H
#define VETORMATRIZ_H

typedef struct{
  TipoMatriz *Matriz;
}TipoVetor;

//void IniciaItemVetor(TipoItemVetor *ItemVetor);

void AlocaVetor(TipoVetor *Vetor, int Tamanho);

void PreencheVetor(TipoVetor *Vetor, int cenario);

void vooAleatorio(TipoMatriz *itemMatriz);

#endif
