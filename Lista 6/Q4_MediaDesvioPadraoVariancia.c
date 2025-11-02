/*
4) Faça um programa que leia vários números naturais maiores que 0, mas o
programa encerará quando o usuário digitar 0. 
No final o programa deve mostrar a
média, o desvio padrão e a variância.
*/
#include<stdio.h>

int main(){
	float Aux=1, N, M, DV, V, Soma;
	printf("\t*Questao 4 - Media, Desvio Padrao e Variancia*\nOBS: AO DIGITAR 0, O PROGRAMA APRESENTARA O RESULTADO DA\nMEDIA, DA VARIANCIA E DO DESVIO PADRAO E SERA ENCERRADO!");
	do{
		printf("\n\nValor %.0f:", Aux);
		scanf("%f", &N);
		Soma = Soma + N;
		Aux +=1;
	}while(N!=0);                                                           
	M = Soma/(Aux-1);
	printf("\n\tMedia: %.1f\n\tDesvio Padrão: %.1f\n\tVariancia: %.1f", M, DV, V);
	return 10;
}
