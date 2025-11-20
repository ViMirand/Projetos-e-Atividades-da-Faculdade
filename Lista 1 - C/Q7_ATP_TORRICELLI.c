#include<stdio.h>
#include<math.h>

int main(){
	float s, v, vo, a, so;
	printf("*Questao 7*\nDigite os valores de: posicao inicial e final, velocidade inicial e aceleracao. Nesta ordem, por favor.");
	scanf("%f%f%f%f", &so,&s,&vo,&a);
	v=sqrt(pow(vo,2)+2*a*(s-so));
	printf("\nA velocidade final e: %1.f", v);
	return 0;
}
