#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/ItemMatriz.h"
#include "../Libs/MatrizVoos.h"
#include "../Libs/VetorMatriz.h"
#include <time.h>

void IniciaItemVetor(TipoItemVetor *ItemVetor){
  IniciaMatriz(&ItemVetor -> Matriz);
}

void IniciaVetor(TipoVetor *Vetor, TipoItemVetor *ItemVetor){
  int i, posicao;
  posicao = rand()%365;

  for (i=0; i < Vetor->Tamanho; i++){
    Vetor[posicao] = ItemVetor;
  }
}
