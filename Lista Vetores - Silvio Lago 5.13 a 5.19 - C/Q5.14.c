/*
Exercício 5.14. Codifique a função strlen(s), que devolve o número de carac-
teres armazenados na string s. Lembre-se de que o terminador '\0' não faz

parte da string e, portanto, não deve ser contado.
*/
#include<stdio.h>
#include<string.h>

int main(){
	char S[10];
	int lenght;
	printf("Digite seu primeiro nome: ");
	gets(S);
	lenght = strlen(S);
	printf("Seu nome possui %d letras.", lenght);
	return 10;
}
