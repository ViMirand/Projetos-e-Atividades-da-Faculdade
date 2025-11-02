#include<stdio.h>


int main(){
	int n;
	printf("\n*Questao 1*\nDigite um numero de 0 a 10: ");
	scanf("%d", &n);
	switch(n){
		case 0:
			printf("zero");break;
		case 1:
			printf("um");break;
		case 2:
			printf("dois");break;
		case 3:
			printf("tres");break;
		case 4:
			printf("quatro");break;
		case 5:
			printf("cinco");break;
		case 6:
			printf("seis");break;
		case 7:
			printf("sete");break;
		case 8:
			printf("oito");break;
		case 9:
			printf("nove");break;
		case 10:
			printf("dez");break;
		default:
			printf("valor nao disponivel!! Tente novamente");
			//main();
	}
	return 10000000;
}

