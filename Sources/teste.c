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
//#include "../Libs/Ordena.h"

int main(){
  srand(time(NULL));
  int modo, cenario, tamanho = 0, algoritmo;
  TipoVetor Vetor;

  printf("====================================================================\n");
  printf("|                      Seja Bem-vindo(a)!                          |\n");
  printf("====================================================================\n");
  printf("\n");

  menu_de_entradas();
  scanf("%d", &modo);
  printf("\n");

  if (modo == 1){
    printf("Entre com o cenário desejado: ");
    scanf("%d", &cenario);
    printf("\n");

    if(cenario == 1 || cenario == 2 || cenario == 3 || cenario == 4){
      tamanho = 365;
      AlocaVetor(&Vetor, tamanho);
      PreencheVetor(&Vetor, cenario, tamanho);
    }
    else if(cenario == 5 || cenario == 6 || cenario == 7 || cenario == 8){
      tamanho = 3650;
      AlocaVetor(&Vetor, tamanho);
      PreencheVetor(&Vetor, cenario, tamanho);
    }
    else if(cenario == 9 || cenario == 10 || cenario == 11 || cenario == 12){
      tamanho = 36500;
      AlocaVetor(&Vetor, tamanho);
      PreencheVetor(&Vetor, cenario, tamanho);
    }
    else{
      printf("Cenário inválido");
    }
    menu_de_odenacoes();
    scanf("%d", &algoritmo);
  }

  //BubbleSort(&Vetor, tamanho);
  for(int i=0; i<10; i++)
    printf("%d ", Vetor.Matriz[i].IdentificadorDeMatriz);
  printf("\nORDENA:\n");
  Heapsort(&Vetor, tamanho);
  for(int i=0; i<10; i++)
    printf("%d ", Vetor.Matriz[i].IdentificadorDeMatriz);
  printf("\n");
  return 0;
}
