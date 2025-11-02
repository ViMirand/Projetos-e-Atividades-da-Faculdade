/*
6) Menu de Operações Matemáticas. Faça um programa que leia dois números inteiros e, em seguida,
exiba um menu com as opções:
1. Soma
2. Subtração
3. Multiplicação
4. Divisão
Use switch-case para executar a operação escolhida pelo usuário.
*/


#include<stdio.h>

int main(){
	float N1, N2;
	int op;
	printf("Questao 6 - Calculadora\ndigite dois numeros:\nN1: ");
	scanf("%f", &N1);
	printf("\nN2: ");
	scanf("%f", &N2);
	printf("\nAgora Escolha a operacao:\n1-SOMA\n2-SUBTRACAO\n3-MULTIPLICACAO\n4-DIVISAO\n");
	scanf("%d", &op);
	switch(op){
		case 1:
			printf("Operacao: SOMA\n%.0f + %.0f = %.0f", N1, N2, N1+N2);break;
		case 2:
			printf("Operacao: SUBTRACAO\n%.0f - %.0f = %.0f", N1, N2, N1-N2);break;
		case 3:
			printf("Operacao: MULTIPLICACAO\n%.0f x %.0f = %.0f", N1, N2, N1*N2);break;
		case 4:
			printf("Operacao: DIVISAO");
			if(N1 == 0 || N2 == 0){
				printf("\nNao e possivel fazer divisao por zero!!!!!");break;
			}else{
				printf("\n%.0f / %.0f = %.0f", N1, N2, N1/N2);break;
			}
		default:
			printf("O valor digitado nao corresponde a nenhuma operacao!");
	}
	return 10;
}
