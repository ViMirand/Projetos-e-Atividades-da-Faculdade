#include<stdio.h>
#include<math.h>


int main(){
	float v,r;
	printf("*Questao 13*\nDigite o valor do raio da circunferencia:\n");
	scanf("%f", &r);
	v=(4*3.14*pow(r,3))/3;
	printf("\nO volume da esfera e: %.1f unidades cubicas ou %.0fPi", v, v/3.14);
	return 0;
}
