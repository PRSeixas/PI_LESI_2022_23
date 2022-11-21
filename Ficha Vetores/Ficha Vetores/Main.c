/*****************************************************************//**
 * \file   Main.c
 * \brief  
 * Resolu��o ficha de vetores de Programa��o Imperativa
 * Prof Jo�o Carlos
 * \author Pedro Raphael
 * \date   October 2022
 *********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#pragma region FuncoesProf
#define TAM 5 // defini��o de uma constante

 // Vari�veis globais
float turma[TAM];

// Procedimento Leitura
void leitura()
{
	for (int i = 0; i < TAM; i++)
	{
		printf("Nota do aluno %d\n", i + 1);
		scanf("%f", &turma[i]);
	}
}

// Procedimento para escrita do conte�do do array turma na consola
void escrita(float turma[])
{
	for (int i = 0; i < TAM; i++)
		printf("%.2f ", turma[i]);
}

// Defini��o de uma constante
//#define TAM 10

typedef int idade;
typedef char nome[50];

typedef struct
{
	int numero;
	nome nm;
	int ano;
	float nota;
	idade id;
} Aluno;

// Fun��o para obten��o da m�dia das notas constanres no array passado por par�metro
float media(float turma[])
{
	float soma = 0;
	for (int i = 0; i < TAM; i++)
		soma = soma + turma[i]; // soma+=turma[i];
	return(soma / TAM);
}

int supMedia(float turma[])
{
	float mediaTurma = media(turma);
	int contador = 0;
	for (int i = 0; i < TAM; i++)
		if (turma[i] > mediaTurma) contador++;
	return(contador);
}


int supMedia2(float turma[], float media)
{
	int contador = 0;
	for (int i = 0; i < TAM; i++)
		if (turma[i] > media) contador++;
	return(contador);
}

// Fun��o para obten��o da nota mais alta
float maior(float turma[])
{
	float aux = 0;
	for (int i = 0; i < TAM; i++)
		if (turma[i] > aux) aux = turma[i];
	return(aux);
}

int qtMaior(float turma[])
{
	int contador = 0;
	float aux = maior(turma);
	for (int i = 0; i < TAM; i++)
		if (turma[i] == aux) contador++;
	return(contador);
}

// Procedimento para obten��o da nota mais alta
void menor(float turma[])
{
	float aux = turma[0];
	for (int i = 0; i < TAM; i++)
		if (turma[i] < aux) aux = turma[i];
	for (int i = 0; i < TAM; i++)
		if (turma[i] == aux) printf("indice: %d\n", i);
}

// Guardar as notas da turma no ficheiro dados.txt
int escrever(float turma[])
{
	FILE* fp;
	fp = fopen("dados.txt", "w"); // r (read) a (append)
	if (fp != NULL)
	{
		for (int i = 0; i < TAM; i++)
			fprintf(fp, "Aluno %d: %.2f\n", i + 1, turma[i]);
		fclose(fp);
		return(1);
	}
	else return(0);
}
#pragma endregion


int main() {
	setlocale(LC_ALL, "Portuguese");

#pragma region ExemplosProf
	#pragma region Ex1 VarGlobal
	//Ex1 VarGlobal
	leitura();
	for (int i = 0; i < TAM; i++)
		printf("%.2f ", turma[i]);

	#pragma endregion

	#pragma region Ex1 VarLocal
	//Ex1 VarLocal
	int A[10]; // Defini��o de um array de inteiros 
	// (10 inteiros no m�ximo em cada instante de tempo)

	A[0] = 20;
	A[1] = 10;
	A[2] = 11;
	A[3] = 14;
	A[4] = 10;
	A[5] = 1;
	A[6] = 10;
	A[7] = 20;
	A[8] = 22;
	A[9] = 30;

	for (int i = 0; i <= 9; i++)
		printf("%d ", A[i]);

	#pragma endregion

	#pragma region Ex1 VarLocal2
	//Ex1 VarLocal2
	float turma[TAM]; // defini��o de uma vari�vel local
	leitura(turma); // invoca��o do procedimento leitura com passagem por par�metro
	// do endere�o de mem�ria do array turma
	escrita(turma); // invoca��o do procedimento escrita com passagem por par�metro
	// do endere�o de mem�ria do array turma

	#pragma endregion

	#pragma region Ex3
	int i, valor, soma = 0;
	int sequencia[20];

	for (i = 1; i <= 20; i++)
	{
		do scanf("%d", &valor); while (valor < 0);
		sequencia[i - 1] = valor;
	}

	for (i = 19; i >= 0; i--)
		printf("%d ", sequencia[i]);



	for (i = 0; i <= 19; i++)
	{
		if (sequencia[i] < 10) soma += sequencia[i];
	}
	printf("%d\n", soma);

	#pragma endregion

	#pragma region Ex5
	//Ex5
	int i, valor, soma = 0, contador = 0, soma1 = 0;
	int sequencia[TAM];

	Aluno a;
	a.numero = 1234;
	strcpy(a.nm, "Joao");
	a.ano = 1;
	a.nota = 15;
	a.id = 18;

	printf("Nome %s\n", a.nm);

	printf("int %ld\n", sizeof(int));
	printf("float %ld\n", sizeof(float));
	printf("char %ld\n", sizeof(char));
	printf("array sequencia %ld\n", sizeof(sequencia) / sizeof(int));
	printf("Aluno %ld\n", sizeof(Aluno));
	printf("Aluno %ld\n", sizeof(a));


	i = 0;
	do
	{
		do scanf("%d", &valor);
		while (valor < 0);
		if (valor > 0) {
			sequencia[i] = valor;
			contador++;
		}
		i++;
	} while ((valor != 0) && (i < TAM));


	for (i = 0; i < contador; i++)
	{
		printf("%d ", sequencia[i]);
		if (sequencia[i] < 10) soma1 += sequencia[i];
	}
	printf("\n");
	printf("Soma dos valores inferiores a 10: %d\n", soma1);

	for (i = contador - 1; i >= 0; i--)
		printf("sequencia[%d]=%d\n", i, sequencia[i]);

	#pragma endregion

	#pragma region Ex1 Varlocal v2
	float turma[TAM]; // defini��o de uma vari�vel local
	leitura(turma); // invoca��o do procedimento leitura com passagem por par�metro
	// do endere�o de mem�ria do array turma
	escrita(turma); // invoca��o do procedimento escrita com passagem por par�metro
	// do endere�o de mem�ria do array turma

	float resultado = media(turma);
	printf("Media da turma: %.2f\n", resultado);
	printf("Quantidade de supMedia: %d", supMedia(turma));
	printf("Quantidade de supMedia: %d", supMedia2(turma, resultado));
	int res1 = escrever(turma);

	#pragma endregion


#pragma endregion


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
		//Opera��o para contar quantidade de notas abaixo da m�dia
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
