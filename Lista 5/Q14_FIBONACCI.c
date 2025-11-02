/*
14) Gerar a série de Fibonacci que é formada pela seguinte
sequência: 1, 1, 2, 3, 5, 8, 13, 21, ... A quantidade de número da série
o usuário informará.
*/

#include<stdio.h>

int main(){
	int F, aux, Soma = 0, Soma2 = 1;
	printf("Questao 14 - FIBONACCI\nDigite a quantidade de numero da serie: ");
	scanf("%d", &F);
	printf("\nA sequencia Fibonacci com %d elementos e:\n", F);
	while(aux<F){
		printf("%d, ", Soma);
		Soma = Soma + Soma2;
		Soma2 = Soma - Soma2;
		aux+=1;
	}
	return 0;
}
