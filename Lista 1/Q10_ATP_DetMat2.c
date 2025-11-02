#include<stdio.h>

int main(){
	float det, a1, a2, a3, a4;
	printf("*Questao 10*\nDigite os valores da primeira linha da matriz:\n");
	scanf("%f%f", &a1, &a2);
	printf("\nAgora, digite os valores da segunda linha da matriz:\n");
	scanf("%f%f", &a3, &a4);
	det = (a1*a4)-(a2*a3);
	printf("\nO determinante da matriz e: %.1f", det);
	return 0;
}
