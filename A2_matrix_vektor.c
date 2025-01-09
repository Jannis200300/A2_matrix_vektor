#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ZEILEN 4
#define SPALTEN 4

int matrix_a[ZEILEN][SPALTEN];
int vektor_a[ZEILEN];
int vektor_b[ZEILEN];

/* Funktion zur Initialisierung von Matrix und Vektor */
void initialize_matrix_and_vector() {
    int i, j;
    for (i = 0; i < ZEILEN; i++) {
        for (j = 0; j < SPALTEN; j++) {
            matrix_a[i][j] = (rand() % 64) - 32; /* Werte von -32 bis 31 */
        }
        vektor_a[i] = (rand() % 64) - 32; /* Werte von -32 bis 31 */
    }
}

/* Funktion zur Matrix-Vektor-Multiplikation */
void matrix_vector_multiplication() {
    int i, j;
    for (i = 0; i < ZEILEN; i++) {
        vektor_b[i] = 0;
        for (j = 0; j < SPALTEN; j++) {
            vektor_b[i] += matrix_a[i][j] * vektor_a[j];
        }
    }
}

/* Funktion zur Ausgabe der Matrix und Vektoren */
void print_matrix_and_vectors() {
    int i, j;
    printf("Matrix A:\n");
    for (i = 0; i < ZEILEN; i++) {
        for (j = 0; j < SPALTEN; j++) {
            printf("%4d ", matrix_a[i][j]);
        }
        printf("\n");
    }
    printf("\nVektor A:\n");
    for (i = 0; i < ZEILEN; i++) {
        printf("%4d\n", vektor_a[i]);
    }
    printf("\nErgebnisvektor B:\n");
    for (i = 0; i < ZEILEN; i++) {
        printf("%4d\n", vektor_b[i]);
    }
}

int main() {
    double timeEnd, timeBegin;

    timeBegin = clock();

    srand((unsigned int)time(NULL));
    initialize_matrix_and_vector();
    matrix_vector_multiplication();
    print_matrix_and_vectors();

    timeEnd= clock();
    printf("Clock ticks started at: %f\n", timeBegin);
    printf("Clock ticks ended at: %f\n", timeEnd);
    timeEnd = timeEnd - timeBegin;
    printf("Clock ticks needed: %f\n", timeEnd);
    timeEnd = timeEnd / CLOCKS_PER_SEC;
    printf("Time needed in seconds: %f\n", timeEnd);
    return 0;
}
