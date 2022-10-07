/*****************************************************************//**
 * \file   main.c
 * \brief  
 * Resolução ficha de fundamentos de Programação Imperativa
 * Prof João Carlos
 * \author Pedro Raphael
 * \date   October 2022
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");

	//Escrever mensagens na consola
	#pragma region Questao_1
	printf("Este é o meu primeiro programa!!\n");
	printf("E esta a segunda frase.\n");
	printf("Terceira frase...!");
	printf("\n");

	#pragma endregion

	//Ler / Escrever na consola
	#pragma region Questoes_2_3
	
	int idade = 0;
	char nome;
	
	printf("Qual seu nome? \n");
	scanf("%c", &nome);
	printf("Qual sua idade? \n");
	scanf("%d", &idade);

	//Segunda parte, dois números inteiros e escrever sua soma.
	int x, y, soma;

	printf("Informe o valor do primeiro número: \n");
	scanf("%d", &x);
	printf("Informe o valor do segundo número: \n");
	scanf("%d", &y);
	soma = x + y;
	printf("A soma dos dois números: %d", soma);
	printf("\n");
	
	#pragma endregion

	//Área e perímetro de rectângulo
	#pragma region Questao_4
	int lado1, lado2, area, perimetro;

	printf("Qual a valor do primeiro lado do rectângulo?\n");
	scanf("%d", &lado1);
	printf("Qual a valor do segundo lado do rectângulo?\n");
	scanf("%d", &lado2);
	area = lado1 * lado2;
	perimetro = (2 * lado1) + (2 * lado2);
	printf("A área do rectângulo é: %d e seu perímetro %d.", area, perimetro);
	printf("\n");

	#pragma endregion

	//Soma e média de 5 inteiros
	#pragma region Questao_5
	int num1, num2, num3, num4, num5, media;

	printf("Informe o primeiro número inteiro: \n");
	scanf("%d", &num1);
	printf("Informe o segundo número inteiro: \n");
	scanf("%d", &num2);
	printf("Informe o terceiro número inteiro: \n");
	scanf("%d", &num3);
	printf("Informe o quarto número inteiro: \n");
	scanf("%d", &num4);
	printf("Informe o quinto número inteiro: \n");
	scanf("%d", &num5);
	soma = num1 + num2 + num3 + num4 + num5;
	media = soma / 5;
	printf("A soma ´dos números: %d e sua média: %d", soma, media);

	#pragma endregion

	//Soma e média de 5 números reais
	#pragma region Questao_6
	float real1, real2, real3, real4, real5, realMedia, realSoma;

	printf("Informe o primeiro número real: \n");
	scanf("%f", &real1);
	printf("Informe o segundo número real: \n");
	scanf("%f", &real2);
	printf("Informe o terceiro número real: \n");
	scanf("%f", &real3);
	printf("Informe o quarto número real: \n");
	scanf("%f", &real4);
	printf("Informe o quinto número real: \n");
	scanf("%f", &real5);
	realSoma = real1 + real2 + real3 + real4 + real5;
	realMedia = realSoma / 5;
	printf("A soma ´dos números: %f e sua média: %f", realSoma, realMedia);

	#pragma endregion

	//Nota final do aluno
	#pragma region Questao_7_8
	int testeEscrito1, testeEscrito2, tp1, tp2, tp3, tp4;
	float mediaTestes, mediaTp, mediaFinal;

	printf("Qual a nota do primeiro teste escrito?\n");
	scanf("d", &testeEscrito1);
	printf("Qual a nota do segundo teste escrito?\n");
	scanf("d", &testeEscrito2);
	printf("Qual a nota do primeiro trabalho prático?\n");
	scanf("%d", &tp1);
	printf("Qual a nota do segundo trabalho prático?\n");
	scanf("%d", &tp2);
	printf("Qual a nota do terceiro trabalho prático?\n");
	scanf("%d", &tp3);
	printf("Qual a nota do quarto trabalho prático?\n");
	scanf("%d", &tp4);

	mediaTestes = (testeEscrito1 + testeEscrito2) / 2;
	mediaTp = (tp1 + tp2 + tp3 + tp4) / 4;
	mediaFinal = (mediaTestes * 0.7) + (mediaTp * 0.3);

	#pragma endregion

	//Bônus de Natal do colaborador
	#pragma region Questao_9
	int filhos, qtdAno, bonus;

	printf("Quantos filhos tens?\n");
	scanf("%d", &filhos);
	printf("Quantos anos de empresa tens?\n");
	scanf("%d", &qtdAno);

	bonus = (filhos * 20) + (qtdAno * 10);

	printf("Seu bônus de natal será: %d", bonus);

	#pragma endregion

}
