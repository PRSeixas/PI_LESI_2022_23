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
 */
void IniciaBasePessoa(pessoa p[]) {

	int i = 0;

	for (size_t i = 0; i < TamPart; i++)
	{
		char vazio[50] = "";

		p[i].num = 0;
		strcpy(p[i].nome, vazio);
		p[i].telefone = 0;
		p[i].idade = 0;
	}
}

#pragma endregion

#pragma region FuncoesAtividades
/**
 * .
 * 
 * \param a
 */
void IniciaBaseAtividade(infoAtividade a[]) {

	int i = 0;
	char vazio[15] = "";

	for (size_t i = 0; i < TamAtiv; i++)
	{
		a[i].idPrat = 0;
		a[i].dia = 0;
		a[i].mes = 0;
		a[i].ano = 0;
		strcpy(a[i].atividade, vazio);
		a[i].tempo = 0;
		a[i].distancia = 0;
	}
}

#pragma endregion

#pragma region FuncoesPlano
/**
 * .
 * 
 * \param p
 */
void iniciaBasePlano(planoAtividade p[]) {

	int i = 0;
	char vazio[15] = "";

	for (size_t i = 0; i < TamPlan; i++)
	{
		p[i].numPrat = 0;
		p[i].diaIni = 0;
		p[i].mesIni = 0;
		p[i].anoIni = 0;
		p[i].hIni = 0;
		p[i].mIni = 0;
		p[i].diaFim = 0;
		p[i].mesFim = 0;
		p[i].anoFim = 0;
		p[i].hFim = 0;
		p[i].mFim = 0;
		strcpy(p[i].ativ, vazio);
		p[i].dist = 0;
	}
}

#pragma endregion

#pragma region FuncoesManipulacaoDados 
/**
 * .
 * Função para importar os dados dos participantes de um ficheiro 
 * \param p vetor de pessoas (participantes)
 * \param nomeFicheiro
 * \return -1 caso erro ou quantidade de participantes
 */
int ImportaDadosParticipantes(pessoa p[], char* nomeFicheiro) {

	FILE* fp;
	int i = 0;

	fp = fopen(nomeFicheiro, "rt");

	//Verificar se o ficheiro é vazio
	if (fp != NULL)
	{
		do
		{
			fscanf(fp, "%d;%[^;];%d;%d\n", &p[i].num, p[i].nome, &p[i].telefone, &p[i].idade);
			i++;

		} while (!feof(fp));
		fclose(fp);

		return i;
	}
	else return -1;
}

/**
 * .
 * Função para importar as informações das atividades de um ficheiro
 * \param a vetor para informação das atividades
 * \param nomeFicheiro
 * \return true caso preenchimento com sucesso ou false se o ficheiro ofr vazio.
 */
bool ImportaInfoAtividade(infoAtividade a[], char* nomeFicheiro) {

	FILE* fp;
	int i = 0;

	fp = fopen(nomeFicheiro, "rt");

	if (fp != NULL)
	{
		do
		{
			fscanf(fp, "%d;%d-%d-%d;%[^;];%d;%d\n",
				&a[i].idPrat,
				&a[i].dia, &a[i].mes, &a[i].ano,
				a[i].atividade,
				&a[i].tempo,
				&a[i].distancia);
			i++;

		} while (!feof(fp));
		fclose(fp);
		return true;
	}
	else return false;
}

/**
 * .
 * Função para importar as informações das atividades de um ficheiro
 * \param p vetor de planos de atividades
 * \param nomeFicheiro
 * \return true caso preenchimento com sucesso ou false se o ficheiro ofr vazio.
 */
bool ImportaPlanoAtividade(planoAtividade p[], char* nomeFicheiro) {

	FILE* fp;
	int i = 0;

	fp = fopen(nomeFicheiro, "rt");

	if (fp != NULL)
	{
		do
		{
			fscanf(fp, "%d;%d-%d-%d;%dh%d;%d-%d-%d;%dh%d;%[^;];%d",
				&p[i].numPrat,
				&p[i].diaIni, &p[i].mesIni, &p[i].anoIni,
				&p[i].hIni, &p[i].mIni,
				&p[i].diaFim, &p[i].mesFim, &p[i].anoFim,
				&p[i].hFim, &p[i].mFim,
				p[i].ativ,
				&p[i].dist);
			i++;

		} while (!feof(fp));
		fclose(fp);
		return true;
	}
	else return false;
}
#pragma endregion


#pragma region Desenvolvimento


#pragma endregion
