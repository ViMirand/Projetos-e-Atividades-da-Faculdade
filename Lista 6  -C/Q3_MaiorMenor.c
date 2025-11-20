/*
3) Faça um programa que leia vários números e mostre o maior e o menor digitado
(encerre com -1).
*/

#include<stdio.h>

int main(){
	int aux = 2, maior, menor, N;
	printf("\t*Questao 3 - Maior e menor*\nOBS: AO DIGITAR -1, SEU PROGRAMA TERMINA E APRESENTA O MAIOR E O MENOR TERMO DIGITADOS!");
	printf("\nTermo 1: ");
	scanf("%d", &N);
	maior = menor = N;
	do{
		printf("Termo %d: ", aux);
		scanf("%d", &N);
		if(N>=maior){
			maior = N;
		}else if(N<=menor){
			menor = N;
		}
		aux+=1;
	}while(N!=-1);
	printf("\nO maior termo e: %d\nE o menor termo e: %d", maior, menor);
	return 10;
}
