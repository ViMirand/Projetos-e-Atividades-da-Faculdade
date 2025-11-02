/*
Exercício 5.10. Codifique a função histograma(t), que exibe um histograma

da variação da temperatura durante a semana. Por exemplo, se as tempera-
turas em t forem 19, 21, 25, 22, 20, 17 e 15°C, a função deverá exibir:

D: ___________________
S: _____________________
T: _________________________
Q: ______________________
Q: ____________________
S: _________________
S: _______________
*/


#include<stdio.h>
#include<windows.h>
#define TAM 7

void textcolor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
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
			case 0: printf("\nD: ");break;
			case 1: printf("\nS: ");break;
			case 2: printf("\nT: ");break;
			case 3: printf("\nQ: ");break;
			case 4: printf("\nQ: ");break;
			case 5: printf("\nS: ");break;
			case 6: printf("\nS: ");break;
			default: printf("\nUm dia inventado!");break;
		}
		for(j=1;j<=Temp[i]; j++){
			textcolor(2); //2 - cor verde!
			printf("%c", 219);
		}
	}
}

int main(){
	histograma();
	return 10;
}

/*
  TABELA DE CORES
Cor				Valor
Preto			0
Azul			1
Verde			2
Ciano			3
Vermelho		4
Roxo			5
Amarelo			6
Cinza claro		7

*/
