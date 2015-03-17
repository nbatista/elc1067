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
		printf("Não foi possível abrir arquivo de entrada.\n");
		return 1;
	}
		while (fgets(linha,100,fp) != NULL) {
			if (strstr(linha,nome) != NULL) {
				achou = 1;
				if (achou){	
				printf(" %s\n", linha);									
				}	
			}
			
		}
		fclose(fp);
		return 0;
	}
