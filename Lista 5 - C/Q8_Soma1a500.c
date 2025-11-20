/*
Implemente um programa que calcule a soma dos números ímpares
entre 1 e 500.
*/

#include<stdio.h>

int main(){
	int soma=0, aux=1;
	while(aux<=500){
		if(aux%2!=0){
			soma = soma + aux;
		}
		aux+=1;
	}
	printf("A Soma dos numeros no intervalo de 1 a 500 e: %d", soma);
	return 0;
}
