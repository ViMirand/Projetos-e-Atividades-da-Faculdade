#include<stdio.h>

int main(){
	int N, aux = 2;
	printf("Digite um numero: ");
	scanf("%d", &N);
	while(N%aux!=0 && aux<8){
		aux+=1;
		if(aux==4){
			aux+=1;
		}else if(aux==6){
			aux+=1;
		}
	}
	if(aux == 8 || ((N==2 || N==3) || (N==5 || N==7))){
		printf("\nO numero %d e primo!", N);
	}else{
		printf("\nO numero %d nao e primo!", N);
	}
	return 90;
}
