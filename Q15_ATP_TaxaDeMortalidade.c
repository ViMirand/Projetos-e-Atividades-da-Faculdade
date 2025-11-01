#include<stdio.h>

int main(){
	float Mort, obitos, habit;
	printf("*Questao 14*\nDigite o numero de obitos e o numero de habitantes, nesta ordem, por favor:\n");
	scanf("%f%f", &obitos, &habit);
	Mort=obitos*1000/habit;
	printf("\nA taxa de mortalidade e: %.0f%%", Mort);
	return 0;
}
