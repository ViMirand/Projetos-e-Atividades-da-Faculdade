#include<stdio.h>

int main(){
	int Fal;
	float N1, N2, M;
	printf("Questao 7 - Situacao do aluno: Aprovado ou Reprovado?*\nDigite o numero de faltas do aluno: ");
	scanf("%d", &Fal);
	printf("\nDigite as duas notas que ele recebeu nas provas: \n");
	scanf("%f%f", &N1, &N2);
	M = (N1 + N2)/2;
	if(M>=5){
		if(Fal>20){
			printf("\nAluno Reprovado!!!\nMotivo:\nFREQUENCIA MINIMA: 60\nFREQUENCIA DO ALUNO: %d\nABAIXO DO LIMITE DE 75%% DE PRESENCA EXIGIDOS PELA ESCOLA", 80-Fal);
		}else{
			printf("\nAluno Aprovado!!");
		}
	}else{
		printf("\nAluno Reprovado!!!\nMotivo: Media: %.1f", M);
	}
	return 50; 
}
