#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
int main (int argc, char *argv[])
{
	int i;
	int achou = 0;
	char *nome1; 
	nome1 = (char*) malloc( 50 * sizeof(char)); 
	char linha[50];
	FILE* fp; 


	fp = fopen("alunos.txt","rt");
	if (fp == NULL) {
		printf("N�o foi poss�vel abrir arquivo de entrada.\n");
		return 1;
	}
		while (fgets(linha,100,fp) != NULL) {
			if (strstr(linha,argv[1]) != NULL) {
				achou = 1;
				if (achou){
					printf(" %s\n", &linha[i]);								
					}
						
			}
								
		}	

		fclose(fp);
		return 0;
	}

