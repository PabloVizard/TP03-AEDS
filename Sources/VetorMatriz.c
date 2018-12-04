#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/ItemMatriz.h"
#include "../Libs/MatrizVoos.h"
#include "../Libs/VetorMatriz.h"
#include <time.h>
#include <malloc.h>

//void IniciaItemVetor(TipoItemVetor *ItemVetor){
  //IniciaMatriz(ItemVetor -> Matriz);
//}

void AlocaVetor(TipoVetor *Vetor, int Tamanho){
  Vetor->Matriz = (TipoMatriz *)malloc(Tamanho*sizeof(TipoMatriz));
}

void PreencheVetor(TipoVetor *Vetor, int cenario){

}
