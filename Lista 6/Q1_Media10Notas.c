//1) Faça um programa que leia 10 números e exiba a média deles.

#include<stdio.h>

int main(){
	int Soma = 0, M, N, aux=1;
	printf("*Questao 1 - Media de 10 numeros*\n");
	do{
		printf("\nDigite a nota da %d avaliacao: ", aux);
		scanf("%d", &N);
		Soma = N + Soma;
		aux+=1;
	}while(aux<=10);
	M = Soma/10;
	printf("\nA media do aluno e: %d", M);
	return 10;
}
