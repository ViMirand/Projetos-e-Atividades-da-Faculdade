#include<stdio.h>
#include<math.h>

int main(){
	float Sal, Ajuste;
	printf("*Questao 5 - Reajuste de Salario*\nDigite seu salario: ");
	scanf("%f", &Sal);
	if(Sal<700){
		Ajuste = Sal * 1.15;
	}else if( Sal<=1200){
		Ajuste = Sal * 1.10;
	}else{
		Ajuste = Sal * 1.05;
	}
	printf("\nSeu novo salario e: %.2f", Ajuste);
	return 10;
}
