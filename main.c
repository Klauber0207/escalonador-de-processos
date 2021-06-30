#include "klibrary.h"

void main(){

Processo carregar[T];		//Vetor para armazenar os processos que irão ser carregados.
Processo pronto[T];			//Vetor que irá armazenar os processos que passaram pela execução.
vetor_zero(pronto);			//Enche o vetor carrega com elementos vazios.
enche_vetor(carregar, T);	//Enche o vetor carrega, criando novos processos.
imprime_vetor(carregar, T);	//Imprime os processos criados no vetor carregar.
continuar();				//Deseja continuar?
escalonamento(carregar, pronto);	//Chama o escalonamento em si. 
continuar();				//Deseja continuar?

}
