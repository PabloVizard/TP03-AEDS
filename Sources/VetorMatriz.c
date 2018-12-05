#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/ItemMatriz.h"
#include "../Libs/MatrizVoos.h"
#include "../Libs/VetorMatriz.h"
#include <time.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/time.h>
#define GET_MS(ini, fim)  ((fim.tv_sec * 1000000 + fim.tv_usec) \
      - (ini.tv_sec * 1000000 + ini.tv_usec))
//void IniciaItemVetor(TipoItemVetor *ItemVetor){
  //IniciaMatriz(ItemVetor -> Matriz);
//}

void VetorAleatorio(int *VetorIndex, int Tamanho, int Preenchido){
  int aleatorio;
  int confirma = 0, cont = 0, i, aux = 0;
  while(confirma == 0){
    aleatorio = (rand()%(Tamanho-1));
    for (i = 0; i < aux; i++){
      if(aleatorio != VetorIndex[i])
        cont++;
    }
    if(cont == aux){
      VetorIndex[aux] = aleatorio;
      aux++;
    }
    cont = 0;
    if(aux == Preenchido)
      confirma = 1;
  }
}

void SetIdentificador(TipoVetor *Vetor, int a){
  int NovoValor;
  int confirma = 0, cont = 0, i;
  while (confirma == 0) {
    NovoValor = (rand()%1000000);
    for(i = 0; i < a; i++){
      if(NovoValor != Vetor->Matriz[i].IdentificadorDeMatriz){
        cont++;
      }
    }
    if(cont == a){
      Vetor->Matriz[a].IdentificadorDeMatriz = NovoValor;
      confirma = 1;
    }
  }
}

void AlocaVetor(TipoVetor *Vetor, int Tamanho){
  int i;
  Vetor->Matriz = (TipoMatriz *)malloc(Tamanho*sizeof(TipoMatriz));
  for(i=0; i<Tamanho; i++){
    IniciaMatriz(&(Vetor->Matriz[i]));
    SetIdentificador(Vetor, i);
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

}}

void PreencheVetor(TipoVetor *Vetor, int cenario, int Tamanho){
  int i = 0, j = 0, a=0, b=0;
  if(cenario%2==1){                 // Se o cenário for ímpar, preencherá 20% das matrizes
    if(cenario==1 || cenario==3){
      a=73;
    }else if(cenario==5 || cenario==7){
      a=730;
    }else{
      a=7300;
    }
  }else{                            // Se o cenário for par, preencherá 100% das matrizes
    if(cenario==2 || cenario==4){
      a=365;
    }else if(cenario==6 || cenario==8){
      a=3650;
    }else{
      a=36500;
    }
  }
  if((cenario%4)==1 || (cenario%4)==2){   // se o resto da divisão do cenário por 4 for igual a 1 ou 2, cada matriz terá 10 voos
    b=10;
  }else{                                  // se o resto da divisão do cenário por 4 for igual a 3 ou 0, cada matriz terá 100 voos
    b=100;
  }
  int VetorIndex[Tamanho];

  VetorAleatorio(VetorIndex, Tamanho, a);
    for(i=0; i < a; i++){
      for(j=0; j < b; j++){
        vooAleatorio(&Vetor->Matriz[VetorIndex[i]]);

      }
    }
}

void BubbleSort(TipoVetor *Vetor, int Tamanho){
  int i, j;
  struct timeval inicio, fim;
  gettimeofday(&inicio, NULL);

  long int Comparacao = 0, Movimentacao = 0;
  TipoVetor VetorAUX;
  for(i = 0 ; i < Tamanho-1 ; i++ ){
    for (j = 1 ; j < Tamanho-i ; j++ ){
      Comparacao ++;
      if (Vetor[j].Matriz->IdentificadorDeMatriz < Vetor[j-1].Matriz->IdentificadorDeMatriz)
      {
        VetorAUX = Vetor[j];
        Vetor[j] = Vetor[j-1];
        Vetor[j-1] = VetorAUX;
        Movimentacao += 3;
      } // if
    }
  }
  gettimeofday(&fim, NULL);

  printf("\n====================================================================\n");
  printf("          #######--> Tempo de Execução: %.5f s <--#######", (float)GET_MS(inicio, fim)/1000000);
  printf("\n====================================================================\n");
}

void SelectionSort(TipoVetor *Vetor, int Tamanho){
  int i, j, min;
  long int Comparacao = 0, Movimentacao = 0;
  TipoVetor VetorAUX;

  struct timeval inicio, fim;
  gettimeofday(&inicio, NULL);

  for(i = 0; i < (Tamanho - 1); i++){
    min = i;
    for(j = (i + 1); j < Tamanho; j++){
      Comparacao ++;
      if(Vetor[j].Matriz->IdentificadorDeMatriz < Vetor[min].Matriz->IdentificadorDeMatriz){
        min = j;
      }
      if (Vetor[i].Matriz->IdentificadorDeMatriz != Vetor[min].Matriz->IdentificadorDeMatriz){
        VetorAUX = Vetor[min];
        Vetor[min] = Vetor[i];
        Vetor[i] = VetorAUX;
        Movimentacao += 3;
      }
    }
  }
  gettimeofday(&fim, NULL);

  printf("\n====================================================================\n");
  printf("          #######--> Tempo de Execução: %.5f s <--#######", (float)GET_MS(inicio, fim)/1000000);
  printf("\n====================================================================\n");
}

void InsertionSort(TipoVetor *Vetor, int Tamanho){
  int i,j;
  long int Comparacao = 0, Movimentacao = 0;
  TipoVetor VetorAUX;

  struct timeval inicio, fim;
  gettimeofday(&inicio, NULL);

  for(i = 1; i < Tamanho; i++){
    VetorAUX = Vetor[i];
    Movimentacao ++;
    j = i - 1;
    while((j >= 0) && (Vetor[j].Matriz->IdentificadorDeMatriz < VetorAUX.Matriz->IdentificadorDeMatriz)){
      Vetor[j + 1] = Vetor[j];
      Movimentacao ++;
      j --;
      Comparacao ++;
    }
    Vetor[j + 1] = VetorAUX;
  }

  gettimeofday(&fim, NULL);

  printf("\n====================================================================\n");
  printf("          #######--> Tempo de Execução: %.5f s <--#######", (float)GET_MS(inicio, fim)/1000000);
  printf("\n====================================================================\n");
}
