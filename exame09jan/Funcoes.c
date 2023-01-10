/*****************************************************************//**
 * \file   Funcoes.c
 * \brief  
 * 
 * \author pedro
 * \date   January 2023
 *********************************************************************/

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "Lista.h"


#pragma region DadosImovel

/**
 * Func��o para a resolu��o da alinha a.
 * 
 * \param cod
 * \return 
 */
imovel lerDados(int cod) {
	imovel aux;
	char morada[50];
	char descricao[100] = "";
	aux.cod = cod;

	printf("Informe o tipo do im�vel, 0 - morada ou 1 - apartamento: \n");
	scanf("%d", &aux.tipoImovel);
	printf("Informe a morada: \n");
	scanf("%s", &morada);
	strcpy(aux.morada, morada);
	print("Deseja informar alguma descri��o? \n");
	scanf("%s", &descricao);
	strcpy(aux.descricao, descricao);
	printf("Qual o pre�o de venda? \n");
	scanf("%f", &aux.precoVenda);
	printf("Qual a �rea do im�vel? \n");
	scanf("%f", &aux.area);
	printf("Qual o NIF do propriet�rio? \n");
	scanf("%d", &aux.NIF);

	return aux;
}

/**
 * Fun��o para a resolu��o da alinha a.
 * 
 * \param a
 * \param im
 * \param cod
 * \return 
 */
int inserirImovel(imovel a, imovel im[], int cod) {
	int x = cod;

	im[x] = a;
	x++;

	return x;
}

/**
 * Fun��o para limpar lixo de mem�ria.
 * 
 * \param im
 */
void iniciaPlanoDados(imovel im[]) {

	char vazio[50] = "";
	char vazio2[100] = "";

	for (int i = 0; i < registo; i++)
	{
		im[i].cod = -1;
		im[i].area = 0;
		im[i].NIF = 0;
		strcpy(im[i].morada, vazio);
		strcpy(im[i].descricao, vazio2);
		im[i].precoVenda = 0;
		im[i].tipoImovel = -1;
	}
}

/**
 * Resolu��o alinha b.
 * 
 * \param im
 * \param preco
 */
void listarImoveisSuperior100(imovel im[], float preco) {

	for (int i = 0; i < registo; i++)
	{
		if (im[i].cod != -1)
		{
			if (im[i].precoVenda < preco && im[i].area > 100)
			{
				printf("C�digo imov�l: %d\n�rea: %f\nPre�o: %f", im[i].cod, im[i].area, im[i].precoVenda);
				if (im[i].tipoImovel == 0)
				{
					printf("Tipo: moradia\n");
				}
				if (im[i].tipoImovel == 1)
				{
					printf("Tipo: apartamento\n");
				}
			}
		}
	}
}

/**
 * Func�o necess�ria na resolucao da alinha c.
 * 
 * \param im
 */
void ordenarCrescentePreco(imovel im[]) {

	imovel aux;

	for (int i = 0; i < registo; i++)
	{
		for (int j = i; j < registo; j++)
		{
			if (im[i].precoVenda > im[j].precoVenda)
			{
				aux = im[i];
				im[i] = im[j];
				im[j] = aux;
			}
		}
	}
}

/**
 * Resolu��o alinha c.
 * 
 * \param im
 */
void listarTodosImoveisCrecentePreco(imovel im[]) {

	imovel aux[] = im;

	ordenarCrescentePreco(aux);

	for (int i = 0; i < registo; i++)
	{
		if (aux[i].cod != -1)
		{
			printf("C�digo imov�l: %d\n�rea: %f\nPre�o: %f", aux[i].cod, aux[i].area, aux[i].precoVenda);
			if (aux[i].tipoImovel == 0)
			{
				printf("Tipo: moradia\n");
			}
			if (aux[i].tipoImovel == 1)
			{
				printf("Tipo: apartamento\n");
			}
		}
	}
}

/**
 * Resolu��o da alinha d.
 * Fun��o devolve apenas a quantiadde de registo dos im�veis do tipo moradia
 * 
 * \param im
 * \return 
 */
int quantidadeRegistoMoradia(imovel im[]) {
	int qtd = 0;

	for (int i = 0; i < registo; i++)
	{
		if (im[i].tipoImovel == 0 && im[i].cod != -1)
		{
			qtd++;
		}
	}
	return qtd;
}

/**
 * Resolu��o alinha e.
 * 
 * \param im
 * \param nif
 * \return 
 */
float valorTotalVendaPorNIF(imovel im[], int nif) {

	float total = 0;

	for (int i = 0; i < registo; i++)
	{
		if (im[i].cod != -1 && im[i].NIF == nif)
		{
			total = total + im[i].precoVenda;
		}
	}
	return total;
}
#pragma endregion

#pragma region OutraFuncoes
/**
 * Apresenta��o do Menu de op��es no ecr�.
 * 
 * \return 
 */
int MENU() {
	int op = -1;

	do
	{
		printf("*********** M E N U ***********\n");
		printf("1 - Registar im�vel.\n");
		printf("2 - Listar im�veis existe superior a 100m2, para determinado pre�o\n");
		printf("3 - C�digos dos im�veis por ordem crescente de pre�o\n");
		printf("4 - Quantidade de moradias registradas\n");
		printf("5 - Valor total de venda por NIF\n");
		printf("0 - Sair.\n");
		scanf("%d", &op);
	} while (op < 5 || op > -1);

	return op;
}


#pragma endregion

