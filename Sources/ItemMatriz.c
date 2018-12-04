#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/ItemMatriz.h"

// Função para Iniciar o item
void IniciaItem (ItemMatriz *Item){
    Item->Lista.pPrimeiro = NULL;
    Item->Lista.pUltimo = NULL;
    Item->NumeroVoos = 0;
    Item->HrLast = 0;
    Item->MntsLast = 0;
    SetLista(Item);
}// Iniciamos o item com tudo zerado

// Função para Imprimir o item
void ImprimirItem(ItemMatriz Item){
  ImprimirLVoos(Item.Lista);
  SetNumVoo(&Item);
  printf("Numero de Voos: %d\n", Item.NumeroVoos);
  printf("Horario da Ultima Atualização: %d:%d\n", Item.HrLast, Item.MntsLast);
}

/*--------------------------------------------------------------------------------------*/
                              //Funções Set: Funções de alteração
/*--------------------------------------------------------------------------------------*/

//------------------------------------------------------------------------------------------
//Função para alterar a lista cadastrada
void SetLista(ItemMatriz *Item){
    IniciaLista(&Item->Lista);
}
//------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------
//Função para alterar o numero de voos cadastrados
void SetNumVoo(ItemMatriz *Item){ //Em SetNumVoo percorrerei a lista com loop while, assim ao final obtenho o tamanho da lista linear
    TCelula *Contador = NULL;
    int tamanho = 0;
    Contador = Item->Lista.pPrimeiro;
    while(Contador->pProximo != NULL){
        tamanho++;
        Contador = Contador->pProximo;
    }
    Item->NumeroVoos = tamanho;
}
//------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------
//Função para alterar as horas e minutos de atualização cadastrados

void SetHreMntsLast(ItemMatriz *Item){ //Nessa função eu uso a estrutura tm para pegar a hora e minutos da última alteração na lista
    struct tm *horarioatual;
    time_t momentoatual;
    momentoatual= time(NULL);
    horarioatual=localtime(&momentoatual);

    Item->HrLast = horarioatual->tm_hour;
    Item->MntsLast = horarioatual->tm_min;

}
//------------------------------------------------------------------------------------------

/*--------------------------------------------------------------------------------------*/
                              //Funções Get: Funções de leitura
/*--------------------------------------------------------------------------------------*/
 //Função para ler a lista cadastrada
TLista GetLista(ItemMatriz Item){
    return Item.Lista; //Retorna a lista
}
//Função para alterar o numero de voos cadastrados
int GetNumVoo(ItemMatriz Item){
    return Item.NumeroVoos; //Retorna o numero de voos
}
//Função para ler a hora de atualização cadastrada
int GetHrLast(ItemMatriz Item){
    return Item.HrLast; //Retorna a hora de atualização
}
//Função para ler os minutos de atualização cadastrada
int GetMntsLast(ItemMatriz Item){
    return Item.MntsLast; //Retorna os minutos de atualização
}
