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

void VetorAleatorio(int *VetorIndex, int Tamanho, int Preenchido){
  int aleatorio;
  int confirma = 0, cont = 0, i, aux = 0;
  //Ciclo de repetição
  while(confirma == 0){
    //Gerando número aleatório
    aleatorio = (rand()%(Tamanho-1));
    for (i = 0; i < aux; i++){
      if(aleatorio != VetorIndex[i])
        cont++;
        //Se o valor criado for diferente dos já existentes, incrementa-se o contador
    }
    //Se o contador for igual ao auxiliar, significa que o valor criado é diferente dos já existentes, ou seja, pode ser inserido
    if(cont == aux){
      VetorIndex[aux] = aleatorio;
      aux++;
    }
    cont = 0;
    //Se o valor do auxiliar chegar no número de casas a serem preenchidas, a função é parada
    if(aux == Preenchido)
      confirma = 1;
  }
}

void SetIdentificador(TipoVetor *Vetor, int a){
  long int NovoValor;
  int confirma = 0, cont = 0, i;
  //printf("mago implacavel 7 %d cenario\n", a);
  //O processo para a criação de um valor aleatório para o ID assemelha-se muito ao da criação do vetor
  while (confirma == 0) {
    NovoValor = (rand()%100000000000000);
    for(i = 0; i < a; i++){
      if(NovoValor != Vetor->Matriz[i].IdentificadorDeMatriz){
        cont++;
      }
    }
    //A execução é parada nessa parte porque a função é chamada uma vez por matriz.
    if(cont == a){
      Vetor->Matriz[a].IdentificadorDeMatriz = NovoValor;
      confirma = 1;
    }
  }
}

void AlocaVetor(TipoVetor *Vetor, int Tamanho){
  int i;
  //Alocando as matrizes fazendo um vetor
  Vetor->Matriz = (TipoMatriz *)malloc(Tamanho*sizeof(TipoMatriz));
  for(i=0; i<Tamanho; i++){
    //printf("mago implacavel 4 %d cenario\n", Tamanho);
    IniciaMatriz(&(Vetor->Matriz[i]));
    //printf("mago implacavel 5 %d cenario\n", Tamanho);
    SetIdentificador(Vetor, i);
    //printf("mago implacavel 6 %d cenario\n", Tamanho);
  }
}

void vooAleatorio(TipoMatriz *itemMatriz){

  TVoo vooReserva;

  int aux1, aux2, aux3;

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
}

void PreencheVetor(TipoVetor *Vetor, int cenario, int Tamanho){
  int i = 0, j = 0, a=0, b=0;

  switch (cenario) {
    case 1:
      a = 73;
      b = 10;
      break;
    case 2:
      a = 365;
      b = 10;
      //printf("certo %d\n", cenario);
      break;
    case 3:
      a = 73;
      b = 100;
      break;
    case 4:
      a = 365;
      b = 100;
      break;
    case 5:
      a = 730;
      b = 10;
      break;
    case 6:
      a = 3650;
      b = 10;
      break;
    case 7:
      a = 730;
      b = 100;
      break;
    case 8:
      a = 3650;
      b = 100;
      break;
    case 9:
      a = 7300;
      b = 10;
      break;
    case 10:
      a = 36500;
      b = 10;
      break;
    case 11:
      a = 7300;
      b = 100;
      break;
    case 12:
      a = 36500;
      b = 100;
      break;
  }

  if (a == 73 || a == 730 || a == 7300){
    int VetorIndex[Tamanho];
    //printf("certo3 %d\n", cenario);
    VetorAleatorio(VetorIndex, Tamanho, a);
    //printf("certo6 %d\n", cenario);
    for(i=0; i < a; i++){
      //printf("certo4 %d\n", cenario);
      for(j=0; j < b; j++){
        //printf("certo5 %d\n", cenario);
        vooAleatorio(&Vetor->Matriz[VetorIndex[i]]);
        //printf("certo7 %d\n", cenario);
      }
    }
  }
  else{
    for(i=0; i < a; i++){
      for(j=0; j < b; j++){
        vooAleatorio(&Vetor->Matriz[i]);
        //printf("arthur  %d\n", cenario);
      }
    }
  }
}

//========== BUBBLE SORT ==================//

void BubbleSort(TipoVetor *Vetor, int Tamanho){
  int i, j;
  struct timeval inicio, fim;
  gettimeofday(&inicio, NULL);

  long int Comparacao = 0, Movimentacao = 0;
  TipoMatriz MatrizAUX;

  for(i = 0 ; i < Tamanho-1 ; i++ ){
    for (j = 1 ; j < Tamanho-i ; j++ ){
      Comparacao ++;
      if (Vetor->Matriz[j].IdentificadorDeMatriz < Vetor->Matriz[j-1].IdentificadorDeMatriz)
      {
        MatrizAUX = Vetor->Matriz[j];
        Vetor->Matriz[j] = Vetor->Matriz[j-1];
        Vetor->Matriz[j-1] = MatrizAUX;
        Movimentacao += 3;
      } // if
    }
  }
  gettimeofday(&fim, NULL);

  printf("\n====================================================================\n");
  printf("Numero de Comparações: %ld\n", Comparacao);
  printf("Numero de Movimentações: %ld\n", Movimentacao);
  printf("Tempo de Execução: %.5f s", (float)GET_MS(inicio, fim)/1000000);
  printf("\n====================================================================\n");
}

//========== SELECTION SORT ==================//

void SelectionSort(TipoVetor *Vetor, int Tamanho){
  int i, j, min;
  long int Comparacao = 0, Movimentacao = 0;
  TipoMatriz MatrizAUX;

  struct timeval inicio, fim;
  gettimeofday(&inicio, NULL);

  for(i = 0; i < (Tamanho - 1); i++){
    min = i;
    for(j = (i + 1); j < Tamanho; j++){
      Comparacao ++;
      if(Vetor->Matriz[j].IdentificadorDeMatriz < Vetor->Matriz[min].IdentificadorDeMatriz){
        min = j;
      }
    }
      if (Vetor->Matriz[i].IdentificadorDeMatriz != Vetor->Matriz[min].IdentificadorDeMatriz){
        MatrizAUX = Vetor->Matriz[i];
        Vetor->Matriz[i] = Vetor->Matriz[min];
        Vetor->Matriz[min] = MatrizAUX;
        Movimentacao += 3;
    }
  }
  gettimeofday(&fim, NULL);

  printf("\n====================================================================\n");
  printf("Numero de Comparações: %ld\n", Comparacao);
  printf("Numero de Movimentações: %ld\n", Movimentacao);
  printf("Tempo de Execução: %.5f s", (float)GET_MS(inicio, fim)/1000000);
  printf("\n====================================================================\n");
}

//========== INSERTION SORT ==================//

void InsertionSort(TipoVetor *Vetor, int Tamanho){
  int i,j;
  long int Comparacao = 0, Movimentacao = 0;
  TipoMatriz MatrizAUX;

  struct timeval inicio, fim;
  gettimeofday(&inicio, NULL);

  for(i = 1; i < Tamanho; i++){
    MatrizAUX = Vetor->Matriz[i];
    Movimentacao ++;
    j = i - 1;
    Comparacao ++;
    while((j >= 0) && (Vetor->Matriz[j].IdentificadorDeMatriz > MatrizAUX.IdentificadorDeMatriz)){
      Vetor->Matriz[j + 1] = Vetor->Matriz[j];
      Movimentacao ++;
      j --;
      Comparacao ++;
    }
    Vetor->Matriz[j + 1] = MatrizAUX;
    Movimentacao ++;
  }

  gettimeofday(&fim, NULL);

  printf("\n====================================================================\n");
  printf("Numero de Comparações: %ld\n", Comparacao);
  printf("Numero de Movimentações: %ld\n", Movimentacao);
  printf("Tempo de Execução: %.5f s", (float)GET_MS(inicio, fim)/1000000);
  printf("\n====================================================================\n");
}

//========== SHELL SORT ==================//

void ShellSort(TipoVetor *Vetor, int Tamanho){
    int i, j;
    int h = 1;
    long int Comparacao = 0, Movimentacao = 0;

    TipoMatriz MatrizAUX;

    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);
    Comparacao ++;
    do{
      h = (h*3)+1;
    }while (h < Tamanho);
    Comparacao ++;
    do{
      h = h/3;
      for(i = h; i < Tamanho; i++){
        MatrizAUX = Vetor->Matriz[i];
        Movimentacao ++;
        j = i;
        Comparacao ++;
        while(Vetor->Matriz[j - h].IdentificadorDeMatriz > MatrizAUX.IdentificadorDeMatriz){
          Vetor->Matriz[j] = Vetor->Matriz[j-h];
          Movimentacao ++;
          j = j - h;
          Comparacao ++;
          if(j < h){
            break;
          }
        }
        Vetor->Matriz[j] = MatrizAUX;
        Movimentacao ++;
      }
    }while(h != 1);
  /*  while(h < Tamanho) {
        h = 3 * h + 1;
    }
    while (h > 1) {
        h /= 3;
        for(i = h; i < Tamanho; i++) {
            MatrizAUX = Vetor->Matriz[i];
            Movimentacao ++;
            j = i;
            Comparacao ++;
            while (j >= h && Vetor->Matriz[j - h].IdentificadorDeMatriz > MatrizAUX.IdentificadorDeMatriz) {
                Vetor[j] = Vetor[j - h];
                Movimentacao ++;
                j = j - h;
            }
            Vetor->Matriz[j] = MatrizAUX;
            Movimentacao ++;
        }
    }
*/
    gettimeofday(&fim, NULL);

    printf("\n====================================================================\n");
    printf("Numero de Comparações: %ld\n", Comparacao);
    printf("Numero de Movimentações: %ld\n", Movimentacao);
    printf("Tempo de Execução: %.5f s", (float)GET_MS(inicio, fim)/1000000);
    printf("\n====================================================================\n");

}

//========== QUICK SORT ==================//

void Particao(int Esq, int Dir, int *i, int *j, TipoVetor *Vetor, long int *Comparacao, long int *Movimentacao){
  int pivo;
  TipoMatriz aux;
  *i = Esq;
  *j = Dir;
  pivo = Vetor->Matriz[(*i + *j)/2].IdentificadorDeMatriz;
  do{
    (*Comparacao) ++;
    while(pivo > Vetor->Matriz[*i].IdentificadorDeMatriz){
      (*i)++;
      (*Comparacao) ++;
    }
    (*Comparacao) ++;
    while(pivo < Vetor->Matriz[*j].IdentificadorDeMatriz){
      (*j)--;
      (*Comparacao) ++;
    }
    if(*i <= *j){
      aux = Vetor->Matriz[*i];
      Vetor->Matriz[*i] = Vetor->Matriz[*j];
      Vetor->Matriz[*j] = aux;
      (*Movimentacao) += 3;
      (*i)++;
      (*j)--;
    }
  }while(*i <= *j);
}

void Ordena(int Esq, int Dir, TipoVetor *Vetor, long int *Comparacao, long int *Movimentacao){
  int i, j;
  Particao(Esq, Dir, &i, &j, Vetor, Comparacao, Movimentacao);
  if(Esq < j){
    Ordena(Esq, j, Vetor, Comparacao, Movimentacao);
  }
  if(i < Dir){
    Ordena(i, Dir, Vetor, Comparacao, Movimentacao);
  }
}

void QuickSort(TipoVetor *Vetor, int Tamanho){
  long int Comparacao = 0, Movimentacao = 0;

  struct timeval inicio, fim;
  gettimeofday(&inicio, NULL);

  Ordena(0, Tamanho-1, Vetor, &Comparacao, &Movimentacao);

  gettimeofday(&fim, NULL);

  printf("\n====================================================================\n");
  printf("Numero de Comparações: %ld\n", Comparacao);
  printf("Numero de Movimentações: %ld\n", Movimentacao);
  printf("Tempo de Execução: %.5f s", (float)GET_MS(inicio, fim)/1000000);
  printf("\n====================================================================\n");
}

//========== HEAP SORT ==================//

void heapsort(TipoVetor *a, int n) {
   int i = n / 2, pai, filho;
   long int Comparacao = 0, Movimentacao = 0;
   TipoMatriz t;

   struct timeval inicio, fim;
   gettimeofday(&inicio, NULL);

   Comparacao ++;
   while(1) {
     Comparacao ++;
      if (i > 0) {
          i--;
          t = a->Matriz[i];
          Movimentacao ++;
      } else {
          n--;
          Comparacao ++;
          if (n == 0)
            break;
          t = a->Matriz[n];
          a->Matriz[n] = a->Matriz[0];
          Movimentacao += 2;
      }
      pai = i;
      filho = i * 2 + 1;
      Comparacao ++;
      while (filho < n) {
          Comparacao += 2;
          if ((filho + 1 < n)  &&  (a->Matriz[filho + 1].IdentificadorDeMatriz > a->Matriz[filho].IdentificadorDeMatriz))
              filho++;
          if (a->Matriz[filho].IdentificadorDeMatriz > t.IdentificadorDeMatriz) {
             a->Matriz[pai] = a->Matriz[filho];
             pai = filho;
             filho = pai * 2 + 1;
             Movimentacao ++;
          } else {
             break;
          }
      }
      a->Matriz[pai] = t;
      Movimentacao ++;
   }
   gettimeofday(&fim, NULL);

   printf("\n====================================================================\n");
   printf("Numero de Comparações: %ld\n", Comparacao);
   printf("Numero de Movimentações: %ld\n", Movimentacao);
   printf("Tempo de Execução: %.5f s", (float)GET_MS(inicio, fim)/1000000);
   printf("\n====================================================================\n");
}
