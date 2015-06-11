#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include "arv.h"
#include "pilha.h"
#include "memo.h"

pilha_t *pilha_cria(void){
	pilha_t* p = (pilha_t*) malloc(sizeof(pilha_t));
	p->n = 0; /* inicializa com zero elementos */
	return p;
}



void pilha_insere(pilha_t* p, arv_t* arv){
	Lista *q = (Lista*)memo_aloca(sizeof(Lista));
	q->ar=arv;
	q->prox=p->n;
	p->n=q;

}

arv_t* pilha_remove(pilha_t* p)
{	
	arv_t *galho;
	Lista *m;
	m = p->n;
	p->n = m->prox;
	galho = m->ar;
	memo_libera(m);
	
	return galho;
}


bool pilha_vazia(pilha_t* p){

	return (p->n==0);
}

void pilha_destroi(pilha_t* p){

	memo_libera(p);

}


