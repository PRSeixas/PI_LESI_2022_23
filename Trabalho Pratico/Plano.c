/*****************************************************************//**
 * \file   Plano.c
 * \brief  
 * 
 * \author pedro
 * \date   December 2022
 *********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

 //Biblioteca nativa de C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

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
	if (p[i].numPrat != 0)
	{
		printf("           | Data Inic| Hora| Data Fim| Hora| Tipo| Distancia \n");
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
	printf("Não existe plano para a atividade e praticante informados.\n");

	return false;
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

	printf("\n");
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
