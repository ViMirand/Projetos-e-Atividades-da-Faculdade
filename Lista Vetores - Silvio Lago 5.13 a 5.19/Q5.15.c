/*
Exercício 5.15. Codifique a função strupr(s), que converte a string s em
maiúscula. Por exemplo, se x armazena "Teste", após a chamada strupr(x), x
estará armazenando "TESTE".
*/

#include<stdio.h>
#include<string.h>

int main(){
	char S[10];
	printf("Digite seu ultimo nome todo em letra minuscula: ");
	gets(S);
	printf("Gritando seu nome: %s!!!!!", strupr(S));
	return 10;
}
