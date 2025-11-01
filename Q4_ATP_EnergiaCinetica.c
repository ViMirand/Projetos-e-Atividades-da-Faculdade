#include<stdio.h>
#include<math.h>

int main(){
	float Ec, m , v;
	printf("*Questao 16*\nDigite os valores da massa e velocidade, nesta ordem:\n");
	scanf("%f%f", &m, &v);
	Ec=0.5*m*pow(v,2);
	printf("\nO Energia cinetica e: %.1f", Ec);
	return 0;
}
