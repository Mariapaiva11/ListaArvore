// 1

// Pré-ordem: 10-8-5-1-2-7-20-15-12

// Em ordem: 1-2-5-7-8-10-12-15-20

// Pós ordem: 2-1-7-5-8-12-15-20-10


// // 2 

// 20, 10, 15, 4, 7, 8, 3, 1, 2

// 	    20 
//      10     15
//    4   7   8   3
//  1   2


// //a)

// Passo 1: 10 - 15 - 4 - 7 - 8 - 3 - 1 - 2

// Passo 2: 2 - 10 - 15 - 4 - 7 - 8 - 3 - 1 

// Passo 3: 15 - 10 - 2 - 4 - 7 - 8 - 3 - 1

// Vetor após remoção: [15 - 10 - 2 - 4 - 7 - 8 - 3 - 1]


// //b)

// Passo 1: Adicionado o elemento 16 ao final do vetor.

// Vetor após a inserção: [20, 10, 15, 4, 7, 8, 3, 1, 2, 16]

// Passo 2: Reorganizando o vetor para garantir a propriedade. Comparando o 16 com seu pai, posição (i-1/2).

// Vetor final:[20, 16, 15, 10, 4, 7, 8, 3, 1, 2]


//3 


#include <stdio.h>
#include <stdlib.h>


 typedef struct noA{
    int info;
    struct noA *esq;
    struct noA *dir;
 }TnoA;

int somafolhas(TnoA *no) {
    if (no == NULL) {
        return 0;
    }

    if (no->esq == NULL && no->dir == NULL) {
        return no->info;
    }

    int soma = 0;

    if (no->esq != NULL) {
        soma += somafolhas(no->esq);
    }

    if (no->dir != NULL) {
        soma += somafolhas(no->dir);
    }

    return soma;
}

void imprimePosordem(TnoA *no){
    if(no != NULL){
        imprimePosordem(no->esq);
        imprimePosordem(no->dir);
        printf("%d-", no->info);
    }
}

void imprimeEmOrdem(TnoA *no){ //simetrica);
    if(no != NULL){
       imprimeEmOrdem(no->esq);
       printf("%d-", no->info);
       imprimeEmOrdem(no->dir);
    }

}

void imprimePreordem(TnoA *no){ //pre-ordem(profundidade);
    if(no != NULL){
        printf("%d-", no->info);
        imprimePreordem(no->esq);
        imprimePreordem(no->dir);
    }

}

int alturaNo(TnoA *no){
    int alt_esquerda = 1;
    int alt_direita = 1;
    
    if(no == NULL){
        return 0;
    }
    if(no != NULL){
        alt_esquerda += alturaNo(no->esq);
        alt_direita += alturaNo(no->dir);
    }
    if(alt_esquerda < alt_direita){
        return alt_direita;
    }
    else{
        return alt_esquerda;
    }
}

int calculaFatorBalanceamento(TNoA *no) {
    if (no == NULL) {
        return 0;
    }

    int alturaEsquerda = alturaNo(no->esq);  // Use a função alturaNo para calcular a altura da subárvore esquerda
    int alturaDireita = alturaNo(no->dir);   // Use a função alturaNo para calcular a altura da subárvore direita

    return alturaEsquerda - alturaDireita;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int calculaNivelDaArvore(TnoA *raiz) {
    if (raiz == NULL) {
        return 0; 
    }

    int nivelEsquerda = calculaNivelDaArvore(raiz->esq);
    int nivelDireita = calculaNivelDaArvore(raiz->dir);

    return max(nivelEsquerda, nivelDireita) + 1;
}

int calculaProdutoNos(TnoA *raiz) {
    if (raiz == NULL) {
        return 1;
    }    
    int produtoEsquerda = calculaProdutoNos(raiz->esq);
    int produtoDireita = calculaProdutoNos(raiz->dir);

    return raiz->info * produtoEsquerda * produtoDireita;
}





 TnoA *criaNo(int no){
    TnoA *aux;
    aux = (TnoA*)malloc(sizeof(TnoA));
    aux->info = no;
    aux->esq = NULL;
    aux->dir = NULL;

    return aux;
 }

 TnoA *insere(TnoA *no, int elem){
    if(no == NULL){
        return criaNo(elem);
    }
    if(elem < no->info){
        no->esq = insere(no->esq, elem);
    }
    else if(elem > no->info){
        no->dir = insere(no->dir, elem);
    }
    return no;  
 }


//1 - 





int alturadado(TnoA *no, int elem) {
    if (no == NULL) {
        return -1; // Retorna -1 se o nó for NULL ou se o elemento não for encontrado
    }

    if (no->info == elem) {
        int alturaEsquerda = alturadado(no->esq, elem);
        int alturaDireita = alturadado(no->dir, elem);

        if (alturaEsquerda > alturaDireita) {
            return alturaEsquerda + 1;
        } else {
            return alturaDireita + 1;
        }
    }

    int alturaEsquerda = alturadado(no->esq, elem);
    int alturaDireita = alturadado(no->dir, elem);

    if (alturaEsquerda >= 0) {
        return alturaEsquerda + 1;
    } else if (alturaDireita >= 0) {
        return alturaDireita + 1;
    } else {
        return -1; // Elemento não encontrado em nenhuma subárvore
    }
}


int main(){

    TnoA *arvore = NULL;
	int altura, soma;
	
    arvore = insere(arvore, 10);
    arvore = insere(arvore, 20);
    arvore = insere(arvore, 15);
    arvore = insere(arvore, 12);
    arvore = insere(arvore, 8);
    arvore = insere(arvore, 5);
    arvore = insere(arvore, 7);
    arvore = insere(arvore, 1);
    arvore = insere(arvore, 2);
    
    //imprimeEmOrdem(arvore);


    //imprimePosordem(arvore);


    //imprimePreordem(arvore);

    soma = somafolhas(arvore);

    printf("Soma: %d", soma);

	printf("\n");
	
    altura = alturaNo(arvore);
    printf("Altura: %d", altura);

    return 0;
}


	


