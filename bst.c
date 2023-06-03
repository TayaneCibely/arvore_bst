#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

arvore inserir_bst(int valor, arvore raiz) {
    if (raiz == NULL) {
        arvore novo_no = (arvore) malloc(sizeof(struct no));
        novo_no->valor = valor;
        novo_no->esq = NULL;
        novo_no->dir = NULL;
        return novo_no;
    } else {
        if (valor < raiz->valor) {
            raiz->esq = inserir_bst(valor, raiz->esq);
        } else if (valor > raiz->valor) {
            raiz->dir = inserir_bst(valor, raiz->dir);
        }
        return raiz;
    }
}

void preorder_bst(arvore raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preorder_bst(raiz->esq);
        preorder_bst(raiz->dir);
    }
}

void inorder_bst(arvore raiz) {
    if (raiz != NULL) {
        inorder_bst(raiz->esq);
        printf("%d ", raiz->valor);
        inorder_bst(raiz->dir);
    }
}

void posorder_bst(arvore raiz) {
    if (raiz != NULL) {
        posorder_bst(raiz->esq);
        posorder_bst(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

void reverso_bst(arvore raiz) {
    if (raiz != NULL) {
        reverso_bst(raiz->dir);
        printf("%d ", raiz->valor);
        reverso_bst(raiz->esq);
    }
}

int qtdPrimo_bst(arvore raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        int qtd = 0;
        if (numero_primo(raiz->valor)) {
            qtd++;
        }
        qtd += qtdPrimo_bst(raiz->esq);
        qtd += qtdPrimo_bst(raiz->dir);
        return qtd;
    }
}

int numero_primo(int num) {
	int i;
    if (num < 2) {
        return 0;
    }
    for (i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

arvore sucessor_bst(arvore raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }
    if (valor < raiz->valor) {
        arvore esq = sucessor_bst(raiz->esq, valor);
        if (esq != NULL) {
            return esq;
        } else {
            return raiz;
        }
    } else {
        return sucessor_bst(raiz->dir, valor);
    }
}

void imprimir_sucessor(int n, arvore raiz) {
    arvore sucessor = sucessor_bst(raiz, n);
    if (sucessor == NULL) {
        printf("Nao ha sucessor para o valor %d\n", n);
    } else {
        printf("%d: %d\n", n, sucessor->valor);
    }
}

void caminho_bst(int n, arvore raiz) {
    if (raiz == NULL) {
        return;
    }
    printf("%d ", raiz->valor);
    if (n < raiz->valor) {
        caminho_bst(n, raiz->esq);
    } else if (n > raiz->valor) {
        caminho_bst(n, raiz->dir);
    }
}

arvore remover_bst(int valor, arvore raiz) {
    //Remover de uma (sub)árvore vazia / remover elemento inexistente
    if(raiz == NULL) {
        return raiz;
    }
    //Encontrou o elemento
    if(raiz->valor == valor) {
        //Verificação de 0 filhos, 1 filho, 2 filhos
        //caso 1 - zero filhos
        if(raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            return NULL;
        }
        //caso 2 (a): exatamente um filho esquerdo
        if(raiz->esq != NULL && raiz->dir == NULL) {
            arvore aux = raiz->esq;
            free(raiz);
            return aux;
        }

        //caso 2 (b): exatamente um filho direito

        //caso 3: dois filhos
        //não precisa de if

        int maiorValorSubarvoreEsquerda = maior(raiz->esq)->valor;
        raiz->valor = maiorValorSubarvoreEsquerda;
        raiz->esq = remover_bst(maiorValorSubarvoreEsquerda, raiz->esq);

        return raiz;
    }
    if(valor > raiz->valor) {
       raiz->dir = remover_bst(valor, raiz->dir);
    } else {
        //simétrico
    }
    return raiz;
}

int maiorValorSubarvoreEsquerda(arvore raiz) {
    if (raiz == NULL) {
        return 0;
    }
    while (raiz->dir != NULL) {
        raiz = raiz->dir;
    }
    return raiz->valor;
}

int somatorio_bst(arvore raiz) {
    int soma;
    if (raiz == NULL) {
        return 0;
    } else {
        soma = raiz->valor + somatorio_bst(raiz->esq) + somatorio_bst(raiz->dir);
        return soma;
    }
}

arvore podar_bst(int valor, arvore raiz) {
    if (raiz == NULL) {
        return NULL;
    }

    if (valor < raiz->valor) {
        raiz->esq = podar_bst(valor, raiz->esq);
    } else if (valor > raiz->valor) {
        raiz->dir = podar_bst(valor, raiz->dir);
    } else {
        // Caso chegue aqui encontrou o valor
        // Abaixo do valor, será podado
        if (raiz->esq != NULL) {
            free(raiz->esq);
            raiz->esq = NULL;
        }
        if (raiz->dir != NULL) {
            free(raiz->dir);
            raiz->dir = NULL;
        }
    }
    return raiz;
}

void reajustar_bst(arvore raiz, int percentual) {
    if (raiz == NULL) {
        return;
    }
    // Aplicar reajuste, passar como int
    raiz->valor += (int)(raiz->valor * (percentual / 100.0));

    // Recursão esq, dir
    reajustar_bst(raiz->esq, percentual);
    reajustar_bst(raiz->dir, percentual);
}

int existe_bst(arvore raiz, int chave) {
    if (raiz == NULL) {
        return 0; // Chave não encontrada
    }

    if (chave < raiz->valor) {
        return existe_bst(raiz->esq, chave);
    } else if (chave > raiz->valor) {
        return existe_bst(raiz->dir, chave);
    } else {
        return 1; // Chave encontrada
    }
}

void descendentes_bst(int n, arvore raiz) {
    if (raiz == NULL) {
        return;
    }
    if (raiz->valor > n) {
        descendentes_bst(n, raiz->esq);
    }
    if (raiz->valor >= n) {
        printf("[%d]", raiz->valor);
    }
    if (raiz->valor < n) {
        descendentes_bst(n, raiz->dir);
    }
}

int altura_bst(arvore raiz) {
    int altura_esq, altura_dir;

    if (raiz == NULL) {
        return 0;
    }
    altura_esq = altura_bst(raiz->esq);
    altura_dir = altura_bst(raiz->dir);

    if (altura_esq > altura_dir) {
        return 1 + altura_esq;
    } else {
        return 1 + altura_dir;
    }
}

