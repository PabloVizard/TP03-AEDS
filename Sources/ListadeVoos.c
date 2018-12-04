#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Libs/voo.h"
#include "../Libs/ListadeVoos.h"

/*--------------------------------------------------------------------------------------*/
                                       //Funções
/*--------------------------------------------------------------------------------------*/

//--------------------------------------------------------------------------------------------
//Função inicializa dando à lista uma célula cabeça
void IniciaLista(TLista *pLista){
  pLista -> pPrimeiro = (TCelula*) malloc(sizeof(TCelula)); //Alocamos a celula na memoria
  pLista -> pUltimo = pLista -> pPrimeiro;
  pLista -> pUltimo -> pProximo = NULL;
}
//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
//Função para inserir a celula na ultima posição
void InserirUltimo(TLista *Lista, TVoo Voo)
{
  Lista -> pUltimo -> pProximo = (TCelula *) malloc(sizeof(TCelula)); //Alocamos a celula na memoria
  Lista -> pUltimo = Lista -> pUltimo -> pProximo;
  Lista -> pUltimo -> Voo = Voo;
  Lista -> pUltimo -> pProximo = NULL;
  printf("====================================================================\n\n");
  printf("              >>> Voo Cadastrado com o VID: %.4d <<<\n\n", Voo.vid);
  printf("====================================================================\n\n");
}
//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
//Função para ver se a lista é vazia
int ListaVazia(TLista Lista)
{
  return (Lista.pPrimeiro == Lista.pUltimo); //Retorna 1 se for vazia
}
//--------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Função para inserir a celula na posição correta
void InserirNovo(TLista *Lista, TVoo Voo){
  if(ListaVazia((*Lista))==1 || ((Voo.horaDecolagem * 60 )+Voo.minutosDecolagem) >= ((Lista->pUltimo->Voo.horaDecolagem *60 )+ Lista->pUltimo->Voo.minutosDecolagem)){
    InserirUltimo(Lista, Voo); //Chamamos a função para inserir na ultima posição caso a lista seja vazia ou o novo voo seja maior que o ultimo
    return; //Finaliza a função
  }

  else{ // Caso não atenda a condição acima, entramos nessa condição
    TCelula *novacelula = (TCelula*) malloc(sizeof(TCelula)); //Alocamos a celula na memoria
    TCelula *antecessor = (Lista -> pPrimeiro);
    int horario;

    novacelula->Voo.vid = Voo.vid;
    novacelula->Voo.horaDecolagem = Voo.horaDecolagem;
    novacelula->Voo.minutosDecolagem = Voo.minutosDecolagem;
    novacelula->Voo.horaPouso = Voo.horaPouso;
    novacelula->Voo.minutosPouso = Voo.minutosPouso;
    strcpy(novacelula->Voo.aeroportoDecolagem,Voo.aeroportoDecolagem);
    strcpy(novacelula->Voo.aeroportoPouso,Voo.aeroportoPouso);
    novacelula->Voo.identificadorPista = Voo.identificadorPista;

    horario = (novacelula -> Voo.minutosDecolagem + (novacelula -> Voo.horaDecolagem * 60)); // A variavel horario recebe um int dos minutos somados com as horas convertidas em minutos
    while(horario > (antecessor -> pProximo -> Voo.minutosDecolagem + (antecessor -> pProximo -> Voo.horaDecolagem*60))){ // Compara a hora de decolagem do novo voo da lista com cada um já pertencente à lista, em ordem crescente.
        antecessor = antecessor -> pProximo;// Pega o endereço da próxima célula
    }
    novacelula -> pProximo = antecessor -> pProximo; // Pega o endereço da voo com horario de decolagem maior que o da nova celula
    antecessor -> pProximo = novacelula; // Célula com último voo menor aponta para nova celula
    printf("====================================================================\n\n");
    printf("              >>> Voo Cadastrado com o VID: %d <<<\n\n", novacelula->Voo.vid);
    printf("====================================================================\n\n");
    return; //Finaliza a função
  }
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//Busca o vôo pelo identificador e não o remove.
//Aqui busco o voo pelo identificador e a função retorna o ponteiro da célula que contém tal voo
TCelula *ProcurarVoo(TLista *pLista, int Id){
    TCelula *retorno = pLista -> pPrimeiro;

    while(retorno->pProximo!=NULL){ // Enquanto o proximo de retorno for diferente de NULL
      if (retorno -> pProximo->Voo.vid == Id){ // Compara o vid buscado com cada vid da lista, e se o encontra, retorna o endereço dessa célula
        return retorno->pProximo;
      }
      retorno = retorno->pProximo;
      }
  return NULL;
}
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//Função para buscar o vôo pelo identificador, remover da lista e o retornar.

/*Aqui fazemos o uso da função ProcuraVoo para encontrar o voo a ser removido e também buscamos o
seu antecessor(que contém seu endereço), para pegar o endereço guardado na célula a ser
removida no seu antecessor e depois liberar a memória ocupada pela célula removida. */
int RemoverVoo(TLista *pLista, int Id){
  TCelula *CelulaaRemover= NULL, *Antecessor = NULL;
  CelulaaRemover = ProcurarVoo(pLista, Id);
  if(CelulaaRemover!= NULL){
    Antecessor = pLista -> pPrimeiro;
    while(Antecessor -> pProximo->Voo.vid != CelulaaRemover->Voo.vid){
      Antecessor = Antecessor -> pProximo;
    }

    if(CelulaaRemover == pLista -> pUltimo){
      pLista -> pUltimo = Antecessor;
    }

    Antecessor -> pProximo = CelulaaRemover -> pProximo;
    free(CelulaaRemover);
    printf("====================================================================\n\n");
    printf("               >>> Removido com sucesso :) <<<\n\n");
    printf("====================================================================\n\n");
    return 1;
  }
  else{
    return 0;
  }
}
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//Função para imprimir os voos na lista
void ImprimirLVoos(TLista Lista) {
  TCelula* Aux; Aux = Lista.pPrimeiro -> pProximo;
   while (Aux != NULL) {
     //printf("%d\n", Aux -> Item.Chave);
     printf("\nVid: %d\n", Aux -> Voo.vid);
     printf("Horario de Decolagem: %d:%d\n", Aux -> Voo.horaDecolagem, Aux -> Voo.minutosDecolagem);
     printf("Horario de Pouso: %d:%d\n", Aux -> Voo.horaPouso, Aux -> Voo.minutosPouso);
     printf("Aeroporto de Decolagem: %s\n", Aux -> Voo.aeroportoDecolagem);
     printf("Aeroporto de Pouso: %s\n", Aux -> Voo.aeroportoPouso);
     printf("Identificador de Pista: %d\n\n", Aux ->Voo.identificadorPista);

     Aux = Aux -> pProximo; } }

//--------------------------------------------------------------------------------------------------
