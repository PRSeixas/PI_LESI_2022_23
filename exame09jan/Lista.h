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

#define registo 50			//definição de tamanho do array de imóveis.

#pragma region Structs
//Definição de estrutura para armazenar os dados dos imóveis.
typedef struct imovel {
	int cod;
	int tipoImovel;			//0 = morada, 1 = apartamento
	char morada[50];
	char descricao[100];
	float precoVenda;
	float area;				//em metros quadrados
	int NIF;				//NIF do proprietário
}imovel;

#pragma endregion

#pragma region AssinaturaFuncoesDadosImovel
//Funcão para ler os dados de um novo imóvel.
imovel lerDados(int cod);

//Função para inserir no arrays o registo de um novo imóvel.
int inserirImovel(imovel a, imovel im[], int cod);

//Função para limpar lixo de memória
void iniciaPlanoDados(imovel im[]);

//Função para listar os imóveis superior a 100 metros quadrados até um determinado valor
void listarImoveisSuperior100(imovel im[], float preco);

//Função para ordenar um arrays de forma crescente pelo preço de venda do imóvel
void ordenarCrescentePreco(imovel im[]);

//Listar todos os imóveis de forma crescente pelo preço de venda
void listarTodosImoveisCrecentePreco(imovel im[]);

//Função devolve a quantidade de registos de imóveis do tipo morada
int quantidadeRegistoMoradia(imovel im[]);

//Valor total dos imóveis a venda por NIF
float valorTotalVendaPorNIF(imovel im[], int nif);

#pragma endregion

#pragma region OutrasFuncoes
//Apresentação do menu no ecrã
int MENU();

#pragma endregion
