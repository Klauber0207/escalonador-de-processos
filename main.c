#include <stdio.h>
#include "klibrary.h"

void main(){

Processo carregar[T];		//Vetor para armazenar os processos que irão ser carregados.
//Processo executar[1];		//Vetor que irá armazenar o processo que esta executando no momento.
Processo pronto[T];			//Vetor que irá armazenar os processos que passaram pela execução.

enche_vetor(carregar, T);	//Enche o vetor carrega, criando novos processos.
imprime_vetor(carregar, T);	//Imprime os processos criados no vetor carregar.

continuar();				//Deseja continuar?

escalonamento(carregar, pronto);	//Chama o escalonamento em si.


 
}
