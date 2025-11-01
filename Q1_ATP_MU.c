#include<stdio.h>

int main(){
	float s,so,v,t; //Q1
	printf("*Questao 1*\nDigite os valores da posicao inicial, a velocidade e o tempo, netsa ordem, por favor.");
	scanf("%f%f%f", &so, &v, &t);
	s=so+v*t;
	printf("O valor da posicao final e: %.1f\n", s);
	return 0;
}
