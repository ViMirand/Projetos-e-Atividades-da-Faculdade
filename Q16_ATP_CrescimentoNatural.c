#include<stdio.h>

int main(){
	float cv, born, die;
	printf("*Questao 16*\nDigite os valores da taxa de natalidade e taxa de mortalidade, nesta ordem:\n");
	scanf("%f%f", &born, &die);
	cv = born - die;
	printf("\nO crescimento natural e: %.1f", cv);
	return 0;
}
