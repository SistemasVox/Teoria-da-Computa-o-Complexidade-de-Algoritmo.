/////////////INFORMAÇÕES/////////////////////////
// Autor: Marcelo J. Vieira.                 ///
// 5º Período Licenciatura em Computação.   ///
// Data:04/02/2017 Versão Final 3.4.       /// //Tratamento de erro corrigido.
// Matéria: Teoria da Computação.         /// //Login & Logoff.
// Contato: dj.marcelo.2009@gmail.com    ///
///////////////////////////////////////////

// Bibliotecas utilizadas //
#include <stdio.h>   	 // Entrada e saida né Mano. printf(); scanf();
#include <windows.h>    // Por causa da função Sleep();.
#include <time.h>      // Por causa dos códigos randômicos. srand( (unsigned)time(NULL) );
#include <locale.h>   // Por causa das acentuações. setlocale(LC_ALL, "Portuguese");
///////////////////////

///////////////////Variáeis Globais//////////////////////////////////////////
int tc = 0, op = 0, opr = 0, TAM, cp= 0, modo=-1, num_ale=0;// Inteiros  ///
int vet[15], vet_ori[15]; //Vetores de números inteiros                 ///
//////////////////////////////////////////////////////////////////////////

// PRÉ CARREGANDO DAS FUNÇÕES////////////////////////////
void MenuM (int vet[], int TAM);                     ///
void Modo();                                        ///
void ModoManual (int vet[], int TAM);              ///
void ModoAleatorio (int vet[], int TAM);          ///
void MenuE (int vet[], int TAM);                 ///
void Continuar ();                              ///
void ContinuarM();                             ///
void quick(int vet[], int esq, int dir);      ///
void imprimirFinal(int vet[], int dir);      ///
void heapsort(int vet[], int n);            ///
void shellSort(int vet[], int size);       ///
void imprimir(int vet[], int size);       ///
void selection_sort(int vet[], int tam); ///
void Inserction(int vet[], int n);      ///
void Bubble(int vet[], int n);         ///
void Caso ();                         ///
void Teto ();                        ///
void Login();                       ///
void Logoff();                     ///
void QTD ();                      ///
////////////////////////////////////

int main()
{
////Função para acentuação dos textos////
	setlocale(LC_ALL, "Portuguese");	// 
///////////////////////////////////////
///Função para sempre mudar os randômicos///
	srand((unsigned)time(NULL));	// 
//////////////////////////////////////////
///////Welcome/////////////
	Login();		//////
/////////////////////////
	// Chamando Função QTD();
	QTD();
}

// Quantidade
void QTD()
{
////////Design////////////
	Teto();		 ////////
////////////////////////
	printf(">> Insira a quantidade de números a ser ordenados: ");
	scanf("%i", &TAM);
	if (TAM >= 1 && TAM <= 15)
	{
		TAM = TAM;
		system("Color 13");
		printf("\n\n>>[VALOR ACEITO]: %i", TAM);
		Sleep(2000);
		// Chamando Função Modo
		Modo();
	}
	else
	{
		system("Color 47");
		printf("\n\n>>[VALOR INVÁLIDO] Valores válidos são inteiros positivos entre 1 a 15.");
		Sleep(3000);
		TAM = 4;
		printf("\n\n>>Atruibuindo valor [%i] padrão válido!", TAM);
		Sleep(3000);
		// Chamando Função Modo
		Modo();
	}

}

// Função MODO "Aleatório" ou "Manual.
void Modo()
{
	do
	{
////////Design////////////
		Teto();	 ////////
////////////////////////
		// Limpeza do buffer do teclado após scanf 
		fflush(stdin);
		printf(">> Deseja inserir de [MODO] 'MANUAL' ou 'ALEATÓRIO'?\n");
		printf(">> 0/MANUAL 1/ALEATÓRIO: ");
		scanf("%i", &modo);
	}
	while (modo < 0 || modo > 1);
	// Previnindo os Erros.
	if (modo == 0)
	{
		ModoManual(vet, TAM);
	}
	else if (modo == 1)
	{
		ModoAleatorio(vet, TAM);
	}
	else
	{
		Modo();
	}
	// Fim da Prevenção.
}

// Modo Manual Selecionado
void ModoManual(int vet[], int TAM)
{
	for (int i = 0; i < TAM; i++)
	{
		// Limpeza do buffer do teclado após scanf 
		fflush(stdin);
		printf("\n>> [%iº] número: ", i + 1);
		scanf("%i", &vet[i]);
		// Backup da ordem orginal do vetor.
		vet_ori[i] = vet[i];
	}
	// Chamando Função Menu Escolha de Métodos
	MenuE(vet, TAM);
}

// Modo Aleatório Selecionado
void ModoAleatorio(int vet[], int TAM)
{
	do
	{
////////Design////////////
		Teto();	 ////////
////////////////////////
		// Limpeza do buffer do teclado após scanf 
		fflush(stdin);
		printf(">> Insira o intervalo de 1 até: ");
		scanf("%i", &num_ale);
	}
	while (num_ale < 1 || num_ale > 999);
	/* Prevenção de erro. */
	if (num_ale > 1 || num_ale < 999)
	{
		num_ale = num_ale;
	}
	else
	{
		ModoAleatorio(vet, TAM);
	}
	/* FIM DA PREVEÇÃO */
	// Preenchendo o Vator.
	for (int i = 0; i < TAM; i++)
	{
		vet[i] = 1 + rand() % num_ale;	// gerando números aleatórios maiores que 0 "1 +..."
		printf("\n>> [%iº] número: %i.", i + 1, vet[i]);
		// Backup da ordem orginal do vetor.
		vet_ori[i] = vet[i];
		// Esperando 1s para ver qual número foi gerado.
		Sleep(1000);
	}
	// Chamando Função Menu Escolha de Métodos
	MenuE(vet, TAM);
}

// Menu Escolha de Métodos
void MenuE(int vet[], int TAM)
{
	do
	{
////////Design////////////
		Teto();	 ////////
////////////////////////
		// Limpeza do buffer do teclado após scanf 
		fflush(stdin);
		printf("|                    ESCOLHA SEU MÉTODO DE ORDENAÇÃO        [-] [?] [×]   |\n");
		printf("\n > Menu:");
		printf("\n  1. Seleção  |  4. Heapsort");
		printf("\n  2. Inserção |  5. Shell");
		printf("\n  3. Bolha    |  6. Quick");
		printf("\n > Resposta: ");
		scanf("%i", &op);
	}
	while (op < 1 || op > 6);
	// Chamando Função Menu Todos os Métodos
	MenuM(vet, TAM);
}

// Menu Todos os Métodos
void MenuM(int vet[], int TAM)
{
////////Design////////////
	Teto();		 ////////
////////////////////////
	if (op == 1)
	{
		// Testar o Selection sort 
		printf(">> Selection sort: \n");
		tc = 0, cp = 0, opr = 0;
		printf(">> Original: ");
		imprimirFinal(vet, TAM);
		// Selection sort
		selection_sort(vet, TAM);
		printf("\n>> Ordenado: ");
		imprimirFinal(vet, TAM);
		printf("\n>> Comparações seguidas de trocas: %i", cp);
		// Chamando Função Caso
		Caso();
		// Chamando Função Continuar
		Continuar();
	}
	else if (op == 2)
	{
		// Testar o Insertion sort///////////////////
		printf(">> Insertion sort: \n");
		tc = 0, cp = 0, opr = 0;
		printf(">> Original: ");
		imprimirFinal(vet, TAM);
		// Inserction sort
		Inserction(vet, TAM);
		printf("\n>> Ordenado: ");
		imprimirFinal(vet, TAM);
		printf("\n>> Comparações seguidas de trocas: %i", cp);
		// Chamando Função Caso
		Caso();
		// Chamando Função Continuar
		Continuar();

	}
	else if (op == 3)
	{
		// Testar o Bubble sort
		printf(">> Bubble sort:\n");
		tc = 0, cp = 0, opr = 0;
		printf(">> Original: ");
		imprimirFinal(vet, TAM);
		// Bubble sort
		Bubble(vet, TAM);
		printf("\n>> Ordenado: ");
		imprimirFinal(vet, TAM);
		printf("\n>> Comparações seguidas de trocas: %i", cp);
		// Chamando Função Caso
		Caso();
		// Chamando Função Continuar
		Continuar();
	}
	else if (op == 4)
	{
		// Testar o Heap sort 
		printf(">> Heapsort sort: \n");
		tc = 0, cp = 0, opr = 0;
		printf(">> Original: ");
		imprimirFinal(vet, TAM);
		// Heapsort
		heapsort(vet, TAM);
		printf("\n>> Ordenado: ");
		imprimirFinal(vet, TAM);
		printf("\n>> Comparações seguidas de trocas: %i", cp);
		// Chamando Função Caso
		Caso();
		// Chamando Função Continuar
		Continuar();
	}
	else if (op == 5)
	{
		// Testar o Shell sort
		printf(">> Shell sort: \n");
		tc = 0, cp = 0, opr = 0;
		printf(">> Original: ");
		imprimirFinal(vet, TAM);
		// Shell sort
		shellSort(vet, TAM);
		printf("\n>> Ordenado: ");
		imprimirFinal(vet, TAM);
		printf("\n>> Comparações seguidas de trocas: %i", cp);
		// Chamando Função Caso
		Caso();
		// Chamando Função Continuar
		Continuar();
	}
	else if (op == 6)
	{
		// Testar o Quicksort///////////////////
		printf(">> Quicksort: \n");
		tc = 0, cp = 0, opr = 0;
		printf(">> Original: ");
		imprimirFinal(vet, TAM - 1);
		// Quicksort
		quick(vet, 0, TAM - 1);
		printf("\n>> Ordenado: ");
		imprimirFinal(vet, TAM - 1);
		printf("\n>> Comparações seguidas de trocas: %i", cp);
		// Chamando Função Caso
		Caso();
		// Chamando Função Continuar
		Continuar();
	}
	else
	{
		main();
	}

}

// Melhor Caso, Caso Médio, Pior Caso.
void Caso()
{
	// x = (n*(n-1))/2. Fórmula para achar o pior caso.
	if (op == 2 || op == 3 || op == 5 || op == 6)
	{
		if (cp == ((TAM * (TAM - 1)) / 2))
		{
			printf(". [PIOR CASO].");
		}
		else if (cp > 0 && cp < ((TAM * (TAM - 1)) / 2))
		{
			printf(". [CASO MÉDIO].");
		}
		else if (cp == 0)
		{
			printf(". [MELHOR CASO].");
		}
	}
	else
	{
		printf(". [MESMA COMPLEXIDADE].");
	}
}

// Continuar
void Continuar()
{
	// Variável de controle Y ou N
	char continuar[1];
	// Limpeza do buffer do teclado após scanf 
	fflush(stdin);
	printf("\n\n>> Deseja ordenar os mesmos números com outro Método? Y/sim N/não");
	printf("\n>>");
	scanf("%s", continuar);
	if ((continuar[0] == 'Y') || (continuar[0] == 'y'))
	{
		// Chamando função Menu Continuar
		ContinuarM();
	}
	else if ((continuar[0] == 'N') || (continuar[0] == 'n'))
	{
		printf("\n");
		printf("---------------------------------------------------------------------------\n");
		printf("|                      FIM DA EXECUÇÃO DO PROGRAMA                        |\n");
		printf("---------------------------------------------------------------------------\n");
		Sleep(2000);
		// Chamando Função Logoff
		Logoff();
		exit(0);
	}
	else
	{
		Continuar();
	}
}

// Função Menu do Continuar
void ContinuarM()
{
	////////Design////////////
	// Limpa tela toda vez que for chamado.
	system("cls");
	printf("---------------------------------------------------------------------------\n");
	printf("|                       BEM VINDO AO SISTEMA VOX                          |\n");
	printf("---------------------------------------------------------------------------\n");
	// Limpeza do buffer do teclado após scanf 
	fflush(stdin);
	printf("|                    ESCOLHA AS OPÇÕES PARA CONTINUAR       [-] [?] [×]   |\n");
	printf("---------------------------------------------------------------------------\n");
	printf("\n > Menu:");
	printf("\n  1. Reiniciar O Programa");
	printf("\n  2. Gerar Novas Combinações");
	printf("\n  3. Ordenar Usando Outro Método");
	printf("\n > Resposta: ");
	scanf("%i", &op);
	if (op == 1)
	{
		// Zerando todas as variáveis Globais
		TAM = 0;
		op = 0;
		cp = 0;
		modo = -1;
		num_ale = 0;
		// Zerando todas as casas do vetor
		for (int i = 0; i < TAM; i++)
		{
			vet[i] = 0;
		}
		// Chamando função principal
		main();
	}
	else if (op == 2)
	{
		// Zerando variáveis Globais
		op = 0;
		cp = 0;
		modo = -1;
		num_ale = 0;
		// Chamando Função Menu Escolha de Métodos
		Modo();
	}
	else if (op == 3)
	{
		// Voltando o vetor para ordem orginal.
		for (int i = 0; i < TAM; i++)
		{
			// Voltando o vetor para ordem orginal.
			vet[i] = vet_ori[i];
		}
		// Zerando variáveis Globais
		op = 0;
		// Chamando Função Menu Escolha de Métodos
		MenuE(vet, TAM);
	}
	else
	{
		// Chamando Função Menu Continuar
		ContinuarM();
	}
}

// Imprimir
void imprimirFinal(int vet[], int dir)
{
	for (int i = 0; i < TAM; i++)
		printf("[%i]", vet[i]);
	printf(" Tempo de Custo [%i].\n", tc);
	printf("\n");
}

// Imprimir processo detro das funções;
void imprimir(int vet[], int size)
{
	for (int i = 0; i < TAM; i++)
		printf("[%i]", vet[i]);
	Sleep(255);					// 225 milesegundo.
}

// Selection sort
void selection_sort(int vet[], int tam)
{
	int i, j, min, aux;

	for (i = 0; i < (tam - 1); i++)
	{
		printf("Processando: ");
		imprimir(vet, TAM);
		printf(" TC [%i].", tc);
		printf(" OP [%i].", tc - opr);
		printf("\n");
		opr = tc;				// Atribuindo o valor de tc antes de acumular.
		min = i;
		for (j = (i + 1); j < tam; j++)
		{
			if (vet[j] < vet[min])
				min = j;
			tc++;				// tempo de custo
		}
		if (i != min)
		{
			aux = vet[i];
			vet[i] = vet[min];
			vet[min] = aux;
			cp++;				// Incrementando o Contador de COMPARAÇÕES SEGUIDAS DE TROCAS.
		}
	}
	// Para fins mais didáticos esse campo imprime o último já ordenado.
	printf("Processando: ");
	imprimir(vet, TAM);
	printf(" TC [%i],", tc);
	printf(" OP [%i].", tc - opr);
	printf("\n");
}

// Insertion sort
void Inserction(int vet[], int n)
{
	int j, i, key;
	for (j = 1; j < n; j++)
	{

		printf("Processando: ");
		imprimir(vet, TAM);
		printf(" TC: %i,", tc);
		printf(" OP |%i|.", cp - opr);
		printf("\n");
		opr = cp;				// Atribuindo o valor de tc antes de acumular.

		key = vet[j];
		i = j - 1;
		while (i >= 0 && vet[i] > key)
		{
			vet[i + 1] = vet[i];
			i = i - 1;
			tc++;				// tempo de custo sendo incrementado
			cp++;
		}
		vet[i + 1] = key;
		tc++;					// tempo de custo sendo incrementado
	}
	// Para fins mais didáticos esse campo imprime o último já ordenado.
	printf("Processando: ");
	imprimir(vet, TAM);
	printf(" TC: %i,", tc);
	printf(" OP |%i|.", cp - opr);
	printf("\n");
}

// Bubble sort
void Bubble(int vet[], int n)
{
	int aux;
	for (int i = n - 1; i >= 1; i--)
	{
		printf("Processando: ");
		imprimir(vet, TAM);
		printf(" TC: %i,", tc);
		printf(" OP |%i|.", cp - opr);
		printf("\n");
		opr = cp; // Atribuindo o valor de tc antes de acumular.

		for (int j = 0; j < i; j++)
		{
			if (vet[j] > vet[j + 1])
			{
				aux = vet[j];
				vet[j] = vet[j + 1];
				vet[j + 1] = aux;
				cp++;			// se incrementar essa variavel não é o melhor caso.
				tc++;			// tempo de custo "if" sendo incrementado
			}
		}
		 tc++; // tempo de custo do "for" sendo incrementado
	}
	// Para fins mais didáticos esse campo imprime o último já ordenado.
	printf("Processando: ");
	imprimir(vet, TAM);
	printf(" TC: %i,", tc);
	printf(" OP |%i|.", cp - opr);
	printf("\n");
}

// Heapsort
void heapsort(int vet[], int n)
{
	int i = n / 2, pai, filho, t;
	for (;;)
	{
		if (i == 0)
		{
			printf("Processando: ");
			imprimir(vet, TAM);
			printf(" TC: %i ", tc);
			printf("\n");
		}
		if (i > 0)
		{
			i--;
			t = vet[i];
			cp++;
		}
		else
		{
			n--;
			if (n == 0)
				return;
			t = vet[n];
			vet[n] = vet[0];
			tc++;
			cp++;
		}
		pai = i;
		filho = i * 2 + 1;
		while (filho < n)
		{
			if ((filho + 1 < n) && (vet[filho + 1] > vet[filho]))
				filho++;
			if (vet[filho] > t)
			{
				vet[pai] = vet[filho];
				pai = filho;
				filho = pai * 2 + 1;
				tc++;
			}
			else
			{
				break;
			}
		}
		vet[pai] = t;
		tc++;
	}
}

// Shell sort
void shellSort(int vet[], int size)
{
	int i, j, value, m;
	int gap = 1;
	while (gap < size)
	{
		gap = 3 * gap + 1;
	}
	while (gap > 1)
	{
		gap /= 3;
		for (i = gap; i < size; i++)
		{
			value = vet[i];
			j = i - gap;
			while (j >= 0 && value < vet[j])
			{
				printf("Processando: ");
				imprimir(vet, TAM);
				printf(" TC: %i", tc);
				printf("\n");
				vet[j + gap] = vet[j];
				j -= gap;
				tc++;
				cp++;
			}
			vet[j + gap] = value;
		}
	}
	// Para fins mais didáticos esse campo imprime o último já ordenado.
	printf("Processando: ");
	imprimir(vet, TAM);
	printf(" TC: %i", tc);
	printf("\n");
}

// Quicksort
void quick(int vet[], int esq, int dir)
{
	int pivo = esq, i, ch, j, m;
	printf("Processando: ");
	imprimir(vet, TAM);
	printf(" TC [%i].", tc);
	printf(" OP |%i|.", tc - opr);
	printf("\n");
	opr = tc;					// Atribuindo o valor de tc antes de acumular.
	for (i = esq + 1; i <= dir; i++)
	{
		j = i;
		if (vet[j] < vet[pivo])
		{
			ch = vet[j];
			while (j > pivo)
			{
				vet[j] = vet[j - 1];
				j--;
			}
			vet[j] = ch;
			pivo++;
			tc++;
			cp++;
		}
	}
	if (pivo - 1 >= esq)
	{
		quick(vet, esq, pivo - 1);
	}
	if (pivo + 1 <= dir)
	{
		quick(vet, pivo + 1, dir);
		tc++;
	}
}

// Design
void Teto()
{
	// Limpa tela toda vez que for chamado.
	system("cls");
	system("Color 07");
	printf("---------------------------------------------------------------------------\n");
	printf("|                      BEM VINDO AO SISTEMA VOX                           |\n");
	printf("---------------------------------------------------------------------------\n");
	if (TAM > 0 && TAM < 10)
		printf("|                      Quantidade De Elementos: [%i]                       |\n", TAM);
	if (TAM > 9 && TAM < 100)
		printf("|                      Quantidade De Elementos: [%i]                      |\n", TAM);
	if (TAM > 0)
		printf("---------------------------------------------------------------------------\n");
	if (modo == 1)
		printf("|                      Modo Escolhido: [ALEATÓRIO]                        |\n");
	if (modo == 0)
		printf("|                      Modo Escolhido: [MANUAL]                           |\n");
	if (modo == 0 || modo == 1)
		printf("---------------------------------------------------------------------------\n");
	if (num_ale > 1 && num_ale < 10)
		printf("|                      INTERVALO DE 1 ATÉ: [%i]                            |\n", num_ale);
	if (num_ale > 9 && num_ale < 100)
		printf("|                      INTERVALO DE 1 ATÉ: [%i]                           |\n", num_ale);
	if (num_ale > 99 && num_ale < 1000)
		printf("|                      INTERVALO DE 1 ATÉ: [%i]                          |\n", num_ale);
	if (num_ale > 1)
		printf("---------------------------------------------------------------------------\n");
	if (op == 1)
		printf("|                      Método Escolhido: [SELEÇÃO]                        |\n");
	if (op == 2)
		printf("|                      Método Escolhido: [INSERÇÃO]                       |\n");
	if (op == 3)
		printf("|                      Método Escolhido: [BOLHA]                          |\n");
	if (op == 4)
		printf("|                      Método Escolhido: [HEAPSORT]                       |\n");
	if (op == 5)
		printf("|                      Método Escolhido: [SHELL]                          |\n");
	if (op == 6)
		printf("|                      Método Escolhido: [QUICK]                          |\n");
	if (op >= -999)
		printf("---------------------------------------------------------------------------\n");
	printf("|  ESTA VERSÃO É BETA, PODENDO HAVER ALGUNS BUG's, POR FALTA DE TEMPO...  |\n");
	printf("|...  A ENCERRO, ESPERO QUE APRENDA UM POUCO COM ELA, ASSIM COMO APRENDI. |\n");
	printf("---------------------------------------------------------------------------\n");
	printf("|        Análise de Algoritmos: Melhor caso, pior caso e caso médio.      |\n");
	printf("---------------------------------------------------------------------------\n");

}

// Welcome
void Login()
{
	system("cls");
	system("Color 02");
	printf("____ ____ ____ ____ ____ ____ ____ _  _ ___  ____    ");
	Sleep(400);
	printf("\n|    |__| |__/ |__/ |___ | __ |__| |\\ | |  \\ |  |    ");
	Sleep(400);
	printf("\n|___ |  | |  \\ |  \\ |___ |__] |  | | \\| |__/ |__| ");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf("\n");
	printf("\n___  ____ _  _    _  _ _ _  _ ___  ____    ____ ____ ");
	Sleep(400);
	printf("\n|__] |___ |\\/|    |  | | |\\ | |  \\ |  |    |__| |  | ");
	Sleep(400);;
	printf("\n|__] |___ |  |     \\/  | | \\| |__/ |__|    |  | |__| ");
	Sleep(400);
	printf("\n                                                     ");
	Sleep(400);
	printf("\n____ _ ____ ___ ____ _  _ ____    _  _ ____ _  _ ");
	Sleep(400);
	printf("\n[__  | [__   |  |___ |\\/| |__|    |  | |  |  \\/  ");
	Sleep(400);
	printf("\n___] | ___]  |  |___ |  | |  |     \\/  |__| _/\\_ .");
	Sleep(400);
	printf("\n                                                 ");
	Sleep(400);
}

// Goodbye!
void Logoff()
{
	system("cls");
	system("Color 02");
	printf("___  ____ ____ _    _ ____ ____ _  _ ___  ____ \n");
	Sleep(400);
	printf("|  \\ |___ [__  |    | | __ |__| |\\ | |  \\ |  |\n");
	Sleep(400);
	printf("|__/ |___ ___] |___ | |__] |  | | \\| |__/ |__|");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf("\n");
	printf("____ _ ____ ___ ____ _  _ ____    _  _ ____ _  _\n");
	Sleep(400);
	printf("[__  | [__   |  |___ |\\/| |__|    |  | |  |  \\/ \n");
	Sleep(400);
	printf("___] | ___]  |  |___ |  | |  |     \\/  |__| _/\\_ .\n");
	printf("\n");
	printf("_  _ ____ _    ___ ____    ____ ____ _  _ ___  ____ ____\n");
	Sleep(400);
	printf("|  | |  | |     |  |___    [__  |___ |\\/| |__] |__/ |___\n");
	Sleep(400);
	printf(" \\/  |__| |___  |  |___    ___] |___ |  | |    |  \\ |___ .\n");
	Sleep(1000);
	system("cls");
	system("Color 07");
	exit(0);
}
/* Descrição: Este programa em C, possui 7 variáveis globais, são elas:
	
•	cp: responsável pela contagem de Comparações seguidas de trocas.
•	modo: Modo Aleatória ou Manual de elementos (números) para ordenação.
•	num_ale: Intervalo dos números Aleatórios que vária entre +1 a +999.
•	op: Opção de escolha de Menu, escolhendo qual algoritmo de ordenação usará.
•	opr: Uma variável auxiliar, para armazenar o valor de uma variável, para assim dizer quantos passos o algoritmo usou para deixar o vetor ordenado naquela posição.
•	TAM: Tamanho do vetor, em alguns algoritmos é o mesmo que SIZE.
•	TC: Tempo de custo que cada algotirmo usa para ordenar todo o vetor.

?	Dois Vetores:
	
•	vet[15]: Um vetor de 15 casas, elementos "números".
•	vet_ori[15]: Um vetor de 15 casas, elementos "números". Faz Backup do vet[15].
----------------------------------------------------------------------------------
?	Vinte e uma Funções:

•	int main(): Principal.
•	void QTD(): resposável pela leitura da quantidade de números a ser ordenados.
•	void Modo(): resposável pela leitura do MODO "Aleatório" ou "Manual.
•	void ModoManual(): resposável pela leitura dos números a ser ordenados.
•	void ModoAleatorio(): resposável pela criação de números a ser ordenados.
•	void MenuE(): resposável pela Escolha de Métodos de ordenação.
•	void Caso(): resposável por definir Melhor Caso, Caso Médio, Pior Caso. (Não funciona para o Shell -- Por causa do While!).
•	void Continuar(): resposável pela escolha se deseja continuar interagindo com o Programa.
•	void ContinuarM(): resposável pela escolha se deseja continuar interagindo com o Programa de que forma.
•	void imprimir(): resposável por imprimir o processo enquanto está acontecendo a ordenação.
•	void imprimirFinal(): resposável por imprimir o estado final do vetor ordenado.
•	void selection_sort(): Algoritmo de ordenação.
•	void Inserction(): Algoritmo de ordenação.
•	void Bubble(): Algoritmo de ordenação.
•	void heapsort(): Algoritmo de ordenação.
•	void shellSort(): Algoritmo de ordenação.
•	void quick (): Algoritmo de ordenação.

?	Design:

•	void Teto(): Imprime toda vez o cabeçalho do Programa.
•	void Login(): Tela de Boas-Vindas :D (Em Homenagem a Matrix e A Máquina do Tempo (2002)).
•	void Logoff(): Encerramento do Programa. :(
------------------------------------------------------------------------------------------
Referências:
Para facilitar sua vida eu adaptei todos os algoritmos da Wkipédia para funcionar da forma mais simples e didática possível.
Sem modificações até a data deste programa.

https://pt.wikipedia.org/wiki/Quicksort
https://pt.wikipedia.org/wiki/Heapsort
https://pt.wikipedia.org/wiki/Selection_sort
https://pt.wikipedia.org/wiki/Bubble_sort
https://pt.wikipedia.org/wiki/Insertion_sort
https://pt.wikipedia.org/wiki/Shell_sort

Agradecimentos: A minha Força de Lanterna Verde de Vontade, Meu PC, Meu Not, e ao Profº Walteno Martins.
*/
