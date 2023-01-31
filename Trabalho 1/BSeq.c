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
    int BS; int a = 0;

    // int x = 8; int b = 4;
    // int vetor[] = {4, 8, 8, 15, 23};

    int x = 82; int b = 15;
    int vetor[]= {6, 7, 7, 18, 25, 25, 48, 55, 78, 82, 82, 96, 97, 99, 105};

    printf ("\n");
    printf ("O valor que estamos buscando é: x = %d\n", x);
    printf ("\n");

    printf("O vetor ordenado é: \n");
    printf ("vetor [%d] = ", b+1);
    for (int i = 0; i <= b; i++){
        printf ("%d ", vetor[i]);
    }
    printf ("\n");  printf ("\n");

    clock_t start, end;
    double total;
    start = clock();

    BS = BuscaSequencial(x, vetor, a, b);

    end = clock();
    total = ((double)end - start)/CLOCKS_PER_SEC;

    printf("O tempo levado para execução foi de: %f\n", total);
    printf ("\n");

    printf ("O indice de x é: %d\n", BS);
    printf ("\n");
}