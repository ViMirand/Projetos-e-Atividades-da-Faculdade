/*
12) Calcular N! (fatorial de N), sendo que o valor inteiro de N deve
ser fornecido pelo usuário.
*/

#include<stdio.h>

int main(){
	int N, Fat=1, aux=1;
	printf("Questao 12 - Fatorial\nDigite um valor: ");
	scanf("%d", &N);
	while(aux<=N){
		Fat = aux*Fat;
		aux+=1;
	}
	printf("O fatorial de %d e: %d", N, Fat);
	return 10;
}
