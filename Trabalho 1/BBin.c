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
 int BB; int a = 0;

    int x = 15; int b = 4;
    int vetor[] = {3, 7, 8, 15, 23};

    // int x = 55; int b = 15;
    // int vetor[]= {6, 7, 9, 18, 24, 25, 48, 55, 78, 80, 82, 96, 97, 99, 105};

    printf ("\n");
    printf ("o valor que estamos buscando é: x = %d\n", x);
    printf ("\n");

    printf("O vetor ordenado é: \n");
    printf ("vetor [%d] = ", b+1);

    for (int i = 0; i < b; i++){
        printf ("%d ", vetor[i]);
    }
    printf ("\n");  printf ("\n");

    clock_t start, end;
    double total;
    start = clock();
    
    BB = BuscaBinaria(x, vetor, a, b);

    end = clock();
    total = ((double)end - start)/CLOCKS_PER_SEC;

    printf("o tempo levado para execução foi de: %f\n", total);
    printf ("\n");

    printf ("o indice do valor de x é: %d\n", BB);
    printf ("\n");
}