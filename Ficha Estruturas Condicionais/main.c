/*****************************************************************//**
 * \file   main.c
 * \brief  
 * Resolu��o ficha de estruturas condicionais de Programa��o Imperativa
 * Prof Jo�o Carlos
 * \author Pedro Raphael
 * \date   October 2022
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	//Verifica se divis�vel por 3
#pragma region Questao_1
	int num1;
	
	printf("Informe um n�mero inteiro: \n");
	scanf("%d", &num1);

	if (num1 % 3 == 0)
	{
		printf("Esse n�mero � divis�vel por 3.\n");
	}
	else
	{
		printf("O n�mero informado n�o � divis�vel por 3.\n");
	}
	
#pragma endregion

	//Maior de dois n�meros
#pragma region Questao_2
	int num2;

	printf("Informe um n�mero inteiro: \n");
	scanf("%d", &num1);
	printf("Informe outro n�mero inteiro: \n");
	scanf("%d", &num2);

	if (num1 == num2)
	{
		printf("Os n�meros s�o iguais.\n");
	}
	if (num1 > num2)
	{
		printf("%d", num1);
	}
	else {
		printf("%d", num2);
	}
	
#pragma endregion

	//Maior de tr�s n�meors
#pragma region Questao_3
	int num3;

	printf("Informe um n�mero inteiro: \n");
	scanf("%d", &num1);
	printf("Informe outro n�mero inteiro: \n");
	scanf("%d", &num2);
	printf("Informe o terceiro n�mero inteiro:\n");
	scanf("%d", &num3);

	if (num1 == num2 && num2 == num3)
	{
		printf("Os n�meros s�o iguais.\n");
	}
	if (num1 > num2)
	{
		if (num1 > num3)
		{
			printf("%d", num1);
		}
		else
		{
			printf("%d", num3);
		}
	}
	if (num2 > num1)
	{
		if (num2 > num3)
		{
			printf("%d", num2);
		}
		else
		{
			printf("%d", num3);
		}
	}
		
#pragma endregion

	//Idade para a carta de condu��o
#pragma region Questao_4
	int idade, idadeFalta;

	printf("Informe a sua idade: \n");
	scanf("%d", &idade);

	if (idade >= 18)
	{
		printf("Voc� j� pode tirar a carta de condu��o.\n");
	}
	else
	{
		idadeFalta = idade - 18;
		printf("Faltam %d anos para voc� tirar a carta de condu��o.\n", idadeFalta);
	}

#pragma endregion

	//B�nus de Natal do colaborador
#pragma region Questao_5
	int antiguidade, filhos;

	printf("Informe sua idade: \n");
	scanf("%d", &idade);
	printf("informe sua antiguidade na empresa: \n");
	scanf("%d", &antiguidade);
	printf("Informe a quantidade de filhos: \n");
	scanf("%d", &filhos);

	int bonusIdade, bonusAntiguidade, bonusFilho, bonusTotal;

	if (idade > 45)
	{
		bonusIdade = (idade - 45) * 5;
	}

	if (antiguidade > 10)
	{
		bonusAntiguidade = ((antiguidade - 10) * 20) + 100;
	}
	else
	{
		bonusAntiguidade = antiguidade * 10;
	}

	if (filhos <= 3)
	{
		bonusFilho = filhos * 25;
	}
	else
	{
		bonusFilho = 75;
	}

	bonusTotal = bonusAntiguidade + bonusFilho + bonusIdade;

	printf("O valor do seu b�nus de Natal ser�: &d", bonusTotal);

#pragma endregion

	//Nota final do aluno
#pragma region Questao_6
	int codAluno, mediaExercicios;
	float n1, n2, n3, MA;

	printf("Qual o c�digo do aluno: \n");
	scanf("%d", &codAluno);
	printf("Informe a m�dia dos exerc�cios: \n");
	scanf("%d", &mediaExercicios);
	printf("Informe agora as 3 notas do aluno: \n");
	scanf("%f", &n1);
	scanf("%f", &n2);
	scanf("%f", &n3);

	MA = (n1 + (2 * n2) + (3 * n3) + mediaExercicios) / 7;

	if (MA >= 17)
	{
		printf("Aluno: %d\n", codAluno);
		printf("Notas: %f, %f, %f\n M�dia dos exerc�cios: %d\n", n1, n2, n3, mediaExercicios);
		printf("M�dia de aproveitamento: %f\n", MA);
		printf("Avalia��o final 'A'\n **APROVADO**\n");
	}
	if (MA >= 14 && MA < 17)
	{
		printf("Aluno: %d\n", codAluno);
		printf("Notas: %f, %f, %f\n M�dia dos exerc�cios: %d\n", n1, n2, n3, mediaExercicios);
		printf("M�dia de aproveitamento: %f\n", MA);
		printf("Avalia��o final 'B'\n **APROVADO**\n");
	}
	if (MA >= 10 && MA < 14)
	{
		printf("Aluno: %d\n", codAluno);
		printf("Notas: %f, %f, %f\n M�dia dos exerc�cios: %d\n", n1, n2, n3, mediaExercicios);
		printf("M�dia de aproveitamento: %f\n", MA);
		printf("Avalia��o final 'C'\n **APROVADO**\n");
	}
	if (MA >= 8 && MA < 10)
	{
		printf("Aluno: %d\n", codAluno);
		printf("Notas: %f, %f, %f\n M�dia dos exerc�cios: %d\n", n1, n2, n3, mediaExercicios);
		printf("M�dia de aproveitamento: %f\n", MA);
		printf("Avalia��o final 'D'\n **REPROVADO**\n");
	}
	if (MA < 8)
	{
		printf("Aluno: %d\n", codAluno);
		printf("Notas: %f, %f, %f\n M�dia dos exerc�cios: %d\n", n1, n2, n3, mediaExercicios);
		printf("M�dia de aproveitamento: %f\n", MA);
		printf("Avalia��o final 'E'\n **REPROVADO**\n");
	}

#pragma endregion

	//Aumento de sal�rio em fun��o do cargo
#pragma region Questao_7
	int codCargo;
	float salario, novoSalario, aumento;

	printf("Informe o c�digo do seu cargo: \n");
	scanf("%d", &codCargo);
	printf("Informe o seu sal�rio atual: \n");
	scanf("%f", &salario);

	if (codCargo == 1)
	{
		aumento = salario * 0.1;
	}
	if (codCargo == 2)
	{
		aumento = salario * 0.2;
	}
	if (codCargo == 3)
	{
		aumento = salario * 0.3;
	}
	else
	{
		aumento = salario * 0.4;
	}

	novoSalario = salario + aumento;
	printf("Sal�rio atual: %f\n Novo Sal�rio: %f\n Aumento de: %f\n", salario, novoSalario, aumento);

#pragma endregion

}
