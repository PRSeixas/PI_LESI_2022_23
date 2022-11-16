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

#define dadosC 4		//Quantidade de colunas matriz dados pessoas
#define infoC 5			//Quantidade de colunas matriz info atividade
#define planoC 7		//Quantidade de colunas matriz plano atividade


#pragma region Structs
//Estrutura para armazenar os dados dos participantes
typedef struct pessoa {
	int num;
	char nome;
	int telefone;
	int idade;

}pessoa;

//Estrutura para armazenar as informa��es das atividades
typedef struct infoAtividade {
	int idPrat;
	char data;
	char atividade;
	int tempo;
	int distancia;

}infoAtividade;

//Estrutura para armazenar o planeamento das atividades
typedef struct planoAtividade {

	int numPrat;
	char dataInicio;
	char horaInicio;
	char dataFim;
	char horaFim;
	char ativ;
	int dist;
}planoAtividade;

#pragma endregion

#pragma region AssinaturaFuncoesPessoas
//Fun��o para limpar o lixo da mem�ria
void IniciaBasePessoa(pessoa p[], int linhas);

//Fun��o para preencher o vetor com os dados dos participantes importados do ficheiro
bool ImportaDadosParticipantes(pessoa p[], char* nomeFicheiro);
#pragma endregion

#pragma region AssinaturasFuncoesAtividades
//Fun��o para limpar o lixo da mem�ria 
void IniciaBaseAtividade(infoAtividade a[], int linhas);

#pragma endregion




