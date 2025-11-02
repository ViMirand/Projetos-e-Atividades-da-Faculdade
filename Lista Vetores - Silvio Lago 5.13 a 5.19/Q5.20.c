/*
Exercício 5.12. Altere a rotina histograma() de modo que as linhas do grá-
fico sejam verticais. Além disso, faça com que as linhas que representam

temperaturas iguais à média apareçam na cor verde, aquelas corresponden-
tes a temperaturas abaixo da média em azul e aquelas acima da média, em

vermelho. [Dica: use as funções gotoxy() e textcolor(), definidas em conio.h]
*/

#include<stdio.h>
#include<windows.h>
#define TAM 2

void gotoxy(int x, int y) {
    COORD coord = {x, y};  // Define coordenadas X e Y
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void histograma(){
	float Temp[TAM];
	int i, j;
	printf("Digite as temperaturas:");
	for(i=0; i<TAM;i++){
		printf("\nDia %d: ", i+1);
		scanf("%f", &Temp[i]);
	}
	for(i=0;i<TAM;i++){
		switch (i){
			case 0: printf("\tD: ");break;
			case 1: printf("\tS: ");break;
			case 2: printf("\tT: ");break;
			case 3: printf("\tQ: ");break;
			case 4: printf("\tQ: ");break;
			case 5: printf("\tS: ");break;
			case 6: printf("\tS: ");break;
			default: printf("\tUm dia inventado!");break;
		}
		for(j=1;j<=Temp[i]; j++){
			gotoxy(i+3,j);
			printf("%c", 219);
		}
	}
}

int main(){
	histograma();
	return 10;
}
