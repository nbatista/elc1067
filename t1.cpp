#include <stdio.h>
#include <string.h> 
int main (void)
{
	int n = 0,size;
	int achou = 0;
	char nome[100], nome1[100]; 
	char linha[100];
	FILE* fp; 
	
	printf("Digite o nome a procurar: ");
	scanf("%120s",nome);
	/* abre arquivos para leitura */
	fp = fopen("alunos.txt","rt");
	if (fp == NULL) {
		printf("N�o foi poss�vel abrir arquivo de entrada.\n");
		return 1;
	}
		return 0;
	}
