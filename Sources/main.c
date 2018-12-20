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

  printf("====================================================================\n");
  printf("|                      Seja Bem-vindo(a)!                          |\n");
  printf("====================================================================\n");
  printf("\n");

  menu_de_entradas();
  scanf("%d", &modo);
  printf("\n");

  if (modo == 1){
    TipoVetor Vetor, VetorAUX;

    printf("Entre com o cenário desejado: ");
    scanf("%d", &cenario);
    printf("\n");

    if(cenario == 1 || cenario == 2 || cenario == 3 || cenario == 4){
      //printf("arthur %d\n", cenario);
      tamanho = 365;
      AlocaVetor(&Vetor, tamanho);
      AlocaVetor(&VetorAUX, tamanho);
      //printf("arthur %d\n", cenario);
      PreencheVetor(&Vetor, cenario, tamanho);
      //printf("arthur %d\n", cenario);
    }
    else if(cenario == 5 || cenario == 6 || cenario == 7 || cenario == 8){
      tamanho = 3650;
      //printf("mago implacavel 1 %d cenario\n", cenario);
      AlocaVetor(&Vetor, tamanho);
      AlocaVetor(&VetorAUX, tamanho);
      //printf("mago implacavel 2 %d cenario\n", cenario);
      PreencheVetor(&Vetor, cenario, tamanho);
      //printf("mago implacavel 3 %d cenario\n", cenario);
    }
    else if(cenario == 9 || cenario == 10 || cenario == 11 || cenario == 12){
      tamanho = 36500;
      AlocaVetor(&Vetor, tamanho);
      AlocaVetor(&VetorAUX, tamanho);
      PreencheVetor(&Vetor, cenario, tamanho);
    }
    else{
      printf("Cenário inválido");
    }



  for(int i = 0; i < tamanho; i++){
    VetorAUX.Matriz[i] = Vetor.Matriz[i];
  }
  while(1){
    menu_de_odenacoes();
    scanf("%d", &algoritmo);
    switch (algoritmo) {
      case 1:
      printf("BUBBLE SORT\n");
      BubbleSort(&VetorAUX, tamanho);
      for(int i = 0; i < tamanho; i++){
        VetorAUX.Matriz[i] = Vetor.Matriz[i];
      }
      break;
      case 2:
      printf("SELECT SORT\n");
      SelectionSort(&VetorAUX, tamanho);
      for(int i = 0; i < tamanho; i++){
        VetorAUX.Matriz[i] = Vetor.Matriz[i];
      }
      break;
      case 3:
      printf("INSERT SORT\n");
      InsertionSort(&VetorAUX, tamanho);
      for(int i = 0; i < tamanho; i++){
        VetorAUX.Matriz[i] = Vetor.Matriz[i];
      }
      break;
      case 4:
      printf("SHELL SORT\n");
      ShellSort(&VetorAUX, tamanho);
      for(int i = 0; i < tamanho; i++){
        VetorAUX.Matriz[i] = Vetor.Matriz[i];
      }
      break;
      case 5:
      printf("QUICK SORT\n");
      QuickSort(&VetorAUX, tamanho);
      for(int i = 0; i < tamanho; i++){
        VetorAUX.Matriz[i] = Vetor.Matriz[i];
      }
      break;
      case 6:
      printf("HEAP SORT\n");
      heapsort(&VetorAUX, tamanho);
      for(int i = 0; i < tamanho; i++){
        VetorAUX.Matriz[i] = Vetor.Matriz[i];
      }
      break;
    }
    if(algoritmo == 0)
      break;
    }
}
  else if(modo == 2){
    FILE *Arquivo;

    char Nome[100];
    int tamanhoReal = 0, voos;

    TipoVetor Vetor, VetorAUX;
    TVoo vooArquivo;
    TipoMatriz MatrizArquivo;

    IniciaMatriz(&MatrizArquivo);

    printf("Nome do Arquivo (com extensão .txt): ");
    scanf("%s", Nome);

    if(strcmp(Nome, "cenario1.txt") == 0){
      tamanho = 365;
      AlocaVetor(&Vetor, tamanho);
      AlocaVetor(&VetorAUX, tamanho);
      tamanhoReal = 73;
      voos = 10;

    }
    else if(strcmp(Nome, "cenario2.txt") == 0){
      tamanho = 365;
      AlocaVetor(&Vetor, tamanho);
      AlocaVetor(&VetorAUX, tamanho);
      tamanhoReal = 365;
      voos = 10;
    }
    else if(strcmp(Nome, "cenario3.txt") == 0){
      tamanho = 365;
      AlocaVetor(&Vetor, tamanho);
      AlocaVetor(&VetorAUX, tamanho);
      tamanhoReal = 73;
      voos = 100;
    }
    else if(strcmp(Nome, "cenario4.txt") == 0){
      tamanho = 365;
      AlocaVetor(&Vetor, tamanho);
      AlocaVetor(&VetorAUX, tamanho);
      tamanhoReal = 365;
      voos = 100;
    }
    else if(strcmp(Nome, "cenario5.txt") == 0){
      tamanho = 3650;
      AlocaVetor(&Vetor, tamanho);
      AlocaVetor(&VetorAUX, tamanho);
      tamanhoReal = 730;
      voos = 10;
    }
    else if(strcmp(Nome, "cenario6.txt") == 0){
      tamanho = 3650;
      AlocaVetor(&Vetor, tamanho);
      AlocaVetor(&VetorAUX, tamanho);
      tamanhoReal = 3650;
      voos = 10;
    }
    else if(strcmp(Nome, "cenario7.txt") == 0){
      tamanho = 3650;
      AlocaVetor(&Vetor, tamanho);
      AlocaVetor(&VetorAUX, tamanho);
      tamanhoReal = 730;
      voos = 100;
    }
    else if(strcmp(Nome, "cenario8.txt") == 0){
      tamanho = 3650;
      AlocaVetor(&Vetor, tamanho);
      AlocaVetor(&VetorAUX, tamanho);
      tamanhoReal = 3650;
      voos = 100;
    }
    else if(strcmp(Nome, "cenario9.txt") == 0){
      tamanho = 36500;
      AlocaVetor(&Vetor, tamanho);
      AlocaVetor(&VetorAUX, tamanho);
      tamanhoReal = 7300;
      voos = 10;
    }
    else if(strcmp(Nome, "cenario10.txt") == 0){
      tamanho = 36500;
      AlocaVetor(&Vetor, tamanho);
      AlocaVetor(&VetorAUX, tamanho);
      tamanhoReal = 36500;
      voos = 10;
    }
    else if(strcmp(Nome, "cenario11.txt") == 0){
      tamanho = 36500;
      AlocaVetor(&Vetor, tamanho);
      AlocaVetor(&VetorAUX, tamanho);
      tamanhoReal = 7300;
      voos = 100;
    }
    else if(strcmp(Nome, "cenario12.txt") == 0){
      tamanho = 36500;
      AlocaVetor(&Vetor, tamanho);
      AlocaVetor(&VetorAUX, tamanho);
      tamanhoReal = 36500;
      voos = 100;
    }
    Arquivo = fopen(Nome, "r");
    int Posicao[tamanhoReal];
    for(int i = 0; i < tamanhoReal; i++){
      fscanf(Arquivo, "%d", &Posicao[i]);
    }

    for(int i = 0; i < tamanhoReal; i++){
      for(int j = 0; j < voos; j++){

        IniciaVoo(&vooArquivo);
        SetVid(&vooArquivo);

        fscanf(Arquivo,"%d:%d", &vooArquivo.horaDecolagem, &vooArquivo.minutosDecolagem);
        fscanf(Arquivo,"%d:%d", &vooArquivo.horaPouso, &vooArquivo.minutosPouso);
        fscanf(Arquivo,"%s", vooArquivo.aeroportoDecolagem);
        fscanf(Arquivo,"%s", vooArquivo.aeroportoPouso);
        fscanf(Arquivo,"%d", &vooArquivo.identificadorPista);
        InserirMVoo(&Vetor.Matriz[Posicao[i]], &vooArquivo);
      }
      VetorAUX.Matriz[i] = Vetor.Matriz[i];
    }
    fclose(Arquivo);
    while(1){
      menu_de_odenacoes();
      scanf("%d", &algoritmo);
      switch (algoritmo) {
        case 1:
        printf("BUBBLE SORT\n");
        BubbleSort(&VetorAUX, tamanho);
        for(int i = 0; i < tamanho; i++){
          VetorAUX.Matriz[i] = Vetor.Matriz[i];
        }
        break;
        case 2:
        printf("SELECT SORT\n");
        SelectionSort(&VetorAUX, tamanho);
        for(int i = 0; i < tamanho; i++){
          VetorAUX.Matriz[i] = Vetor.Matriz[i];
        }
        break;
        case 3:
        printf("INSERT SORT\n");
        InsertionSort(&VetorAUX, tamanho);
        for(int i = 0; i < tamanho; i++){
          VetorAUX.Matriz[i] = Vetor.Matriz[i];
        }
        break;
        case 4:
        printf("SHELL SORT\n");
        ShellSort(&VetorAUX, tamanho);
        for(int i = 0; i < tamanho; i++){
          VetorAUX.Matriz[i] = Vetor.Matriz[i];
        }
        break;
        case 5:
        printf("QUICK SORT\n");
        QuickSort(&VetorAUX, tamanho);
        for(int i = 0; i < tamanho; i++){
          VetorAUX.Matriz[i] = Vetor.Matriz[i];
        }
        break;
        case 6:
        printf("HEAP SORT\n");
        heapsort(&VetorAUX, tamanho);
        for(int i = 0; i < tamanho; i++){
          VetorAUX.Matriz[i] = Vetor.Matriz[i];
        }
        break;
      }
      if(algoritmo == 0)
        break;
      }
  }

  return 0;
}
