#include<stdio.h>

/*
7) Ler 3 notas de 6 alunos e suas respectivas matrículas. Calcular a média aritmética das notas
dos alunos. Informar a matrícula do aluno, a média aritmética e se o aluno foi aprovado
(maior ou igual a 7) ou reprovado, caso contrário.
*/

#define LINHAS 2
#define COL 4
int main(){
	int Aluno[LINHAS][COL], soma=0, Media, a, b;
	printf("Digite, nesta ordem, a MATRICULA e as NOTAS do ");
	for(a=0; a<LINHAS; a++){
		printf("Aluno %d: \n", a+1);
		for(b=0; b<COL; b++){
			scanf("%d", &Aluno[a][b]);
		}
	}
	printf("\n\nMATRICULA\tNOTAS 1\t\tNOTA 2\t\tNOTA 3\t\tMEDIA\t\tSITUACAO\n");
	for(a=0; a<LINHAS; a++){
			printf("%d", Aluno[a][0]);
			for(b=1; b<COL; b++){
				printf("\t\t%d", Aluno[a][b]);
				soma += Aluno[a][b];
			}
			Media= soma/3;
			if(Media>=7){
		 	printf("\t\t%d\t\tAPROVADO!", Media);
			}else{
		 	printf("\t\t%d\t\tREPROVADO!", Media);	
			}
			printf("\n");
			soma = 0;
	}
	return 10;
}
