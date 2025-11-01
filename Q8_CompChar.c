#include<stdio.h>

/*
8) Preencher um vetor de 30 posições com caracteres. Verificar a ocorrência (quantidade de
vezes) de uma letra fornecida pelo usuário, que exista no vetor.
*/
#define TAM 30
int main(){
	char vet[TAM], Letra, soma=0, a;
	printf("Preencha o vetor apenas com caracteres, por favor.\nOBS: Caracteres sao simbolos e letras!\n");
	for(a=0; a<TAM; a++){
		scanf(" %c", &vet[a]);
	}
	printf("Agora digite uma letra.\n");
	scanf(" %c", &Letra);
	for(a=0; a<TAM; a++){
		if(vet[a]==Letra){
			soma++;
		}
	}
	printf("A letra %c se repete %d vezes no vetor.", Letra, soma);
	return 10;
}
