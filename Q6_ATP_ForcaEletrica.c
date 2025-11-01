#include<stdio.h>
#include<math.h>

int main(){
	float FEl, k, d;
	int q1, q2;
	printf("*Questao 6*\nDigite os valores: da carga 1, da carga 2, da distancia e da constante, nesta ordem:\n");
	scanf("%d%d%f%f", &q1, &q2, &d, &k);
	FEl=k*((abs(q1)*abs(q2))/pow(d,2));
	printf("\nForca eletrica e: %.1f", FEl);
	return 0;
}
