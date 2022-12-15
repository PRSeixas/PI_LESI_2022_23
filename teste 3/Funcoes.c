/*****************************************************************//**
 * \file   Funcoes.c
 * \brief  
 * 
 * \author pedro raphael pereira seixas
 * aluno: a21872
 * LESI-PL
 * \date   December 2022
 *********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

//Biblioteca nativa de C
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "Lista.h"


#pragma region FuncoesAtletas
/**
 * .
 * Fun��o para limpar o lixo de mem�ria do array.
 * \param a
 */
void iniciarBaseAtleta(atleta a[]) {

	int i = 0;
	char nome[50] = "";

	for (size_t i = 0; i < Tam; i++)
	{
		a[i].altura = 0;
		strcpy(a[i].nome, nome);
		a[i].codAtleta = 0;
	}
	return;
}

/**
 * .
 * Fun��o para guardar as informa��es de um atleta em um array de atletas.
 * \param a
 * \param posicao
 * \param altura
 * \param nome
 * \return 
 */
int guardarAtleta(atleta a[], int posicao, int altura, char nome[50]) {

	int cont = 0;

	
	a[posicao].codAtleta = posicao+1;
	strcpy(a[posicao].nome, nome);
	a[posicao].altura = altura;
	

	cont = posicao + 1;

	return cont;
}

/**
 * .
 * Fun��o para listar o nome de todos os atletas do array.
 * \param a
 */
void listarNomeTodosAtletas(atleta a[]) {
	
	int i = 0;

	printf("Lista de todos os atletas:\n");

	for (size_t i = 0; i < Tam; i++)
	{
		if (a[i].codAtleta != 0)
		{
			printf("Nome: %s\n", a[i].nome);
		}
	}
}

/**
 * .
 * Fun��o para listar as informa��es de um atleta, recebido c�digo por par�metro
 * \param a
 * \param codAtleta
 */
void listarUmAtleta(atleta a[], int codAtleta) {

	int i = 0;

	printf("Toda a informa��o do atleta solicitado:\n");

	for (size_t i = 0; i < Tam; i++)
	{
		if (a[i].codAtleta == codAtleta && a[i].codAtleta != 0)
		{
			printf("C�digo: %d | Nome: %s | Altura: %d\n", a[i].codAtleta, a[i].nome, a[i].altura);
		}
	}
}

/**
 * .
 * Fun��o para calcular a m�dia da altura dos atletas que est�o cadastrados no array.
 * \param a
 * \return 
 */
int alturaMediaAtletas(atleta a[]) {
	int i = 0;
	int soma = 0;
	int media = 0;
	int cont = 0;

	for (size_t i = 0; i < Tam; i++)
	{
		if (a[i].codAtleta !=0)
		{
			soma = soma + a[i].altura;
			cont++;
		}
	}

	media = soma / cont;

	printf("A altura m�dia dos atletas: %d", media);

	return media;
}

#pragma endregion

#pragma region OutrasFuncoes
/**
 * .
 * Fun��o que apresenta o menu de op��es no ecr�.
 * \return 
 */
int Menu() {
	int opcao = -1;

	do
	{
		printf("MENU\n");
		printf("1 - Registar atleta.\n");
		printf("2 - Listar todos os atletas.\n");
		printf("3 - Listar a informa��o apenas de um atleta.\n");
		printf("4 - M�dia da altura dos atletas.\n");
		printf("0 - Sair.\n");
		scanf("%d", &opcao);

	} while (opcao <=-1 && opcao >= 4);

	return opcao;
}

#pragma endregion
