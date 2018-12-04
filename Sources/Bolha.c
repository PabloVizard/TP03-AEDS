#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/ItemMatriz.h"
#include "../Libs/MatrizVoos.h"

void Bolha (Item * v, int n )
{
  int i, j;
  Item aux;
  for(i = 0 ; i < n-1 ; i++ )
  {
    for (j = 1 ; j < n-i ; j++ )
      if (v[j].Chave < v[j-1].Chave )
      {
        aux = v[j];
        v[j] = v[j-1];
        v[j-1] = aux;
      } // if
    }
  }
