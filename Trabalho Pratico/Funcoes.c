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

/**
 * .
 * Função para ordenar de forma crescente um vetor de informação de atividades por número de participante.
 * \param a
 * \return 
 */
bool ordenarAtividadeCrescenteParticipantes(infoAtividade a[]) {

	infoAtividade aux;
	int i = 0;
	int x = 0;

	for (size_t i = 0; i < TamAtiv; i++)
	{
		for (size_t x = i + 1; x < TamAtiv; x++)
		{
			if (a[i].idPrat > a[x].idPrat)
			{
				aux = a[i];
				a[i] = a[x];
				a[x] = aux;
			}
		}
	}
	return true;
}

/**
 * .
 * Função para ordenar de forma decrescente um vetor de informação de atividades por número de participante.
 * \param a
 * \return 
 */
bool ordenarAtividadesDecrescenteParticipantes(infoAtividade a[]) {

	infoAtividade aux;
	int i = 0;
	int x = 0;

	for (size_t i = 0; i < TamAtiv; i++)
	{
		for (size_t x = i + 1; x < TamAtiv; x++)
		{
			if (a[i].idPrat < a[x].idPrat)
			{
				aux = a[i];
				a[i] = a[x];
				a[x] = aux;
			}
		}
	}
	return true;
}

/**
 * .
 * Função para listar o número dos participantes de um vetor de informação de atividades
 * \param a
 * \param tam
 * \param ativ
 */
void listarNumeroParticipanteAtividade(infoAtividade a[], int tam, char ativ[15]) {
	int i = 0;

	printf("Listagem dos números dos participantes da atividade %s.\n", ativ);
	for (size_t i = 0; i < tam; i++)
	{
		printf("Número: %d \n", a[i].idPrat);

	}
}

/**
 * .
 * Funcão para listar o número dos participantes que realizaram determinada atividade, num determinado período.
 * Resolução da alinha 2.
 * \param a
 * \param tipo
 * \return 
 */
bool AtividadePorPeriodoParticipante(infoAtividade a[], char tipo[15]) {

	infoAtividade aux[TamAtiv];
	int iaux = 0;
	data dataInicio;
	data dataFim;

	printf("Data inicial:\n");
	dataInicio = lerData();
	printf("\nData final:\n");
	dataFim = lerData();
	printf("\n");

	for (size_t i = 0; i < TamAtiv; i++)
	{
		if (a[i].ano <= dataFim.ano && a[i].ano >= dataInicio.ano
			&& a[i].mes <= dataFim.mes && a[i].mes >= dataInicio.mes
			&& a[i].dia <= dataFim.dia && a[i].dia >= dataInicio.dia)
		{
			if (strcmp(a[i].atividade, tipo) == 0)
			{
				aux[iaux] = a[i];
				iaux++;
			}
		}
	}

	listarNumeroParticipanteAtividade(aux, iaux, tipo);

	return true;
}

/**
 * .
 * Função para listar participantes por ordem decrescente do número do partipante, que realizaram uma determinada atividade
 * num determinado período.
 * Resolução da alinha 3.
 * \param a
 * \param p
 * \param ativ
 * \return 
 */
int listarInfoAtividadeParticipanteDecrescente(infoAtividade a[], pessoa p[], char ativ[15]) {

	infoAtividade aux[TamAtiv];
	IniciaBaseAtividade(aux);

	int iaux = 0;

	data dataInicio;
	data dataFim;

	printf("Data inicial:\n");
	dataInicio = lerData();
	printf("\nData final:\n");
	dataFim = lerData();
	printf("\n");

	for (size_t i = 0; i < TamAtiv; i++)
	{
		if (a[i].ano <= dataFim.ano && a[i].ano >= dataInicio.ano
			&& a[i].mes <= dataFim.mes && a[i].mes >= dataInicio.mes
			&& a[i].dia <= dataFim.dia && a[i].dia >= dataInicio.dia)
		{
			if (strcmp(a[i].atividade, ativ) == 0)
			{
				aux[iaux] = a[i];
				iaux++;
			}
		}
	}

	ordenarAtividadesDecrescenteParticipantes(aux);

	printf("Listagem decrescente dos participantes da atividade %s.\n", ativ);

	int x = 0;
	int y = 0;

	for (size_t i = 0; i < TamAtiv; i++)
	{
		y = 0;
		for (size_t y = 0; y < TamPart; y++)
		{
			if (p[y].num == aux[i].idPrat && p[y].num != 0) {
				printf("Número: %d nome: %s\n", p[y].num, p[y].nome);
			}
		}
	}
	return 0;
}

/**
 * .
 * Função para calcular a média do tempo de um participante.
 * Resolução da alinha 5.
 * \param a
 * \param codPrat
 * \return 
 */
int calcularMediaPraticante(infoAtividade a[], int codPrat) {

	int soma = 0;
	int media = 0;
	int i = 0;
	int cont = 0;

	for (size_t i = 0; i < TamAtiv; i++)
	{
		if (a[i].idPrat == codPrat)
		{
			soma = soma + a[i].tempo;
			cont++;
		}
	}
	media = soma / cont;

	return media;
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

/**
 * .
 * Função para listar um vetor de plano de atividades.
 * \param p
 * \return 
 */
bool listarPlanoAtividade(planoAtividade p[]) {

	int i = 0;

	for (size_t i = 0; i < TamPlan; i++)
	{
		if (p[i].numPrat != 0)
		{
			printf("Praticante: %d;%d-%d-%d;%dh%d;%d-%d-%d;%dh%d;%s;%d\n",
				p[i].numPrat,
				p[i].diaIni, p[i].mesIni, p[i].anoIni,
				p[i].hIni, p[i].mIni,
				p[i].diaFim, p[i].mesFim, p[i].anoFim,
				p[i].hFim, p[i].mFim,
				p[i].ativ,
				p[i].dist);
		}
	}
	return true;
}

/**
 * .
 * Função para apresentar o plano de atividade para um determinado praticante, num determinado período, para um tipo de atividade
 * Resolução da alinha 4.
 * \param p
 * \param ativ
 * \param codPrat
 * \return 
 */
bool apresentarPlanoPorTipoPeriodoPraticante(planoAtividade p[], char ativ[15], int codPrat) {

	planoAtividade aux[TamPlan];
	iniciaBasePlano(aux);

	int iaux = 0;

	data dataInicio;
	data dataFim;

	printf("Data inicial:\n");
	dataInicio = lerData();
	printf("\nData final:\n");
	dataFim = lerData();
	printf("\n");

	for (size_t i = 0; i < TamPlan; i++)
	{
		if (p[i].anoIni >= dataInicio.ano && p[i].anoFim <= dataFim.ano
			&& p[i].mesIni >= dataInicio.mes && p[i].mesFim <= dataFim.mes
			&& p[i].diaIni >= dataInicio.dia && p[i].diaFim <= dataFim.dia)
		{
			if (strcmp(p[i].ativ, ativ) == 0)
			{
				if (p[i].numPrat == codPrat)
				{
					aux[iaux] = p[i];
					iaux++;
				}
			}
		}
	}

	listarPlanoAtividade(aux);

	return true;
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

#pragma region OutrasFuncoes
/**
 * .
 * Função para leitura do período de datas informada pelo utilizador via stdin
 * \return 
 */
data lerData() {

	data a;
	printf("Informe o dia (dd): ");
	scanf("%d", &a.dia); while ((getchar()) != '\n');
	printf("Informe o mes (mm): ");
	scanf("%d", &a.mes); while ((getchar()) != '\n');
	printf("Informe o ano (aaaa): ");
	scanf("%d", &a.ano); while ((getchar()) != '\n');

	return a;
}

#pragma endregion

#pragma region Desenvolvimento






#pragma endregion
