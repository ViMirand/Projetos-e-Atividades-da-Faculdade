/*
9) Ler um vetor de 20 posições inteiras e o coloque em ordem crescente, utilizando a seguinte
estratégica de ordenação (algoritmo conhecido como seleção direta):
a) selecione o elemento do vetor de 20 posições que apresenta o menor valor;
b) troque este elemento pelo primeiro;
c) repita estas operações, envolvendo agora apenas os 19 elementos restantes (selecionando
o de menor valor com a segunda posição), depois os 18 elementos (trocando o de menor
valor com a terceira posição), depois os 17, 16 e assim por diante, até restar um único
elemento, o de maior valor.
*/

#include<stdio.h>
#define TAM 5

int main(){
	int vet[TAM], a, i, aux, menor, count=0;
	printf("Preencha o vetor de %d posicoes.\n", TAM);
	for(a=0; a<TAM; a++){
		scanf("%d", &vet[a]);
	}
	printf("Vetor em ordem crescente:\n\n");
	for(a=0; a<TAM; a++){
		menor = vet[a];
		for(i=count;i<TAM;i++){
			if(vet[i]<=menor){
				menor = vet[i];	
				vet[i] = vet[a];		
			}
			vet[a] = menor;
		}
		count++;
		printf("%d ", vet[a]);
	}
	return 10;	
}
