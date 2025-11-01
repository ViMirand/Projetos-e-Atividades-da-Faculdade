#include<stdio.h>

/*
5) Preencher dois vetores, A e B de 5 posições, com caracteres. Construir um terceiro vetor C
para armazenar a concatenação (junção dos conteúdos) dos vetores A e B. Apresentar o
resultado dos elementos do vetor C.
*/
#define TAM 5
int main(){
	char A[TAM], B[TAM], C[TAM*2], a;
	printf("Preencha as 5 posicoes do vetor A com caracteres:\nA:\n");
	for(a=0; a<TAM; a++){
		scanf(" %c", &A[a]);
	}
	printf("Agora, preencha as 5 posicoes do vetor B com caracteres:\nB:\n");
	for(a=0; a<TAM; a++){
		scanf(" %c", &B[a]);
	}
	printf("Vetor C:\n");
	for(a =0; a<TAM; a++){
		C[a] = A[a];
		C[a+TAM] = B[a];
	}
	for(a =0 ; a<TAM*2; a++){
		printf(" %c ", C[a]);
	}
	return 10;
}
