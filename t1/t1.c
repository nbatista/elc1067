#include <stdio.h>
#include <string.h> 
int main (int argc, char *argv[])
{
	int i;
	int achou = 0;
	char nome1[100]; 
	char linha[100];
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
			
				float nota1, nota2;
				FILE *arq;
				arq = fopen("notas.txt", "r");
				if(arq == NULL)
					printf("N�o foi poss�vel abrir arquivo de entrada.\n");
				else
					while( (fscanf(arq,"%s %f %f \n", nome1, &nota1, &nota2))!=EOF )
						if (strstr(linha,nome1) != NULL) {
							if (achou){
								printf("\n\n  %.2f      ",  (nota1+nota2)/2);
									for(i=9;i<10;i++)
									printf(" %s\n", &linha[i]);								
								}
						
						}
								
				}	
			}
			
		}
		fclose(fp);
		return 0;
	}
