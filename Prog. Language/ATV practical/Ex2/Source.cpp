/*
UNINTER - ENGENHARIA DA COMPUTA��O
Disciplina de Linguagem de Programa��o
Exerc�cio 2 - Atividade pr�tica

Autor: Paulo Vinicius Pereira Pinheiro
RU: 3760288

In�cio: 02/07/2022			Fim: 02/07/2022
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>


void titulo() 
{
	printf("###############    Exerc�cio 2 - Atividade Pr�tica     ###############\n");
	printf(" Aluno: Paulo Vinicius P. Pinheiro\n");
	printf(" RU: 3760288\n\n");
};

struct dados
{
	char nome[30];
	char endereco[50];
	char telefone[15];
};

int main()
{
	setlocale(LC_ALL, ""); // permite utilizar caracteres em pt-br

	int cont_car = 0, cont_dig = 0, cont = 0;
	struct dados pessoa {};
	const int tam_total = sizeof(pessoa.nome) + sizeof(pessoa.endereco) + sizeof(pessoa.telefone); // verifica tamanho total as strings concatenadas
	char dados_total[tam_total]{};

	titulo();

	printf("\n Digite o seu nome completo: ");
	gets_s(pessoa.nome, 29);

	printf("\n Digite o seu endereco completo: ");
	gets_s(pessoa.endereco, 49);

	printf("\n Digite o seu telefone completo: ");
	gets_s(pessoa.telefone, 15);

      // como a string final (dados_total) j� foi inicializada, apenas realiza-se
      //o processo de concatena��o dos 3 dados inputados
	strcat_s(dados_total, pessoa.nome);
	strcat_s(dados_total, pessoa.endereco);
	strcat_s(dados_total, pessoa.telefone);

	for (int i = 0; i < strlen(dados_total); i++)
	{
	        // ver PVPP
		/*if (isalpha(dados_total[i])) printf("\n %c ok\n", dados_total[i]);
		else printf("\n %c not ok\n", dados_total[i]);*/

            // verifica  quais s�o caracteres alfab�ticos e conta-os
		if (isalpha(dados_total[i]))
		{
			cont_car++;
			cont++;
		}
		
		//verifica quais s�o caracteres num�ricos
		if (isdigit(dados_total[i]))
		{
			cont_dig++;
			cont++;
		}
	}

	printf("\n\n ## Resultado ##\n\n");
	printf("\n Quantidade de caracteres do alfabeto: %d \n", cont_car);
	printf("\n Quantidade de caracteres numericos: %d \n", cont_dig);
	printf("\n Quantidade total de caracteres digitados: %u \n", strlen(dados_total)-1);

	return 0;
}