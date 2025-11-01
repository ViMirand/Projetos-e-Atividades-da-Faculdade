#include<stdio.h>

/*
6) Preencher um vetor de 12 posições com caracteres. Inverter o conteúdo do vetor. Informar
o resultado da inversão.
*/


#define TAM 5
int main(){
	char Vet[TAM];
	printf("Preencha o Vetor:\n");
	for(int a=0; a<TAM; a++){
		scanf(" %c", &Vet[a]);
	}
	printf("Vetor invertido:\n");
	for(int a=TAM-1; a>=0; a--){
		printf(" %c", Vet[a]);
	}
	return 10;
}
