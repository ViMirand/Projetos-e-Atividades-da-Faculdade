/*
8) Escreva um trecho de código em C para somar as duas últimas linhas de uma matriz 5 x 5 e
armazenar o resultado em um vetor.
*/

#include<stdio.h>
#define TAM 5
int main(){
	int vet[TAM][TAM], a1, a2, soma[TAM];
	for(a1=0; a1<TAM; a1++){
		for(a2=0; a2<TAM; a2++){
			scanf("%d", &vet[a1][a2]);
			if(a1==TAM-2){
				soma[a2]=vet[a1][a2];
			}
			if(a1==TAM-1){
				soma[a2]+=vet[a1][a2];
			}
		}
	}
	printf("Vetor Soma: ");
	for(a1=0; a1<TAM; a1++){
		printf(" %d", soma[a1]);
	}
	return 10;
}
