#include<stdio.h>
#include<math.h>

int main(){
	float x, y, e;
	e = 2.7183;
	printf("*Questao 9*\nDigite o valor de x: ");
	scanf("%f", &x);
	if(x>=0 && x<=1){
		y = cos(x)-pow(e,x);
	}else{
		y = sin(x)+pow(x,5)-abs(pow(x,2));
	}
	printf("O valor de y e: %.2f", y);
	return 0;
}
