#define _CRT_SECURE_NO_WARNINGS

//Biblioteca nativa de C
#include <stdio.h>
#include <locale.h>
#include <string.h>#pragma once

#define Tam 100

#pragma region Structs
//Definição da estrutura para armazenar as informações dos atletas.
typedef struct Atleta {
	int codAtleta;
	char nome[50];
	int altura;

}atleta;

#pragma endregion

#pragma region OutrasFuncoes
//Função que apresenta o menu de opções no ecrã.
int Menu();

#pragma endregion


#pragma region FuncoesAtletas
//Função para limpar o lixo de memória do array.
void iniciarBaseAtleta(atleta a[]);

//Função para guardar as informações de um atleta em um array de atletas.
int guardarAtleta(atleta a[], int posicao, int altura, char nome[50]);

//Função para listar o nome de todos os atletas do array.
void listarNomeTodosAtletas(atleta a[]);

//Função para listar as informações de um atleta, recebido código por parâmetro
void listarUmAtleta(atleta a[], int codAtleta);

//Função para calcular a média da altura dos atletas que estão cadastrados no array.
int alturaMediaAtletas(atleta a[]);

#pragma endregion









