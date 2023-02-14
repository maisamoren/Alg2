#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// Estrutura para representar um item no Saco do Papai Noel.
typedef struct {
    int peso;
    int valor;
} Presente;

// Função auxiliar para encontrar a combinação de itens de valor máximo usando backtracking.
void knapsack_helper(int p_max, int item_index, int n, Presente saco[], bool current_solution[], int *max_value, bool solution[]) {
    // Se todos os itens foram avaliados, retorna.
    if (item_index == n) {
        int current_value = 0;
        for (int i = 0; i < n; i++) {
            if (current_solution[i]) {
                current_value += saco[i].valor;
            }
        }
        // Se a solução atual tiver um valor maior que o máximo encontrado até agora, atualiza a solução ótima.
        if (current_value > *max_value) {
            *max_value = current_value;
            for (int i = 0; i < n; i++) {
                solution[i] = current_solution[i];
            }
        }
        return;
    }
    
    // Testa se o item atual pode ser selecionado e chama a função recursivamente para o próximo item.
    if (saco[item_index].peso <= p_max) {
        current_solution[item_index] = true;
        knapsack_helper(p_max - saco[item_index].peso, item_index+1, n, saco, current_solution, max_value, solution);
    }
    
    // Chama a função recursivamente para o próximo item sem selecioná-lo.
    current_solution[item_index] = false;
    knapsack_helper(p_max, item_index+1, n, saco, current_solution, max_value, solution);
}


// Função para encontrar a combinação de itens de valor máximo que podem ser colocados no saco.
void knapsack(int p_max, int n, Presente saco[], bool solution[]) {
    int max_value = 0;  // valor máximo encontrado
    bool current_solution[n];  // solução atual sendo testada
    
    // Inicializa a solução atual com todos os itens como não selecionados.
    for (int i = 0; i < n; i++) {
        current_solution[i] = false;
    }
    
    // Chama a função auxiliar de backtracking para encontrar a solução ótima.
    knapsack_helper(p_max, 0, n, saco, current_solution, &max_value, solution);
    
    // Imprime a solução encontrada.
    printf("Valor máximo: %d\n", max_value);
    printf("Itens selecionados: ");
    for (int i = 0; i < n; i++) {
        if (solution[i]) {
            printf("%d ", i+1);
        }
    }
    printf("\n");
}


void ler(Presente *saco, int n){

    int v,p;

    for (int i = 0; i < n; i++ ){
        scanf("%d", &v);// ler valor
        scanf("%d", &p);// ler peso
        saco[i].valor = v;
        saco[i].peso = p;
    }

}

// Exemplo de uso.
int main() {

    int p_max;
    int n;

    scanf("%d", &n);// ler n
    scanf("%d", &p_max);// ler n

    Presente *saco = malloc(sizeof(Presente)*n);
    ler(saco,n);
    bool solution[n];
    
    // Encontra a combinação de itens de valor máximo que podem ser colocados no saco.
    knapsack(p_max, n, saco, solution);
    
    return 0;
}
