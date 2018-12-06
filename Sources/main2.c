#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "../Libs/ItemMatriz.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/MatrizVoos.h"
#include "../Libs/voo.h"
#include "../Libs/menu.h"
#include "../Libs/VetorMatriz.h"

int main(){
  srand(time(NULL)); //Utilizamos esse comando para podermos usar numeros aleatorios para o vid

  //Declaração dos Tipos Abstratos de Dados (TADs).
  TipoMatriz Principal;
  TipoVetor Vetor;
  TVoo vooReserva;

  //Declaração das variáveis básicas.
  int i, j, modo, vid, hrPouso, minPouso, hrDecolagem, minDecolagem;

  //Variáveis auxiliares para a interrupção dos whiles.
  int operadorAuxiliar = 1, modoAuxiliar = 1;

  //Caracteres que recebem as operações e confirmação de saída.
  char op, confirma;
  //Caracter para execução do arquivo
  char p;
  //Variáveis para receber o valor numérico dos caracteres setados.
  int intConfirma = 0, intOperador = 0;

  char nomeArquivo[50];

  int horario, auxhorariodecolagem, auxhorariopouso;

  int aux1, aux2, aux3;


//>>>>> CENARIO 01 <<<<<<<<
  int tamanho = 365;

  AlocaVetor(&Vetor, tamanho);
  PreencheVetor(&Vetor, 1, tamanho);
  for(i=0; i<tamanho; i++)
    printf("%d ", Vetor.Matriz[i].IdentificadorDeMatriz);

  printf("\nORDENA:\n");
  heapsort(&Vetor, tamanho);

  for(i=0; i<tamanho; i++)
    printf("%d ", Vetor.Matriz[i].IdentificadorDeMatriz);
  printf("\n");


  /*Testando arquivo*/

//  if(cenario)
  //FILE *arq = fopen("nomeArquivo", "r");



  return 0;
}
