#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(int argc, char* argv[]) {
    arvore raiz = NULL;
    int opcao, aux;
  //  a = NULL;

    while (1) {
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                scanf("%d", &aux);
                raiz = inserir_bst(aux, raiz);
                break;
            case 2:
                preorder_bst(raiz);
                printf("\n");
                break;
            case 3:
                inorder_bst(raiz);
                printf("\n");
                break;
            case 4:
                posorder_bst(raiz);
                printf("\n");
                break;
            case 5:
                reverso_bst(raiz);
                printf("\n");
                break;
            case 6:
                printf("%d\n", qtdPrimo_bst(raiz));
                break;
            case 7:
                scanf("%d", &aux);
                imprimir_sucessor(aux, raiz);
                break;
            case 8:
                scanf("%d", &aux);
                caminho_bst(aux, raiz);
                printf("\n");
                break;
            case 9:
                scanf("%d", &aux);
            	raiz = remover_bst(aux, raiz);
                break;
            case 10:
                printf("%d\n", somatorio_bst(raiz));
                break;
            case 12:
                scanf("%d", &aux);
                reajustar_bst(raiz, aux);
                break;
            case 13:
                scanf("%d", &aux);
                printf("%d\n", existe_bst(raiz, aux));
                break;
            case 14:
                scanf("%d", &aux);
                descendentes_bst(aux, raiz);
                printf("\n");
                break;
            case 15:
                printf("%d\n", altura_bst(raiz));
                break;
            case 99:
                exit(0);
        }
    }
}
