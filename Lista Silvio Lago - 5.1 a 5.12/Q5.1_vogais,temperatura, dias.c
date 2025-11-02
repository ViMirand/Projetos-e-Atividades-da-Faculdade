#include<stdio.h>

/*
Exercício 5.1. Crie tipos de vetores para armazenar:
a) as letras vogais do alfabeto.
b) as temperaturas diárias de uma semana.
c) o número de dias em cada um dos meses do ano.
Em geral, um vetor v pode ser indexado com qualquer expressão cujo valor
seja de tipo integral2. Essa expressão pode ser uma simples constante, uma
variável ou então uma expressão propriamente dita, contendo operadores,
constantes e variáveis.
*/
#define Tmeses 12
#define Ttemp 7
#define Tvogais 5
int main(){
	char Vogais[Tvogais];
	int Meses[Tmeses], a;
	float Temp[Ttemp];
	
	printf("Preencha o vetor com todas as vogais do alfabeto:\n");
	for(a=0; a<Tvogais; a++){
		scanf(" %c", &Vogais[a]);
	}
	printf("Preencha o vetor com a quantidade de dias de cada mes do ano:\n");
	for(a=0; a<Tvogais; a++){
		printf("Mes %d: ", a+1);
		scanf(" %d", &Meses[a]);
	}
	printf("Preencha o vetor com a temperatura de cada dia da semana:\n");
	for(a=0; a<Tvogais; a++){
		printf("Dia %d: ", a+1);
		scanf(" %f", &Temp[a]);
	}
	printf("\n\nEsses sao os vetores:\nVOGAIS: ");
	for(a=0; a<Tvogais; a++){
		printf(" %c", Vogais[a]);
	}
	printf("\nMES - DIAS\n");
	for(a=0; a<Tmeses; a++){
		printf("Mes %d: %d\n", a+1, Meses[a]);
	}
	printf("\nDIA - TEMPERATURA\n");
	for(a=0; a<Ttemp; a++){
		printf("Dia %d: %f\n", a+1, Temp[a]);
	}
	return 10;
}
