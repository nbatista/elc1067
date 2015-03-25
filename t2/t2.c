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
		printf("Não foi possível abrir arquivo de entrada.\n");
		return 1;
	}
	float nota1, nota2;
	FILE *arq;
	arq = fopen("notas.txt", "r");
	if(arq == NULL)
		printf("Não foi possível abrir arquivo de entrada.\n");

		while (fgets(linha,100,fp) != NULL) {
			if (strstr(linha,argv[1]) != NULL) {
				achou = 1;
				if (achou){
					printf(" %s\n", &linha[i]);								
					}
						
			}
								
		}


		while( (fscanf(arq,"%s %f %f \n", nome1, &nota1, &nota2))!=EOF )
			if (strstr(linha,nome1) != NULL) {
				if (achou){
					printf("\n\n  %.2f      ",  (nota1+nota2)/2);
					}
			}
		
		fclose(fp);
		fclose(arq);
		return 0;
	}

