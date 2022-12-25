/*****************************************************************//**
 * \file   Pessoa.c
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

