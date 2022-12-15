#define _CRT_SECURE_NO_WARNINGS

//Biblioteca nativa de C
#include <stdio.h>
#include <locale.h>
#include <string.h>#pragma once

#define Tam 100

#pragma region Structs
//Defini��o da estrutura para armazenar as informa��es dos atletas.
typedef struct Atleta {
	int codAtleta;
	char nome[50];
	int altura;

}atleta;

#pragma endregion

#pragma region OutrasFuncoes
//Fun��o que apresenta o menu de op��es no ecr�.
int Menu();

#pragma endregion


#pragma region FuncoesAtletas
//Fun��o para limpar o lixo de mem�ria do array.
void iniciarBaseAtleta(atleta a[]);

//Fun��o para guardar as informa��es de um atleta em um array de atletas.
int guardarAtleta(atleta a[], int posicao, int altura, char nome[50]);

//Fun��o para listar o nome de todos os atletas do array.
void listarNomeTodosAtletas(atleta a[]);

//Fun��o para listar as informa��es de um atleta, recebido c�digo por par�metro
void listarUmAtleta(atleta a[], int codAtleta);

//Fun��o para calcular a m�dia da altura dos atletas que est�o cadastrados no array.
int alturaMediaAtletas(atleta a[]);

#pragma endregion









