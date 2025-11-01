#include<stdio.h>

int main(){
	float Q, m, c, t, to;
	printf("*Questao 5*\nDigite a massa, o calor especifico, a temperatura inicial e a temperatura final, nesta ordem, por favor.");
	scanf("%f%f%f%f", &m, &c, &to, &t);
	Q=m*c*(t-to);
	printf("\nA quantidade de calor e: %1.f\n", Q);
	return 0;
}
