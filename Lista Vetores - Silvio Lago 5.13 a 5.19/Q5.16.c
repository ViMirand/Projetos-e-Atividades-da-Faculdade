/*
Exercício 5.16. Codifique a função strcat(s,t), que concatena a string t ao
final da string s. Por exemplo, se x armazena "facil" e y armazena "idade",
após a chamada strcat(x,y), x estará armazenando "facilidade".
*/
#include<stdio.h>
#include<string.h>
char Strcat( char V1[10], char V2[10]){
	int c1=0, c2=0, aux;
	char V3[22];
	for(aux=0; aux<10; aux++){
		if(V1[aux]!=' '){
			c1++;
		}
		if(V2[aux]!=' '){
			c2++;
		}
	}
	printf("C1(%d) + C2(%d) = %d", c1, c2, c1+c2);
	for(aux=0; aux<c1; aux++){
		V3[aux]=V1[aux];
	}
	for(aux=c1; aux<c1+c2; aux++){
		V3[aux]=V2[aux];
	}
	return V3[];
}
int main(){
	char T[10], S[10];
	printf("Digite seu primeiro nome: ");
	gets(T);
	printf("\nAgora, digite seu ultimo nome: ");
	gets(S);
	printf("Seu nome de usuario sera: %s", Strcat(T,S));
	return 10;
}
