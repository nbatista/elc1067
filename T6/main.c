/*
 * principal.c
 * Implementação de árvore de expressões aritméticas.
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

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "arv.h"
#include "pilha.h"
#include "memo.h"

int main(int argc, char **argv)
{


	arv_t* raiz;
	arv_t* n1;
	pilha_t* pilha;
	pilha = pilha_cria();
	op_t op;
	char* y = (char*) memo_aloca(sizeof(char));
	double z;



	printf("Digite a expressao na forma: x x * 2 + x 1 + /  = ((x * x) + 2)/(x + 1) \n");
	do{
		printf("\nPara SAIR Digite  -1 ");

		printf("\nDigite um operando ou operador: ");
		scanf("%s",y);
		if((y!= '/')||(y!='*')||(y!='+')||(y!='-')){
				z = atof(y);
				op.tipo = OPERANDO;
				op.u.operando= z; 
				pilha_insere( pilha, op );
		}
		else{
			op.tipo = OPERADOR;
			op.u.operador= y;
			raiz = arv_cria( op );
			n1 = pilha_remove(pilha);
			arv_insere_esquerda( raiz, n1 );
			n1 = pilha_remove(pilha);
			arv_insere_direita( raiz, n1 );
		
		}
	
		pilha_insere( pilha, op );			
	}while( y != '-1'  );
	
	n1 = pilha_remove(pilha);
	printf("\n Pre ordem :  ");
	arv_imprime_pre_ordem(n1);
	printf("\n Em ordem :  ");
	arv_imprime_em_ordem(n1);
	printf("\n Pos ordem :  ");
	arv_imprime_pos_ordem(n1);

	printf("\n");
	arv_destroi( raiz );
	pilha_destroi(pilha);
	memo_relatorio();
	return 0;
}
