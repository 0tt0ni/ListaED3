#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int nume;
    struct no *prox;
} No;


No* criarNo(int nume) {
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo->nume = nume;
    novoNo->prox = NULL;
    return novoNo;
}


void inserirNo(No **topo, int nume) {
    No *novoNo = criarNo(nume);
    if (*topo == NULL || (*topo)->nume >= novoNo->nume) {
        novoNo->prox = *topo;
        *topo = novoNo;
    } else {
        No *atual = *topo;
        while (atual->prox != NULL && atual->prox->nume < novoNo->nume) {
            atual = atual->prox;
        }
        novoNo->prox = atual->prox;
        atual->prox = novoNo;
    }
}


void imprimirLista(No *topo) {
    No *temp = topo;
    while(temp != NULL) {
        printf("%d ", temp->nume);
        temp = temp->prox;
    }
}

int main() {
    No *topo = NULL;
    int n, nume;
    	printf("Digite o tamanho da fila que deseja criar: ");
scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Digite o elemento %d: ", i+1);
scanf("%d", &nume);
        inserirNo(&topo, nume);
    }
    
    	printf("Fila ordenada: ");
    imprimirLista(topo);
    return 0;
}

