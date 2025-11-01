#include<stdio.h>

int main(){
	float a, b, tgA, tgB, SomaAB;
	printf("*Questao 9*\nDigite os valores dos angulos 1 e 2:\n");
	scanf("%f%f", &a, &b);
	printf("\nAgora, digite os valores das tangentes desses angulos, respectivamente:\n");
	scanf("%f%f", &tgA, &tgB);
	SomaAB=(tgA+tgB)/1-tgA*tgB;
	printf("\nA tangente da soma dos angulos: %.1f e %.1f, e: %.1f", a, b, SomaAB);
	return 0;
}
