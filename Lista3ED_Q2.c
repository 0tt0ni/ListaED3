#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int frente, tras, tamanho;
    unsigned capacidade;
    char** array;
} Fila;

Fila* criarFila(unsigned capacidade) {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->capacidade = capacidade;
    fila->frente = fila->tamanho = 0; 
    fila->tras = capacidade - 1;
    fila->array = (char**) malloc(fila->capacidade * sizeof(char*));
    return fila;
}

int estaCheia(Fila* fila) {
    return (fila->tamanho == fila->capacidade);
}

void adicionar(Fila* fila, char* item) {
    if (estaCheia(fila)) {
        printf("limite excedido\n");
        return;
    }
    fila->tras = (fila->tras + 1) % fila->capacidade;
    fila->array[fila->tras] = item;
    fila->tamanho = fila->tamanho + 1;
    printf("%s adicionado a lista\n", item);
}

void imprimirFila(Fila* fila) {
    if (fila->tamanho == 0) {
        printf("lista vazia\n");
        return;
    }
    printf("lista: ");
    for (int i = fila->frente; i <= fila->tras; i++) {
        printf("%s ", fila->array[i]);
    }
    printf("\n");
}

int main() {
    unsigned capacidade;
    printf("Digite o tamanho da lista que deseja criar: ");
    scanf("%u", &capacidade);
    Fila* fila = criarFila(capacidade);

    while (1) {
        printf("Digite: \n 1 para adicionar um alimento \n 2 para imprimir a lista \n 3 para sair: ");
        int opcao;
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: {
                printf("Digite o alimento que deseja adicionar: ");
                char* alimento = (char*) malloc(50 * sizeof(char));
                scanf("%s", alimento);
                adicionar(fila, alimento);
                break;
            }
            case 2: {
                imprimirFila(fila);
                break;
            }
            case 3: {
                printf("Encerrando o programa...\n");
                return 0;
            }
            default: {
                printf("Opção inválida\n");
                break;
            }
        }
    }

    return 0;
}

