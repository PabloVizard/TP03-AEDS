#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/ItemMatriz.h"
#include "../Libs/MatrizVoos.h"

#ifndef VETORMATRIZ_H
#define VETORMATRIZ_H

typedef struct{
  TipoMatriz* Matriz;
}TipoItemVetor;

typedef struct{
  TipoItemVetor Item;
}TipoVetor;

void IniciaItemVetor(TipoItemVetor *ItemVetor);

void IniciaVetor(TipoVetor *Vetor, int Tamanho);

#endif
