#include<stdio.h>

int main(){
	int N, aux = 2, aux2;
	printf("Questao 6 - Esse numero e primo?\n\tOBS: O NUMERO 0 PARA A REPETICAO!");
	while(aux2!=0){
		printf("\nDigite um numero: ");
		scanf("%d", &N);
		aux2=N;
		aux = 2;
		while(N%aux!=0 && aux<8){
			aux+=1;
			if(aux==4){
				aux+=1;
			}else if(aux==6){
				aux+=1;
			}
		}
		if(aux == 8 || ((N==2 || N==3) || (N==5 || N==7))){
			printf("- O numero %d e primo!\n", N);
		}else{
			printf("- O numero %d nao e primo!\n", N);
		}
	}
	return 90;
}
