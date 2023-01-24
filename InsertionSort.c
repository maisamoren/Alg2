#include <stdio.h>
#include <math.h>
// #include <time.h>

int Busca (int x, int v[], int a, int b){
    
    if (a > b)
        return 0;   // 0 para falso
    if (x == v[b])
        return b;
    return Busca(x, v, a, b-1);
}

void Troca (int v[], int i, int j){
int aux;

    if (v[i] > v[j]){
        aux = v[i];
        v[i] = v[j];
        v[j] = aux;
    }
}

void Insere (int v[], int a, int b){
    int p, i;

    p = Busca (v[b], v, a, b-1);
    i = b;

    while (i > p+1){
        Troca (v, i, i-1);
        i--;

        for (int i = 0; i < b; i++){
            printf ("%d ", v[i]);
        }
        printf ("\n");
    }

    //return v;
}

int Ordena(int v[], int a, int b) {

	if (a > b)
        return 0;

    Ordena (v, a, b-1);
    Insere (v, a, b);

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
