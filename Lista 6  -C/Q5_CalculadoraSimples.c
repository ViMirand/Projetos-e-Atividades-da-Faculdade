/*
5) Faça um programa para simular uma calculadora simples, que contenha funções
para o título do programa, cálculo das operações (funções com retorno e que
tenham dois parâmetros) e switch-case (Menu). Deve-se aplicar um laço de
repetição com teste no final que englobe o Menu, a fim que o programa fique
executando enquanto o usuário desejar.
*/

#include<stdio.h>

int main(){
	int op, Again=0;
	float N1, N2;
	printf("*Questao 5 - Calculadora Simples*");
	do{
		printf("\nDigite dois valores:\nValor 1: ");
		scanf("%f", &N1);
		printf("\nValor 2: ");
		scanf("%f", &N2);
		do{
			op = menu();
			switch(op){
				case 1:
					printf("%f + %f = %f", N1, N2, soma(N1, N2));break;
				case 2:
					printf("%f + %f = %f", N1, N2, subtracao(N1, N2));break;
				case 3:
					printf("%f + %f = %f", N1, N2, multiplicacao(N1, N2));break;
				case 4:
					printf("%f + %f = %f", N1, N2, divisao(N1, N2));break;
				default:
					printf("Opcao invalida!\n");
					Again ==1;break;
			}
		}while(Again ==1);
		printf("\n\nDeseja usar a calculadora novamente?\n1 - SIM\t0 - NAO");
		scanf("%d", &Again);
	}while(Again == 1);
	return 10;
}

int menu(){
	int op;
	printf("\nEscolha a operacao matematica:\n\t1_SOMA\n\t2_SUBTRACAO\n\t3_MULTIPLICACAO\n\t4_DIVISAO\n");
	scanf("%d", &op);
	return op;
}

float soma(float n1, float n2){
	return n1 + n2;
}
float subtracao(float n1, float n2){
	return n1 - n2;
}
float multiplicacao(float n1, float n2){
	return n1 * n2;
}
float divisao(float n1, float n2){
	int div;
	if(n1==0 || n2 == 0){
		printf("Resultado indefinido.\nNao e possivel fazer divisao por zero! \n\nEscolha outros valores para a divisao, por favor.");
		main();
		return 0;
	}else{
		div = n1/n2;
		return div;
	}
}
