#include <stdio.h>
#include <math.h>
#include <time.h>

void Troca (int v[], int m, int i){
    int aux;

    if (v[m] > v[i]){
        aux = v[m];
        v[m] = v[i];
        v[i] = aux;
    }

}

int Particiona (int v[], int a, int b, int x){
    int m;

    m = a - 1;
    for (int i = a; i <= b; i ++){

        if (v[i] <= x){
            m++;
            Troca(v, m, i);
        }
    }

    return m;
}

int QuickSort (int v[], int a, int b){
    int m;

    if (a >= b)
        return 0;

    m = Particiona(v, a, b, v[b]);

    QuickSort(v, a, m-1);
    QuickSort(v, m+1, b);

    return 0;
}

int main (){
    int a = 0; int b = 5;
    int vetor[]= {42, 15, 23, 8, 4, 16};

    printf("o vetor NAO ordenado eh: \n");
    for (int i = 0; i <= b; i++){
        printf ("%d ", vetor[i]);
    }
    printf ("\n"); printf ("\n");

    //clock_t start, end;
    //double total;

    //start = clock();
    
    SelectionSort(vetor, a, b);

    //end = clock();

    //total = ((double)end - start)/CLOCKS_PER_SEC;

    //printf("Tempo total: %f\n", total);

    printf ("\n");

    printf("o vetor ordenado eh: \n");

    for (int i = 0; i <= b; i++){
        printf ("%d ", vetor[i]);
    }

    printf ("\n"); printf ("\n");
    
    return 0;
}