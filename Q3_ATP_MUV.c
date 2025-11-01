#include<stdio.h>
#include<math.h>

int main(){
	float s, so, vo, t, a;
	printf("*Questao 3\nDigite os valores da posicao inicial, velocidade inicial, tempo e aceleracao, nesta ordem, por favor.");
	scanf("%f%f%f%f", &so,&vo,&t,&a);
	s=so+vo*t+0.5*a*pow(t,2);
	printf("\nO valor da posicao final e: %.1f", s);
	return 0;
}
