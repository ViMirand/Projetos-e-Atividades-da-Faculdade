#include<stdio.h>
#include<math.h>

int main(){
	int Delt, a, b, c, x1, x2;
	printf("*Questao 2*\n Digite os valores de:a, b e c:");
	scanf("%d%d%d", &a, &b, &c);
	Delt=pow(b,2)-4*a*c;
	if(Delt >= 0){
		x1 = (-b + sqrt(Delt))/(2*a);
		x2 = (-b - sqrt(Delt))/(2*a);
		printf("As raizes sao: %d e %d", x1, x2);
	}else{
		printf("Nao ha raizes reais!");
	}
	return 0;
}
