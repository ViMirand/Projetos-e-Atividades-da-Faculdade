#include<stdio.h>

int main(){
	float v, vo, a, t;
	printf("*Questao 2*\nDigite os valores da velocidade inicial, da aceleracao e do tempo:\n");
	scanf("%f%f%f", &vo, &a, &t);
	v= vo+a*t;
	printf("\nA velocidade final e: %.1f", v);
	return 0;
}
