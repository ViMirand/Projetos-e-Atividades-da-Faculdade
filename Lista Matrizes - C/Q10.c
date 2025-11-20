/*
10) Crie uma função que receba uma matriz 5 x 5 e troque a linha 1 pela linha 3.
*/
#include<stdio.h>
#define TAM 5
int main(){
	int vet[TAM][TAM], a1, a2, soma[TAM];
	printf("Digite sua matriz de ordem 5. \nOBS: Pode ser assim: a11 a12 a13 [...] a55\nou assim:\na11 a12 a13 a14 a15\na21 a22 a23 a24 a25\na31 a32 a33 a34 a35\n[...]\nMatriz: ");
	for(a1=0; a1<TAM; a1++){
		for(a2=0; a2<TAM; a2++){
			scanf("%d", &vet[a1][a2]);
			if(a1==2){
				soma[a2]=vet[0][a2];
				vet[0][a2] = vet[a1][a2];
				vet[a1][a2] = soma[a2];
			}
		}
	}
	printf("\n\nMatriz com 2 linha permutadas.\n");
	for(a1=0; a1<TAM; a1++){
		for(a2=0; a2<TAM; a2++){
			printf("%d ", vet[a1][a2]);
		}
		printf("\n");
	}
	return 10;
}
