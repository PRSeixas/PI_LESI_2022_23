/*****************************************************************//**
 * \file   main.c
 * \brief  
 * Resolução ficha matrizes de Programação Imperativa
 * Prof João Carlos
 * \author Pedro Raphael
 * \date   October 2022
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	//Problema da Enfermaria
#pragma region Questao_1

	int camas[24][4]; //24 linhas (hora), 4 colunas (camas na enfermaria)

	//Preenchimento da matriz
	for (int i = 0; i < 24; i++)
	{
		int hora = i + 1;
		for (int j = 0; j < 4; j++) {
			int cama = j + 1;
			printf("Informe a pulsação do paciente da cama %d na %dª hora: ", cama, hora);
			scanf("%d", &camas[i][j]);
		}
	}

	//Variáveis para calcular média e armazenar posições
	int media[4], auxSoma[4];
	int maiorMedia = 0;
	int maiorValor = 0;
	int posicaoMaiorMedia = 0;
	int posicaoMaiorValor = 0;
	int horaMaiorValor = 0;

	//Acumular valores para calculo da média.
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 4; j++) {
			auxSoma[j] = auxSoma[j] + camas[i][j];
			if (camas[i][j] > maiorValor)
			{
				maiorValor = camas[i][j];
				posicaoMaiorValor = j + 1;
				horaMaiorValor = i + 1;
			}
		}
	}

	for (int j = 0; j < 4; j++)
	{
		int paciente = j + 1;
		media[j] = auxSoma[j] / 24;
		printf("A pulsação média do paciente %d foi: %d\n", paciente, media[j]);
		if (media[j] > maiorMedia) {
			maiorMedia = media[j];
			posicaoMaiorMedia = j + 1;
		}
	}

	printf("O paciente com maior pulsação média encontra-se na cama: %d\n", posicaoMaiorMedia);
	printf("O valor mais elevado foi: %d na cama: %d e na hora: %d", maiorValor, posicaoMaiorValor, horaMaiorValor);

#pragma endregion

	//Problema dos parafusos
#pragma region Questao_2

	float parafusos[1000][2]; //Coluna 1 peso, coluna 2 comprimento.

	//Preenchimento da matriz com peso e comprimento de 1000 parafusos
	for (int i = 0; i < 1000; i++)
	{
		int linha = i + 1;
		for (int j = 0; j < 2; j++)
		{
			if (j == 0) {
				printf("Informe o peso do %dº parafuso: \n", linha);
				scanf("%f", &parafusos[i][j]);
			}
			if (j == 1)
			{
				printf("Informe o comprimento do %d parafuso: \n", linha);
				scanf("%f", &parafusos[i][j]);
			}
		}
	}

	//Variaveis para calcular médias.
	float pesoMedio, comprimentoMedio, somaPeso, somaComprimento;
	
	//Cálculo das médias.
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 2; j++) {
			if (j == 0) {
				somaPeso = somaPeso + parafusos[i][j];
			}
			if (j == 1)
			{
				somaComprimento = somaComprimento + parafusos[i][j];
			}
		}
	}
	pesoMedio = somaPeso / 1000;
	comprimentoMedio = somaComprimento / 1000;

	//Variáveis para calcular quantidade de parafusos com peso superior a média, identificar o mais curto e mais comprido
	int qtdPesoSuperiorMedia = 0;
	float maisComprido, maisCurto;

	//Busca pela quantidade de parafusos com peso superior a média, identificar o mais curto e mais comprido
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 2; j++) {
			if (j == 0) {
				if (parafusos[i][j] > pesoMedio)
				{
					qtdPesoSuperiorMedia++;
				}
			}
			if (j == 1)
			{
				if (parafusos[i][j] > maisComprido)
				{
					maisComprido = parafusos[i][j];
				}
				if (parafusos[i][j] < maisCurto)
				{
					maisCurto = parafusos[i][j];
				}
			}
		}
	}

	float difComprimento, percentagem;

	percentagem = qtdPesoSuperiorMedia / 1000;
	difComprimento = maisComprido - maisCurto;

#pragma endregion

	//Menor elemento da diagonal principal
#pragma region Questao_4

	int diagPrincipal[6][6];

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++) {
			printf("Informe um número inteiro: \n");
			scanf("%d", &diagPrincipal[i][j]);
		}
	}

	int i = 0;
	int j = 0;
	int posicaoi, posicaoj;
	int menorElemento = diagPrincipal[i][j];

	while (i < 6 && j < 6)
	{
		i++;
		j++;
		if (menorElemento < diagPrincipal[i][j]) {
			menorElemento = diagPrincipal[i][j];
			posicaoi = i;
			posicaoj = j;
		}
	}

#pragma endregion

	//Contagem de ocorrências numa matriz
#pragma region Questao_5
	int A, contador;
	int M[30][30];

	printf("Informe um número inteiro A: \n");
	scanf("%d", &A);

	//Preenchimento da matriz
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++) {
			printf("Informe um número inteiro para compor a matriz: \n");
			scanf("%d", &M[i][j]);
		}
	}
	//Contador de ocorrências iguais
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++) {
			if (M[i][j] == A)
			{
				contador++;
			}
		}
	}

#pragma endregion

}
