#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/ItemMatriz.h"
#include "../Libs/MatrizVoos.h"
#include "../Libs/VetorMatriz.h"
#include <stdio.h>

void Bolha (TipoVetor *v, int Tamanho, long int comparacao, long int movimentacao){
  int i, j;
  TipoMatriz aux;
  comparacao = 0;
  movimentacao = 0;
  for(i = 0 ; i < Tamanho-1 ; i++ ){
    for (j = 1 ; j < Tamanho-i ; j++ ){
      if ((v->Matriz[j].IdentificadorDeMatriz) < (v->Matriz[j-1].IdentificadorDeMatriz)){
      comparacao++;

        aux = v->Matriz[j];
        v->Matriz[j] = v->Matriz[j-1];
        v->Matriz[j-1] = aux;
        movimentacao+=3;
      } // if
    }
  }
  printf("Comparações = %ld\n", comparacao);
  printf("Movimentações = %ld\n", movimentacao);
}

void selection(TipoVetor* v, int Tamanho, long int comparacao, long int movimentacao){
  int i,j,min,aux;
  comparacao = 0;
  movimentacao = 0;
  for(i=0;i<(Tamanho-1);i++){
    min =i;
    for(j=(i+1);j<Tamanho;j++){
      comparacao++;
      if(v->Matriz[j].IdentificadorDeMatriz<v->Matriz[min].IdentificadorDeMatriz){
        min = j;
      }
    }
    aux=v->Matriz[min].IdentificadorDeMatriz;
    v->Matriz[min].IdentificadorDeMatriz=v->Matriz[i].IdentificadorDeMatriz;
    v->Matriz[i].IdentificadorDeMatriz=aux;
    movimentacao+=3;
  }
  printf("Comparações = %ld\n", comparacao);
  printf("Movimentações = %ld\n", movimentacao);
}

void insertion(TipoVetor *v,int tamanho, long int comparacao, long int movimentacao){
  int i,j,aux;
  comparacao = 0;
  movimentacao = 0;
  for(i=1;i<tamanho;i++){
    aux=v->Matriz[i].IdentificadorDeMatriz;
    j=i-1;
    while((j>=0) && (aux<v->Matriz[j].IdentificadorDeMatriz)){
      comparacao++;
      v->Matriz[j+1].IdentificadorDeMatriz=v->Matriz[j].IdentificadorDeMatriz;
      j--;
      movimentacao++;
    }
    comparacao++;
  v->Matriz[j+1].IdentificadorDeMatriz=aux;
  movimentacao++;
  }
  printf("Comparações = %ld\n", comparacao);
  printf("Movimentações = %ld\n", movimentacao);
  //Estou com dúvidas quanto à quantidade de Comparações
}

void shellsort(TipoVetor *v,int tamanho, long int comparacao, long int movimentacao){
  int i,j,h=1,aux;
  comparacao = 0;
  movimentacao = 0;
  do h = h*3+1;
  while(h<tamanho);
  do{
    h= h/3;
    for(i=h;i<tamanho;i++){
      aux=v->Matriz[i].IdentificadorDeMatriz;
      j = i;
      while(v->Matriz[j-h].IdentificadorDeMatriz>aux){
        movimentacao++;
        v->Matriz[j].IdentificadorDeMatriz=v->Matriz[j-h].IdentificadorDeMatriz;
        j -= h;
        if(j<h)break;
      }
      v->Matriz[j].IdentificadorDeMatriz=aux;
      movimentacao++;
    }
  } while(h != 1);
  printf("Comparações = %ld\n", comparacao);
  printf("Movimentações = %ld\n", movimentacao);
}

//QuickSort NÃO ENTENDI COMO SÃO AS COMPARAÇÕES

void particao(int esq,int dir,int* i, int* j, TipoMatriz * a, long int *comparacao, long int *movimentacao){
  int pivo,aux;
  *i=esq;
  *j=dir;
  pivo=a[(*i+*j)/2].IdentificadorDeMatriz;
  do{
    while (pivo>a[*i].IdentificadorDeMatriz){
      (*i)++;
      *comparacao+=1;
    }
    while (pivo<a[*j].IdentificadorDeMatriz){
      (*j)--;
      *comparacao+=1;
    }
    if(*i<=*j){
      aux=a[*i].IdentificadorDeMatriz;
      a[*i].IdentificadorDeMatriz=a[*j].IdentificadorDeMatriz;
      a[*j].IdentificadorDeMatriz=aux;
      *movimentacao+=3;
      (*i)++;
      (*j)--;
    }
  }while(*i<*j);
}

void ordena(int e, int d,TipoMatriz *A, long int *comparacao, long int *movimentacao){
  int i,j;
  particao(e,d,&i,&j,A,comparacao,movimentacao);
  if(e<j) ordena(e,j,A,comparacao,movimentacao);
  if(i<d) ordena(i,d,A,comparacao,movimentacao);

}

void quicksort(TipoVetor *v,int tamanho, long int *comparacao, long int *movimentacao){
  ordena(0,tamanho-1,v->Matriz, comparacao, movimentacao);
  printf("Comparações = %ld\n", *comparacao);
  printf("Movimentações = %ld\n", *movimentacao);
}

//Heap



void Refaz(int Esq, int Dir, TipoMatriz *A)
{ int i = Esq;
  int j;
  TipoMatriz x;
  j = (i * 2);
  x = A[i];
  while (j <= Dir)
    { if (j < Dir)
      { if (A[j].IdentificadorDeMatriz< A[j+1].IdentificadorDeMatriz)
	j++;
      }
      if (x.IdentificadorDeMatriz >= A[j].IdentificadorDeMatriz){
      A[i] = A[j];

    }
      i = j; j = (i * 2);
    }
}
void Constroi(TipoMatriz *A, int *n)
{ int Esq;
  Esq = *n / 2 +1;
  while (Esq > 1)
    { Esq--;
      Refaz(Esq, *n, A);
    }
}

/*--Entra aqui a funcao Refaz do Programa 4.9 --*/
/*--Entra aqui a funcao Constroi do Programa 4.10--*/

void Heapsort(TipoVetor *v,int *n)
{ int Esq, Dir;
  TipoMatriz x;
  IniciaMatriz(&x);
  Constroi(v->Matriz, n);   /* constroi o heap */
  Esq = 0; Dir = *(n)-1;
  while (Dir > 0)
    { /* ordena o vetor */
      x = v->Matriz[0]; v->Matriz[0] = v->Matriz[Dir]; v->Matriz[Dir] = x;
      Dir--;
      Refaz(Esq, Dir, v->Matriz);
    }
}
