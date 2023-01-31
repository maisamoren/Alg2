#include <stdio.h>
#include <math.h>
#include <time.h>

int Busca (int x, int v[], int a, int b){
    
    if (a >= b)
        return 0;   // 0 para falso
    if (x == v[b])
        return b;
    return Busca(x, v, a, b-1);
}

void Troca (int v[], int i, int j){
int aux;

    if (v[i] < v[j]){
        aux = v[i];
        v[i] = v[j];
        v[j] = aux;
    }
}

int *Insere (int v[], int a, int b){
    int p, i;

    p = Busca (v[b], v, a, b-1);
    i = b;

    while (i > p){
        Troca (v, i, i-1);
        i--;

        // for (int i = 0; i < b; i++){
            // printf ("%d ", v[i]);
        // }
        // printf ("\n");
    }

    return v;
}

int *Ordena(int v[], int a, int b) {

	if (a > b)
        return v;

    Ordena (v, a, b-1);
    Insere (v, a, b);

    return v;
}

int main (){
    int *O; int a = 0; int b = 9;
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
    
    O = Ordena(vetor, a, b);

    end = clock();

    total = ((double)end - start)/CLOCKS_PER_SEC;

    printf("O tempo levado para execução foi de: %f\n", total);

    printf ("\n");

    printf("O vetor ordenado é: \n");
    printf ("vetor [%d] = ", b+1);
    for (int i = 0; i <= b; i++){
        printf ("%d ", O[i]);
    }
    printf ("\n");  printf ("\n");

    return 0;
}
