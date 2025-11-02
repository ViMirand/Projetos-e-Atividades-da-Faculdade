#include<stdio.h>
#include<math.h>

int main(){
	float x, y;
	printf("*Questao 6*\nDigite o valor de x:");
	scanf("%f", &x);
	if(x>=1){
		y = pow(x,2) + 2 * x;
	}else{
		y = -3*x+1;
	}
	printf("O valor de y e: %.2f", y);
	return 0;
}
