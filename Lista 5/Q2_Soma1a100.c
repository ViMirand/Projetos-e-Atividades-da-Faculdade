#include<stdio.h>

int main(){
	int aux = 1, Soma = 0;
	
	while(aux<=100){
		Soma = Soma + aux;
		aux+=1;
	}
	printf("O valor da soma de 1 a 100 e: %d", Soma);
	return 0;
}
