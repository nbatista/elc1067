#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include "arv.h"
#include "pilha.h"
#include "memo.h"


arv_t* arv_insere_esquerda(arv_t* arv, arv_t* p))
{

		arv->esq = p;
	return arv;
}



arv_t* arv_insere_direita(arv_t* arv, arv_t* p)
{

		arv->dir = p;	
	return arv;
}


void arv_destroi(arv_t* arv){
	if (!arv_vazia(arv)){
		arv_destroi(arv->esq); /* libera sae */
		arv_destroi(arv->dir); /* libera sad */
	memo_libera(arv); /* libera raiz */
	}
}
arv_t* arv_cria(op_t op)
{
	arv_t* p=(arv_t*)malloc(sizeof(arv_t));
	p->dado = op;
	p->esq = NULL;
	p->dir = NULL;
	return p;
}

int arv_vazia (arv_t* arv)
{
	return arv==NULL;
}
void arv_imprime_pre_ordem(arv_t* arv)
{
	if (!arv_vazia(arv)){
		printf("%c ", arv->dado); /* mostra raiz */
		arv_imprime_pre_ordem(arv->esq); /* mostra sae */
		arv_imprime_pre_ordem(arv->dir); /* mostra sad */
	}
}
void arv_imprime_pos_ordem(arv_t* arv)
{
	if (!arv_vazia(arv)){
		arv_imprime_pos_ordem(arv->esq); /* mostra sae */
		arv_imprime_pos_ordem(arv->dir); /* mostra sad */
		printf("%c ", arv->dado); /* mostra raiz */

	}
}

void arv_imprime_em_ordem(arv_t* arv)
{
	if (!arv_vazia(arv)){
		arv_imprime_em_ordem(arv->esq); /* mostra sae */

		printf("%c ", arv->dado); /* mostra raiz */
		arv_imprime_em_ordem(arv->dir); /* mostra sad */

	}
}

