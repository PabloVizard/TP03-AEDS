#ifndef VOO_H
#define VOO_H

typedef struct{
  int vid;
  int horaDecolagem;
  int minutosDecolagem;
  int horaPouso;
  int minutosPouso;
  char aeroportoDecolagem[3];
  char aeroportoPouso[3];
  int identificadorPista;
}TVoo; //As horas e minutos foram separadas as para facilitar a execução do programa


void IniciaVoo(TVoo *Voo); // Função para iniciar o voo
void ImprimirTVoo(TVoo Voo); // Função para imprimir o voo

/*--------------------------------------------------------------------------------------*/
                              //Funções Get: Funções de leitura
/*--------------------------------------------------------------------------------------*/

int GetVid(TVoo Voo); //Função para retornar o vid cadastrado

int GetHrDecolagem(TVoo Voo); //Função para retornar as horas de decolagem cadastradas

int GetMinutosDecolagem(TVoo Voo); //Função para retornar os minutos de decolagem cadastrados

int GetHoraPouso(TVoo Voo); //Função para retornar as horas de pouso cadastradas

int GetMinutosPouso(TVoo Voo); //Função para retornar os minutos de pouso cadastrados

char* GetAeroportoDecolagem(TVoo Voo); //Função para retornar o aeroporto de decolagem cadastrado

char* GetAeroportoPouso(TVoo Voo); //Função para retornar o aeroporto de pouso cadastrado

int GetIdPista(TVoo Voo); //Função para retornar o identificador da pista cadastrado

/*--------------------------------------------------------------------------------------*/
                             //Funções Set: Funções de alteração
/*--------------------------------------------------------------------------------------*/

void SetVid(TVoo *Voo); //Função para alterar o vid cadastrado

void SetHrDecolagem(TVoo *Voo, int horaDecolagem); //Função para alterar as horas de decolagem cadastradas

void SetMinutosDecolagem(TVoo *Voo, int minutosDecolagem); //Função para alterar os minutos de decolagem cadastrados

void SetHrPouso(TVoo *Voo, int horaPouso); //Função para alterar as horas de pouso cadastradas

void SetMinutosPouso(TVoo *Voo, int minutosPouso); //Função para alterar os minutos de pouso cadastrados

void SetAeroportoPouso(TVoo *Voo, char *aeroportoPouso); //Função para alterar o aeroporto de decolagem cadastrado

void SetAeroportoDecolagem(TVoo *Voo, char *aeroportoDecolagem); //Função para alterar o aeroporto de pouso cadastrado

void SetIdPista(TVoo *Voo, int identificadorPista); //Função para alterar o identificador da pista cadastrado

#endif
