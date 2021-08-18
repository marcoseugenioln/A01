#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	//Cria struct com os valores necess�rios
	typedef struct ficha
	{
		char marca[20];
		char modelo[20];
		char ano[5];
		char placa[9];
	}type_carro;
	
	//cria 10 sctructs chamos de carros
	type_carro carros[10];
	
	//laço de repetição para o programa
	char resposta;
	do{
		//vari�vel para escolha do usu�rio
		int escolha;
		
		//Display do menu inicial
		printf("Escolha uma opcao: \n");
		printf("1 - Listar carros.\n");
		printf("2 - Inserir carro.\n");
		printf("3 - Filtrar por ano.\n");
		printf("4 - Filtrar a partir de ano.\n");
		printf("5 - Filtrar por modelo.\n");
		printf("6 - sair.\n");
		printf("> ");
		

		//input do valor da variavel parametro do switch
		//Validação do valor para ser int dentro das opções
		scanf("%d", &escolha);
		while ( escolha < 1 || escolha > 6)
		{
			printf("> ");
			scanf("%d", &escolha);
			
		}// fim da validação
		

		//inicio da arvore de decisão múltipla
		switch (escolha)
		{
		case 1: //listar carros
			fflush(stdin);

			//dislay do cabeçalho
			printf("       LISTA DE CARROS       \n");
			printf("-----------------------------\n");

			//itera pelas posições imprime os valores caso exista
			//conta o número de carros
			int num_carros = 0, i;
			for ( i = 0; i < 10; i++)
			{
				int ano_carro = atoi(carros[i].ano);
				if ( ano_carro > 0)
				{
					printf("%s ",carros[i].marca);
					printf("%s ",carros[i].modelo);
					printf("%s ",carros[i].ano);
					printf("%s ",carros[i].placa);
					printf("\n");
					num_carros = num_carros + 1;
				}
				
			}// fim da iteração


			//se não houverem carros registrados imprime
			if (num_carros == 0)
			{
				printf("Nenhum carros registrado.\n");
			}

			break;

		case 2: //inserir carro
			fflush(stdin);

			//display do cabeçalho
			printf("        INSERIR CARROS       \n");
			printf("-----------------------------\n");
	
			//verifica a primeira posição livre
			int index;
			int j;
			for (j = 0; j < 10; j++)
			{
				int verif = atoi(carros[j].ano);
				if (verif > 1900)
				{
					index = index + 1;
				}
				
			}

			//imprime se não houver lugar na lista
			if (index == 10)
			{
				printf("Lista cheia.\n");
			}
			
			//senão coleta e valida os dados
			//Marca
			printf("Marca: ");
			scanf("%s",&carros[index].marca);

			//modelo
			printf("Modelo: ");
			scanf("%s",&carros[index].modelo);

			//ano e valida se for menor que 4
			printf("Ano (AAAA): ");
			scanf("%s",&carros[index].ano);
			while (strlen(carros[index].ano) < 4)
			{
				printf("Ano (AAAA): ");
				scanf("%s",&carros[index].ano);
			}
			
			//placa e valida se está no formato correto
			printf("Placa (XXX-YYYY): ");
			scanf("%s",carros[index].placa);
			while (carros[index].placa[3] != '-')
			{
				printf("Placa (XXX-YYYY): ");
				scanf("%s",carros[index].placa);
			}

			//Bubble sort com base no int do ano
			struct ficha auxiliar;
			int l;
			for (l = 0; l < 9; l++)
			{
				if (atoi(carros[l].ano) > atoi(carros[l + 1].ano) )
				{
					auxiliar = carros[l];
					carros[l] = carros[l + 1];
					carros[l + 1] = auxiliar;
				}	
			}
			
			break;

		case 3: //filtrar por ano
			fflush(stdin);

			//display do cabeçalho
			printf("        FILTRAR POR ANO      \n");
			printf("-----------------------------\n");
			
			//coleta ano e valida com data lógica
			int ano_escolhido;
			printf("Ano (AAAA): ");
			scanf("%d", &ano_escolhido);
			while (ano_escolhido < 1900)
			{
				printf("Ano (AAAA): ");
				scanf("%d", &ano_escolhido);
			}
			
			//itera pelas posições e imprime se tiver valor igual
			//conta o número de carros encontrados
			int count = 0;
			for (i = 0; i < 10; i++)
			{
				int ano_lista = atoi(carros[i].ano);
				if (ano_lista == ano_escolhido)
				{
					printf("%s ",carros[i].marca);
					printf("%s ",carros[i].modelo);
					printf("%s ",carros[i].ano);
					printf("%s ",carros[i].placa);
					printf("\n");
					count = count + 1;
				}
				
			}

			//caso não encontre carros imprime
			if (count == 0)
			{
				printf("Nenhum carro do ano escolhido registrado.\n");
			}

			break;
			
		case 4://filtrar a partir de ano
			fflush(stdin);

			//display do cabeçalho
			printf("   FILTRAR A PARTIR DE ANO   \n");
			printf("-----------------------------\n");
			
			//coleta ano e valida com data lógica
			int ano_filtro = 0;
			printf("Ano (AAAA): ");
			scanf("%d", &ano_filtro);
			while (ano_escolhido < 1000)
			{
				printf("Ano (AAAA): ");
				scanf("%d", &ano_filtro);
			}
			
			//itera pelas posições e imprime se tiver valor igual
			//conta o número de carros encontrados
			int contador = 0;
			for (i = 0; i < 10; i++)
			{
				int ano_filtro_lista = atoi(carros[i].ano);
				if (ano_filtro_lista >= ano_filtro)
				{
					printf("%s ",carros[i].marca);
					printf("%s ",carros[i].modelo);
					printf("%s ",carros[i].ano);
					printf("%s ",carros[i].placa);
					printf("\n");
					contador = contador + 1;
				}
				
			}

			//caso não encontre carros imprime
			if (contador == 0)
			{
				printf("Nenhum carro do ano escolhido ou maior registrado.\n");
			}

			break;

		case 5://filtrar por modelo
			fflush(stdin);

			//display do cabeçalho
			printf("      FILTRAR POR MODELO     \n");
			printf("-----------------------------\n");
			
			//coleta ano e valida com data lógica
			char modelo_escolhido[20];
			printf("Modelo: ");
			scanf("%s",modelo_escolhido);
			
			//itera pelas posições e imprime se tiver valor igual
			//conta o número de carros encontrados
			int c = 0;
			int k;
			for (k = 0; k < 10; k++)
			{
				int resultado = strcmp(carros[k].modelo,  modelo_escolhido);
				if (resultado == 0)
				{
					printf("%s ",carros[k].marca);
					printf("%s ",carros[k].modelo);
					printf("%s ",carros[k].ano);
					printf("%s ",carros[k].placa);
					printf("\n");
					c = c + 1;
				}
				
			}

			//caso não encontre carros imprime
			if (c == 0)
			{
				printf("Nenhum carro do modelo escolhido registrado.\n");
			}
			
			break;
		case 6:
			fflush(stdin);

			system("pause");
			return 0;
		}

		fflush(stdin);

		//repete ciclo ou não
		printf("\nOutro comando? [s/n]\n");
		scanf("%c", &resposta);

	} while(resposta == 's');

	printf("Programa encerrado\n");
	system("pause");
	return 0;
} 
