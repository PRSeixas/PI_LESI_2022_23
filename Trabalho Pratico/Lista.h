/*****************************************************************//**
 * \file   Lista.h
 * \brief  
 * 
 * \author Pedro Raphael
 * \date   November 2022
 *********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

 //Bibliotecas nativas de C
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

#define TamPart 4						//Tamanho do vetor de participantes
#define TamAtiv 6						//Tamanho do vetor informação de atividades
#define TamPlan 4						//Tamanho do vetor com os planos
#define TamCol 7						//Quantidade de colunas da tabela de avaliação de atividades
#define Linhas 10						//Quantidade de linhas da matriz

#pragma region Structs
//Estrutura para armazenar os dados dos participantes
typedef struct pessoa {
	int num;							//Número identificação
	char nome[50];						//Nome do participante
	int telefone;						//Número do telefone
	int idade;							//Idade do participante

}pessoa;

//Estrutura para armazenar as informações das atividades
typedef struct infoAtividade {
	int idPrat;							//Número do participante
	int dia, mes, ano;					//Dia, mes e ano da atividade
	char atividade[15];					//Tipo de atividae
	int tempo;							//duração da atividade em minutos
	int distancia;						//distância da atividade em metros

}infoAtividade;

//Estrutura para armazenar o planeamento das atividades
typedef struct planoAtividade {

	int numPrat;						//Número do participante
	int diaIni, mesIni, anoIni;			//Dia, mês e ano do início da atividade
	int hIni, mIni;						//Hora e minuto do início atividade
	int diaFim, mesFim, anoFim;			//Dia, mês e ano do final da atividade
	int hFim, mFim;						//Hora e minuto do final da atividade
	char ativ[15];						//Tipo de atividade
	int dist;							//Distância em metros
}planoAtividade;

//Estrutura para armazenar os dados que irão compor a tabela de avaliação
typedef struct avaliacaoAtividade {
	
	int codPart;
	char nome[50];
	int diaIni, mesIni, anoIni;			//Dia, mês e ano do início da atividade
	int diaFim, mesFim, anoFim;			//Dia, mês e ano do final da atividade
	int totDist;
	int totTemp;

}avaliacaoAtividade;

//Definição de string para montar tabela de avaliação de atividade
typedef struct Celula {

	char dados[50];

}Celula;

//Definição de uma estrutura para manipulação de datas
typedef struct data {
	int dia;
	int mes;
	int ano;
}data;

#pragma endregion

#pragma region AssinaturaFuncoesPessoas
//Função para limpar o lixo de memória do vetor de participantes.
void IniciaBasePessoa(pessoa p[]);

//Função para retornar a distância total das atividades de um participante.
int totalDistanciaParticipante(int codPart, infoAtividade a[]);

//Função para retornar o tempo total das atividades realizadas por um participante.
int totalTempoParticipante(int codPart, infoAtividade a[]);

//Função para calcular a média do tempo de um praticante.
int calcularMediaPraticante(infoAtividade a[], int codPrat);

//Função para percorrer array de pessoas e devolver o nome de um praticante
char nomePraticante(pessoa p[], int codPrat);

#pragma endregion

#pragma region AssinaturasFuncoesAtividades
//Função para limpar o lixo de memória do vetor das informações das atividades
void IniciaBaseAtividade(infoAtividade a[]);

//Função para ordenar de forma crescente um vetor de informação de atividades por número de participante.
bool ordenarAtividadeCrescenteParticipantes(infoAtividade a[], int tam);

//Função para ordenar de forma decrescente um vetor de informação de atividades por número de participante.
bool ordenarAtividadesDecrescenteParticipantes(infoAtividade a[]);

//Função para listar o número dos participantes de um vetor de informação de atividades
void listarNumeroParticipanteAtividade(infoAtividade a[], int tam, char ativ[15]);

//Função para listar o número e nome dos participantes de um vetor de informação de atividades
bool listarNumeroNomeParticipanteAtividade(pessoa p[], infoAtividade a[]);

//Funcão para listar o número dos participantes que realizaram determinada atividade, num determinado período.
bool AtividadePorPeriodoParticipante(infoAtividade a[], char tipo[15]);

//Função para listar participantes por ordem decrescente, que realizaram uma determinada atividade, num determinado período.
int InfoAtividadeParticipanteDecrescente(infoAtividade a[], pessoa p[], char ativ[15]);



#pragma endregion

#pragma region AssinaturasFuncoesPlano
//Função para limpar o lixo de memória do vetor das informações dos planos
void iniciaBasePlano(planoAtividade p[]);

//Função para listar um vetor de plano de atividades.
bool listarPlanoAtividade(planoAtividade p[]);

//Função para apresentar o plano de atividade para um determinado praticante, num determinado período, para um tipo de atividade
bool apresentarPlanoPorTipoPeriodoPraticante(planoAtividade p[], char ativ[15], int codPrat);
#pragma endregion

#pragma region AssinaturasAvaliacaoAtividades
//Função para limpar lixo de memória
void iniciaBaseAvaliacaoAtividade(avaliacaoAtividade at[]);

//Funcão para limpar o lixo de memória
void iniciaBaseCelula(Celula c[Linhas][TamCol]);

//Função para preencher o array de avaliação de atividades com a informação da atividade e do praticante.
int CompilarAvaliacaoAtividade(avaliacaoAtividade at[], pessoa p[], infoAtividade a[]);

//Função para gerar a tabela das avaliações e mostrar no ecrã.
bool gerarTabelaAvaliacaoAtividade(avaliacaoAtividade at[]);

//Consolidação dos dados para gerar a tabela de avaliação
bool gerarDadosAvaliacao(avaliacaoAtividade at[]);

//Consolidação dos dados para gerar a tabela de avaliação
bool lerDadosAvaliacao(Celula c[Linhas][TamCol]);

//Função para escrerver os dados da tabela de avaliação no ecrã
bool escreverDadosAvaliacao(Celula c[Linhas][TamCol]);

#pragma endregion

#pragma region AssinaturasManipulacaoDados
//Função para preencher o vetor com os dados dos participantes importados do ficheiro
int ImportaDadosParticipantes(pessoa p[], char* nomeFicheiro);

//Função para preencher o vetor com as informações das atividades
bool ImportaInfoAtividade(infoAtividade a[], char* nomeFicheiro);

//Função para preencher o vetor com os dados dos planos dos participantes
bool ImportaPlanoAtividade(planoAtividade p[], char* nomeFicheiro);

//Função para guardar a tabela gerada em um ficheiro binário.
bool guardarDadosAvaliacaoBinario(avaliacaoAtividade at[], int qtdAvaliacoes);

#pragma endregion

#pragma region AssinaturaOutrasFuncoes
//Função para leitura do período de datas informada pelo utilizador via stdin
data lerData();

//Função para comparar duas datas
data compararMenorData(data a, data b);

//Função para apresentar MENU no ecrã do utilizador.
int Menu();
#pragma endregion

#pragma region FuncoesEmTestes


#pragma endregion




