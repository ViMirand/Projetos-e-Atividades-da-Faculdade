/*
Exercício 5.8. Digite as funções apresentadas e teste o funcionamento do
programa que resolve o problema das temperaturas acima da média.
*/

#include<stdio.h>
#define max 7

void obtem(float t[]) {
	int i;
	puts("Informe as temperaturas: ");
	for(i=0; i<max; i++) {
		printf("%do valor? ",i+1);
		scanf("%f", &t[i] );
	}
}

int conta(float t[], float m) {
	int i, c=0;
	for(i=0; i<max; i++)
		if( t[i]>m )
			c++;
	return c;
}

float media(float t[]) {
	int i;
	float s=0;
	for(i=0; i<max; i++)
		s += t[i];
	return s/max;
}

void main(void) {
	float temp[max], m;
	obtem(temp);
	m = media(temp);
	printf("Estatística: %d", conta(temp,m) );
}
