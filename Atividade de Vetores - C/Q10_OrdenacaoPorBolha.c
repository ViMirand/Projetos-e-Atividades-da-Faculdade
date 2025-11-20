#include<stdio.h>

/*
10) Ler um vetor de 20 posições inteiras e o coloque em ordem crescente, utilizando como
estratégia de ordenação a comparação de pares de elementos adjacentes, permutando-os
quando estiverem fora de ordem, até que todos estejam ordenados (algoritmo conhecido
como “ordenação por bolhas” ou “método da bolha”).

*/
#define TAM 9
int main(){
	int vet[TAM], aux, a, troca;
	printf("Preencha o vetor de %d posicoes:\n", TAM);
	for(a=0; a<TAM; a++){
		scanf("%d", &vet[a]);
	}
	printf("Vetor original:\n");
	for(a=0; a<TAM;a++){
		printf("%d ", vet[a]);
	}
	do{
		troca=0;
		for(a=0;a<TAM-1;a++){
			if(vet[a]>vet[a+1]){
				aux = vet[a];
				vet[a] = vet[a+1];
				vet[a+1] = aux;
				troca++;
			}
		}
	}while(troca!=0);
	printf("\n\nVetor reordenado:\n");
	for(a=0; a<TAM;a++){
		printf("%d ", vet[a]);
	}
	return 10;
}
