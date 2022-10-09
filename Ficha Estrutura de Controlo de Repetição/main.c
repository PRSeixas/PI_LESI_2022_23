/*****************************************************************//**
 * \file   main.c
 * \brief  
 * Resolu��o ficha de estruturas de controlo de repeti��o Programa��o Imperativa
 * Prof Jo�o Carlos
 * \author Pedro Raphael
 * \date   October 2022
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	//M�dia, maior e menor nota da turma, 10 alunos.
#pragma region Questoes_1_2_3
	int nota, somaNotas, media;
	int maiorNota = 0;
	int menorNota = 0;
	int i = 0;

	while (i < 10)
	{
		int aluno = i + 1;
		printf("Informa a nota do %d� aluno: \n", aluno);
		scanf("%d", &nota);
		somaNotas = somaNotas + nota;
		
		if (nota > maiorNota);
		{
			maiorNota = nota;
		}
		if (nota < menorNota);
		{
			menorNota = nota;
		}
		i++;
	}
	media = somaNotas / 10;

	printf("A m�dia dos 10 alunos �: %d", media);
	printf("A menor nota dos 10 alunos �: %d", menorNota);
	printf("A meior nota dos 10 alunos �: %d", maiorNota);

#pragma endregion

	//M�dia, maior e menor nota da turma, 20 alunos com n�mero de aluno.
#pragma region Questoes_4_5_6

	//Matriz para guardar as informa��es dos 20 alunos, coluna 1: N�mero do aluno, coluna 2: nota 1
	//Coluna 3: nota 2, Coluna 4: nota 3 e Coluna 5: m�dia.
	int alunos[20][5];

	int mediaAluno, codAluno, auxSoma;
	int i = 0;
	int j = 0;

	//Preenchimento da matriz
	while (i < 20)
	{
		printf("Informe o n�mero do aluno: \n");
		scanf("%d", &codAluno);
		alunos[i][j] = codAluno;

		j = 1;

		while (j < 4)
		{
			int x = j;
			printf("Informe a %d nota: \n");
			scanf("%d", &nota);
			auxSoma = auxSoma + nota;
			j++;
		}
		
		mediaAluno = auxSoma / 3;

		alunos[i][j] = mediaAluno;

		j = 0;
		auxSoma = 0;
		i++;
	}

	int mediaTurma, maiorMedia, menorMedia, alunoMenorMedia, alunoMaiorMedia, somaAuxMedia;

	menorMedia = alunos[0][4];
	maiorMedia = menorMedia;
	alunoMaiorMedia = alunos[0][0];
	alunoMenorMedia = alunoMaiorMedia;

	//Ciclo para procurar maior e menor m�dia com seus respectivos alunos e calcular m�dia da turma.
	for (int i = 0; i < 20; i++)
	{
		for (int j = 4; j < 5; j++) {
			somaAuxMedia = somaAuxMedia + alunos[i][j];
			if (alunos[i][j] > maiorMedia)
			{
				maiorMedia = alunos[i][j];
				alunoMaiorMedia = alunos[i][0];
			}
			if (alunos[i][j] < menorMedia)
			{
				menorMedia = alunos[i][j];
				alunoMenorMedia = alunos[i][0];
			}
		}
	}

	mediaTurma = somaAuxMedia / 20;

	int maiorNota, menorNota, alunoMenorNota, alunoMaiorNota;
	menorNota = alunos[0][1];
	maiorNota = alunos[0][1];
	alunoMenorNota = alunos[0][0];
	alunoMaiorNota = alunos[0][0];

	//Ciclo para procurar a maior e menor nota.
	for (int i = 0; i < 20; i++)
	{
		for (int j = 1; j < 4; j++) {
			if (menorNota < alunos[i][j])
			{
				menorNota = alunos[i][j];
				alunoMenorNota = alunos[i][0];
			}
			if (maiorNota > alunos[i][j])
			{
				maiorNota = alunos[i][j];
				alunoMaiorNota = alunos[i][0];
			}
		}
	}

#pragma endregion


	//Temperaturas (com e sem sentinela)
#pragma region Questoes_7_8
	int temperatura, maiorTemperatura, mediaTemperatura, auxSomaTemperatura;
	int qtdDia = 0;
	maiorTemperatura = 0;

	//Ciclo sem sentinela
	while (qtdDia < 30)
	{
		qtdDia++;
		printf("Informe a temperatura m�dia do %d dia: ", qtdDia);
		scanf("%d", &temperatura);
		auxSomaTemperatura = auxSomaTemperatura + temperatura;
		if (maiorTemperatura < temperatura)
		{
			maiorTemperatura = temperatura;
		}
	}
	mediaTemperatura = auxSomaTemperatura / qtdDia;

	qtdDia = 0;
	maiorTemperatura = 0;
	auxSomaTemperatura = 0;

	//Ciclo com sentinela, valor de refer�ncia 100 indicado no enunciado.
	while (temperatura < 100)
	{
		qtdDia++;
		printf("Informe a temperatura m�dia do %d dia: ", qtdDia);
		scanf("%d", &temperatura);
		if (temperatura < 100)
		{
			auxSomaTemperatura = auxSomaTemperatura + temperatura;
			if (maiorTemperatura < temperatura)
			{
				maiorTemperatura = temperatura;
			}
		}
	}
	mediaTemperatura = auxSomaTemperatura / qtdDia;

#pragma endregion

	//M�dia, max e min de sequ�ncia de inteiros terminada por zero "0"
#pragma region Questao_9
	int num, max, min, media, numAuxSoma, x;

	char parar = "n";
	x = 0;

	//Ciclo para ler a sequ�ncia de n�meros inteiros.
	while (parar != "s")
	{
		printf("Informe um n�mero inteiro terminado em zero '0': \n");
		scanf("%d", &num);
		if (num % 10 == 0)						//valida se o n�mero termina em zero
		{
			numAuxSoma = numAuxSoma + num;
			if (max < num)
			{
				max = num;
			}
			if (min < num)
			{
				min = num;
			}

			//Pergunta ao usu�rio se gostaria de continuar informando n�meros para a sequ�ncia
			printf("Escolha s para continuar ou n para parar.\n");
			scanf("%c", &parar);

			while (parar != "s" && parar != "n")	//valida a op��o escolhida
			{
				printf("Voc� digitou uma op��o invalida, digite s ou n.\n");
				scanf("%c", parar);
			}
			x++;
		}
		else
		{
			printf("Voc� informou um n�mero que n�o termina em zero.\n\n");
		}
	}
	media = numAuxSoma / x;

#pragma endregion

	//Auxiliar de compras
#pragma region Questao_10
	int saldo, compra, compraTotal, qtdCompra, valor;
	compraTotal = 0;

	printf("Qual o saldo dispon�vel para efetuar compras? \n");
	scanf("%d", &saldo);

	while (saldo > 0)
	{
		printf("Qual valor da compra? \n");
		scanf("%d", valor);
		if (saldo < valor)
		{
			printf("Voc� n�o tem saldo para essa efetuar essa compra, assistente encerrado.\n");
			break;
		}
		if (valor >= 0)
		{
			saldo = saldo - valor;
			compraTotal = compraTotal + valor;
			printf("Seu saldo restante �: %d", saldo);
			qtdCompra++;
		}
		else
		{
			printf("Voc� informou um valor negativo, n�o � permitido.\n");
		}		
	}
	printf("O valor total da sua compra foi: %d, com %d itens.\n", compraTotal, qtdCompra);
	printf("O seu saldo restante �: %d", saldo);

#pragma endregion
}
