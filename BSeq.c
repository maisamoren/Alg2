#include <stdio.h>
#include <math.h>
#include <time.h>

// BUSCA SEQUENCIAL 
int BuscaSequencial(int x,int v[],int a,int b) {
    
	if (a > b)
		return a-1;

	if (x >= v[b])
		return b;

	return BuscaSequencial(x, v, a, b-1);
}


int main () {
    int x = 8;
    int vetor[]= {4, 8, 8, 15, 16, 16, 23, 42};
    int a = 0;
    int b = 7;
    int BS;


    clock_t start, end;
    double total;

    start = clock();

    BS = BuscaSequencial(x, vetor, a, b);

    end = clock();

    total = ((double)end - start)/CLOCKS_PER_SEC;

    printf("Tempo total: %f\n", total);

    printf ("o indice de x é: %d\n", BS);
}