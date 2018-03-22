#ifndef _ARVORE_BIN_H_
#define _ARVORE_BIN_H_

typedef struct nodo{
    char info;
    struct nodo *esq;
    struct nodo *dir;
}Nodo;
typedef struct arv_bin{
    Nodo *raiz;
}Arv_bin;
Arv_bin* nova_arv(Nodo* raiz);
Nodo* nova_arv_no(char c,Nodo* esq,Nodo* dir);

void print_escolhendo_ordem(Arv_bin* a);
static void print_preordem(Nodo* n);
void print_inordem(Nodo* n);
void pirnt_posordem(Nodo* n);

void arv_print_pre(Arv_bin* a);

int arv_pertence(Arv_bin* a, char c);
static int arv_pertence_no(Nodo* n,char c);

Nodo* arv_busca(Arv_bin* a);
Nodo* arv_busca_no(Nodo*n);

int arv_altura(Arv_bin* a);
static int arv_altura_no(Nodo* n);
static int max2(int a,int b);

void arv_libera(Arv_bin* a);
static void arv_libera_no(Nodo* r);

//contanto os nós
int tamanho(Arv_bin* a);
int tamanho_no(Nodo* n);
int arv_folhas(Arv_bin* a);
int arv_folhas_no(Nodo* n);
//verificamdo se eh estritamente binaria
void arv_estrita(Arv_bin* a);
//eh completa?
void arv_completa(Arv_bin* a);
#endif
