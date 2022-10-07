/*****************************************************************//**
 * \file   Main.c
 * \brief  
 * Resolu��o ficha de vetores de Programa��o Imperativa
 * Prof Jo�o Carlos
 * \author Pedro Raphael
 * \date   October 2022
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	#pragma region Questao_1
	//Opera��es sobre as notas de 80 alunos
	float notas[80];

	//Preenchimento do vetor com a nota dos 80 alunos
	for (int i = 0; i < 80; i++) {
		int aluno = i + 1;
		printf("Informe a nota do %d� aluno", aluno);
		scanf("%f", &notas[i]);		
	}

	//Vari�veis para as opera��es solicitadas.
	float media = 0 , maiorNota = 0, menorNota = 0, auxMedia = 0;
	int auxMaior = 0, auxMenor = 0, contador = 0, posicaoMenor = 0;

	for (int i = 0; i < 80; i++)
	{
		auxMedia = auxMedia + notas[i];
		contador++;

		//Opera��o para salvar maior nota
		if (notas[i] > maiorNota) {
			maiorNota = notas[i];
		}
		//Opera��o para salvar menor nota e sua posi��o no array
		if (notas[i] < menorNota){}
		{
			menorNota = notas[i];
			posicaoMenor = i;
		}
		//Opera��o para contar quantidade de notas acima da m�dia
		if (notas[i] >= 10) {
			auxMaior++;
		}
		//Opera��o para contar quantidade de ntoas abaixo da m�dia
		if (notas[i] < 10) {
			auxMenor++;
		}
	}
	//Calculo da m�dia.
	media = auxMedia / contador;

	#pragma endregion

	#pragma region Questao_2
	//Opera��es sobre array de 20 inteiros

	int seq[20];

	//Preenchimento do vetor com os 20 n�meros inteiros.
	for (int i = 0; i < 20; i++)
	{
		int posicao = i + 1;
		printf("Informe o %d� n�mero inteiro:", posicao);
		scanf("%d", &seq[i]);
	}

	//Mostrar no ecr� o conte�do do array e sua posi��o
	for (int i = 0; i < 20; i++)
	{
		printf("O n�mero da posi��o %d �: %d", i, seq[i]);
	}

	int seqAux[20];
	int aux = 20;

	//Opera��o para criar um vetor preenchido de forma inversa que o original.
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

	//Mostrar no ecr� o conte�do do array e sua posi��o do final para o in�cio
	for (int i = 20; i > 0; i--)
	{
		printf("O n�mero da posi��o %d �: %d", i, seq[i]);
	}

	#pragma endregion

	#pragma region Questao_3
	//Sequ�ncia de inteiros

	int seqPositivos[20];

	//Preenchimento do vetor com 20 n�meros positivos, incluindo teste se � positivo
	for (int i = 0; i < 20; i++)
	{
		int numero = i + 1;
		printf("Informe um %d� n�mero inteiro positivo", numero);
		scanf("%d", &seqPositivos[i]);
		if (seqPositivos[i] <= 0)
		{
			printf("Voc� informou um n�mero que n�o � positivo");
			while (seqPositivos[i] <= 0)
			{
				printf("Informe um n�mero positivo:");
				scanf(seqPositivos[i]);
			}
		}
	}

	//Mostra no ecr� o vetor de forma inversa.
	int i = 20;
	while (seqPositivos[i] != 0);
	{
		i--;
		printf("O n�mero da posi��o %d �: %d", i, seqPositivos[i]);
	}

	#pragma endregion

	#pragma region Questao_4
	//Somat�rio de inteiros positivos com o vetor da quest�o 3.

	int somaMenor10 = 0;
	//Opera��o para somar os n�meros menores que 10 do vetor seqPositivos
	for (int i = 0; i < 20; i++)
	{
		if (seqPositivos[i] < 10) {
			somaMenor10 = somaMenor10 + seqPositivos[i];
		}
	}

	#pragma endregion

}
