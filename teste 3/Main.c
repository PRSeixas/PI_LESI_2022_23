/*****************************************************************//**
 * \file   Main.c
 * \brief  
 * 
 * \author pedro raphael pereira seixas
 * aluno a21872
 * LESI-PL
 * \date   December 2022
 *********************************************************************/




#define _CRT_SECURE_NO_WARNINGS

//Biblioteca nativa de C
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "Lista.h"

int main() {
	setlocale(LC_ALL, "Portuguese");


	atleta Atletas[Tam];

	int posicao =0;			//Variável determinar a posição do arrays e código do atleta automático.
	int opcao = 0;			//Váriável para usar no menu.
	int altura = 0;			//Variável para receber informarção da altura do atleta em centímetros.
	char nome[50];			//Variável para receber a informação do nome do atleta.


	int codAtleta = 0;

	iniciarBaseAtleta(Atletas);
	do
	{
	
	switch (opcao = Menu())
	{
	case 1: 
		printf("Qual código do atleta?: ");
		scanf("%d", &codAtleta);
		printf("Informe o nome do atleta: ");
		scanf("%[^\n]", nome); while ((getchar()) != '\n');
		printf("Informe a altura do atleta em centímetros:\n");
		scanf("%d", &altura); while ((getchar()) != '\n');
		posicao = guardarAtleta(Atletas, posicao, altura, nome);
		break;
	case 2: 
		listarNomeTodosAtletas(Atletas);
		break;
	case 3:
		printf("Qual atleta você deseja obter as informações? ");
		scanf("%d\n", &codAtleta);
		listarUmAtleta(Atletas, codAtleta);
		break;
	case 4:
		alturaMediaAtletas(Atletas);
		break;
	default:
		break;
	}

	} while (opcao !=0);

}






