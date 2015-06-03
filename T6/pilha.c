#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include "pilha.h"
#include "memo.h"

pilha_t *pilha_cria(void){
	pilha_t* p = (pilha_t*) malloc(sizeof(pilha_t));
	p->n = 0; /* inicializa com zero elementos */
	return p;
}



void pilha_insere(pilha_t* p, arv_t* arv){
	if (p->n == N) { /* capacidade esgotada */
		printf("Capacidade da pilha estourou.\n");
		system ("pause");
		exit(1); /* aborta programa */
	return (0);
	}
	/* insere elemento na próxima posição livre */
	p->vet[p->n] = arv->dado;
	p->n++;

}

arv_t* pilha_remove(pilha_t* p)
{
	arv_t* v;
	if (pilha_vazia(p)) { printf("Pilha vazia.\n");
		exit(1); } /* aborta programa */
	/* retira elemento do topo */
	v = p->vet[p->n-1];
	p->n--;
	return v;
}


bool pilha_vazia(pilha_t* p){

	return (p->n==0);
}

void pilha_destroi(pilha_t* p){

	memo_libera(p);

}

