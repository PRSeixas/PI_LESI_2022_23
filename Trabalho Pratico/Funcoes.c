/*****************************************************************//**
 * \file   Funcoes.c
 * \brief  
 * 
 * \author Pedro Raphael
 * \date   November 2022
 *********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

 //Biblioteca nativa de C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"


#pragma region FuncoesPessoas
/**
 * .
 * 
 * \param p
 * \param linhas
 */
void IniciaBasePessoa(pessoa p[], int linhas) {

	int i = 0;

	for (size_t i = 0; i < linhas; i++)
	{
		p[i].num = -1;
		p[i].nome = "0";
		p[i].telefone = -1;
		p[i].idade = -1;
		i++;
	}
}

#pragma endregion

#pragma region FuncoesAtividades
/**
 * .
 * 
 * \param a
 * \param linhas
 */
void IniciaBaseAtividade(infoAtividade a[], int linhas) {

	int i = 0;

	for (size_t i = 0; i < linhas; i++)
	{
		a[i].idPrat = -1;
		a[i].data = "0";
		a[i].atividade = "0";
		a[i].tempo = -1;
		a[i].distancia = -1;

		i++;
	}
}

#pragma endregion


#pragma region Desenvolvimento

//Função para importar os dados dos participantes do ficheiro 
bool ImportaDadosParticipantes(pessoa p[], char* nomeFicheiro) {

	FILE* fp;
	pessoa aux;
	int i = 0;

	//Teste se o ficheiro é vazio
	if ((fp = fopen(nomeFicheiro, "r")) == NULL) return false;

	else
	{
		while (fscanf(fp,"%d %s %d %d\n", &aux.num, &aux.nome, &aux.telefone, &aux.idade) != EOF)
		{
			//sscanf(c, "%d;%c;%d;%d\n", &aux.num, &aux.nome, &aux.telefone, &aux.idade);
			p[i].num = aux.num;
			p[i].nome = aux.nome;
			p[i].telefone = aux.telefone;
			p[i].idade = aux.idade;

			i++;
		}
	}
		
/*
		while (fgets(c, sizeof(c), fp) != EOF)
		{
			sscanf(c, "%d;%s;%d;%d\n", &aux.num, aux.nome, &aux.telefone, &aux.idade);
			p[i].num = aux.num;
			p[i].nome[30] = aux.nome[30];
			p[i].telefone = aux.telefone;
			p[i].idade = aux.idade;
			i++;
		}
	*/
	
	fclose(fp);

	return true;
}

//Função para importar as informações das atividades de um ficheiro
bool ImportaInfoAtividade(infoAtividade a[], char* nomeFicheiro) {

	FILE* fp;
	infoAtividade aux;
	int i = 0;

	if ((fp = fopen(nomeFicheiro, "r")) == NULL) return false;
	else
	{
		while (fscanf(fp, "%d %s %s %d %d\n", &aux.idPrat, &aux.data, &aux.atividade, &aux.tempo, &aux.distancia) != EOF)
		{
			a[i].idPrat = aux.idPrat;
			a[i].data = aux.data;
			a[i].atividade = aux.atividade;
			a[i].tempo = aux.tempo;
			a[i].distancia = aux.distancia;

			i++;
		}
	}

	fclose(fp);

	return true;
}

//Função para importar as informações das atividades de um ficheiro
bool ImportaPlanoAtividade(planoAtividade p[], char* nomeFicheiro) {

	FILE* fp;
	planoAtividade aux;
	int i = 0;

	if ((fp = fopen(nomeFicheiro, "r")) == NULL) return false;
	else
	{
		while (fscanf(fp, "%d %s %s %s %s %s %d", &aux.numPrat, &aux.dataInicio, &aux.horaInicio, &aux.dataFim,
		&aux.horaFim, &aux.ativ, &aux.dist) != EOF)
		{
			p[i].numPrat = aux.numPrat;
			p[i].dataInicio = aux.dataInicio;
			p[i].horaInicio = aux.horaInicio;
			p[i].dataFim = aux.dataFim;
			p[i].horaFim = aux.horaFim;
			p[i].ativ = aux.ativ;
			p[i].dist = aux.dist;

			i++;
		}
	}

	fclose(fp);

	return true;
}


#pragma endregion
