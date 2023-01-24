#include <stdio.h>
#include <math.h>
#include <time.h>

int Minimo (int v[], int a, int b){
    int m;

    if (a == b) 
        return a;

    m = Minimo(v, a, b-1);
    
    if (v[b] < v[m])
        m = b;

    return m;
}

void Troca (int v[], int i, int j){
    int aux;

    if (v[i] > v[j]){
        aux = v[i];
        v[i] = v[j];
        v[j] = aux;
    }
}

int SelectionSort (int v[], int a, int b){

    if (a > b)
        return 0;
    Troca(v, a, Minimo(v,a,b));
    
    return SelectionSort(v, a+1, b);
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