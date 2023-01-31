#include <stdio.h>
#include <math.h>
#include <time.h>

void Intercala (int v[], int a, int m, int b){
    int i, j, k;
    int es = m - a + 1;
    int di = b - m;

    int E[es], D[di];

    for (i = 0; i < es; i++)
        E[i] = v[a + i];

    for (j = 0; j < di; j++)
        D[j] = v[m + 1 + j];

    i = 0; j = 0; k = a;

    while (i < es && j < di) {
        if (E[i] <= D[j]) {
            v[k] = E[i];
            i++;
        } else {
            v[k] = D[j];
            j++;
        }
        k++;
    }

    while (i < es) {
        v[k] = E[i];
        i++;
        k++;
    }

    while (j < di) {
        v[k] = D[j];
        j++;
        k++;
    }
}

void MergeSort (int v[], int a, int b){
    
    int m = ((a+b)/2);
    m = floor(m);

    if (a < b) {
        MergeSort(v, a, m);
        MergeSort(v, m+1, b);

        Intercala(v,a,m,b);
    }
}

int main (){
    int a = 0; 
    
    int b = 9;
    int vetor[]= {42, 15, 23, 8, 4, 16, 45, 17, 20, 6};

    printf ("\n");

    printf("O vetor NAO ordenado é: \n");
    printf ("vetor [%d] = ", b+1);
    for (int i = 0; i <= b; i++){
        printf ("%d ", vetor[i]);
    }
    printf ("\n");  printf ("\n");

    clock_t start, end;
    double total;

    start = clock();
    
    MergeSort(vetor, a, b);

    end = clock();

    total = ((double)end - start)/CLOCKS_PER_SEC;

    printf("O tempo levado para execução foi de: %f\n", total);

    printf ("\n");

    printf("O vetor ordenado é: \n");
    printf ("vetor [%d] = ", b+1);
    for (int i = 0; i <= b; i++){
        printf ("%d ", vetor[i]);
    }
    printf ("\n");  printf ("\n");
    
    return 0;
}