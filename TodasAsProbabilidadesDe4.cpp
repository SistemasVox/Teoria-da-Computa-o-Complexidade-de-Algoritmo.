/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Marcelo
 *
 * Created on 24 de Maio de 2019, 00:26
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int diferente(int n, int j, int k, int l);

int main(int argc, char **argv) {
    int TAM = 4;
    int cont = 0;
    int i, j, k, l;
    for (i = 1; i <= TAM; i++) {
        for (j = 1; j <= TAM; j++) {
            for (k = 1; k <= TAM; k++) {
                for (l = 1; l <= TAM; l++) {
                    if (diferente(i, j, k, l) && diferente(j, i, k, l) && diferente(k, j, i, l) &&
                        diferente(l, j, k, i)) {
                        printf("%i %i %i %i.\n", i, j, k, l);
                        cont++;
                    }
                }
            }
        }
        printf("\n");
    }
    printf("%i", cont);
    return (EXIT_SUCCESS);
}

int diferente(int n, int j, int k, int l) {
    if (n != j && n != k && n != l) {
        return 1;
    } else {
        return 0;
    }

}