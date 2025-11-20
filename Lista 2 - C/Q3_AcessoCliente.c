#include<stdio.h>

int main(){
	int c, s, Cartao, Senha;
	Cartao = 75986;
	Senha = 1232796;
	printf("*Questao 3*\nDigite:\nSenha:");
	scanf("%d", &s);
	printf("Cartao:");
	scanf("%d", &c);
	if(Senha == s && Cartao == c){
		printf("\nAcesso Autorizado!");
	}else{
		printf("\nAcesso Negado!");
	}
	return 0;
}
