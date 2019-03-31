/////////////INFORMA��ES/////////////////////////
// Autor: Marcelo J. Vieira.                 ///
// 5� Per�odo Licenciatura em Computa��o.   ///
// Data:04/02/2017 Vers�o Final 3.4.       /// //Tratamento de erro corrigido.
// Mat�ria: Teoria da Computa��o.         /// //Login & Logoff.
// Contato: dj.marcelo.2009@gmail.com    ///
///////////////////////////////////////////

// Bibliotecas utilizadas //
#include <stdio.h>   	 // Entrada e saida n� Mano. printf(); scanf();
#include <windows.h>    // Por causa da fun��o Sleep();.
#include <time.h>      // Por causa dos c�digos rand�micos. srand( (unsigned)time(NULL) );
#include <locale.h>   // Por causa das acentua��es. setlocale(LC_ALL, "Portuguese");
///////////////////////

///////////////////Vari�eis Globais//////////////////////////////////////////
int tc = 0, op = 0, opr = 0, TAM, cp= 0, modo=-1, num_ale=0;// Inteiros  ///
int vet[15], vet_ori[15]; //Vetores de n�meros inteiros                 ///
//////////////////////////////////////////////////////////////////////////

// PR� CARREGANDO DAS FUN��ES////////////////////////////
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
////Fun��o para acentua��o dos textos////
	setlocale(LC_ALL, "Portuguese");	// 
///////////////////////////////////////
///Fun��o para sempre mudar os rand�micos///
	srand((unsigned)time(NULL));	// 
//////////////////////////////////////////
///////Welcome/////////////
	Login();		//////
/////////////////////////
	// Chamando Fun��o QTD();
	QTD();
}

// Quantidade
void QTD()
{
////////Design////////////
	Teto();		 ////////
////////////////////////
	printf(">> Insira a quantidade de n�meros a ser ordenados: ");
	scanf("%i", &TAM);
	if (TAM >= 1 && TAM <= 15)
	{
		TAM = TAM;
		system("Color 13");
		printf("\n\n>>[VALOR ACEITO]: %i", TAM);
		Sleep(2000);
		// Chamando Fun��o Modo
		Modo();
	}
	else
	{
		system("Color 47");
		printf("\n\n>>[VALOR INV�LIDO] Valores v�lidos s�o inteiros positivos entre 1 a 15.");
		Sleep(3000);
		TAM = 4;
		printf("\n\n>>Atruibuindo valor [%i] padr�o v�lido!", TAM);
		Sleep(3000);
		// Chamando Fun��o Modo
		Modo();
	}

}

// Fun��o MODO "Aleat�rio" ou "Manual.
void Modo()
{
	do
	{
////////Design////////////
		Teto();	 ////////
////////////////////////
		// Limpeza do buffer do teclado ap�s scanf 
		fflush(stdin);
		printf(">> Deseja inserir de [MODO] 'MANUAL' ou 'ALEAT�RIO'?\n");
		printf(">> 0/MANUAL 1/ALEAT�RIO: ");
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
	// Fim da Preven��o.
}

// Modo Manual Selecionado
void ModoManual(int vet[], int TAM)
{
	for (int i = 0; i < TAM; i++)
	{
		// Limpeza do buffer do teclado ap�s scanf 
		fflush(stdin);
		printf("\n>> [%i�] n�mero: ", i + 1);
		scanf("%i", &vet[i]);
		// Backup da ordem orginal do vetor.
		vet_ori[i] = vet[i];
	}
	// Chamando Fun��o Menu Escolha de M�todos
	MenuE(vet, TAM);
}

// Modo Aleat�rio Selecionado
void ModoAleatorio(int vet[], int TAM)
{
	do
	{
////////Design////////////
		Teto();	 ////////
////////////////////////
		// Limpeza do buffer do teclado ap�s scanf 
		fflush(stdin);
		printf(">> Insira o intervalo de 1 at�: ");
		scanf("%i", &num_ale);
	}
	while (num_ale < 1 || num_ale > 999);
	/* Preven��o de erro. */
	if (num_ale > 1 || num_ale < 999)
	{
		num_ale = num_ale;
	}
	else
	{
		ModoAleatorio(vet, TAM);
	}
	/* FIM DA PREVE��O */
	// Preenchendo o Vator.
	for (int i = 0; i < TAM; i++)
	{
		vet[i] = 1 + rand() % num_ale;	// gerando n�meros aleat�rios maiores que 0 "1 +..."
		printf("\n>> [%i�] n�mero: %i.", i + 1, vet[i]);
		// Backup da ordem orginal do vetor.
		vet_ori[i] = vet[i];
		// Esperando 1s para ver qual n�mero foi gerado.
		Sleep(1000);
	}
	// Chamando Fun��o Menu Escolha de M�todos
	MenuE(vet, TAM);
}

// Menu Escolha de M�todos
void MenuE(int vet[], int TAM)
{
	do
	{
////////Design////////////
		Teto();	 ////////
////////////////////////
		// Limpeza do buffer do teclado ap�s scanf 
		fflush(stdin);
		printf("|                    ESCOLHA SEU M�TODO DE ORDENA��O        [-] [?] [�]   |\n");
		printf("\n > Menu:");
		printf("\n  1. Sele��o  |  4. Heapsort");
		printf("\n  2. Inser��o |  5. Shell");
		printf("\n  3. Bolha    |  6. Quick");
		printf("\n > Resposta: ");
		scanf("%i", &op);
	}
	while (op < 1 || op > 6);
	// Chamando Fun��o Menu Todos os M�todos
	MenuM(vet, TAM);
}

// Menu Todos os M�todos
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
		printf("\n>> Compara��es seguidas de trocas: %i", cp);
		// Chamando Fun��o Caso
		Caso();
		// Chamando Fun��o Continuar
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
		printf("\n>> Compara��es seguidas de trocas: %i", cp);
		// Chamando Fun��o Caso
		Caso();
		// Chamando Fun��o Continuar
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
		printf("\n>> Compara��es seguidas de trocas: %i", cp);
		// Chamando Fun��o Caso
		Caso();
		// Chamando Fun��o Continuar
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
		printf("\n>> Compara��es seguidas de trocas: %i", cp);
		// Chamando Fun��o Caso
		Caso();
		// Chamando Fun��o Continuar
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
		printf("\n>> Compara��es seguidas de trocas: %i", cp);
		// Chamando Fun��o Caso
		Caso();
		// Chamando Fun��o Continuar
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
		printf("\n>> Compara��es seguidas de trocas: %i", cp);
		// Chamando Fun��o Caso
		Caso();
		// Chamando Fun��o Continuar
		Continuar();
	}
	else
	{
		main();
	}

}

// Melhor Caso, Caso M�dio, Pior Caso.
void Caso()
{
	// x = (n*(n-1))/2. F�rmula para achar o pior caso.
	if (op == 2 || op == 3 || op == 5 || op == 6)
	{
		if (cp == ((TAM * (TAM - 1)) / 2))
		{
			printf(". [PIOR CASO].");
		}
		else if (cp > 0 && cp < ((TAM * (TAM - 1)) / 2))
		{
			printf(". [CASO M�DIO].");
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
	// Vari�vel de controle Y ou N
	char continuar[1];
	// Limpeza do buffer do teclado ap�s scanf 
	fflush(stdin);
	printf("\n\n>> Deseja ordenar os mesmos n�meros com outro M�todo? Y/sim N/n�o");
	printf("\n>>");
	scanf("%s", continuar);
	if ((continuar[0] == 'Y') || (continuar[0] == 'y'))
	{
		// Chamando fun��o Menu Continuar
		ContinuarM();
	}
	else if ((continuar[0] == 'N') || (continuar[0] == 'n'))
	{
		printf("\n");
		printf("---------------------------------------------------------------------------\n");
		printf("|                      FIM DA EXECU��O DO PROGRAMA                        |\n");
		printf("---------------------------------------------------------------------------\n");
		Sleep(2000);
		// Chamando Fun��o Logoff
		Logoff();
		exit(0);
	}
	else
	{
		Continuar();
	}
}

// Fun��o Menu do Continuar
void ContinuarM()
{
	////////Design////////////
	// Limpa tela toda vez que for chamado.
	system("cls");
	printf("---------------------------------------------------------------------------\n");
	printf("|                       BEM VINDO AO SISTEMA VOX                          |\n");
	printf("---------------------------------------------------------------------------\n");
	// Limpeza do buffer do teclado ap�s scanf 
	fflush(stdin);
	printf("|                    ESCOLHA AS OP��ES PARA CONTINUAR       [-] [?] [�]   |\n");
	printf("---------------------------------------------------------------------------\n");
	printf("\n > Menu:");
	printf("\n  1. Reiniciar O Programa");
	printf("\n  2. Gerar Novas Combina��es");
	printf("\n  3. Ordenar Usando Outro M�todo");
	printf("\n > Resposta: ");
	scanf("%i", &op);
	if (op == 1)
	{
		// Zerando todas as vari�veis Globais
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
		// Chamando fun��o principal
		main();
	}
	else if (op == 2)
	{
		// Zerando vari�veis Globais
		op = 0;
		cp = 0;
		modo = -1;
		num_ale = 0;
		// Chamando Fun��o Menu Escolha de M�todos
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
		// Zerando vari�veis Globais
		op = 0;
		// Chamando Fun��o Menu Escolha de M�todos
		MenuE(vet, TAM);
	}
	else
	{
		// Chamando Fun��o Menu Continuar
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

// Imprimir processo detro das fun��es;
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
			cp++;				// Incrementando o Contador de COMPARA��ES SEGUIDAS DE TROCAS.
		}
	}
	// Para fins mais did�ticos esse campo imprime o �ltimo j� ordenado.
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
	// Para fins mais did�ticos esse campo imprime o �ltimo j� ordenado.
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
				cp++;			// se incrementar essa variavel n�o � o melhor caso.
				tc++;			// tempo de custo "if" sendo incrementado
			}
		}
		 tc++; // tempo de custo do "for" sendo incrementado
	}
	// Para fins mais did�ticos esse campo imprime o �ltimo j� ordenado.
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
	// Para fins mais did�ticos esse campo imprime o �ltimo j� ordenado.
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
		printf("|                      Modo Escolhido: [ALEAT�RIO]                        |\n");
	if (modo == 0)
		printf("|                      Modo Escolhido: [MANUAL]                           |\n");
	if (modo == 0 || modo == 1)
		printf("---------------------------------------------------------------------------\n");
	if (num_ale > 1 && num_ale < 10)
		printf("|                      INTERVALO DE 1 AT�: [%i]                            |\n", num_ale);
	if (num_ale > 9 && num_ale < 100)
		printf("|                      INTERVALO DE 1 AT�: [%i]                           |\n", num_ale);
	if (num_ale > 99 && num_ale < 1000)
		printf("|                      INTERVALO DE 1 AT�: [%i]                          |\n", num_ale);
	if (num_ale > 1)
		printf("---------------------------------------------------------------------------\n");
	if (op == 1)
		printf("|                      M�todo Escolhido: [SELE��O]                        |\n");
	if (op == 2)
		printf("|                      M�todo Escolhido: [INSER��O]                       |\n");
	if (op == 3)
		printf("|                      M�todo Escolhido: [BOLHA]                          |\n");
	if (op == 4)
		printf("|                      M�todo Escolhido: [HEAPSORT]                       |\n");
	if (op == 5)
		printf("|                      M�todo Escolhido: [SHELL]                          |\n");
	if (op == 6)
		printf("|                      M�todo Escolhido: [QUICK]                          |\n");
	if (op >= -999)
		printf("---------------------------------------------------------------------------\n");
	printf("|  ESTA VERS�O � BETA, PODENDO HAVER ALGUNS BUG's, POR FALTA DE TEMPO...  |\n");
	printf("|...  A ENCERRO, ESPERO QUE APRENDA UM POUCO COM ELA, ASSIM COMO APRENDI. |\n");
	printf("---------------------------------------------------------------------------\n");
	printf("|        An�lise de Algoritmos: Melhor caso, pior caso e caso m�dio.      |\n");
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
/* Descri��o: Este programa em C, possui 7 vari�veis globais, s�o elas:
	
�	cp: respons�vel pela contagem de Compara��es seguidas de trocas.
�	modo: Modo Aleat�ria ou Manual de elementos (n�meros) para ordena��o.
�	num_ale: Intervalo dos n�meros Aleat�rios que v�ria entre +1 a +999.
�	op: Op��o de escolha de Menu, escolhendo qual algoritmo de ordena��o usar�.
�	opr: Uma vari�vel auxiliar, para armazenar o valor de uma vari�vel, para assim dizer quantos passos o algoritmo usou para deixar o vetor ordenado naquela posi��o.
�	TAM: Tamanho do vetor, em alguns algoritmos � o mesmo que SIZE.
�	TC: Tempo de custo que cada algotirmo usa para ordenar todo o vetor.

?	Dois Vetores:
	
�	vet[15]: Um vetor de 15 casas, elementos "n�meros".
�	vet_ori[15]: Um vetor de 15 casas, elementos "n�meros". Faz Backup do vet[15].
----------------------------------------------------------------------------------
?	Vinte e uma Fun��es:

�	int main(): Principal.
�	void QTD(): respos�vel pela leitura da quantidade de n�meros a ser ordenados.
�	void Modo(): respos�vel pela leitura do MODO "Aleat�rio" ou "Manual.
�	void ModoManual(): respos�vel pela leitura dos n�meros a ser ordenados.
�	void ModoAleatorio(): respos�vel pela cria��o de n�meros a ser ordenados.
�	void MenuE(): respos�vel pela Escolha de M�todos de ordena��o.
�	void Caso(): respos�vel por definir Melhor Caso, Caso M�dio, Pior Caso. (N�o funciona para o Shell -- Por causa do While!).
�	void Continuar(): respos�vel pela escolha se deseja continuar interagindo com o Programa.
�	void ContinuarM(): respos�vel pela escolha se deseja continuar interagindo com o Programa de que forma.
�	void imprimir(): respos�vel por imprimir o processo enquanto est� acontecendo a ordena��o.
�	void imprimirFinal(): respos�vel por imprimir o estado final do vetor ordenado.
�	void selection_sort(): Algoritmo de ordena��o.
�	void Inserction(): Algoritmo de ordena��o.
�	void Bubble(): Algoritmo de ordena��o.
�	void heapsort(): Algoritmo de ordena��o.
�	void shellSort(): Algoritmo de ordena��o.
�	void quick (): Algoritmo de ordena��o.

?	Design:

�	void Teto(): Imprime toda vez o cabe�alho do Programa.
�	void Login(): Tela de Boas-Vindas :D (Em Homenagem a Matrix e A M�quina do Tempo (2002)).
�	void Logoff(): Encerramento do Programa. :(
------------------------------------------------------------------------------------------
Refer�ncias:
Para facilitar sua vida eu adaptei todos os algoritmos da Wkip�dia para funcionar da forma mais simples e did�tica poss�vel.
Sem modifica��es at� a data deste programa.

https://pt.wikipedia.org/wiki/Quicksort
https://pt.wikipedia.org/wiki/Heapsort
https://pt.wikipedia.org/wiki/Selection_sort
https://pt.wikipedia.org/wiki/Bubble_sort
https://pt.wikipedia.org/wiki/Insertion_sort
https://pt.wikipedia.org/wiki/Shell_sort

Agradecimentos: A minha For�a de Lanterna Verde de Vontade, Meu PC, Meu Not, e ao Prof� Walteno Martins.
*/
