
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

	//testes das fun�oes em desenvolvimento

	pessoa participantes[TamPart];				//Array para armazenar os dados importados dos participantes
	infoAtividade atividades[TamAtiv];			//Array para armazenar os dados importados das inform��es das atividades
	planoAtividade plano[TamPlan];				//Array para armazenar os dados importados dos planos das atividades
	avaliacaoAtividade at[Linhas];				//Array para consolidar as avalia��es e gerar tabela.

	//Limpar lixo de mem�ria
	IniciaBasePessoa(participantes);

	//Limpar lixo de mem�ria
	IniciaBaseAtividade(atividades);

	//Limpar lixo de mem�ria
	iniciaBasePlano(plano);

	//Limpar lixo de mem�ria
	iniciaBaseAvaliacaoAtividade(at);

	int opcao = 0;								//Vari�vel para operar o Menu.
	int QtdParticipantes = 0;					//Quantidade de participantes.
	int QtdAvaliacoes = 0;						//Quantidade de avalia��es para gerar tabela.
	int codParticipante = 0;					//Vari�vel para operar o menu.
	char tipo[15] = "";							//Vari�vel para operar o Menu.

	do
	{
		printf("\n");
		opcao = Menu();
		switch (opcao)
		{
		case 1: 
			QtdParticipantes = ImportaDadosParticipantes(participantes, "dadosParticipante.txt");
			break;
		case 2: 
			ImportaInfoAtividade(atividades, "infoAtividade.txt");
			break;
		case 3:
			ImportaPlanoAtividade(plano, "planoAtividade.txt");
			break;
		case 4:
			printf("Qual tipo de atividade deseja consultar?\n");
			scanf("%s", &tipo);
			AtividadePorPeriodoParticipante(atividades, tipo);
			break;
		case 5:
			printf("Qual tipo de atividade deseja consultar?\n");
			scanf("%s", &tipo);
			InfoAtividadeParticipanteDecrescente(atividades, participantes, tipo);
			break;
		case 6:
			printf("Qual tipo de atividade deseja consultar no plano?\n");
			scanf("%s", &tipo);
			printf("Informe o c�digo do praticante: ");
			scanf("%d", &codParticipante);
			apresentarPlanoPorTipoPeriodoPraticante(plano, tipo, codParticipante);
			break;
		case 7:
			printf("Qual praticante deseja consultar a m�dia? ");
			scanf("%d", &codParticipante);
			calcularMediaPraticante(atividades, codParticipante);
			break;
		case 8:
			QtdAvaliacoes = CompilarAvaliacaoAtividade(at, participantes, atividades);
			gerarTabelaAvaliacaoAtividade(at);
			break;
		case 9:
			guardarDadosAvaliacaoBinario(at, QtdAvaliacoes);
		default:
			break;
		}

	} while (opcao!=0);

}
