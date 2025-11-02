/*
5) Escreva um programa que leia um número de 1 a 7 e exiba o dia da semana
correspondente. Caso o número seja inválido, exiba uma mensagem de erro.
*/
#include<stdio.h>

int main(){
	int D;
	printf("*Questao 5 - dias da semana*\nDigite um numero de 1 a 7: ");
	scanf("%d", &D);
	switch(D){
		case 1:
			printf("1 corresponde a DOMINGO!");
			break;
		case 2:
			printf("2 corresponde a SEGUNDA-FEIRA!");
			break;
		case 3:
			printf("3 corresponde a TERCA-FEIRA!");
			break;
		case 4:
			printf("4 corresponde a QUARTA-FEIRA!");
			break;
		case 5:
			printf("5 corresponde a QUINTA-FEIRA!");
			break;
		case 6:
			printf("6 corresponde a SEXTA-FEIRA!");
			break;
		case 7:
			printf("7 corresponde a SABADO!");
			break;
		default:
			printf("Valor fora do limite determinado!");
	}
	return 0;
}
