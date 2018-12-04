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

int main(){
  srand(time(NULL)); //Utilizamos esse comando para podermos usar numeros aleatorios para o vid

  //Declaração dos Tipos Abstratos de Dados (TADs).
  TipoMatriz Principal;
  TVoo vooReserva;

  //Declaração das variáveis básicas.
  int modo, vid, hrPouso, minPouso, hrDecolagem, minDecolagem;

  //Variáveis auxiliares para a interrupção dos whiles.
  int operadorAuxiliar = 1, modoAuxiliar = 1;

  //Caracteres que recebem as operações e confirmação de saída.
  char op, confirma;
  //Caracter para execução do arquivo
  char p;
  //Variáveis para receber o valor numérico dos caracteres setados.
  int intConfirma = 0, intOperador = 0;

  char nomeArquivo[50];

  printf("====================================================================\n");
  printf("|                      Seja Bem-vindo(a)!                          |\n");
  printf("====================================================================\n");
  printf("\n");

  while(modoAuxiliar != 0){
    menu_de_entradas();
    scanf(" %d", &modo);

    if(modo == 0){
      menu_de_confirmacao();
      /*
      O scanf a seguir identifica o caracter digitado pelo usuário e então
      usando a função toupper o caracter é convertido para maiúsculo, após
      este processo, ele é convertido para int e, sendo os caracteres letras
      maiúsculas, elas, ao serem convertidas para int tem seu valor a partir
      de 65, após isso, ao decrescer 64 unidades, obtemos valores a partir de
      1.

      Ao fim é conferido se o intConfirma == 19, o que significaria que a pessoa
      digitou 'S' ou 's', indicando que ela realmente quer parar a execução
      do programa
      */
      scanf(" %c", &confirma);
      printf("\n");
      confirma = toupper(confirma);
      intConfirma = confirma - 64;

      if(intConfirma == 19){
        menu_de_saida();
        modoAuxiliar = 0;
      }
    }
    else if(modo ==1){
      /*
      Confirmando que o operadorAuxiliar = 1 antes de iniciar o programa, para
      caso o usuário alguma hora interrompa o modo interativo e queira retornar
      a usá-lo.
      */
      operadorAuxiliar = 1;

      printf("====================================================================\n");
      printf("                       MODO INTERATIVO\n");
      while(operadorAuxiliar != 0){
        menu_de_opcoes();
        /*
        O processo a seguir se assemelha muito ao já usado anteriormente, agora
        ele verifica cada um dos casos.

        a -> 1
        b -> 2
        .
        .
        .
        m -> 13
        E finalmente:
        s -> 19, que por fim indica que se deseja parar a execução do programa.
        */
        scanf(" %c", &op);
        op = toupper(op);
        intOperador = op - 64;

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

            printf("Horário de Decolagem no formato HH:MM - ");
            scanf("%d:%d", &vooReserva.horaDecolagem, &vooReserva.minutosDecolagem);

            if(vooReserva.horaDecolagem > 23 || vooReserva.minutosDecolagem > 59){
              printf("Formato inválido!\n");
              break;
            }

            printf("Horário de Pouso no formato HH:MM - ");
            scanf("%d:%d", &vooReserva.horaPouso, &vooReserva.minutosPouso);

            if(vooReserva.horaPouso > 23 || vooReserva.minutosPouso > 59){
              printf("Formato inválido!\n");
              break;
            }

            printf("Aeroporto de decolagem: ");
            scanf("%s", vooReserva.aeroportoDecolagem);

            printf("Aeroporto de pouso: ");
            scanf("%s", vooReserva.aeroportoPouso);

            printf("Identificador da pista: ");
            scanf("%d", &vooReserva.identificadorPista);

            InserirMVoo(&Principal, &vooReserva);
            break;

          case 3: //Opção c
            printf("Digite o Vid do voo a ser removido: ");
            scanf("%d", &vid);
            printf("\n");
            RemoverMVoo(&Principal, vid);
            break;

          case 4: //Opção d
            printf("Digite o Vid do voo a ser pesquisado: ");
            scanf("%d", &vid);
            printf("\n");
            ProcurarMVoo(&Principal, vid);
            break;

          case 5: //Opção e
            printf("Horário de Decolagem no formato HH:MM - ");
            scanf("%d:%d",&hrDecolagem, &minDecolagem);
            printf("Horário de Pouso no formato HH:MM - ");
            scanf("%d:%d",&hrPouso, &minPouso);
            printf("\n====================================================================\n");
            printf("Voos cadastrados no horário de decolagem de %.2d:%.2d às %.2d:%.2d ", hrDecolagem,00,hrDecolagem,59);
            printf("\ne no horário de pouso de %.2d:%.2d às %.2d:%.2d\n", hrPouso,00,hrPouso,59);
            ImprimirVooHrDecolagemHrPouso(Principal, hrDecolagem, minDecolagem, hrPouso, minPouso);
            break;

          case 6: //Opção f
            printf("Horário de Decolagem no formato HH:MM - ");
            scanf("%d:%d", &hrDecolagem, &minDecolagem);
            printf("\n====================================================================\n");
            printf(" Voos cadastrados no horário de decolagem de %.2d:%.2d às %.2d:%.2d\n", hrDecolagem,00,hrDecolagem,59);
            ImprimirVooHrDecolagem(Principal, hrDecolagem, minDecolagem);
            break;

          case 7: //Opção g
            printf("Horário de Pouso no formato HH:MM - ");
            scanf("%d:%d", &hrPouso, &minPouso);
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

          case 19: //Opção s
            printf("Você parou a execução do programa!\n");
            /*
            Caso o usuário resolva para o programa, o operadorAuxiliar recebe
            0, o que condiz com a condição de parada do while, ao voltar o modo
            para 1, o operadorAuxiliar volta a valer 1, fazendo assim com que
            o programa volte ao modo interativo.
            */
            operadorAuxiliar = 0;
            break;

          default: //Caso o usuário coloque um uma opção inválida
            printf("Opção inválida\n");
            break;
        }
      }
    }
    else if(modo == 2){
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
    }
  }
  return 0;
}
