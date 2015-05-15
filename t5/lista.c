/*
 * lista.h
 * Funções de TAD lista duplamente encadeada.
 *
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014, 2015 João V. F. Lima, UFSM
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "lista.h"
#include "memo.h"

/* implementa aqui sua estrutura lista_t duplamente encadeada */
lista_t* lst_cria (void)
{
return NULL;
}

lista_t* lst2_insere (lista_t* l, int v)
{
lista_t* novo = (lista_t*) malloc(sizeof(lista_t));
novo->info = v;
novo->prox = l;
novo->ant = NULL;
/* verifica se lista não estava vazia */
if (l != NULL)
l->ant = novo;
return novo;
}

lista_t* lst2_busca (lista_t* l, int v)
{
lista_t* p;
for (p=l; p!=NULL; p=p->prox)
if (p->info == v)
return p;
return NULL; /* não achou o elemento */
}

lista_t* lst2_retira (lista_t* l, int v) {
lista_t* p = lst2_busca (l,v);
if (p == NULL)
return l; /* não achou o elemento: retorna lista inalterada */
/* retira elemento do encadeamento */
if (l == p) /* testa se é o primeiro elemento */
l = p->prox;
else
p->ant->prox = p->prox;
if (p->prox != NULL) /* testa se é o último elemento */
p->prox->ant = p->ant;
free(p);
return l;
}
