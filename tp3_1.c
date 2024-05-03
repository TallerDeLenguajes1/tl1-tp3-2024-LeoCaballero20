#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int matrizProduccion[5][12];
    int *puntMatriz;
    puntMatriz = matrizProduccion;
    srand(time(NULL));
    for (int i=0; i<60; i++) {
        *(puntMatriz + i) = 10000 + rand()%40001;
    }

    for (int i=0; i<5; i++) {
        printf("\nAño número %d:\n", i+1);
        for (int j=0; j<12; j++) {
            printf("Mes %d: %d\n", j+1, *(puntMatriz + (i*12+j)));
        }
    }
    
    for (int i=0; i<5; i++) {
        int suma=0;
        for (int j=0; j<12; j++) {
            suma += *(puntMatriz+(i*12+j));
        }
        int promedio = suma/12;
        printf("\nEl promedio del %dº año es %d\n",i+1,promedio);
    }

    int max = 10000;
    int min = 50000;
    int anioMax, mesMax, anioMin, mesMin;
    for (int i=0; i<5; i++) {
        for (int j=0; j<12; j++) {
            if(*(puntMatriz+(i*12+j))>max) {
                max = *(puntMatriz+(i*12+j));
                anioMax = i+1;
                mesMax = j+1;
            }
            if (*(puntMatriz+(i*12+j))<min){
                min = *(puntMatriz+(i*12+j));
                anioMin = i+1;
                mesMin = j+1;
            }
        }
    }
    printf("\nEl valor máximo ocurrió el mes %d del año %d y fue %d\n", mesMax, anioMax, max);
    printf("El valor mínimo ocurrió el mes %d del año %d y fue %d\n", mesMin, anioMin, min);
}