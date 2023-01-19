#include <stdio.h>
#include <math.h>

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

    printf ("o indice de x é: %d\n", m);
}

int main(){
    int x = 8;
    int vetor[]= {4, 7, 8, 15, 16, 17, 23, 42};
    int a = 0;
    int b = 7;
    
    BuscaBinaria (x, vetor, a, b);
}