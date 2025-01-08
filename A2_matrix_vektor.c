#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ZEILEN 4
#define SPALTEN 4

int matrix_a[ZEILEN][SPALTEN];
int vektor_a[ZEILEN];
int vektor_b[ZEILEN];

int main(void) {
    int c[3];
    int i = 0, j = 0;
    srand((unsigned int)time(NULL)); /* vorgegeben */
    printf("Kontrolle:");
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            matrix_a[i][j] = (rand() % 64) - 32; /* vorgegeben */
            printf("%4d",matrix_a[i][j]);

        }
    }
    for(i=0; i<4; i++) {
        vektor_b[i]= (rand() % 64) - 32;
    }
    printf("\n Matrix A:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            c[i] += matrix_a[i][j] * vektor_b[j];
            printf("%4d",matrix_a[i][j]);
        }
        printf("\n");
    }
    printf("\nVektor b:\n");
    for (j = 0; j < 4; j++) {
        printf("%4d\n", vektor_b[j]);
    }
    printf("\nErgebnisvektor c:\n");
    for (i = 0; i < 4; i++) {
        printf("%4d\n", c[i]);
    }
    return 0;



}