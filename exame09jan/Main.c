/*****************************************************************//**
 * \file   Main.c
 * \brief  
 * 
 * \author pedro
 * \date   January 2023
 *********************************************************************/

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "Lista.h"

int main() {

	imovel dadosImoveis[registo];		//Array para armazenar os registros dos imóveis da imobiliária.
	imovel aux;							//variável auxliar para obter os dados de um novo imóvel.
	int autoGenCodImovel = 0;			//variável para gerar de forma progressiva o código do imóvel.
	int opcao = -1;						//variável para operacionalizar o MENU.
	int nif = 0;						//variável para a opção 5 do MENU.
	float preco = 0;					//variável para a opção 2 do MENU.
	float valorTotal = 0;				//variável para a opção 5 do MENU.

	do
	{
		opcao = MENU;
		switch (opcao)
		{
		case 1: aux = lerDados(autoGenCodImovel);
			autoGenCodImovel = inserirImovel(aux, dadosImoveis, autoGenCodImovel);
			break;
		case 2:
			printf("Informe o preço máximo para consulta: \n");
			scanf("%f", &preco);
			listarImoveisSuperior100(dadosImoveis, preco);
			break;
		case 3:
			listarTodosImoveisCrecentePreco(dadosImoveis);
			break;
		case 4:
			quantidadeRegistoMoradia(dadosImoveis);
			break;
		case 5:
			printf("Informe o NIF para consulta: \n");
			scanf("%d", &nif);
			valorTotal = valorTotalVendaPorNIF(dadosImoveis, nif);
			printf("O Valor total para o NIF: %d é %f", nif, valorTotal);
			break;
		default:
			break;
		}
	} while (opcao != 0);

}
