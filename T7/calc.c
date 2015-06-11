#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include "arv.h"
#include "pilha.h"
#include "memo.h"
#include "calc.h"


double calcula(arv_t* arv)
{	
	double x,y;

    if((arv->dado.u.operador!= '/')&&(arv->dado.u.operador!='*')&&(arv->dado.u.operador!='+')&&(arv->dado.u.operador!='-'))
    {
        return arv->dado.u.operando;
    }
    else{
    	x = calcula(arv->esq);
        y = calcula(arv->dir);
    	    if(arv->dado.u.operador == '+' )
    {
        
        return x + y;
    }
    		else if(arv->dado.u.operador == '-')
    {
      
        return x - y;
    }
    		else if(arv->dado.u.operador == '*')
    {
        return x * y;
    }
    		else if(arv->dado.u.operador == '/')
    {
        
        return x / y;
    }
    }
}
