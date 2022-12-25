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


#pragma region FuncoesManipulacaoDados 
/**
 * .
 * Fun��o para importar os dados dos participantes de um ficheiro 
 * \param p vetor de pessoas (participantes)
 * \param nomeFicheiro
 * \return -1 caso erro ou quantidade de participantes
 */
int ImportaDadosParticipantes(pessoa p[], char* nomeFicheiro) {

	FILE* fp;
	int i = 0;

	fp = fopen(nomeFicheiro, "rt");

	//Verificar se o ficheiro � vazio
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
 * Fun��o para importar as informa��es das atividades de um ficheiro
 * \param a vetor para informa��o das atividades
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
 * Fun��o para importar as informa��es das atividades de um ficheiro
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

/**
 * .
 * Fun��o para guardar a tabela gerada em um ficheiro bin�rio.
 * Resolu��o da alinha 8.
 * \param at
 * \param qtdAvaliacoes
 * \return 
 */
bool guardarDadosAvaliacaoBinario(avaliacaoAtividade at[], int qtdAvaliacoes) {

	if (qtdAvaliacoes == 0)
	{
		printf("Tabela de avalia��es n�o gerada. N�o foi poss�vel exportar os dados.\n");
		return false;
	}
	else
	{
		FILE* fp = fopen("dados.bin", "wb");

		if (fp != NULL)
		{
			fwrite(at, sizeof(avaliacaoAtividade), qtdAvaliacoes, fp);
			fclose(fp);
			return true;
		}
		return false;
	}
}

#pragma endregion

#pragma region OutrasFuncoes
/**
 * .
 * Fun��o para leitura do per�odo de datas informada pelo utilizador via stdin
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

/**
 * .
 * Fun��o para comparar duas datas e devolve a menor, caso sejam iguais devolve a primeira informada, data a.
 * \param a
 * \param b
 * \return 
 */
/*
data compararMenorData(data a, data b) {

	if (a.ano < b.ano) return a;
	if (a.ano > b.ano) return b;
	
	if (a.ano == b.ano && a.mes < b.mes) return a;
	if (a.ano == b.ano && a.mes > b.mes) return b;
	
	if (a.ano == b.ano && a.mes == b.mes)
	{
		if (a.dia <= b.dia) return a;
		else return b;
	}
}
*/

/**
 * .
 * Fun��o para apresentar MENU no ecr� do utilizador.
 * \return 
 */
int Menu() {
	int opcao = -1;

	do
	{
		printf("M E N U\n");
		printf("1 - Carregar dados dos participantes.\n");
		printf("2 - Carregar dados das informa��es das atividades.\n");
		printf("3 - Carregar dados dos planos de atividades.\n");
		printf("4 - N�mero praticante por atividade e per�odo.\n");
		printf("5 - Listagem dos praticantes decrescente por atividade e per�odo.\n");
		printf("6 - Plano de atividades por tipo, praticante e per�odo.\n");
		printf("7 - M�dia do tempo de atividade para um praticante.\n");
		printf("8 - Gerar tabela avalia��o atividades para um per�odo.\n");
		printf("9 - Exportar a tabela de avalia��es para um ficheiro bin�rio.\n");
		printf("0 - SAIR.\n");
		printf("op��o? ");
		scanf("%d", &opcao);

	} while (opcao < 0 || opcao > 9);

	return opcao;
}
#pragma endregion

#pragma region Desenvolvimento


#pragma endregion
