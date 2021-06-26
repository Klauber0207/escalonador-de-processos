#include <stdio.h>
#include "klibrary.h"

void main(){
	
	int i = 1;
	int t = 5;
	Processo p = atribui_Processo(i, t);;
	
	imprime_Processo(p);
	
}
