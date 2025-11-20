#include<stdio.h>

int main(){
	int a, b, maior;
	printf("*Questao 10*\nDigite os valores de a e b:\n");
	scanf("%d%d", &a, &b);
	maior = a;
	if(b>maior){
		maior = b;
	}
	printf("O maior valor entre eles e: %d", maior);
	return 0;
}
