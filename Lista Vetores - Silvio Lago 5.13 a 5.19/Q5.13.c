/*
Exercício 5.13. Codifique a função strcpy(s,t), que copia o conteúdo da
string t para a string s. Essa função é útil quando precisamos realizar
atribuição entre strings; por exemplo, para atribuir a constante "teste" a uma
string x, basta escrever strcpy(x,"teste").
*/

#include<stdio.h>
#include<string.h>
char Strcpy(char Vet1[10], char Vet2[10]){
	char count=0, a=0;
	do{
		printf("count %d\na: %d", count, a);
		count++;
		a++;
	}while(Vet1[a] != ' ');
	for(a=0; a<count; a++){
		printf("count %d\na: %d", count, a);
		Vet2[a]=Vet1[a];
	}
	a=count;
	while(Vet1[a] != ' '){
		printf("count %d\na: %d", count, a);
		Vet2[a]=' ';
		a++;
	}
	
	return Vet2[20];
}
int main(){
	char T[10], S[10];
	int resp;
	printf("Digite seu nome: ");
	gets(T);
	printf("\nAgora, digite seu apelido: ");
	gets(S);
	printf("Tu preferes ser chamado como:\n1-Nome\t2-Apelido\n");
	scanf("%d", &resp);
	switch(resp){
		default: printf("Opcao invalida!");break;
		case 1: printf("Nesse caso: Ola, %s.\n\n\n\t\tTROLADO COM SUCESSO!", Strcpy(T,S));break;
		case 2: printf("Nesse caso: Ola, %s.\n\n\nTROLADO COM SUCESSO!", Strcpy(S,T));break;
	}
	return 10;
}
