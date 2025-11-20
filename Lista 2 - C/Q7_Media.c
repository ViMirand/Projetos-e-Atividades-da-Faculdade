#include<stdio.h>

int main(){
	float M, P1, P2, Proj;
	printf("*Questao 7*\nDigite as notas da Prova 1, da Prova 2 e do Projeto.\n");
	scanf("%f%f%f", &P1, &P2, &Proj);
	M = (P1+P2+(3*Proj))/5;
	if(M<5){
		printf("Sua nota: %.2f\n****Reprovado!", M);
	}else{
		printf("Sua nota: %.2f\n****Aprovado!", M);
	}
	return 0;
}
