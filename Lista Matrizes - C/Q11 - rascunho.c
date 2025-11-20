/*
11) Crie uma função que receba uma matriz de inteiros A[N][N] e calcule o determinante dela (para
N até 3). Utilize a regra de Sarrus para N=3.
*/

#include<stdio.h>

int main(){
	int N, a1, a2;
	printf("Digite a ordem da matriz quadrada:\n\nOBS: MÁx.3\n");
	scanf("%d", &N);
	int mat[N][N];
	printf("Agora preencha a matriz:\n");
	for(a1=0;a1<N;a1++){
		for(a2=0;a2<N;a2++){
			scanf("%d", &mat[a1][a2]);
		}
	}
	
	return 10;
}
