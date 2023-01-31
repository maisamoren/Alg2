#include <stdio.h>
#include <math.h>
#include <time.h>

void Troca (int v[], int i, int maior){
    int aux = v[i];
    v[i] = v[maior];
    v[maior] = aux;
}

void max_heapify (int v[], int n, int i){
    int esq, dir, maior;

    esq = 2*i + 1;
    dir = 2*i + 2;
    maior = i;

    if (esq < n && v[esq] > v[maior]){
        maior = esq; 
    } 

    if (dir < n && v[dir] > v[maior]){
        maior = dir; 
    }

    if (maior != i){ 
        Troca (v, i, maior);
        max_heapify (v, n, maior);
    }
}

void build_max_heap (int v[], int n){

    for (int i = n / 2; i >= 0; i--){
        max_heapify (v, n, i);
    }

}

void HeapSort (int v[], int n){

    build_max_heap (v, n);

    for (int i = n; i >= 1; i--){
        
        // troca 
        Troca (v, 0, i);

        max_heapify (v, i, 0);
    }
}


int main (){
    int n = 9;
    int vetor[] = {5, 0, 5, 4, 7, 4, 7, 4, 2, 0};
    // int* vetor = malloc(n * sizeof(int));

    // srand(time(0));
    // for (int i = 0; i < n; i++){
    //     vetor[i] = rand() % 10;
    // }

    printf ("\n");

    printf("O vetor NAO ordenado é: \n");
    printf ("vetor [%d] = ", n+1);
    for (int i = 0; i <= n; i++){
        printf ("%d ", vetor[i]);
    }
    printf ("\n");  printf ("\n");


    clock_t start, end;
    double total;

    start = clock();
    
    HeapSort(vetor, n);

    end = clock();

    total = ((double)end - start)/CLOCKS_PER_SEC;

    printf("O tempo levado para execução foi de: %f\n", total);

    printf ("\n");

    printf("O vetor ordenado é: \n");
    printf ("vetor [%d] = ", n+1);
    for (int i = 0; i <= n; i++){
        printf ("%d ", vetor[i]);
    }
    printf ("\n");  printf ("\n");

    
    return 0;
}