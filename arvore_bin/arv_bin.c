#include <stdio.h>
#include <stdlib.h>
#include "arv_bin.h"
#include <math.h>
//questao 1, somente repassando o codigo ja apresentado
Nodo* nova_arv_no(char c, Nodo* esq, Nodo* dir){
    Nodo* a = (Nodo*)malloc(sizeof(Nodo));
    a->info = c;
    a->esq = esq;
    a->dir = dir;
    return a;
}
Arv_bin* nova_arv(Nodo* r){
    Arv_bin* arv = (Arv_bin*)malloc(sizeof(Arv_bin));
    arv->raiz = r;
    return arv;
}
static void print_preordem(Nodo* r){
    if (r != NULL){
        printf("%c", r->info);
        print_preordem(r->esq);
        print_preordem(r->dir);
    }
}
void arv_print_pre(Arv_bin* a){
    print_preordem(a->raiz);
    printf("\n");
}

int arv_pertence(Arv_bin* a, char c){
    return arv_pertence_no(a->raiz,c);
}
static int arv_pertence_no(Nodo* r, char c){
    if(r==NULL){
        return 0;
    }
    else
        return c==r->info || arv_pertence_no(r->esq,c) || arv_pertence_no(r->dir,c);
}
void arv_libera(Arv_bin* a){
    arv_libera_no(a->raiz);
    free(a);
}
static void arv_libera_no(Nodo* r){
    if(r!=NULL){
        arv_libera_no(r->esq);
        arv_libera_no(r->dir);
        free(r);
    }
}
static int max2(int a, int b){
    return (a>b) ? a : b;
}
int arv_altura(Arv_bin* a){
    return arv_altura_no(a->raiz);
}
static int arv_altura_no(Nodo* r){
    if (r == NULL) return -1;
    return 1 + max2(arv_altura_no(r->esq),arv_altura_no(r->esq));
}
//questao 3, contado os nos
int tamanho(Arv_bin* a){

    return tamanho_no(a->raiz);
}
int tamanho_no(Nodo* r){
    if(r == NULL) return 0;
    //if (r->esq == NULL && r->dir == NULL) return 1;
    return tamanho_no(r->esq) + tamanho_no(r->dir)+1;
}
//questao 7, contando folhas
int arv_folhas(Arv_bin* a){
    if(a==NULL) return 0;
    return arv_folhas_no(a->raiz);
}
int arv_folhas_no(Nodo* r){
    if(r->esq == NULL && r->dir == NULL) return 1;
    return arv_folhas_no(r->esq) + arv_folhas_no(r->dir);
}
//questao 8, verificando se eh estrita
void arv_estrita(Arv_bin* a){
    if((tamanho(a)-1)%2==0)
        printf("eh estritamente binaria\n");
    else printf("nao eh estritamento binaria");
}
//questao 9, verificando se arvore e completa
void arv_completa(Arv_bin* a){
    if (2*(pow(2,arv_altura(a)))==tamanho(a)+1)
        printf("eh completa\n");
    else printf("nao eh completa\n");
}
/*void BFS(Arv_bin *arv){
    queue<Nodo* > fila;
    Nodo *corr = NULL;

    fila.push(arv->raiz);
    while(!fila.empty()){
        corr = fila.front();
        printf("%c\n",corr->info);
        fila.pop();
        if(corr->esp!=NULL)
            fila.push(corr->esq);
        if(corr->dir!=dir!=NULL)
        fila.push(corr->dir);
        }
}*/
