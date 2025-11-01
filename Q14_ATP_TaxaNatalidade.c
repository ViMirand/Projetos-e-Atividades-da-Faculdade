#include<stdio.h>

int main(){
	float Nat, born, habit;
	printf("*Questao 14*\nDigite o numero de nascimentos e o numero de habitantes, nesta ordem, por favor:\n");
	scanf("%f%f", &born, &habit);
	Nat=born*1000/habit;
	printf("\nA taxa de natalidade e: %.0f%%", Nat);
	return 0;
}
