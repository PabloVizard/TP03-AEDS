#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../Libs/voo.h"

//Função inicia
void IniciaVoo(TVoo *Voo) // Inicia o Voo com tudo zerado
{
  Voo -> vid = 0;
  Voo -> horaDecolagem = 0;
  Voo -> minutosDecolagem = 0;
  Voo -> horaPouso = 0;
  Voo -> minutosPouso = 0;
  strcpy(Voo -> aeroportoDecolagem, "");
  strcpy(Voo -> aeroportoPouso, "");
  Voo -> identificadorPista = 0;
}
//Função Imprimir
void ImprimirTVoo(TVoo Voo)
{
  printf("Vid: %d\n", Voo.vid);
  printf("Horario de Decolagem: %d:%d\n", Voo.horaDecolagem,Voo.minutosDecolagem);
  printf("Horario de Pouso: %d:%d\n", Voo.horaPouso,Voo.minutosPouso);
  printf("Aeroporto de Decolagem: %s\n", Voo.aeroportoDecolagem);
  printf("Aeroporto de Pouso: %s\n", Voo.aeroportoPouso);
  printf("Identificador de Pista: %d\n", Voo.identificadorPista);

}

/*--------------------------------------------------------------------------------------*/
                              //Funções Get: Funções de leitura
/*--------------------------------------------------------------------------------------*/

//Função para ler o vid
int GetVid(TVoo Voo)
{
  return (Voo.vid); //Retorna o vid cadastrado
}

//Função para ler a hora da decolagem
int GetHrDecolagem(TVoo Voo)
{
  return (Voo.horaDecolagem); //Retorna a hora de decolagem cadastrada
}

//Função para ler os minutos da decolagem
int GetMinutosDecolagem(TVoo Voo)
{
  return (Voo.minutosDecolagem); //Retorna os minutos de decolagem cadastrados
}

//Função para ler a hora do pouso
int GetHoraPouso(TVoo Voo)
{
  return (Voo.horaPouso); //Retorna a hora de pouso cadastrada
}

//Função para ler o vid
int GetMinutosPouso(TVoo Voo)
{
  return (Voo.minutosPouso); //Retorna os minutos de pouso cadastrados
}

//Função para ler o aeroporto de decolagem
char* GetAeroportoDecolagem(TVoo Voo)
{
  char* p;
  p = Voo.aeroportoDecolagem;
  return p; //Retorna um ponteiro para o aeroporto de decolagem cadastrado;
}

//Função para ler o aeroporto de pouso
char* GetAeroportoPouso(TVoo Voo)
{
  char* p;
  p = Voo.aeroportoPouso;
  return p;  //Retorna um ponteiro para o aeroporto de decolagem cadastrado;
}

//Função para ler o identificador da pista
int GetIdPista(TVoo Voo)
{
  return (Voo.identificadorPista); //Retorna o indentificador da pista cadastrado
}

/*--------------------------------------------------------------------------------------*/
                             //Funções Set: Funções de alteração
/*--------------------------------------------------------------------------------------*/

//Função para alterar o vid
void SetVid(TVoo *Voo)
{
  Voo -> vid = (rand()%10000); // Cadastra um vid aleatorio entre 10000 números
}

//Função para alterar a hora de decolagem
void SetHrDecolagem(TVoo *Voo, int horaDecolagem)
{
  Voo -> horaDecolagem = horaDecolagem; 
}

//Função para alterar os minutos de decolagem
void SetMinutosDecolagem(TVoo *Voo, int minutosDecolagem)
{
  Voo -> minutosDecolagem = minutosDecolagem;
}

//Função para alterar a hora de pouso
void SetHrPouso(TVoo *Voo, int horaPouso)
{
  Voo -> horaPouso = horaPouso;
}

//Função para alterar os minutos de pouso
void SetMinutosPouso(TVoo *Voo, int minutosPouso)
{
  Voo -> minutosPouso = minutosPouso;
}

//Função para alterar o aeroporto de pouso
void SetAeroportoPouso(TVoo *Voo, char *aeroportoPouso)
{
  strcpy(Voo -> aeroportoPouso, aeroportoPouso);
}

//Função para alterar o aeroporto de decolagem
void SetAeroportoDecolagem(TVoo *Voo, char *aeroportoDecolagem)
{
  strcpy(Voo -> aeroportoDecolagem, aeroportoDecolagem);
}

//Função para alterar o identificador da pista
void SetIdPista(TVoo *Voo, int identificadorPista)
{
  Voo -> identificadorPista = identificadorPista;
}
