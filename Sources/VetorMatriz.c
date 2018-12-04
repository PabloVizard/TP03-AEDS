#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/ItemMatriz.h"
#include "../Libs/MatrizVoos.h"
#include "../Libs/VetorMatriz.h"

void IniciaItemVetor(TipoItemVetor *ItemVetor){
  IniciaMatriz(&ItemVetor -> Matriz);
}

void IniciaVetor(TipoVetor *Vetor){
  int i;
  for (i=0; i < Vetor->Tamanho; i++){
  }
}
