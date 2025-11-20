/*
2) Faça um programa que leia vários números até o usuário digitar 0 e mostre a soma
deles.
*/

#include<stdio.h>

int main(){
	float Soma=0, N;
	printf("\t*Questao 2 - Soma de N termos*\nOBS: AO DIGITAR ZERO, SEU PROGRAMA TERMINA E APRESENTA A SOMA DE TODOS OS TERMOS DIGITADOS!");
	do{
		printf("\nValor: ");
		scanf("%f", &N);
		Soma = Soma+N;
	}while(N!=0);
	printf("A soma de total e: %.1f", Soma);
	return 10;
}
