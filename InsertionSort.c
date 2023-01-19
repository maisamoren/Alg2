#include <math.h>
#include <stdio.h>

void Insere (int v[], int a, int b){
    int aux;
        if (v[a] > v[b]){
            aux = v[a];
            v[a] = v[b];
            v[b] = aux; 
        }
        return v[];
}

void Ordena(int v[], int a, int b) {
	if (a >= b){
        return v[];
    }
    Ordena (v, a, b-1);
    Insere (v, a, b);

    return v[];
}

int main() {
	int v[] = {42, 15, 23, 8, 4, 16};
    int a = 0; int b = 5;

	Ordena(v, a, b);
    
	return 0;
}
