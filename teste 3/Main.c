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

	int posicao =0;			//Vari�vel determinar a posi��o do arrays e c�digo do atleta autom�tico.
	int opcao = 0;			//V�ri�vel para usar no menu.
	int altura = 0;			//Vari�vel para receber informar��o da altura do atleta em cent�metros.
	char nome[50];			//Vari�vel para receber a informa��o do nome do atleta.


	int codAtleta = 0;

	iniciarBaseAtleta(Atletas);
	do
	{
	
	switch (opcao = Menu())
	{
	case 1: 
		printf("Qual c�digo do atleta?: ");
		scanf("%d", &codAtleta);
		printf("Informe o nome do atleta: ");
		scanf("%[^\n]", nome); while ((getchar()) != '\n');
		printf("Informe a altura do atleta em cent�metros:\n");
		scanf("%d", &altura); while ((getchar()) != '\n');
		posicao = guardarAtleta(Atletas, posicao, altura, nome);
		break;
	case 2: 
		listarNomeTodosAtletas(Atletas);
		break;
	case 3:
		printf("Qual atleta voc� deseja obter as informa��es? ");
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






