#include<stdio.h>

int main(){
	float IR, RS;
	printf("*Questao 1 - Imposto de Renda*\nDigite o valor do seu salario: ");
	scanf("%f", &RS);
	if(RS<=1050){
		printf("Isento!");
	}else if(RS<=2500){
		IR = RS * 0.15;
		printf("IR: %.2f", IR);
	}else if(RS<=7500){
		IR = RS * 0.25;
		printf("IR: %.2f", IR);
	}else{
		IR = RS * 0.35;
		printf("IR: %.2f", IR);
	}
	return 10;
}
