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
    int a = 0; int b = 9;
    int vetor[]= {42, 15, 23, 8, 4, 16, 45, 17, 20, 6};

    printf ("\n");

    printf("O vetor NAO ordenado é: \n");
    printf ("vetor [%d] = ", b+1);
    for (int i = 0; i <= b; i++){
        printf ("%d ", vetor[i]);
    }
    printf ("\n"); printf ("\n");

    clock_t start, end;
    double total;

    start = clock();
    
    SelectionSort(vetor, a, b);

    end = clock();

    total = ((double)end - start)/CLOCKS_PER_SEC;

    printf("O tempo levado para execução foi de: %f\n", total);

    printf ("\n");

    printf("O vetor ordenado é: \n");
    printf ("vetor [%d] = ", b+1);
    for (int i = 0; i <= b; i++){
        printf ("%d ", vetor[i]);
    }
    printf ("\n"); printf ("\n");
    
    return 0;
}