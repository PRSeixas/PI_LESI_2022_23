/*****************************************************************//**
 * \file   Avaliacao.c
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


#pragma region FuncoesAvaliacaoAtividades
/**
 * .
 * Funcão para limpar memória
 * \param at
 */
void iniciaBaseAvaliacaoAtividade(avaliacaoAtividade at[]) {

	for (size_t i = 0; i < Linhas; i++)
	{
		at[i].codPart = 0;
	}
}

/**
 * .
 * Função para limpar lixo de memória
 * \param c
 */
void iniciaBaseCelula(Celula c[Linhas][TamCol]) {

	int i = 0;
	char vazio[50] = "";

	for (size_t i = 0; i < Linhas; i++)
	{
		for (size_t j = 0; j < TamCol; j++)
		{
			strcpy(c[i][j].dados, vazio);
		}
	}
}

/**
 * .
 * Função para preencher o array de avaliação de atividades com a informação da atividade e do praticante.
 * devolve a quantidade de avaliações preenchida.
 * \param at
 * \param p
 * \param a
 * \return
 */
int CompilarAvaliacaoAtividade(avaliacaoAtividade at[], pessoa p[], infoAtividade a[]) {

	infoAtividade aux[TamAtiv];
	IniciaBaseAtividade(aux);

	//avaliacaoAtividade at[Linhas];

	int iaux = 0;

	data dataInicio;
	data dataFim;

	printf("\n");
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
			aux[iaux] = a[i];
			iaux++;
		}
	}

	ordenarAtividadeCrescenteParticipantes(aux);

	int x = 0;
	char nome[50];

	for (size_t i = 0; i < TamAtiv; i++)
	{
		if (x != aux[i].idPrat)
		{
			at[x].codPart = aux[i].idPrat;
			for (size_t j = 0; j < TamPart; j++)
			{
				if (p[j].num == aux[i].idPrat)
				{
					strcpy(at[x].nome, p[j].nome);
					break;
				}
			}
			//strcpy(at[x].nome, nomePraticante(p, aux[i].idPrat));
			at[x].diaIni = dataInicio.dia;
			at[x].mesIni = dataInicio.mes;
			at[x].anoIni = dataInicio.ano;
			at[x].diaFim = dataFim.dia;
			at[x].mesFim = dataFim.mes;
			at[x].anoFim = dataFim.ano;
			at[x].totDist = totalDistanciaParticipante(aux[i].idPrat, aux);
			at[x].totTemp = totalTempoParticipante(aux[i].idPrat, aux);
			//desenvolver dia de maior esforço.
		}
		x = aux[i].idPrat;
	}

	return x;
}

/**
 * .
 * Função para gerar a tabela das avaliações e mostrar no ecrã.
 * \param at
 * \return
 */
bool gerarTabelaAvaliacaoAtividade(avaliacaoAtividade at[]) {

	Celula c[Linhas][TamCol];
	iniciaBaseCelula(c);

	gerarDadosAvaliacao(at);

	lerDadosAvaliacao(c);

	escreverDadosAvaliacao(c);

	return true;
}

/**
 * .
 * Consolidação dos dados para gerar a tabela de avaliação
 * \param at
 * \return
 */
bool gerarDadosAvaliacao(avaliacaoAtividade at[]) {

	FILE* fp = fopen("dados.txt", "w");
	FILE* fp2 = fopen("dados2.csv", "w");

	fprintf(fp, "NC;Praticante;Inicio;Fim;Total;Tempo\n");
	fprintf(fp2, "NC;Praticante;Inicio;Fim;Total;Tempo\n");

	for (size_t i = 0; i < Linhas; i++)
	{
		if (at[i].codPart != 0)
		{
			fprintf(fp, "%d;%s;%d-%d-%d;%d-%d-%d;%d;%d\n",
				at[i].codPart,
				at[i].nome,
				at[i].diaIni, at[i].mesIni, at[i].anoIni,
				at[i].diaFim, at[i].mesFim, at[i].anoFim,
				at[i].totDist,
				at[i].totTemp);

			fprintf(fp2, "%d;%s;%d-%d-%d;%d-%d-%d;%d;%d\n",
				at[i].codPart,
				at[i].nome,
				at[i].diaIni, at[i].mesIni, at[i].anoIni,
				at[i].diaFim, at[i].mesFim, at[i].anoFim,
				at[i].totDist,
				at[i].totTemp);
		}
	}

	fclose(fp);
	fclose(fp2);

	return true;
}

/**
 * .
 * Consolidação dos dados para gerar a tabela de avaliação
 * \param c
 * \return
 */
bool lerDadosAvaliacao(Celula c[Linhas][TamCol]) {

	FILE* fp;
	int i = 0;

	fp = fopen("dados.txt", "rt");

	if (fp != NULL)
	{
		do
		{
			fscanf(fp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
				c[i][0].dados,
				c[i][1].dados,
				c[i][2].dados,
				c[i][3].dados,
				c[i][4].dados,
				c[i][5].dados
			);
			i++;

		} while (!feof(fp));
		fclose(fp);
		return true;
	}
	return false;
}

/**
 * Função para escrerver os dados da tabela de avaliação no ecrã.
 *
 * \param c
 * \return
 */
bool escreverDadosAvaliacao(Celula c[Linhas][TamCol]) {

	int i = 0;
	char vazio[50] = "";

	for (size_t i = 0; i < Linhas; i++)
	{
		if (strcmp(c[i][0].dados, vazio) != 0)
		{
			printf("%s %s %s %s %s %s\n",
				c[i][0].dados,
				c[i][1].dados,
				c[i][2].dados,
				c[i][3].dados,
				c[i][4].dados,
				c[i][5].dados);
		}
	}
	return true;
}

#pragma endregion
