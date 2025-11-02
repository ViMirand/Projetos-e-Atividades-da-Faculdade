/*
Exercício 5.17. Codifique a função strpos(s,c), que devolve a posição da pri-
meira ocorrência do caracter c na string s; ou -1, caso ele não ocorra em s.
*/

#include<stdio.h>
#include<string.h>

int Strpos(char S[10], char C){
	int position=0, a=-1, count=0;
	do{
		count++;
		a++;
	}while(S[a] !=' ');
	for(a=0;a<count;a++){
		if((S[a] == C)&&(position==0))
			position=a+1;
	}
	if(position == 0)
		position--;
	return position;
}

int main(){
	char S[10], C;
	printf("Digite seu primeiro nome: ");
	gets(S);
	printf("Agora digite o caracter que deseja encontar a posicao: ");
	scanf("%c", &C);
	if(Strpos(S, C) == -1){
		printf("Nao ha esse caracter no seu nome!");
	}else{
		printf("A letra %c aparece em seu nome na posicao %d", C, Strpos(S,C));		
	}
	return 10;
}

