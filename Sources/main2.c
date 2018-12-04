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

  for(i = 0; i < 10; i++)
    {
      //Criando voos aleatoriamente
      IniciaMatriz(&Principal);
      IniciaVoo(&vooReserva);
      SetVid(&vooReserva);

      vooReserva.horaDecolagem = (rand()%23);
      vooReserva.minutosDecolagem = (rand()%59);

      vooReserva.horaPouso = (rand()%23);
      vooReserva.minutosPouso = (rand()%59);

    //===========================================================================

      aux1 = (rand()%25)+65;
      aux2 = (rand()%25)+65;
      aux3 = (rand()%25)+65;

      vooReserva.aeroportoPouso[0] = aux1;
      vooReserva.aeroportoPouso[1] = aux2;
      vooReserva.aeroportoPouso[2] = aux3;
    //===========================================================================

      aux1 = (rand()%25)+65;
      aux2 = (rand()%25)+65;
      aux3 = (rand()%25)+65;

      vooReserva.aeroportoDecolagem[0] = aux1;
      vooReserva.aeroportoDecolagem[1] = aux2;
      vooReserva.aeroportoDecolagem[2] = aux3;

    //===========================================================================
      vooReserva.identificadorPista = (rand()%100);

      InserirMVoo(&Principal, &vooReserva);
      ImprimirMatriz(Principal);
}

  TipoItemVetor Item;
  TipoVetor Vetor;
  Vetor.Tamanho = 73;
  IniciaItemVetor(&Item);
  IniciaVetor(&Vetor, &Item);
    /*else if(modo == 2){
      FILE *arq;
      menu_arquivo();
      scanf("%s", nomeArquivo);
      printf("\n");
      arq = fopen(nomeArquivo, "r"); //Abertura do arquivo

      if(arq == NULL){
        printf("O arquivo digitado não foi encontrado.\n");
      }else{
        while(feof(arq) != 1){ //Enquanto não for o fim do arquivo, ele mantém o while, quando chegar no fim, retorna 1
          fscanf(arq,"%c", &p);
          p = toupper(p);
          intOperador = p - 64;
          switch (intOperador){
            case 1: //Opção a
              IniciaMatriz(&Principal);
              printf("\n");
              printf("====================================================================\n");
              printf("\n               >>> A MATRIZ FOI INICIALIZADA! <<<\n\n");
              printf("====================================================================\n\n");
              break;

            case 2: //Opção b
              IniciaVoo(&vooReserva);
              SetVid(&vooReserva);

              fscanf(arq,"%d:%d", &vooReserva.horaDecolagem, &vooReserva.minutosDecolagem);
              fscanf(arq,"%d:%d", &vooReserva.horaPouso, &vooReserva.minutosPouso);
              fscanf(arq,"%s", vooReserva.aeroportoDecolagem);
              fscanf(arq,"%s", vooReserva.aeroportoPouso);
              fscanf(arq,"%d", &vooReserva.identificadorPista);

              InserirMVoo(&Principal, &vooReserva);
              break;

            case 3: //Opção c
              fscanf(arq,"%d", &vid);
              RemoverMVoo(&Principal, vid);
              break;

            case 4: //Opção d
              fscanf(arq,"%d", &vid);
              ProcurarMVoo(&Principal, vid);
              break;

            case 5: //Opção e
              fscanf(arq,"%d:%d",&hrDecolagem, &minDecolagem);
              fscanf(arq,"%d:%d",&hrPouso, &minPouso);
              printf("\n====================================================================\n");
              printf("Voos cadastrados no horário de decolagem de %.2d:%.2d às %.2d:%.2d ", hrDecolagem,00,hrDecolagem,59);
              printf("\ne no horário de pouso de %.2d:%.2d às %.2d:%.2d\n", hrPouso,00,hrPouso,59);
              ImprimirVooHrDecolagemHrPouso(Principal, hrDecolagem, minDecolagem, hrPouso, minPouso);
              break;

            case 6: //Opção f
              fscanf(arq,"%d:%d", &hrDecolagem, &minDecolagem);
              printf("\n====================================================================\n");
              printf(" Voos cadastrados no horário de decolagem de %.2d:%.2d às %.2d:%.2d\n", hrDecolagem,00,hrDecolagem,59);
              ImprimirVooHrDecolagem(Principal, hrDecolagem, minDecolagem);
              break;

            case 7: //Opção g
              fscanf(arq,"%d:%d", &hrPouso, &minPouso);
              printf("\n====================================================================\n");
              printf("   Voos cadastrados no horário de pouso de %.2d:%.2d às %.2d:%.2d\n", hrPouso,00,hrPouso,59);
              ImprimirVooHrPouso(Principal, hrPouso, minPouso);
              break;

            case 8: //Opção h
              printf("====================================================================\n");
              printf("                   Voos cadastrados Na Matriz\n");
              ImprimirMatriz(Principal);
              break;

            case 9: //Opção i
              EncontrarMaiorHorario(&Principal);
              break;

            case 10: //Opção j
              EncontrarMenorHorario(&Principal);
              break;

            case 11: //Opção k
              EncontrarListaMaisRecente(&Principal);
              break;

            case 12: //Opção l
              EncontrarListaMenosRecente(&Principal);
              break;

            case 13: //Opção m
              MatrizEsparca(&Principal);
              break;
              fclose(arq); //Encerramento do arquivo
          }
        }
      }
    }*/
  return 0;
}
