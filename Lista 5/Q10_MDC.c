/*
10) Escreva um programa que calcule o MDC (máximo divisor comum)
de dois números usando repetição.
*/

#include<stdio.h>

int main(){
	int N1, N2, aux2 = 2, arm;
	printf("Questao 10 - MDC\nDigite dois valores:\n");
	scanf("%d%d", &N1, &N2);
	while(N1/aux2 != 0 && N2/aux2 !=0){
		if(N2%aux2==0 && N1%aux2==0){
			arm = aux2;
			aux2 +=1;
		}else{
			aux2+=1;
		}
	}
	printf("O MDC de %d e %d: %d",N1, N2, arm);
	return 0;
}
