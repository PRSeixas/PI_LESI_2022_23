/*****************************************************************//**
 * \file   Main.c
 * \brief  
 * Resolução ficha de vetores de Programação Imperativa
 * Prof João Carlos
 * \author Pedro Raphael
 * \date   October 2022
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	#pragma region Questao_1
	//Operações sobre as notas de 80 alunos
	float notas[80];

	//Preenchimento do vetor com a nota dos 80 alunos
	for (int i = 0; i < 80; i++) {
		int aluno = i + 1;
		printf("Informe a nota do %dº aluno", aluno);
		scanf("%f", &notas[i]);		
	}

	//Variáveis para as operações solicitadas.
	float media = 0 , maiorNota = 0, menorNota = 0, auxMedia = 0;
	int auxMaior = 0, auxMenor = 0, contador = 0, posicaoMenor = 0;

	for (int i = 0; i < 80; i++)
	{
		auxMedia = auxMedia + notas[i];
		contador++;

		//Operação para salvar maior nota
		if (notas[i] > maiorNota) {
			maiorNota = notas[i];
		}
		//Operação para salvar menor nota e sua posição no array
		if (notas[i] < menorNota){}
		{
			menorNota = notas[i];
			posicaoMenor = i;
		}
		//Operação para contar quantidade de notas acima da média
		if (notas[i] >= 10) {
			auxMaior++;
		}
		//Operação para contar quantidade de ntoas abaixo da média
		if (notas[i] < 10) {
			auxMenor++;
		}
	}
	//Calculo da média.
	media = auxMedia / contador;

	#pragma endregion

	#pragma region Questao_2
	//Operações sobre array de 20 inteiros

	int seq[20];

	//Preenchimento do vetor com os 20 números inteiros.
	for (int i = 0; i < 20; i++)
	{
		int posicao = i + 1;
		printf("Informe o %dº número inteiro:", posicao);
		scanf("%d", &seq[i]);
	}

	//Mostrar no ecrã o conteúdo do array e sua posição
	for (int i = 0; i < 20; i++)
	{
		printf("O número da posição %d é: %d", i, seq[i]);
	}

	int seqAux[20];
	int aux = 20;

	//Operação para criar um vetor preenchido de forma inversa que o original.
	for (int i = 0; i < 20; i++)
	{
		aux--;
		seqAux[aux] = seq[i];
	}

	//Soma o valor de 10 a cada elemento do vetor
	for (int i = 0; i < 20; i++)
	{
		seq[i] = seq[i] + 10;
	}

	//Mostrar no ecrã o conteúdo do array e sua posição do final para o início
	for (int i = 20; i > 0; i--)
	{
		printf("O número da posição %d é: %d", i, seq[i]);
	}

	#pragma endregion

	#pragma region Questao_3
	//Sequência de inteiros

	int seqPositivos[20];

	//Preenchimento do vetor com 20 números positivos, incluindo teste se é positivo
	for (int i = 0; i < 20; i++)
	{
		int numero = i + 1;
		printf("Informe um %dº número inteiro positivo", numero);
		scanf("%d", &seqPositivos[i]);
		if (seqPositivos[i] <= 0)
		{
			printf("Você informou um número que não é positivo");
			while (seqPositivos[i] <= 0)
			{
				printf("Informe um número positivo:");
				scanf(seqPositivos[i]);
			}
		}
	}

	//Mostra no ecrã o vetor de forma inversa.
	int i = 20;
	while (seqPositivos[i] != 0);
	{
		i--;
		printf("O número da posição %d é: %d", i, seqPositivos[i]);
	}

	#pragma endregion

	#pragma region Questao_4
	//Somatório de inteiros positivos com o vetor da questão 3.

	int somaMenor10 = 0;
	//Operação para somar os números menores que 10 do vetor seqPositivos
	for (int i = 0; i < 20; i++)
	{
		if (seqPositivos[i] < 10) {
			somaMenor10 = somaMenor10 + seqPositivos[i];
		}
	}

	#pragma endregion

}
