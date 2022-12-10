
/*****************************************************************//**
 * \file   Main.c
 * \brief  
 * 
 * \author Pedro Raphael
 * \date   November 2022
 *********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

 //Biblioteca nativa de C
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "Lista.h"

int main() {
	setlocale(LC_ALL, "Portuguese");

	//testes das funçoes em curso

	pessoa dados[TamPart];
	infoAtividade atividades[TamAtiv];
	planoAtividade plano[TamPlan];

	int QtdParticipantes=0;

	//QtdParticipantes = ImportaDadosParticipantes(dados, "dadosParticipante.txt");

	//ImportaInfoAtividade(atividades, "infoAtividade.txt");

	//ImportaPlanoAtividade(plano, "planoAtividade.txt");


}
