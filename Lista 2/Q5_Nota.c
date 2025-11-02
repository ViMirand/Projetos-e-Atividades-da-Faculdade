#include<stdio.h>

int main(){
	float nota;
	printf("Questao 5\nDigite a nota:");
	scanf("%f", &nota);
	if(nota>=0 && nota <=10){
		printf("Nota Valida!");
	}else{
		printf("Nota invalida!");
	}
	return 0;
}
