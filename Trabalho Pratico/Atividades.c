/*****************************************************************//**
 * \file   Atividades.c
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

	if (a[i].idPrat != 0)
	{
		printf("Listagem dos números dos participantes da atividade %s.\n", ativ);
		for (size_t i = 0; i < tam; i++)
		{
			printf("Número: %d \n", a[i].idPrat);

		}
		printf("\n");
	}
	else printf("Sem participantes para a atividade e período escolhido.\n\n");
}

/**
 * .
 * Função para listar o número e nome dos participantes de um vetor de informação de atividades
 * \param p
 * \param a
 * \return
 */
bool listarNumeroNomeParticipanteAtividade(pessoa p[], infoAtividade a[]) {

	int i = 0;
	int y = 0;

	if (a[i].idPrat != 0)
	{
		for (size_t i = 0; i < TamAtiv; i++)
		{
			y = 0;
			for (size_t y = 0; y < TamPart; y++)
			{
				if (p[y].num == a[i].idPrat && p[y].num != 0) {
					printf("Número: %d nome: %s\n", p[y].num, p[y].nome);
				}
			}
		}
		printf("\n");

		return true;
	}
	else printf("Sem participantes para a atividade e período escolhido.\n\n");

	return false;
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
int InfoAtividadeParticipanteDecrescente(infoAtividade a[], pessoa p[], char ativ[15]) {

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

	listarNumeroNomeParticipanteAtividade(p, aux);

	return 0;
}

#pragma endregion
