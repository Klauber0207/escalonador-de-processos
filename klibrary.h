/*klibrary.h*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define T 3
/*Hello world*/
void hl(){
	
	printf("Hello world");
}


/*Estrutura Processo*/
typedef struct processo{
	int id;
	int duracao;
}Processo;


/*Cria um processo com id = 0 e duração = 0.*/
Processo cria_Processo(){
	Processo p;
	
	p.id = 0;
	p.duracao = 0;
	return p;	
}


/*Imprime as informações de um processo, como id e duração.*/
void imprime_Processo(Processo p){
	printf("Processo %d -> tamanho: %d", p.id, p.duracao);
	
}


/*Cria um Processo e atribui valores de id e duração a um processo*/
Processo atribui_Processo(int id, int duracao){
	Processo p;
	p.id = id;
	p.duracao = duracao;
	
	return p;
}


int valor_ramdom(){
	srand( (unsigned)time(NULL) );
	return rand() % 3;
	
}

