#include<stdio.h>

int main(){
	int N, aux=1;
	printf("*Tabuada de Multiplicacao*\nDigite um numero inteiro: ");
	scanf("%d", &N);
	while(aux<=10){
		printf("\n%d x %d = %d", N, aux, aux*N);
		aux+=1;
	}
	return 19;
}
