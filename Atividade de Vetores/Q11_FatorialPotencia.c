#include<stdio.h>

/*
11)
a) Preencher um vetor, chamado vetorBase, de 20 posições com números reais;
b) Preencher um vetor, chamado vetorExp, de 20 posições com números inteiros;
c) Preencher outro vetor de 20 posições, chamado vetorResultado, onde cada elemento
será o resultado da expressão vetorBasei(elevado a vetorExpi) + vetorExpi! , onde i e j são índices dos vetores, respectivamente.

Sugestão: você pode usar funções para calcular a potência e o fatorial.
d) Escrever o conteúdo de vetorResultado.
*/

#define TAM 4

int Potencia( int Ve, float vb){
	int soma=1, i;
	for(i=1; i<=Ve; i++){
		soma*=vb;
	}
	return soma;
}

int Fatorial(int Ve){
	int soma=1, a, c;
	for(a=Ve; a>1;a--){
		soma*=a;
	}
	return soma;
}

int main(){
	int vetE[TAM], vetR[TAM], j, i;
	float vetB[TAM];
	
	printf("Preencha o vetorBase de %d posicoes:\n", TAM);
	for(i=0; i<TAM; i++){
		scanf("%f", &vetB[i]);
	}
	printf("Agora, preencha o vetorExp de %d posicoes:\n", TAM);
	for(i=0; i<TAM; i++){
		scanf("%d", &vetE[i]);
	}
	for(i=0;i<TAM;i++){
		vetR[i] = Potencia(vetE[i], vetB[i]) + Fatorial(vetE[i]);
	}
	printf("\nOBS: Vetor Resultado foi preenchido como a operacao:\nvetorBasei(elevado a vetorExpi) + vetorExpi! \n\nVetores:\nBASE\t\tEXP\tRESULTADO\n");
	for(i=0; i<TAM; i++){
		printf("%f\t%d\t%d\n", vetB[i], vetE[i], vetR[i]);
	}
	return 10;
}

