#include<stdio.h>
/*
4) Ler 15 números inteiros e armazenar em um vetor. Calcular o fatorial destes números,
armazenar em outro vetor e informar o resultado. Faça uma outra versão desse programa,
onde deve ser usado uma função para calcular o fatorial de um número.
*/
#define Tam 15

void Fatorial(){
	int vet[Tam], fat[Tam], soma, c;
	for(int a=0; a<Tam; a++){
		printf("%d- ", a+1);
		scanf("%d", &vet[a]);
		soma = 1;
		for(int i=vet[a]; i>0;i--){
			c = i;
			soma = soma * c;
		}
		fat[a] = soma;
		printf("\n");
	}
	printf("Lista com os 15 elementos:\n");
	for(int a =0; a<Tam; a++){
		printf("%d ", vet[a]);
	}
	printf("\n\nSeus respectivos fatoriais:\n");
	for(int a =0; a<Tam; a++){
		printf("%d ", fat[a]);
	}
}

int main(){
	printf("Digite 15 numeros em sequencia, por favor:\n");
	Fatorial();
	return 10;
}
