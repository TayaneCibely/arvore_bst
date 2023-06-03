#ifndef BST_H
#define BST_H

typedef struct no {
    int valor;
    struct no *esq, *dir;
} no;

typedef no* arvore;

arvore inserir_bst(int valor, arvore raiz);
void preorder_bst(arvore raiz);
void inorder_bst(arvore raiz);
void posorder_bst(arvore raiz);
void reverso_bst(arvore raiz);
int qtdPrimo_bst(arvore raiz);
int numero_primo(int num);
arvore sucessor_bst(arvore raiz, int valor);
void imprimir_sucessor(int n, arvore raiz);
void caminho_bst(int n, arvore raiz);
arvore remover_bst(int valor, arvore raiz);
no* maior(no* raiz);
int somatorio_bst(arvore raiz);
arvore podar_bst(int n, arvore raiz);
void reajustar_bst(arvore raiz, int percentual);
int existe_bst(arvore raiz, int chave);
void descenndentes_bst(int n, arvore raiz);
int altura_bst(arvore raiz);

#endif
