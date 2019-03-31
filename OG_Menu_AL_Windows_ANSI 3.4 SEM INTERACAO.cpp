/////////////INFORMAÇÕES/////////////////////////
// Autor: Marcelo J. Vieira.                 ///
// 5º Período Licenciatura em Computação.   ///
// Data:04/02/2017 Versão Final 3.4.       /// //Tratamento de erro corrigido.
// Matéria: Teoria da Computação.         /// //Login & Logoff.
// Contato: dj.marcelo.2009@gmail.com    ///
///////////////////////////////////////////

/* Versão final sem interação com usuário (sem entrada de dados). */

// Bibliotecas utilizadas //
#include <stdio.h>   	 // Entrada e saida né Mano. printf(); scanf();
#include <windows.h>    // Por causa da função Sleep();.
#include <time.h>      // Por causa dos códigos randômicos. srand( (unsigned)time(NULL) );
#include <locale.h>   // Por causa das acentuações. setlocale(LC_ALL, "Portuguese");
///////////////////////

///////////////////Variáeis Globais/////////////////
int tc = 0, tc_antes = 0, TAM = 5, cp = 0, op; ////
int vet[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; ///
/////////////////////////////////////////////////

// PRÉ CARREGANDO DAS FUNÇÕES ///////////////////////////
void quick(int vet[], int esq, int dir);         ///////
void imprimirFinal(int vet[], int dir);         ///////
void heapsort(int vet[], int n);               ///////
void Inverter(int vet[]);                     ///////
void shellSort(int vet[], int size);         ///////
void imprimir(int vet[], int size);         /////// 
void selection_sort(int vet[], int tam);   ///////
void Inserction(int vet[], int n);        ///////
void Bubble(int vet[], int n);           ///////
///////////////////////////////////////////////

int main()
{
/*
	// /Testar o Selection sort///////////////////
	printf(">> Selection sort: \n");
	Inverter(vet);
	tc = 0, tc_antes = 0, cp = 0;
	printf(">> Original: ");
	imprimirFinal(vet, TAM);
	// Selection sort
	selection_sort(vet, TAM);
	printf("\n>> Ordenado: ");
	imprimirFinal(vet, TAM);
	printf("\n>> Comparacoes seguida de trocas: %d",cp);

	// /Testar o Heap sort///////////////////
	printf(">> Heapsort sort: \n");
	//Inverter(vet);
	tc = 0, tc_antes = 0, cp = 0;
	printf(">> Original: ");
	imprimirFinal(vet, TAM);
	// Heapsort
	heapsort(vet, TAM);
	printf("\n>> Ordenado: ");
	imprimirFinal(vet, TAM);
	printf("\n>> Comparacoes seguida de trocas: %d",cp);

	// /Testar o Insertion sort///////////////////
	printf(">> Insertion sort: \n");
	//Inverter(vet);
	tc = 0, tc_antes = 0, cp = 0;
	printf(">> Original: ");
	imprimirFinal(vet, TAM);
	// Inserction sort
	Inserction(vet, TAM);
	printf("\n>> Ordenado: ");
	imprimirFinal(vet, TAM);
	printf("\n>> Comparacoes seguida de trocas: %d",cp);

	// Testar o Shell sort///////////////////
	printf(">> Shell sort: \n");
	Inverter(vet);
	tc = 0, tc_antes = 0, cp = 0;
	printf(">> Original: ");
	imprimirFinal(vet, TAM);
	// Shell sort
	shellSort(vet, TAM);
	printf("\n>> Ordenado: ");
	imprimirFinal(vet, TAM);
	printf("\n>> Comparacoes seguida de trocas: %d",cp);

	// Testar o Bubble sort///////////////////
	printf(">> Bubble sort:\n");
	//Inverter(vet);
	tc = 0, tc_antes = 0, cp = 0;
	printf(">> Original: ");
	imprimirFinal(vet, TAM);
	// Bubble sort
	Bubble(vet, TAM);
	printf("\n>> Ordenado: ");
	imprimirFinal(vet, TAM);
	printf("\n>> Comparacoes seguida de trocas: %d",cp);

	// Testar o Quicksort///////////////////
	printf(">> Quicksort: \n");
	//Inverter(vet);
	tc = 0, tc_antes = 0, cp = 0;
	printf(">> Original: ");
	imprimirFinal(vet, TAM - 1);
	// Quicksort
	quick(vet, 0, TAM - 1);
	printf("\n>> Ordenado: ");
	imprimirFinal(vet, TAM - 1);
	printf("\n>> Comparacoes seguida de trocas: %d",cp);
*/
}

// Imprimir
void imprimirFinal(int vet[], int dir)
{
	for (int i = 0; i < TAM; i++)
		printf("[%d]", vet[i]);
	printf(" Tempo de Custo [%i].\n", tc);
	printf("\n");
}

// Imprimir processo detro dos das fun??es;
void imprimir(int vet[], int size)
{
	for (int i = 0; i < TAM; i++)
		printf("[%d]", vet[i]);
	Sleep(255);
}

// Selection sort
void selection_sort(int vet[], int tam)
{
	int i, j, min, aux, op;

	for (i = 0; i < (tam - 1); i++)
	{
		printf("Processando: "); 
		imprimir(vet, TAM);
		printf(" TC [%i],", tc);
		printf(" OP [%i].", tc - op);
		printf("\n");
		min = i;
		op=tc;
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
		} 
	}
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
		printf(" OP |%i|.", cp - op);
		printf("\n");
		op = cp; // Atribuindo o valor de tc antes de acumular.

		key = vet[j];
		i = j - 1;
		while (i >= 0 && vet[i] > key)
		{
			vet[i + 1] = vet[i];
			i = i - 1;
			tc++;				// tempo de custo sendo incrementado
			cp++;
		}
		vet[i + 1] = key; tc++;// tempo de custo sendo incrementado
	}
	printf("Processando: ");
	imprimir(vet, TAM);
	printf(" TC: %i,", tc);
	printf(" OP |%i|.", cp - op);
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
		printf(" OP |%i|.", cp - op);
		printf("\n");
		op = cp; // Atribuindo o valor de tc antes de acumular.

		for (int j = 0; j < i; j++)
		{
			if (vet[j] > vet[j + 1])
			{
				aux = vet[j];
				vet[j] = vet[j + 1];
				vet[j + 1] = aux;
				cp++;// se incrementar essa variavel n?? melhor caso. CP = COMPRARA?ES;	
				tc++;// tempo de custo "if" sendo incrementado
			}
		}
		tc++;// tempo de custo do "for" sendo incrementado
	}
	// Para fins mais didáticos esse campo imprime o último já ordenado.
	printf("Processando: ");
	imprimir(vet, TAM);
	printf(" TC: %i,", tc);
	printf(" OP |%i|.", cp - op);
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
	printf(" OP |%i|.", tc - op);
	printf("\n");
	op = tc; // Atribuindo o valor de tc antes de acumular.
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

// Inverter
void Inverter(int vet[])
{
	int aux = TAM + 1;
	for (int i = 0; i < TAM; i++)
	{
		vet[i] = aux - 1;
		aux--;
	}
}
