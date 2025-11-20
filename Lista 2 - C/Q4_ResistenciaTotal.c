#include<stdio.h>

int main(){
	float Em, R1, R2, RT;
	printf("*Questao 4*\n Digite 0 para Resistores em Paralelo\n\t1 para Resistores em serie.\n");
	scanf("%f", &Em);
	printf("Agora digite o valor de R1 e R2:\n");
	scanf("%f%f", &R1, &R2);
	if(Em==0){
		RT = (R1*R2)/(R1+R2);
	}else{
		RT = R1+R2;
	}
	printf("A resistencia total e: %.20f", RT);
	return 0 ;
}
