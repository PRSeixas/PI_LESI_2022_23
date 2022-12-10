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
#define TamAtiv 5						//Tamanho do vetor informação de atividades
#define TamPlan 4						//Tamanho do vetor com os planos


#pragma region Structs
//Estrutura para armazenar os dados dos participantes
typedef struct pessoa {
	int num;							//Número identificação
	char nome[50];						//Nome do participante
	int telefone;						//Número do telefone
	int idade;							//Idade do participante

}pessoa;

//Estrutura para armazenar as informações das atividades
typedef struct infoAtividade {
	int idPrat;							//Número do participante
	int dia, mes, ano;					//Dia, mes e ano da atividade
	//char data[12];						//Data da atividade
	char atividade[15];					//Tipo de atividae
	int tempo;							//duração da atividade em minutos
	int distancia;						//distância da atividade em metros

}infoAtividade;

//Estrutura para armazenar o planeamento das atividades
typedef struct planoAtividade {

	int numPrat;						//Número do participante
	int diaIni, mesIni, anoIni;			//Dia, mês e ano do início da atividade
	int hIni, mIni;						//Hora e minuto do início atividade
	int diaFim, mesFim, anoFim;			//Dia, mês e ano do final da atividade
	int hFim, mFim;						//Hora e minuto do final da atividade
	char ativ[15];						//Tipo de atividade
	int dist;							//Distância em metros
}planoAtividade;

#pragma endregion

#pragma region AssinaturaFuncoesPessoas
//Função para limpar o lixo de memória do vetor de participantes.
void IniciaBasePessoa(pessoa p[]);

#pragma endregion

#pragma region AssinaturasFuncoesAtividades
//Função para limpar o lixo de memória do vetor das informações das atividades
void IniciaBaseAtividade(infoAtividade a[]);

#pragma endregion

#pragma region AssinaturasFuncoesPlano
//Função para limpar o lixo de memória do vetor das informações dos planos
void iniciaBasePlano(planoAtividade p[]);

#pragma endregion

#pragma region AssinaturasManipulacaoDados
//Função para preencher o vetor com os dados dos participantes importados do ficheiro
int ImportaDadosParticipantes(pessoa p[], char* nomeFicheiro);

//Função para preencher o vetor com as informações das atividades
bool ImportaInfoAtividade(infoAtividade a[], char* nomeFicheiro);

//Função para preencher o vetor com os dados dos planos dos participantes
bool ImportaPlanoAtividade(planoAtividade p[], char* nomeFicheiro);

#pragma endregion




