#ifndef RB_H 
#define RB_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Record Record;
typedef struct Tree Tree;

struct Record{
	int key;
};

struct Tree{
	Record reg;
	Tree *esq, *dir;
	Tree *pai; //específico para rubro negra
	bool cor;  //específico para rubro negra (FALSE = VERMELHOR, TRUE = PRETO)
};


Tree* CreateTree();

void rotacaoSimplesEsquerda(Tree **raiz, Tree *child);
void rotacaoSimplesDireita(Tree **raiz, Tree *child);

void insertFixUp(Tree **raiz, Tree *child);
void insertTree(Tree **t, Tree **pai, Tree **raiz, Record r);
void pesquisa(Tree **t, Tree **aux, Record r);

void preordem(Tree *t);
void central(Tree *t);
void posordem(Tree *t);


#endif
