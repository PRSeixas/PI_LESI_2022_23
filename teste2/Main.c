#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*
int SomaMultiplosN(int n) {
	
	int soma = 0;

	for (size_t i = 0; i <= 100 ; i++)
	{
		if (i % n == 0)
		{
			soma = soma + i;
		}
	}


	return soma;
}
*/

/*
int ComparaArrays(int a1[], int a2[]) {

	int qtd = 0;

	for (int i = 0; i < 30; i++)
	{
		if (a1[i] == a2[i]) {
			qtd++;
		}
	}

	return qtd;
}
*/

/*
float Calculadora(float a, float b) {
	float soma, subt, produto, divi;

	soma = a + b;
	subt = a - b;
	produto = a * b;

	if (a != 0 && b != 0)
	{
		divi = a / b;
	}
	else
	{
		printf("Os resultados foram, soma: %f, subtração: %f, produto: %f\n", soma, subt, produto);
		printf("Operação de divisão impossível\n");
	}

	printf("Os resultados foram, soma: %f, subtração: %f, produto: %f, divisão: %f\n", soma, subt, produto, divi);

	return;
}
*/

/*
int EscreverIntervalo(int a, int b) {

	for (int i = b; i >= a; i--)
	{
		printf("%d\n", i);
	}
}
*/

/*
int DevolveIndice(int n, int a[]) {

	int aux = 0;
	int posicao = 0;
	
		for (int i = 0; i < 30; i++)
		{
			if (a[i] == n)
			{
				posicao = i;
				aux = a[i];
			}
			if (aux == n) {
				break;
			}
		}

	if (aux != n)
	{
		return -1;
	}
	else
	{
		return posicao;
	}
}
*/

/*
void InformarTemperatura(float a[]) {

	float t = 0;

	for (int i = 0; i < 30; i++)
	{
		printf("Qual a %d temperatura?\n", i + 1);
		scanf("%f", &a[i]);
	}
}

void InfoTemperatura(float a[]) {
	float media = 0, soma = 0, terceira = 0, proxZero = 0;
	int tam = 30;
	proxZero = a[0];

	for (int i = 0; i < 30; i++)
	{
		soma = soma + a[i];

		if (a[i] == 2) {
			terceira = a[i];
		}
		if (a[i] < proxZero)
		{
			proxZero = a[i];
		}
	}

	media = soma / tam;

	printf("A terceira temperatura informada foi: %f\n", terceira);
	printf("A média das temperaturas informadas foi: %f\n", media);
	printf("A temperatura registrada mais próxima de zero grau foi: %f", proxZero);

	return;
}
*/

void ConverteTemperatura(float x) {
	
	float c, f;

	f = x;

	c = (f - 32) * 5 / 9;

	printf("%.1f graus Fahrenheit convertem-se em %.1f graus Celsius", f, c);
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	float f = 212.0;

	ConverteTemperatura(f);

}
