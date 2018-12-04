#include <stdio.h>
#include <stdlib.h>
#include "../Libs/menu.h"

void menu_de_entradas(){
  printf("====================================================================\n");
  printf("|                                                                  |\n");
  printf("|                   Deseja usar qual modo?                         |\n");
  printf("|                                                                  |\n");
  printf("====================================================================\n");

  printf("\n");

  printf("  1. Desejo usar o modo interativo.\n");
  printf("  2. Desejo usar o modo arquivo.\n");
  printf("  0. Desejo sair.\n");

  printf("\n");

  printf("====================================================================\n");

  printf("Modo escolhido: ");
}

void menu_de_opcoes(){
  printf("====================================================================\n");
  printf("Escolha uma das opções abaixo:\n");
  printf("\n");
  printf("  a. Iniciar a Matriz.\n");
  printf("  b. Inserir voo.\n");
  printf("  c. Remover voo.\n");
  printf("  d. Procurar voo.\n");
  printf("  e. Imprimir voos a partir dos horários de decolagem e pouso.\n");
  printf("  f. Imprimir voos a partir do horário de decolagem.\n");
  printf("  g. Imprimir voos a partir do horário de pouso.\n");
  printf("  h. Imprimir todos os voos da matriz.\n");
  printf("  i. Encontrar faixa de horário mais movimentada.\n");
  printf("  j. Encontrar faixa de horário menos movimentada.\n");
  printf("  k. Encontrar a lista com atualização mais recente.\n");
  printf("  l. Encontrar a lista com atualização mais antiga.\n");
  printf("  m. Verificar se a matriz é esparça.\n");
  printf("  s. Sair\n");
  printf("\n");
  printf("====================================================================\n");
  printf("Opção escolhida: ");

}

void menu_de_confirmacao(){
  printf("====================================================================\n");
  printf("\n");
  printf("Você deseja realmente parar a execução do programa?\n");
  printf("[S/n]: ");
}
void menu_de_saida(){
  printf("====================================================================\n");
  printf("\n");
  printf("Trabalho feito por:\n\n -> Arthur De Bellis - 03503\n -> Saulo Miranda Silva - 03475\n -> Pablo Ferreira - 03480\n");
  printf("\n");
  printf("====================================================================\n");
}
void menu_arquivo(){
  printf("====================================================================\n");
  printf("                        MODO ARQUIVO\n");
  printf("====================================================================\n");
  printf("\n");
  printf("Entre com o nome do arquivo que deseja ler: ");
}
