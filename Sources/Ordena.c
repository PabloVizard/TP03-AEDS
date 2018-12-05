#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/ItemMatriz.h"
#include "../Libs/MatrizVoos.h"
#include "../Libs/VetorMatriz.h"

void Bolha (TipoVetor *v, int Tamanho, long int comparacao, long int movimentacao){
  int i, j;
  TipoVetor aux;
  comparacao = 0;
  movimentacao = 0;
  for(i = 0 ; i < Tamanho-1 ; i++ ){
    for (j = 1 ; j < Tamanho-i ; j++ ){
      if (v[j].Matriz->IdentificadorDeMatriz < v[j-1].Matriz->IdentificadorDeMatriz)
      comparacao++;
      {
        aux = v[j];
        v[j] = v[j-1];
        v[j-1] = aux;
        movimentacao++;
      } // if
    }
  }
}

void selection(TipoVetor* v, int Tamanho, long int comparacao, long int movimentacao){
  int i,j,min,aux;
  for(i=0;i<(Tamanho-1);i++){
    min =i;
    for(j=(i+1);j<Tamanho;j++){
      comparacao++;
      if(v[j].Matriz->IdentificadorDeMatriz<v[min].Matriz->IdentificadorDeMatriz){
        min=j;
      }
      aux=v[min].Matriz->IdentificadorDeMatriz;
      v[min].Matriz->IdentificadorDeMatriz=v[i].Matriz->IdentificadorDeMatriz;
      v[i].Matriz->IdentificadorDeMatriz=aux;
      movimentacao++;
    }
  }
}

void insertion(int *v,int n, long int comparacao, long int movimentacao){
  int i,j,aux;
  for(i=1;i<n;i++){
    aux=v[i];
    j=i-1;
    while((j>=0) && (aux<v[j])){
      v[j+1]=v[j];
      j--;}
    v[j+1]=aux;
  }
}

void shellsort(int v[], int n){
  int i,j,h=1,aux;
  do h = h*3+1;while(h<n);
  do{
    h= h/3;
    for(i=h;i<n;i++){
      aux=v[i];j = i;
      while(v[j - h]>aux){
        v[j]=v[j-h];j -= h;
        if(j<h)break;
      }
      v[j]=aux;
    }
  } while(h != 1);
}

//QuickSort

void particao(int esq,int dir,int* i, int* j, int * a){
  int pivo,aux;
  *i=esq;
  *j=dir;
  pivo=a[(*i+*j)/2];
  do{
    while (pivo>a[*i]) (*i)++;
    while (pivo<a[*j]) (*j)--;
    if(*i<=*j){
      aux=a[*i];
      a[*i]=a[*j];
      a[*j]=aux;
      (*i)++;
      (*j)--;
    }
  }while(*i<*j);
}

void ordena(int e, int d,int *A){
  int i,j;
  particao(e,d,&i,&j,A);
  if(e<j) ordena(e,j,A);
  if(i<d) ordena(i,d,A);

}

void quicksort(int *v, int n){
  ordena(0,n-1,v);
}

//Heap
/*
void Constroi(Item *A, int *n){
  int Esq;
  Esq = *n / 2 + 1;
  while (Esq > 1){
    Esq--;
    Refaz(Esq, *n, A);
  }
}

void Refaz(int Esq, int Dir, Item *A){
  int j = Esq * 2;
  Item aux = A[Esq];
  while (j <= Dir){
    if ((j < Dir)&&(A[j].Chave < A[j+1].Chave)) j++;
    if (aux.Chave >= A[j].Chave) break;
    A[Esq] = A[j];
    Esq = j;
    j = Esq * 2;
  }
  A[Esq] = aux;
}

void Heapsort(Item *A, Indice *n){
  Indice Esq, Dir;
  Item aux;
  Constroi(A, n);
   constroi o heap
  Esq = 1; Dir = *n;
  while (Dir > 1){
   ordena o vetor 
  aux = A[1]; A[1] = A[Dir]; A[Dir] = aux;
  Dir--;
  Refaz(Esq, Dir, A);
  }
}
*/
