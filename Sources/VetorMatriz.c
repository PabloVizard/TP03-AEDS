#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/ItemMatriz.h"
#include "../Libs/MatrizVoos.h"
#include "../Libs/VetorMatriz.h"
#include <time.h>

void IniciaItemVetor(TipoItemVetor *ItemVetor){
  IniciaMatriz(&ItemVetor -> Matriz);
}

void IniciaVetor(TipoVetor *Vetor, int Tamanho){
  Vetor->Matriz = (TipoMatriz *)malloc(Tamanho*sizeof(TipoMatriz));
}
