#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Libs/MatrizVoos.h"
#include "../Libs/ItemMatriz.h"
#include "../Libs/ListadeVoos.h"
#include "../Libs/voo.h"

/*--------------------------------------------------------------------------------------*/
                                       //Funções
/*--------------------------------------------------------------------------------------*/

//---------------------------------------------------------------------------------------
//Função para iniciar a matriz de Voos
void IniciaMatriz(TipoMatriz *Matriz){
  int i, j;
  for(i = 0; i < 24; i++){
    for(j = 0; j < 24; j++){
      IniciaItem(&(Matriz) -> Matriz[i][j]); //Nesse FOR nós iniciamos o item matriz para cada uma das posições da matriz com valores zerados
    }
  }
  Matriz -> dia = 0;
  Matriz -> mes = 0;
  Matriz -> ano = 0;
  Matriz -> HoradaUltimaAtualizacao = 0;
  Matriz -> MinutosUltimaAtualizacao = 0;
}
//Atualiza o horário e data de atualização da matriz
void AtualizaMatriz(TipoMatriz *Matriz){
  time_t tp;
  struct tm lt;
  time(&tp);
  lt = *localtime(&tp);
  Matriz->dia = lt.tm_mday;
  Matriz->mes = lt.tm_mon;
  Matriz->ano = lt.tm_year;
  Matriz->HoradaUltimaAtualizacao =  lt.tm_hour;
  Matriz->MinutosUltimaAtualizacao = lt.tm_min;
}
//---------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------
//Função para inserir o voo na matriz
void InserirMVoo(TipoMatriz *Matriz, TVoo *voo){
  int i, j;
  i = voo->horaDecolagem;
  j = voo->horaPouso;//+1;
  //if(voo->horaPouso >= 23)
  //  j = 0;
  InserirNovo(&Matriz->Matriz[i][j].Lista, *voo);
  SetNumVoo(&Matriz->Matriz[i][j]);
  SetHreMntsLast(&Matriz->Matriz[i][j]);
  AtualizaMatriz(Matriz);
}
void RemoverMVoo(TipoMatriz *Matriz, int vid){
  int i,j;
  TLista *lista = NULL;
  for(i = 0; i < 24; i++){
    for(j = 0; j < 24; j++){
      lista = &Matriz->Matriz[i][j].Lista;
      if(RemoverVoo(lista, vid)){
        SetHreMntsLast(&Matriz->Matriz[i][j]);
        AtualizaMatriz(Matriz);
        return;
      }

    }
  }
    printf("====================================================================\n\n");
    printf("                  >>> Voo não encontrado. <<<\n\n");
    printf("====================================================================\n\n");
  }


int ProcurarMVoo(TipoMatriz *Matriz, int vid){
  int i, j;
  TLista *lista = NULL;
  TCelula *retorno = NULL;
  for (i = 0; i < 24; i++){
    for(j = 0; j < 24; j++){
      lista = &Matriz->Matriz[i][j].Lista;
      retorno = ProcurarVoo(lista, vid);
      if(retorno!=NULL){
          printf("====================================================================\n\n");
          printf("             >>> O voo informado está cadastrado! <<<\n\n");
          printf("====================================================================\n\n");
          return 1;
      }
    }
  }
  printf("====================================================================\n\n");
  printf("                  >>> Voo não encontrado. <<<\n\n");
  printf("====================================================================\n\n");
  return 0;
}
void ImprimirVooHrDecolagemHrPouso(TipoMatriz Matriz, int horaDecolagem, int minutosDecolagem, int horaPouso, int minutosPouso){
  int i, j;
  i = horaDecolagem;
  j = horaPouso;
  TCelula *pAtual = Matriz.Matriz[i][j].Lista.pPrimeiro->pProximo;
  if(Matriz.Matriz[i][j].NumeroVoos != 0){
    while (pAtual != NULL){
      printf("====================================================================\n\n");
      printf("Vid: %.4d\n", pAtual->Voo.vid);
      printf("Horario de Decolagem: %.2d:%.2d\n", pAtual->Voo.horaDecolagem,pAtual->Voo.minutosDecolagem);
      printf("Horario de Pouso: %.2d:%.2d\n", pAtual->Voo.horaPouso, pAtual->Voo.minutosPouso);
      printf("Aeroporto de Decolagem: %s\n", pAtual->Voo.aeroportoDecolagem);
      printf("Aeroporto de Pouso: %s\n", pAtual->Voo.aeroportoPouso);
      printf("Identificador de Pista: %d\n", pAtual->Voo.identificadorPista);
      printf("====================================================================\n\n");

      pAtual = pAtual -> pProximo;
    }
  }
  else{
    printf("====================================================================\n\n");
    printf("\n       >>>Nao existe voos cadastrados nesse horario <<<\n\n");
    printf("====================================================================\n\n");
  }
}
void ImprimirVooHrDecolagem(TipoMatriz Matriz, int horaDecolagem, int minutosDecolagem){
  int i, j, cont;
  i = horaDecolagem;
  TCelula *pAtual;
  for(j = 0; j < 24; j++)
  {
    if(Matriz.Matriz[i][j].NumeroVoos != 0){
      pAtual = Matriz.Matriz[i][j].Lista.pPrimeiro->pProximo;
      while (pAtual != NULL){
        printf("====================================================================\n\n");
        printf("Vid: %.4d\n", pAtual->Voo.vid);
        printf("Horario de Decolagem: %.2d:%.2d\n", pAtual->Voo.horaDecolagem,pAtual->Voo.minutosDecolagem);
        printf("Horario de Pouso: %.2d:%.2d\n", pAtual->Voo.horaPouso, pAtual->Voo.minutosPouso);
        printf("Aeroporto de Decolagem: %s\n", pAtual->Voo.aeroportoDecolagem);
        printf("Aeroporto de Pouso: %s\n", pAtual->Voo.aeroportoPouso);
        printf("Identificador de Pista: %d\n", pAtual->Voo.identificadorPista);
        printf("====================================================================\n\n");
        cont ++;
        pAtual = pAtual->pProximo;

      }
    }
  }
  if (cont == 0){
    printf("====================================================================\n\n");
    printf("\n       >>>Nao existe voos cadastrados nesse horario <<<\n\n");
    printf("====================================================================\n\n");
  }
}
void ImprimirVooHrPouso(TipoMatriz Matriz, int horaPouso, int minutosPouso){
  int i, j, cont;
  j = horaPouso;
  TCelula *pAtual;
  for(i = 0; i < 24; i++)
  {
    if(Matriz.Matriz[i][j].NumeroVoos != 0){
      pAtual = Matriz.Matriz[i][j].Lista.pPrimeiro->pProximo;
      while (pAtual != NULL){
        printf("====================================================================\n\n");
        printf("Vid: %.4d\n", pAtual->Voo.vid);
        printf("Horario de Decolagem: %.2d:%.2d\n", pAtual->Voo.horaDecolagem,pAtual->Voo.minutosDecolagem);
        printf("Horario de Pouso: %.2d:%.2d\n", pAtual->Voo.horaPouso, pAtual->Voo.minutosPouso);
        printf("Aeroporto de Decolagem: %s\n", pAtual->Voo.aeroportoDecolagem);
        printf("Aeroporto de Pouso: %s\n", pAtual->Voo.aeroportoPouso);
        printf("Identificador de Pista: %d\n", pAtual->Voo.identificadorPista);
        printf("====================================================================\n\n");
        cont ++;
        pAtual = pAtual->pProximo;
      }
    }
  }
  if (cont == 0){
    printf("====================================================================\n\n");
    printf("\n        >>>Nao existe voos cadastrados nesse horario <<<\n\n");
    printf("====================================================================\n\n");
  }
}
void ImprimirMatriz(TipoMatriz Matriz){
  int i, j,cont = 0;
  TCelula *pAtual;
  for(i = 0; i < 24; i ++)
  {
    for (j = 0; j < 24; j++)
    {
      if(Matriz.Matriz[i][j].NumeroVoos != 0){
        pAtual = Matriz.Matriz[i][j].Lista.pPrimeiro->pProximo;
        while (pAtual != NULL){
          printf("====================================================================\n\n");
          printf("Vid: %.4d\n", pAtual->Voo.vid);
          printf("Horario de Decolagem: %.2d:%.2d\n", pAtual->Voo.horaDecolagem,pAtual->Voo.minutosDecolagem);
          printf("Horario de Pouso: %.2d:%.2d\n", pAtual->Voo.horaPouso, pAtual->Voo.minutosPouso);
          printf("Aeroporto de Decolagem: ");
          for(int i=0;i<3;i++)
            printf("%c", pAtual->Voo.aeroportoDecolagem[i]);
          printf("\n");
          printf("Aeroporto de Pouso: %s\n", pAtual->Voo.aeroportoPouso);
          printf("Identificador de Pista: %d\n", pAtual->Voo.identificadorPista);
          printf("====================================================================\n\n");

          pAtual = pAtual->pProximo;
          cont++;
        }
      }
    }
  }
  if(cont==0){
    printf("====================================================================\n\n");
    printf("              >>> Não existem voos cadastrados. <<<\n\n");
    printf("====================================================================\n\n");
  }
}
//Percorre a matriz buscando o item com mais itens, depois percorre comparando o valor encontrado
//com cada item da matriz, assim se houver mais de um item com mais itens, os dois serão impressos
void EncontrarMaiorHorario(TipoMatriz *Matriz){
  int linha=0, coluna=0, numerodevoos, maior;
  for(linha=0; linha<24; linha++){
      for(coluna =0; coluna<24; coluna++){
          numerodevoos = Matriz->Matriz[linha][coluna].NumeroVoos;
          if ((linha+coluna)==0) {
            maior = numerodevoos;
          }
          else{
            if(numerodevoos>maior ){
              maior = numerodevoos;
            }
          }
        }
      }
  if(maior!=0){
    printf("====================================================================\n\n");
    printf("Item com maior quantidade de voos:\n\n");
    for(linha=0; linha<24; linha++){
      for(coluna =0; coluna<24; coluna++){
        numerodevoos = Matriz->Matriz[linha][coluna].NumeroVoos;
        if(maior==numerodevoos){
            printf("====================================================================\n\n");
            printf("i = %d e j = %d e quantidade = %d\n\n", linha, coluna, maior);
        }
      }
    }
    printf("====================================================================\n\n");
  }
  else{
    printf("====================================================================\n\n");
    printf("              >>> Não existem voos cadastrados. <<<\n\n");
    printf("====================================================================\n\n");
  }
}
//Funciona do mesmo jeito que a função anterior, porém essa busca o item com menos voos, não contando com os itens zerados
void EncontrarMenorHorario(TipoMatriz *Matriz){
    int linha=0, coluna=0, numerodevoos, menor =10000;
    printf("====================================================================\n\n");
    printf("Item com menor quantidade de voos:\n\n");
    for(linha=0; linha<24; linha++){
        for(coluna =0; coluna<24; coluna++){
            numerodevoos = Matriz->Matriz[linha][coluna].NumeroVoos;
            if ((linha+coluna)==0 && numerodevoos != 0) {
              menor = numerodevoos;
            }
            else{
              if(numerodevoos<menor && numerodevoos != 0){
                menor = numerodevoos;
              }
            }
          }
        }
    if(menor!=10000){
      for(linha=0; linha<24; linha++){
          for(coluna =0; coluna<24; coluna++){
            numerodevoos = Matriz->Matriz[linha][coluna].NumeroVoos;
              if(menor==numerodevoos){
                  printf("====================================================================\n\n");
                  printf("i = %d e j = %d e quantidade = %d\n\n", linha, coluna, menor);
              }
          }
      }
      printf("====================================================================\n\n");
    }
    else{
      printf("====================================================================\n\n");
      printf("              >>> Não existem voos cadastrados. <<<\n\n");
      printf("====================================================================\n\n");
    }
}
//Busca o menor horário e compara com cada item da lista, para imprimir todos os itens que possuem tal horário
void EncontrarListaMaisRecente(TipoMatriz *Matriz){
  int horas= 0, minutos = 0, minutoMaisRecente =0, horaMaisRecente=-1, linha, coluna;
  for(linha=0; linha<24; linha++){
      for(coluna =0; coluna<24; coluna++){
          horas = Matriz->Matriz[linha][coluna].HrLast*60;
          minutos = Matriz->Matriz[linha][coluna].MntsLast;
          if (horas+minutos != 0){
            if((horas+minutos)>=((horaMaisRecente*60)+minutoMaisRecente)){
              horaMaisRecente = horas;
              minutoMaisRecente = minutos;
            }
          }
      }
    }
    if(horaMaisRecente!=-1){
      printf("====================================================================\n\n");
      printf("Item com a faixa de horario mais recente: \n\n");
      for(linha=0; linha<24; linha++){
          for(coluna =0; coluna<24; coluna++){
            horas = Matriz->Matriz[linha][coluna].HrLast*60;
            minutos = Matriz->Matriz[linha][coluna].MntsLast;
            if((horas+minutos)==(horaMaisRecente+minutoMaisRecente)){
              printf("====================================================================\n\n");
              printf("i = %d, j = %d, horario = %.2d:%.2d\n\n", linha, coluna, (horaMaisRecente/60), minutoMaisRecente);
            }
          }
      }
      printf("====================================================================\n\n");
    }
    else{
      printf("====================================================================\n\n");
      printf("              >>> Não existem voos cadastrados. <<<\n\n");
      printf("====================================================================\n\n");
    }
}
//Funciona da mesma forma que o subprograma acima, porém busca e compara o maior horário
void EncontrarListaMenosRecente(TipoMatriz *Matriz){
    int horas= 0, minutos = 0, minutoMenosRecente =59, horaMenosRecente=23, linha, coluna;
    for(linha=0; linha<24; linha++){
        for(coluna =0; coluna<24; coluna++){
            horas = Matriz->Matriz[linha][coluna].HrLast*60;
            minutos = Matriz->Matriz[linha][coluna].MntsLast;
            if (horas+minutos != 0){
              if((horas+minutos)<=((horaMenosRecente*60)+minutoMenosRecente)){
                horaMenosRecente = horas;
                minutoMenosRecente = minutos;
              }
            }
        }
      }
      if(horaMenosRecente!=23){
        printf("====================================================================\n\n");
        printf("Item com a faixa de horario menos recente: \n\n");
        for(linha=0; linha<24; linha++){
            for(coluna =0; coluna<24; coluna++){
              horas = Matriz->Matriz[linha][coluna].HrLast*60;
              minutos = Matriz->Matriz[linha][coluna].MntsLast;
              if((horas+minutos)==(horaMenosRecente+minutoMenosRecente)){
                printf("====================================================================\n\n");
                printf("i = %d, j = %d, horario = %.2d:%.2d\n\n", linha, coluna, (horaMenosRecente/60), minutoMenosRecente);
              }
            }
        }
        printf("====================================================================\n\n");
      }
      else{
        printf("====================================================================\n\n");
        printf("              >>> Não existem voos cadastrados. <<<\n\n");
        printf("====================================================================\n\n");
      }
}
//Confere se a quantidade de itens vazios é pelo menos 2 terços da matriz.
void MatrizEsparca(TipoMatriz *Matriz){
    int contador =0, linha, coluna,nVoos;
    for(linha=0; linha<24; linha++){
        for(coluna =0; coluna<24; coluna++){
            nVoos = Matriz->Matriz[linha][coluna].NumeroVoos;
            if(nVoos==0){
                contador++;
            }
        }
    }
    if(contador>=384){
      printf("====================================================================\n\n");
      printf("                        >>> É esparça. <<<\n\n");
      printf("====================================================================\n\n");
    }else{
      printf("====================================================================\n\n");
      printf("                       >>> Não é esparça. <<<\n\n");
      printf("====================================================================\n\n");
    }
}
