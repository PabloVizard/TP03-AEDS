#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#ifndef ITEMMATRIZ_H
#define ITEMMATRIZ_H

//Definido a struct
typedef struct {
  TLista Lista; //Lista do tipo TLista, definido no TAD Lista_de_Voos
  int NumeroVoos; //Numero total de voos na lista
  int HrLast; //Hora da ultima atualização
  int MntsLast; //Minutos da ultima atualização
}ItemMatriz;


void IniciaItem (ItemMatriz *Item); // Função para Iniciar o item
void ImprimirItem(ItemMatriz Item); // Função para Imprimir o item

/*--------------------------------------------------------------------------------------*/
                              //Funções Set: Funções de alteração
/*--------------------------------------------------------------------------------------*/

void SetLista(ItemMatriz *Item); //Função para alterar a lista cadastrada
void SetNumVoo(ItemMatriz *Item); //Função para alterar o numero de voos cadastrados
void SetHreMntsLast(ItemMatriz *Item); //Função para alterar as horas e minutos de atualização cadastrados

/*--------------------------------------------------------------------------------------*/
                              //Funções Get: Funções de leitura
/*--------------------------------------------------------------------------------------*/

TLista GetLista(ItemMatriz Item); //Função para ler a lista cadastrada
int GetNumVoo(ItemMatriz Item); //Função para alterar o numero de voos cadastrados
int GetHrLast(ItemMatriz Item); //Função para ler a hora de atualização cadastrada
int GetMntsLast(ItemMatriz Item); //Função para ler os minutos de atualização cadastrada

#endif
