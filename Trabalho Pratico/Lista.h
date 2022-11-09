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

#define dadosC 4		//Quantidade de colunas matriz dados pessoas
#define infoC 5			//Quantidade de colunas matriz info atividade
#define planoC 7		//Quantidade de colunas matriz plano atividade


#pragma region Structs
//Estrutura para armazenar os dados dos participantes
typedef struct pessoa {
	int num;
	char nome[30];
	int telefone;
	int idade;

}pessoa;

typedef struct dadosPessoa {
	int num;
	char nome[30];
	int telefone;
	int idade;

}dadosPessoa;

//Estrutura para armazenar as informações das atividades
typedef struct infoAtividade {
	int idPrat;
	char data[10];
	char atividade[10];
	int tempo;
	int distancia;

}indoAtividade;

//Estrutura para armazenar o planeamento das atividades
typedef struct planoAtividade {

	int numPrat;
	char dataInicio[10];
	char horaInicio[5];
	char dataFim[10];
	char horaFim[5];
	char ativ[10];
	int dist;
}planoAtividade;

#pragma endregion



