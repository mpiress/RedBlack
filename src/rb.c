#include "rb.h"

Tree* CreateTree(){
  return NULL;
}

void insertFixUp(Tree **raiz, Tree *child){
  Tree *tio;

  while((child != *raiz) && (child->pai->cor == false)){
      
      if(child->pai == child->pai->pai->esq){
        
        tio = child->pai->pai->dir;

        //caso 1:
        if((tio != NULL) && (tio->cor == false)){
          child->pai->cor = true;
          tio->cor = true;
          child->pai->pai->cor = false;
          child = child->pai->pai;
        
        }else{
          
          //caso 2
          if(child == child->pai->dir){
            child = child->pai;
            rotacaoSimplesEsquerda(raiz, child);
          }
          
          //caso 3
          child->pai->cor = true;
          child->pai->pai->cor = false;
          rotacaoSimplesDireita(raiz, child->pai->pai);
        }

      }else{
        
        tio = child->pai->pai->esq;
        
        //caso 1
        if((tio != NULL) && (tio->cor == false)){
          child->pai->cor = true;
          tio->cor = true;
          child->pai->pai->cor = false;
          child = child->pai->pai;
        
        }else{
          
          //caso 2
          if(child == child->pai->esq){
            child = child->pai;
            rotacaoSimplesDireita(raiz, child);
          }

          //caso 3
          child->pai->cor = true;
          child->pai->pai->cor = false;
          rotacaoSimplesEsquerda(raiz, child->pai->pai);      
        }

      }

  }

  (*raiz)->cor = true;
}


void insertTree(Tree **t, Tree **pai, Tree **raiz, Record r){
  
  if(*t == NULL){
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->esq = NULL; 
    (*t)->dir = NULL; 
    (*t)->pai = pai!=t?*pai:NULL;
    (*t)->cor = false; //false: vermelho  true:preto
    (*t)->reg = r; 
    insertFixUp(raiz, *t);
    
  } else { 

    if(r.key < (*t)->reg.key){
      insertTree(&(*t)->esq, t, raiz, r);
      return;
    }
    
    if(r.key > (*t)->reg.key){
      insertTree(&(*t)->dir, t, raiz, r);
      return;
    }

  }

}


void pesquisa(Tree **t, Tree **aux, Record r){

  if(*t == NULL){
    printf("[ERROR]: Node not found!");
    return;
  }

  if((*t)->reg.key > r.key){ pesquisa(&(*t)->esq, aux, r); return;}
  if((*t)->reg.key < r.key){ pesquisa(&(*t)->dir, aux, r); return;}

  *aux = *t;
}

void rotacaoSimplesEsquerda(Tree **raiz, Tree *child){
  Tree *x, *y;

  x = child;
  y = child->dir;
  x->dir = y->esq;

  if(y->esq != NULL)
    y->esq->pai = x;

  y->pai = x->pai;
  
  if(x->pai == NULL)
    *raiz = y;

  else{

    if(x == x->pai->esq)
      x->pai->esq = y;

    else
      x->pai->dir = y;
  
  }

  y->esq = x;
  x->pai = y;
}


void rotacaoSimplesDireita(Tree **raiz, Tree *child){
  Tree *x, *y;

  x = child;
  y = child->esq;
  x->esq = y->dir;

  if(y->dir != NULL)
    y->dir->pai = x;

  y->pai = x->pai;
  
  if(x->pai == NULL){
    *raiz = y;
  }

  else{

    if(x == x->pai->dir)
      x->pai->dir = y;

    else
      x->pai->esq = y;
  
  }

  y->dir = x;
  x->pai = y;
  
}


void preordem(Tree *t){
  if(!(t == NULL)){
    printf("%d - %s\t", t->reg.key, t->cor ? "black" : "red");
    preordem(t->esq); 
    preordem(t->dir); 
  }
}


void central(Tree *t){
  if(!(t == NULL)){
    central(t->esq); 
    printf("%d - %s\t", t->reg.key, t->cor ? "black" : "red");
    central(t->dir); 
  }
}

void posordem(Tree *t){
  if(!(t == NULL)){
    posordem(t->esq); 
    posordem(t->dir); 
    printf("%d - %s\t", t->reg.key, t->cor ? "black" : "red");
  }
}