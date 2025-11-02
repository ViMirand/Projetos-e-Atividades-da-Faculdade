#include<stdio.h>
#include<stdlib.h>

void Gotoxy(int x, int y){
	
}

float Msg(int op){
	float VLR[2];
	int a;
	switch (op){
		case 1: 
			printf("Ola, seja bem vindo ao Sistema de Gerenciamento de Poltronas MT CINEMAS.\n\nPreencha a tabela com os valores de Entrada.\nInteira:\nMeia:");
			for(a=0; a<2;a++){
				scanf("%f", &VLR[a]);
			}

	}
}

int main(){
	Msg(1);
	system("pause");
	system("cls");
	return 10;
}
