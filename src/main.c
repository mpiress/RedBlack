#include "rb.h"

int main(){

	int reg[] = {10,2,7,5,3,9,16,4,11,1,6,23,14};

	Tree *raiz = CreateTree();
	Record r;

	for(int i=0; i<13; i++){
		r.key = reg[i];
		insertTree(&raiz, &raiz, &raiz, r);
    }

  	preordem(raiz);
  	printf("\n");
}