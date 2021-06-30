/*klibrary.h*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <windows.h>

#define T 10		//Número de processos.
#define TM 5		//Tempo maximo de um processo.
#define TEMP 1000 	//Numero em milissegundos para cada tempo de execução.


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
void escalonamento(Processo* carregar, Processo* pronto){
	
	printf("escalonando...\n\n");
	
	int i = 0; 
	Processo executar, aux;
	
	for(i; i<T; i++){
		executar = carregar[i];									//Passa o elemento atual para indicar que este está executando.
		carregar[i] = cria_Processo();							//Esvazia o espaço que foi executado.
		printf("Carregar = "); 		imprime_celulas(carregar);	//Imprime os processos que ainda serão executados.
		printf("Pronto   = ");		imprime_celulas(pronto);	//Imprime os processos que estão prontos.
		executa_processo(executar);								//Executa um processo.
				
		pronto[i] = executar;									//Passa o processo que foi executado para a lista de prontos.
		printf("\n\n");
	}
//	printf("\n\n");
//	imprime_vetor(pronto, T);
}


/*Apenas interrope o programa até o usuario apertar ENTER.	*/
void continuar(){
	printf("\n\nPressione ENTER para continuar...");
	scanf("%c");
	printf("\n\n");
}


/*Imprimir vetor em celulas*/
void imprime_celulas(Processo* p){
	int i = 0;
	int contador = 0;
	
	for(i; i<T; i++){
		if(p[i].id != 0){
				printf("  [ %d ]  ", p[i].id);
				contador++;			
		}
	}
	if(contador == 0){
		printf("   [Vazio]");
	}	
	printf("\n");
	
}


/*Atribui ao vetor selecionado todas as suas posições com processos 0 (processos vazios).*/
void vetor_zero(Processo* p){
//	Processo p[T];
	int i = 0;
	
	for(i; i<T; i++){
		p[i] = cria_Processo();
		
	}
//	return p;
}


/*Executa um processos com um delay simbolizando o tempo de execução.*/

void executa_processo(Processo p){
	
	int i = 0;
	printf("Executando = [ %d ] - tamanho: %d	", p.id, p.duracao);
	
	while(i < p.duracao){
		printf("||");
		Sleep(1*TEMP);
		i++;
	}
}


/*Ordena a ordem de processor, do maior para o menor*/
void ordena_vetor(Processo* p){
	
	Processo aux;
	int i = 0;	
	int j;

	for(i; i<T; i++){
		for(j = i; j<T; j++){
			if(p[i].duracao < p[j].duracao){
				
				aux = p[i];
				p[i] = p[j];
				p[j] = aux;
			}
		}
	}	
	imprime_vetor(p, T);
}
