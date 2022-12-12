
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

	//testes das funçoes em desenvolvimento

	pessoa participantes[TamPart];
	infoAtividade atividades[TamAtiv];
	planoAtividade plano[TamPlan];
	
	IniciaBasePessoa(participantes);

	IniciaBaseAtividade(atividades);

	iniciaBasePlano(plano);

	int QtdParticipantes=0;

	QtdParticipantes = ImportaDadosParticipantes(participantes, "dadosParticipante.txt");

	ImportaInfoAtividade(atividades, "infoAtividade.txt");

	ImportaPlanoAtividade(plano, "planoAtividade.txt");

	char tipo[15] = "Marcha";

	apresentarPlanoPorTipoPeriodoPraticante(plano, tipo, 1);

	//AtividadePorPeriodoParticipante(atividades, tipo);

	//listarInfoAtividadeParticipanteDecrescente(atividades, participantes, tipo);

}
