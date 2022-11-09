/*****************************************************************//**
 * \file   Funcoes.c
 * \brief  
 * 
 * \author Pedro Raphael
 * \date   November 2022
 *********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

 //Biblioteca nativa de C
#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

void ListaParticipantes(pessoa p[][dadosC], char* nomeFicheiro) {

	FILE* fp;
	dadosPessoa aux;
	int i = 0;
	
	//Teste se o ficheiro é vazio
	if ((fp = fopen(nomeFicheiro, "r")) == NULL) return NULL;

	char c[1000];
	while (fscanf(fp, "%[^\n] ", c) != EOF)
	{
		//Criar bloco de memória para pessoa e após armazenar na matriz para resolver erro.

		sscanf(c, "%d\;%c\;%d\;%d\n", &aux.num, &aux.nome, &aux.telefone, &aux.idade);
		p[i][0] = aux.num;
		p[i][1] = aux.nome;
		p[i][2] = aux.telefone;
		p[i][3] = aux.idade;
		
		i++;
	}

}
