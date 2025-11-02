#include<stdio.h>

int main(){
	int Id;
	printf("*Questao 6 - Campeonato de Natacao*\nDigite a idade do atleta: ");
	scanf("%d", &Id);
	if(Id>=5){
		if(Id<=7){
			printf("\nCategoria: INFANTIL A");
		}else if(Id<=10){
			printf("\nCategoria: INFANTIL B");
		}else if(Id<=13){
			printf("\nCategoria: JUVENIL A");
		}else if(Id<=17){
			printf("\nCategoria: JUVENIL B");
		}else{
			printf("\nCategoria: SENIOR");
		}
	}else{
		printf("\nInfelizmente o competidor nao podera competir: Jovem demais para qualquer categoria!");
	}
	return 50;
}
