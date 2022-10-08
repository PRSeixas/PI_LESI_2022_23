/*****************************************************************//**
 * \file   main.c
 * \brief  
 * Resolução ficha de estruturas condicionais de Programação Imperativa
 * Prof João Carlos
 * \author Pedro Raphael
 * \date   October 2022
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	//Verifica se divisível por 3
#pragma region Questao_1
	int num1;
	
	printf("Informe um número inteiro: \n");
	scanf("%d", &num1);

	if (num1 % 3 == 0)
	{
		printf("Esse número é divisível por 3.\n");
	}
	else
	{
		printf("O número informado não é divisível por 3.\n");
	}
	
#pragma endregion

	//Maior de dois números
#pragma region Questao_2
	int num2;

	printf("Informe um número inteiro: \n");
	scanf("%d", &num1);
	printf("Informe outro número inteiro: \n");
	scanf("%d", &num2);

	if (num1 == num2)
	{
		printf("Os números são iguais.\n");
	}
	if (num1 > num2)
	{
		printf("%d", num1);
	}
	else {
		printf("%d", num2);
	}
	
#pragma endregion

	//Maior de três númeors
#pragma region Questao_3
	int num3;

	printf("Informe um número inteiro: \n");
	scanf("%d", &num1);
	printf("Informe outro número inteiro: \n");
	scanf("%d", &num2);
	printf("Informe o terceiro número inteiro:\n");
	scanf("%d", &num3);

	if (num1 == num2 && num2 == num3)
	{
		printf("Os números são iguais.\n");
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

	//Idade para a carta de condução
#pragma region Questao_4
	int idade, idadeFalta;

	printf("Informe a sua idade: \n");
	scanf("%d", &idade);

	if (idade >= 18)
	{
		printf("Você já pode tirar a carta de condução.\n");
	}
	else
	{
		idadeFalta = idade - 18;
		printf("Faltam %d anos para você tirar a carta de condução.\n", idadeFalta);
	}

#pragma endregion

	//Bônus de Natal do colaborador
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

	printf("O valor do seu bônus de Natal será: &d", bonusTotal);

#pragma endregion

	//Nota final do aluno
#pragma region Questao_6
	int codAluno, mediaExercicios;
	float n1, n2, n3, MA;

	printf("Qual o código do aluno: \n");
	scanf("%d", &codAluno);
	printf("Informe a média dos exercícios: \n");
	scanf("%d", &mediaExercicios);
	printf("Informe agora as 3 notas do aluno: \n");
	scanf("%f", &n1);
	scanf("%f", &n2);
	scanf("%f", &n3);

	MA = (n1 + (2 * n2) + (3 * n3) + mediaExercicios) / 7;

	if (MA >= 17)
	{
		printf("Aluno: %d\n", codAluno);
		printf("Notas: %f, %f, %f\n Média dos exercícios: %d\n", n1, n2, n3, mediaExercicios);
		printf("Média de aproveitamento: %f\n", MA);
		printf("Avaliação final 'A'\n **APROVADO**\n");
	}
	if (MA >= 14 && MA < 17)
	{
		printf("Aluno: %d\n", codAluno);
		printf("Notas: %f, %f, %f\n Média dos exercícios: %d\n", n1, n2, n3, mediaExercicios);
		printf("Média de aproveitamento: %f\n", MA);
		printf("Avaliação final 'B'\n **APROVADO**\n");
	}
	if (MA >= 10 && MA < 14)
	{
		printf("Aluno: %d\n", codAluno);
		printf("Notas: %f, %f, %f\n Média dos exercícios: %d\n", n1, n2, n3, mediaExercicios);
		printf("Média de aproveitamento: %f\n", MA);
		printf("Avaliação final 'C'\n **APROVADO**\n");
	}
	if (MA >= 8 && MA < 10)
	{
		printf("Aluno: %d\n", codAluno);
		printf("Notas: %f, %f, %f\n Média dos exercícios: %d\n", n1, n2, n3, mediaExercicios);
		printf("Média de aproveitamento: %f\n", MA);
		printf("Avaliação final 'D'\n **REPROVADO**\n");
	}
	if (MA < 8)
	{
		printf("Aluno: %d\n", codAluno);
		printf("Notas: %f, %f, %f\n Média dos exercícios: %d\n", n1, n2, n3, mediaExercicios);
		printf("Média de aproveitamento: %f\n", MA);
		printf("Avaliação final 'E'\n **REPROVADO**\n");
	}

#pragma endregion

	//Aumento de salário em função do cargo
#pragma region Questao_7
	int codCargo;
	float salario, novoSalario, aumento;

	printf("Informe o código do seu cargo: \n");
	scanf("%d", &codCargo);
	printf("Informe o seu salário atual: \n");
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
	printf("Salário atual: %f\n Novo Salário: %f\n Aumento de: %f\n", salario, novoSalario, aumento);

#pragma endregion

}
