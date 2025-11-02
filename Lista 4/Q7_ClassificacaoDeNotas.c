/*7) Classificação de Notas. Leia uma nota inteira de 0 a 10 e utilize switch-case para classificar:
0 a 4 ? Reprovado
5 a 6 ? Recuperação
7 a 10 ? Aprovado
Exiba a mensagem correspondente.
*/

#include<stdio.h>

int main(){
	int N;
	printf("*Questao 7 - Classificacao de notas*\n\nDigite uma nota inteira de 0 a 10: ");
	scanf("%d", &N);
	switch(N){
		case 0: case 1: case 2: case 3: case 4:
			printf("Reprovado!");break;
		case 5: case 6:
			printf("Recuperacao!");break;
		case 7: case 8: case 9: case 10:
			printf("Aprovado!");break;
		default:
			printf("Nota invalida!");
	}
	return 10;
}
