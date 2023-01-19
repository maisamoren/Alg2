#include <stdio.h>
#include <math.h>
#include <time.h>

// BUSCA BINARIA 
int BuscaBinaria(int x,int v[],int a,int b) {
    int m;

        if (a > b)
            return 0;              // 0 = falso 
        
        m = ((a+b)/2);
        m = floor(m);

        if (x == (v[m]))
            return m;

        if (x < (v[m]))
            return BuscaBinaria(x, v, a, m-1);

        return BuscaBinaria(x, v, m+1, b);
}

int main(){
    int x = 8;
    int vetor[]= {4, 7, 8, 15, 16, 17, 23, 42};
    int a = 0;
    int b = 7;
    int bin;


    clock_t start, end;
    double total;

    start = clock();
    bin = BuscaBinaria (x, vetor, a, b);

    end = clock();

    total = ((double)end - start)/CLOCKS_PER_SEC;

    printf("Tempo total: %f\n", total);

    printf ("o indice de x é: %d\n", bin);
}