#include<stdio.h>
#include<math.h>

int main(){
	float a, b, c, x1, x2, delt;
	printf("Questao 4 - Equacao do 2 grau*\nDigite o valor dos coeficientes: a, b e c:\n");
	scanf("%f%f%f", &a, &b, &c);
	if(a!=0){
		delt = pow(b,2) - 4*a*c;
		if(delt>=0){
			x1 = (- b + sqrt(delt))/(2*a);
			x2 = (- b - sqrt(delt))/(2*a);
			printf("As raizes sao: %.1f e %.1f", x1, x2);
		}else{
			printf("Nao ha raizes reais!!!!!");
		}
	}else if(b!=0 && c!=0){
		printf("Os valores nao configuram uma equacao do 2 grau, porem o valor de x e: %.1f ou - %.0f / %.0f", (-c)/b, c, b);
	}else{
		printf("Perdao, os valores dados nao configuram uma equacao do 2 grau nem geram resultado valido!");
	}
	return 0;
}
