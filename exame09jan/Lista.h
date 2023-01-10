/*****************************************************************//**
 * \file   Lista.h
 * \brief  
 * 
 * \author pedro
 * \date   January 2023
 *********************************************************************/

#include <stdio.h>
#include <string.h>
#include <locale.h>

#define registo 50			//defini��o de tamanho do array de im�veis.

#pragma region Structs
//Defini��o de estrutura para armazenar os dados dos im�veis.
typedef struct imovel {
	int cod;
	int tipoImovel;			//0 = morada, 1 = apartamento
	char morada[50];
	char descricao[100];
	float precoVenda;
	float area;				//em metros quadrados
	int NIF;				//NIF do propriet�rio
}imovel;

#pragma endregion

#pragma region AssinaturaFuncoesDadosImovel
//Func�o para ler os dados de um novo im�vel.
imovel lerDados(int cod);

//Fun��o para inserir no arrays o registo de um novo im�vel.
int inserirImovel(imovel a, imovel im[], int cod);

//Fun��o para limpar lixo de mem�ria
void iniciaPlanoDados(imovel im[]);

//Fun��o para listar os im�veis superior a 100 metros quadrados at� um determinado valor
void listarImoveisSuperior100(imovel im[], float preco);

//Fun��o para ordenar um arrays de forma crescente pelo pre�o de venda do im�vel
void ordenarCrescentePreco(imovel im[]);

//Listar todos os im�veis de forma crescente pelo pre�o de venda
void listarTodosImoveisCrecentePreco(imovel im[]);

//Fun��o devolve a quantidade de registos de im�veis do tipo morada
int quantidadeRegistoMoradia(imovel im[]);

//Valor total dos im�veis a venda por NIF
float valorTotalVendaPorNIF(imovel im[], int nif);

#pragma endregion

#pragma region OutrasFuncoes
//Apresenta��o do menu no ecr�
int MENU();

#pragma endregion
