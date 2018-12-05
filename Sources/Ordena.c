#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/ItemMatriz.h"
#include "../Libs/MatrizVoos.h"

void Bolha (Item * v, int n ){
  int i, j;
  Item aux;
  for(i = 0 ; i < n-1 ; i++ ){
    for (j = 1 ; j < n-i ; j++ )
      if (v[j].Chave < v[j-1].Chave )
      {
        aux = v[j];
        v[j] = v[j-1];
        v[j-1] = aux;
      } // if
  }
}

void selection(int *v,int n){
  int i,j,min,aux;
  for(i=0;i<(n-1);i++){
    min =i;
    for(j=(i+1);j<n;j++){
      if(v[j]<v[min]){
        min=j;}
      aux=v[min];
      v[min]=v[i];
      v[i]=aux;
    }
  }
}

void insertion(int *v,int n){
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
