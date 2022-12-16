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

/**
 * .
 * Função para retornar a distância total das atividades de um participante.
 * \param codPart
 * \param a
 * \return 
 */
int totalDistanciaParticipante(int codPart, infoAtividade a[]) {

	int totalDistancia = 0;

	for (size_t i = 0; i < TamAtiv; i++)
	{
		if (a[i].idPrat == codPart)
		{
			totalDistancia = totalDistancia + a[i].distancia;
		}
	}

	return totalDistancia;
}

/**
 * .
 * Função para retornar o tempo total das atividades realizadas por um participante.
 * \param codPart
 * \param a
 * \return 
 */
int totalTempoParticipante(int codPart, infoAtividade a[]) {

	int totalTempo = 0;

	for (size_t i = 0; i < TamAtiv; i++)
	{
		if (a[i].idPrat == codPart)
		{
			totalTempo = totalTempo + a[i].tempo;
		}
	}
	return totalTempo;
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

	printf("A média do praticante %d sao: %d minutos.\n", codPrat, media);

	return media;
}

/**
 * .
 * Função para percorrer array de pessoas e devolver o nome de um praticante
 * \param p
 * \param codPrat
 * \return 
 */
char nomePraticante(pessoa p[], int codPrat) {

	char nome[50] = "";

	for (size_t i = 0; i < TamPart; i++)
	{
		if (p[i].num == codPrat)
		{
			strcpy(nome, p[i].nome);
			return p[i].nome;
		}
	}
	//return nome;
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

/**
 * .
 * Função para guardar a tabela gerada em um ficheiro binário.
 * Resolução da alinha 8.
 * \param at
 * \param qtdAvaliacoes
 * \return 
 */
bool guardarDadosAvaliacaoBinario(avaliacaoAtividade at[], int qtdAvaliacoes) {

	if (qtdAvaliacoes == 0)
	{
		printf("Tabela de avaliações não gerada. Não foi possível exportar os dados.\n");
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

/**
 * .
 * Função para comparar duas datas e devolve a menor, caso sejam iguais devolve a primeira informada, data a.
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
 * Função para apresentar MENU no ecrã do utilizador.
 * \return 
 */
int Menu() {
	int opcao = -1;

	do
	{
		printf("M E N U\n");
		printf("1 - Carregar dados dos participantes.\n");
		printf("2 - Carregar dados das informações das atividades.\n");
		printf("3 - Carregar dados dos planos de atividades.\n");
		printf("4 - Número praticante por atividade e período.\n");
		printf("5 - Listagem dos praticantes decrescente por atividade e período.\n");
		printf("6 - Plano de atividades por tipo, praticante e período.\n");
		printf("7 - Média do tempo de atividade para um praticante.\n");
		printf("8 - Gerar tabela avaliação atividades para um período.\n");
		printf("9 - Exportar a tabela de avaliações para um ficheiro binário.\n");
		printf("0 - SAIR.\n");
		printf("opção? ");
		scanf("%d", &opcao);

	} while (opcao < 0 || opcao > 9);

	return opcao;
}
#pragma endregion

#pragma region Desenvolvimento


#pragma endregion
