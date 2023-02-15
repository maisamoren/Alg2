#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct {
    float peso;
    float valor;
} presente;


void ajudante_noel(float p_max, int indice, int n, presente saco[], bool sol_aux[], int *soma_valor, bool v_solucao[]) {
    
    if (indice == n) {  // caso base

        float aux_valor = 0;
        for (int i = 0; i < n; i++) {
            if (sol_aux[i]) {
                aux_valor = aux_valor + saco[i].valor;
            }
        }

        if (aux_valor > *soma_valor) {
            *soma_valor = aux_valor;
            for (int i = 0; i < n; i++) {
                v_solucao[i] = sol_aux[i];
            }
        } // se a resposta tiver valor maior q o maior -> muda o maior

        return;
    }
    
    if (saco[indice].peso <= p_max) {
        sol_aux[indice] = true;
        ajudante_noel(p_max - saco[indice].peso, indice+1, n, saco, sol_aux, soma_valor, v_solucao);
    }
    
    sol_aux[indice] = false;
    ajudante_noel(p_max, indice+1, n, saco, sol_aux, soma_valor, v_solucao);
}


// soma dos pesos n ultrapassa o peso maximo
void saco_noel(float p_max, int n, presente saco[], bool v_solucao[]){
    int soma_valor = 0; 
    bool sol_aux[n];
    
    for (int i = 0; i < n; i++) {
        sol_aux[i] = false;
    }
    
    ajudante_noel(p_max, 0, n, saco, sol_aux, &soma_valor, v_solucao);
    
    printf("Maior valor sentimental: %d\n", soma_valor);
    printf("Índice dos presentes selecionados: ");
    for (int i = 0; i < n; i++) {
        if (v_solucao[i]) {
            printf("%d ", i+1);
        }
    }
    printf("\n");
}


void ler(presente *saco, int n){

    float v, p;

    for (int i = 0; i < n; i++ ){
        scanf("%f", &v);
        scanf("%f", &p);

        saco[i].valor = v;
        saco[i].peso = p;
    }

}


int main() {

    int n;
    float p_max;

    scanf("%d", &n);
    scanf("%f", &p_max);

    presente *saco = malloc(sizeof(presente)*n);
    ler (saco, n);

    bool v_solucao[n]; // vetor booleano
    
    saco_noel(p_max, n, saco, v_solucao);

    free (saco);
    
    return 0;
}