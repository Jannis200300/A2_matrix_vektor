#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ZEILEN 4
#define SPALTEN 4

int matrix_a[200][200];
int vektor_a[200];
int vektor_b[200];
long zwischenwert = 0;

/* Funktion zur Initialisierung von Matrix und Vektor */
void initialize_matrix_and_vector(int const a, int const b) {
    int i, j;
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            matrix_a[i][j] = (rand() % 64) - 32; /* Werte von -32 bis 31 */
        }
        vektor_a[i] = (rand() % 64) - 32; /* Werte von -32 bis 31 */
    }
}

/* Funktion zur Matrix-Vektor-Multiplikation */
void matrix_vector_multiplication(int const a, int const b) {
    int i, j;
    for (i = 0; i < a; i++) {
        vektor_b[i] = 0;
        for (j = 0; j < b; j++) {
            vektor_b[i] += matrix_a[i][j] * vektor_a[j];
            zwischenwert += vektor_b[i];
        }
    }
}

/* Funktion zur Ausgabe der Matrix und Vektoren */
void print_matrix_and_vectors(int const a, int const b) {
    int i, j;
    printf("Matrix A:\n");
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            printf("%4d ", matrix_a[i][j]);
        }
        printf("\n");
    }
    printf("\nVektor A:\n");
    for (i = 0; i < a; i++) {
        printf("%4d\n", vektor_a[i]);
    }
    printf("\nErgebnisvektor B:\n");
    for (i = 0; i < a; i++) {
        printf("%4d\n", vektor_b[i]);
    }
}

int main() {
    double timeEnd, timeBegin;
    int i;
    for(i=-2;i<=197;i++) {

        timeBegin = clock();
        srand((unsigned int)time(NULL));
        initialize_matrix_and_vector(ZEILEN+i,SPALTEN+i);
        matrix_vector_multiplication(ZEILEN+i,SPALTEN+i);
        /*
        print_matrix_and_vectors(ZEILEN+i,SPALTEN+i);
        */
        printf("\nDimension %d x %d \n",i+3,i+3);
        printf("Zwischenergebniss: %d",zwischenwert);

        timeEnd= clock();
        printf("\nClock ticks started at: %f\n", timeBegin);
        printf("Clock ticks ended at: %f\n", timeEnd);
        timeEnd = timeEnd - timeBegin;
        printf("Clock ticks needed: %f\n", timeEnd);
        timeEnd = timeEnd / CLOCKS_PER_SEC;
        printf("Time needed in seconds: %f\n", timeEnd);
    }
    return 0;
}
