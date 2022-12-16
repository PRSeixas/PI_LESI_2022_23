
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

	pessoa participantes[TamPart];				//Array para armazenar os dados importados dos participantes
	infoAtividade atividades[TamAtiv];			//Array para armazenar os dados importados das informções das atividades
	planoAtividade plano[TamPlan];				//Array para armazenar os dados importados dos planos das atividades
	avaliacaoAtividade at[Linhas];				//Array para consolidar as avaliações e gerar tabela.

	//Limpar lixo de memória
	IniciaBasePessoa(participantes);

	//Limpar lixo de memória
	IniciaBaseAtividade(atividades);

	//Limpar lixo de memória
	iniciaBasePlano(plano);

	//Limpar lixo de memória
	iniciaBaseAvaliacaoAtividade(at);

	int opcao = 0;								//Variável para operar o Menu.
	int QtdParticipantes = 0;					//Quantidade de participantes.
	int QtdAvaliacoes = 0;						//Quantidade de avaliações para gerar tabela.
	int codParticipante = 0;					//Variável para operar o menu.
	char tipo[15] = "";							//Variável para operar o Menu.

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
			printf("Informe o código do praticante: ");
			scanf("%d", &codParticipante);
			apresentarPlanoPorTipoPeriodoPraticante(plano, tipo, codParticipante);
			break;
		case 7:
			printf("Qual praticante deseja consultar a média? ");
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
