/*****************************************************************//**
 * \file   Lista.h
 * \brief  
 * 
 * \author Pedro Raphael
 * \date   November 2022
 *********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

 //Bibliotecas nativas de C
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

#define TamPart 4						//Tamanho do vetor de participantes
#define TamAtiv 6						//Tamanho do vetor informa��o de atividades
#define TamPlan 4						//Tamanho do vetor com os planos


#pragma region Structs
//Estrutura para armazenar os dados dos participantes
typedef struct pessoa {
	int num;							//N�mero identifica��o
	char nome[50];						//Nome do participante
	int telefone;						//N�mero do telefone
	int idade;							//Idade do participante

}pessoa;

//Estrutura para armazenar as informa��es das atividades
typedef struct infoAtividade {
	int idPrat;							//N�mero do participante
	int dia, mes, ano;					//Dia, mes e ano da atividade
	//char data[12];						//Data da atividade
	char atividade[15];					//Tipo de atividae
	int tempo;							//dura��o da atividade em minutos
	int distancia;						//dist�ncia da atividade em metros

}infoAtividade;

//Estrutura para armazenar o planeamento das atividades
typedef struct planoAtividade {

	int numPrat;						//N�mero do participante
	int diaIni, mesIni, anoIni;			//Dia, m�s e ano do in�cio da atividade
	int hIni, mIni;						//Hora e minuto do in�cio atividade
	int diaFim, mesFim, anoFim;			//Dia, m�s e ano do final da atividade
	int hFim, mFim;						//Hora e minuto do final da atividade
	char ativ[15];						//Tipo de atividade
	int dist;							//Dist�ncia em metros
}planoAtividade;

typedef struct data {
	int dia;
	int mes;
	int ano;
}data;
#pragma endregion

#pragma region AssinaturaFuncoesPessoas
//Fun��o para limpar o lixo de mem�ria do vetor de participantes.
void IniciaBasePessoa(pessoa p[]);

#pragma endregion

#pragma region AssinaturasFuncoesAtividades
//Fun��o para limpar o lixo de mem�ria do vetor das informa��es das atividades
void IniciaBaseAtividade(infoAtividade a[]);

//Fun��o para ordenar de forma crescente um vetor de informa��o de atividades por n�mero de participante.
bool ordenarAtividadeCrescenteParticipantes(infoAtividade a[], int tam);

//Fun��o para ordenar de forma decrescente um vetor de informa��o de atividades por n�mero de participante.
bool ordenarAtividadesDecrescenteParticipantes(infoAtividade a[]);

//Fun��o para listar o n�mero dos participantes de um vetor de informa��o de atividades
void listarNumeroParticipanteAtividade(infoAtividade a[], int tam, char ativ[15]);

//Func�o para listar o n�mero dos participantes que realizaram determinada atividade, num determinado per�odo.
bool AtividadePorPeriodoParticipante(infoAtividade a[], char tipo[15]);

//Fun��o para listar participantes por ordem decrescente, que realizaram uma determinada atividade, num determinado per�odo.
int listarInfoAtividadeParticipanteDecrescente(infoAtividade a[], pessoa p[], char ativ[15]);

//Fun��o para calcular a m�dia do tempo de um praticante.
int calcularMediaPraticante(infoAtividade a[], int codPrat);

#pragma endregion

#pragma region AssinaturasFuncoesPlano
//Fun��o para limpar o lixo de mem�ria do vetor das informa��es dos planos
void iniciaBasePlano(planoAtividade p[]);

//Fun��o para listar um vetor de plano de atividades.
bool listarPlanoAtividade(planoAtividade p[]);

//Fun��o para apresentar o plano de atividade para um determinado praticante, num determinado per�odo, para um tipo de atividade
bool apresentarPlanoPorTipoPeriodoPraticante(planoAtividade p[], char ativ[15], int codPrat);
#pragma endregion

#pragma region AssinaturasManipulacaoDados
//Fun��o para preencher o vetor com os dados dos participantes importados do ficheiro
int ImportaDadosParticipantes(pessoa p[], char* nomeFicheiro);

//Fun��o para preencher o vetor com as informa��es das atividades
bool ImportaInfoAtividade(infoAtividade a[], char* nomeFicheiro);

//Fun��o para preencher o vetor com os dados dos planos dos participantes
bool ImportaPlanoAtividade(planoAtividade p[], char* nomeFicheiro);

#pragma endregion

#pragma region OutrasFuncoes
//Fun��o para leitura do per�odo de datas informada pelo utilizador via stdin
data lerData();

#pragma endregion

#pragma region FuncoesEmTestes


#pragma endregion




