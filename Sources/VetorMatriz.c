#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/ItemMatriz.h"
#include "../Libs/MatrizVoos.h"
#include "../Libs/VetorMatriz.h"
#include <time.h>
#include <malloc.h>
#include <stdlib.h>

//void IniciaItemVetor(TipoItemVetor *ItemVetor){
  //IniciaMatriz(ItemVetor -> Matriz);
//}

void AlocaVetor(TipoVetor *Vetor, int Tamanho){
  int i;
  Vetor->Matriz = (TipoMatriz *)malloc(Tamanho*sizeof(TipoMatriz));
  for(i=0; i<Tamanho; i++){
    IniciaMatriz(&(Vetor->Matriz[i]));
  }
}

void vooAleatorio(TipoMatriz *itemMatriz){

  TVoo vooReserva;

  //Declaração das variáveis básicas.
  int i;

  int aux1, aux2, aux3;

  for(i = 0; i < 10; i++)
    {
      //Criando voos aleatoriamente

      IniciaVoo(&vooReserva);
      SetVid(&vooReserva);

      vooReserva.horaDecolagem = (rand()%23);
      vooReserva.minutosDecolagem = (rand()%59);

      vooReserva.horaPouso = (rand()%23);
      vooReserva.minutosPouso = (rand()%59);

    //===========================================================================

      aux1 = (rand()%25)+65;
      aux2 = (rand()%25)+65;
      aux3 = (rand()%25)+65;

      vooReserva.aeroportoPouso[0] = aux1;
      vooReserva.aeroportoPouso[1] = aux2;
      vooReserva.aeroportoPouso[2] = aux3;
    //===========================================================================

      aux1 = (rand()%25)+65;
      aux2 = (rand()%25)+65;
      aux3 = (rand()%25)+65;

      vooReserva.aeroportoDecolagem[0] = aux1;
      vooReserva.aeroportoDecolagem[1] = aux2;
      vooReserva.aeroportoDecolagem[2] = aux3;

    //===========================================================================
      vooReserva.identificadorPista = (rand()%100);

      InserirMVoo(itemMatriz, &vooReserva);
      //ImprimirMatriz(Principal);
}}

void PreencheVetor(TipoVetor *Vetor, int cenario){
  int i = 0, j = 0, a=0, b=0;
  if(cenario%2==1){                 // Se o cenário for ímpar, preencherá 20% das matrizes
    if(cenario==1 || cenario==3){
      i=73;
    }else if(cenario==5 || cenario==7){
      i=730;
    }else{
      i=7300;
    }
  }else{                            // Se o cenário for par, preencherá 100% das matrizes
    if(cenario==2 || cenario==4){
      i=365;
    }else if(cenario==6 || cenario==8){
      i=3650;
    }else{
      i=36500;
    }
  }
  if((cenario%4)==1 || (cenario%4)==2){   // se o resto da divisão do cenário por 4 for igual a 1 ou 2, cada matriz terá 10 voos
    j=10;
  }else{                                  // se o resto da divisão do cenário por 4 for igual a 3 ou 0, cada matriz terá 100 voos
    j=100;
  }

    for(a=0; a < i; a++){
      for(b=0; b < j; b++){
        vooAleatorio(&Vetor->Matriz[a]);
      }
    }

}
