/*klibrary.h*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define T 10		//Número de processos.
#define TM 5		//Tempo maximo de um processo.

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
	printf("Processo %d -> tamanho: %d\n", p.id, p.duracao);
	
}


/*Cria um Processo e atribui valores de id e duração a um processo*/
Processo atribui_Processo(int id, int duracao){
	Processo p;
	p.id = id;
	p.duracao = duracao;
	
	return p;
}


/*Gera um valor aleatório.*/
int valor_ramdom(){
//	srand( (unsigned)time(NULL) );
//	srand(time(NULL));
	return 1 + rand() % TM;
	
}


/*Cria processos para todas as posições de um vetor*/
void enche_vetor(Processo* p, int t){
	int i = 0;	
	
	srand(time(NULL));
	for(i; i<t; i++){
		p[i].id = i+1;
		p[i].duracao = valor_ramdom();
	}
}


/*Imprime todos os processos de um vetor.*/
void imprime_vetor(Processo* p, int t){
	int i = 0;
	for(i; i<t; i++){
		imprime_Processo(p[i]);
	}
}


/*Funcao que executa o escalonamento.	*/
void escalonamento(){
	
	printf("escalonando...\n");
}
