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
#define TamAtiv 5						//Tamanho do vetor informa��o de atividades
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

#pragma endregion

#pragma region AssinaturaFuncoesPessoas
//Fun��o para limpar o lixo de mem�ria do vetor de participantes.
void IniciaBasePessoa(pessoa p[]);

#pragma endregion

#pragma region AssinaturasFuncoesAtividades
//Fun��o para limpar o lixo de mem�ria do vetor das informa��es das atividades
void IniciaBaseAtividade(infoAtividade a[]);

#pragma endregion

#pragma region AssinaturasFuncoesPlano
//Fun��o para limpar o lixo de mem�ria do vetor das informa��es dos planos
void iniciaBasePlano(planoAtividade p[]);

#pragma endregion

#pragma region AssinaturasManipulacaoDados
//Fun��o para preencher o vetor com os dados dos participantes importados do ficheiro
int ImportaDadosParticipantes(pessoa p[], char* nomeFicheiro);

//Fun��o para preencher o vetor com as informa��es das atividades
bool ImportaInfoAtividade(infoAtividade a[], char* nomeFicheiro);

//Fun��o para preencher o vetor com os dados dos planos dos participantes
bool ImportaPlanoAtividade(planoAtividade p[], char* nomeFicheiro);

#pragma endregion




