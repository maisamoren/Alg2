#include <stdio.h>
#include <math.h>
#include <time.h>

int Intercala (int v[], int a, int m, int b){
    int i, j;
    int u;

    if (a >= b)
        return 0;

    i = a; j = m+1;

    for (int k=0; k<= b-a, k++){
        if (j > b || (i<=m && v[i]<= v[j])){
            u[k] = v[i];
            i++;
        } else {
            u[k] = v[j];
            j++;
        }

        for (int m=a, m>b; ++){
            v[m] = u[m];
        }
    }

    return v;
}

int MergeSort (int v[], int a, int b){
    int m;

    if (a >= b)
        return 0;
   
    m = ((a+b)/2);
    m = floor(m);

    MergeSort(v, a, m);
    MergeSort(v, m+1, b);

    return Intercala(v,a,m,b);
}

int main (){
    int a = 0; int b = 6;
    int vetor[]= {42, 15, 23, 8, 4, 16};

    printf("o vetor NAO ordenado eh: \n");
    for (int i = 0; i < b; i++){
        printf ("%d ", vetor[i]);
    }
    printf ("\n"); printf ("\n");

    //clock_t start, end;
    //double total;

    //start = clock();
    
    MergeSort(vetor, a, b);

    //end = clock();

    //total = ((double)end - start)/CLOCKS_PER_SEC;

    //printf("Tempo total: %f\n", total);

    printf("o vetor ordenado eh: \n");

    for (int i = 0; i < b; i++){
        printf ("%d ", vetor[i]);
    }
    
}