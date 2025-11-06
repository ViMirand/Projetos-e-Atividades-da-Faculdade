#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define COL 12
#define LIN 13
float Valores[2];
char Poltronas[COL][LIN];
int ocupados=0, livres=10*10, Ingressos[2], opcao;

void coloracaoTexto(int X, int Z){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, X * 16 + Z); 
// Z e X definem a cor da letra, mas quando X é multiplicado por 16, expande o fundo para preencher todo o byte, ou seja, coloca o X nos bits mais altos.
// Sendo assim: X para a Cor do fundo e Z para a Cor da Letra.
}
int Comp(char op){
	int comp=0, a;
	for(a=0;a<COL-1;a++){
		if((op=='A'+ a)||(op=='1'+ a)){
			comp = 1;
		}else if(op=='#'){
			comp = 2;
		}
	}
	return (comp);
}

void Cor(int op, char poltrona){
	int comp;
	comp = Comp(poltrona);
	if (comp == 1){
		op = 2;
	}else if( comp == 2){
		op = 3;
	}
	switch (op){
		case 0:
			coloracaoTexto(4,15);break;
		case 1:
			coloracaoTexto(2,15);break;
		case 2:
			coloracaoTexto(0,15);break;
		case 3:
			coloracaoTexto(6,15);break;
	}
}

void Start(){	
	int a, b;
	for(a=1;a<COL-1;a++){
		for(b=0;b<LIN-1;b++){
			Poltronas[a][b] = '_';
			Poltronas[0][a] = '0' + a;
			Poltronas[a][0] = 75 - a;
			Poltronas[a][11] = 75 - a;
			if(a==10 && b<11){
				Poltronas[a][b] = '#';
			}
		}
	}
	for(a=0;a<2;a++){
		Ingressos[a]=0;
	}
}

void Gotoxy(int x, int y) {
    COORD coord = {x, y};  // Define coordenadas X e Y
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Editar(){
	
}

void Verificacao(){
	switch (opcao){
		case 1:
			system("cls");
			Msg(2); // Pede os valores dos ingressos.
			coloracaoTexto(0,15);
			system("pause");
			system("cls");
			Venda();break;
		case 2:
			Editar();
	}
}

void Msg(int op){
	int a;
	switch (op){
		case 1:
			printf("\n\n\n\n\n\n\n\n\n\n\t\t\tSistema de Gerenciamento de Poltronas"); 
			coloracaoTexto(0, 14); 
			printf(" ARCA DA ALIANCA.\n\n\n\n\n\n\n\n\n\n\n"); break;
		case 2:
			printf("Preencha a tabela com o valor do Ingresso.\nInteiro:\nMeia:");
			Gotoxy(9, 1);
			scanf("%f", &Valores[0]);
<<<<<<< HEAD
			Valores[1] = (int)Valores[0] / 2;
=======
			Valores[1] = Valores[0]/2;
>>>>>>> fc0ce6b5d11c88a713f70601635b275375657091
			Gotoxy(6, 2);
			printf("%.2f\n"); 
			system("pause"); break;
		case 3:
			printf("\t\tMENU DE OPCOES\n\n1 - Visualizar sala\n2 - Editar Assentos\n\n\n");
			scanf("%d", &opcao);
	}
}

void OcupacaoAssento(char letra, char numero){
	int a, b;
	for(a=1;a<COL-1;a++){
		for(b=1;b<LIN-1;b++){
			if(letra== 75 - a && numero == '0' + b){
				Poltronas[a][b] = 'O';
				livres-=1;
				ocupados+=1;
			}
		}
	}
}

void Tabela(){
	int a, b;
	printf("\t\tTABELA DE PRECOS\n\nInteira: \nMeia: ");
	Gotoxy(40, 3);
	for(a=0; a<2;a++){
		printf("%.2f", Valores[a]);
		Gotoxy(40, 4);
	}
	printf("\n\t\t    ASSENTOS\nLivres: \t\t\t\t%d\nOcupados: \t\t\t\t%d", livres, ocupados);
	printf("\n\n\t\tTABELA DE LUGARES\n\n");
	for(a=0;a<COL-1;a++){
		Gotoxy(5, 12+a);
		for(b=0;b<LIN-1;b++){
			Cor(Poltronas[a][b] == '_', Poltronas[a][b]);
			printf(" %c ", Poltronas[a][b]);
		}
	}
	printf("\n\t*********** TELA *************\n");
}
void Entrada(int ingresso){
	if(ingresso == '1'){
		Ingressos[1] +=1;
	}else if(ingresso == '2'){
		Ingressos[0] +=1;
	}
}

void Legenda(){
	int A = 15;
	Gotoxy(50, A-1);
	printf("    LEGENDA DE ASENTOS");
	Gotoxy(50, A);
	printf("_______________________");
	Gotoxy(50,A +1);
	printf("NORMAL: ");
	coloracaoTexto(2, 15);
	printf(" _ ");
	Gotoxy(50, A + 2);
	coloracaoTexto(0, 15);
	printf("PRIORIDADE: ");
	coloracaoTexto(6, 15);
	printf(" # ");
	Gotoxy(50, A + 3);
	coloracaoTexto(0, 15);
	printf("OCUPADO: ");
	coloracaoTexto(4, 15);
	printf(" O ");
	Gotoxy(50, A + 4);
	coloracaoTexto(0, 15);
	printf("________________________");
}

<<<<<<< HEAD
void Opcao(){
	int a;
	switch (opcao){
		case 0:
=======
void Venda(){
	char assento[3];
	int a, b=1, soma;
	do{
		soma=0;
		coloracaoTexto(12,0);
		printf("*PARA FECHAR O PROGRAMA, DIGITE 0! PARA EXCLUIR UMA ENTRADA DIGITE 1*\n");
		coloracaoTexto(0, 15);
		Tabela(); // Mostra a Tabela de Preços + matriz das poltronas.
		coloracaoTexto(0, 15);
		printf("continuar?");
		Legenda();
		Gotoxy(10,24);
		scanf("%d", &b);
		if(b!=0){
>>>>>>> fc0ce6b5d11c88a713f70601635b275375657091
			Gotoxy(0, 27);
			printf("Letra da fileira: \t\tNumero do assento: \t\tEntrada: \n\t\t\t\t\t\t\t\t\t1-Meia\t2-Inteira");
			Gotoxy(17, 27);
			for(a=0; a<3;a++){
				scanf(" %c", &assento[a]);
				if(a==0){
					Gotoxy(50, 27);
				}else if(a==1){
					Gotoxy(73, 27);
				}
				if(a==2){
					while(assento[a] !='1' && assento[a] !='2'){
						Gotoxy(75, 27);
						coloracaoTexto(12,15);
						printf("OPCAO INVALIDA! DIGITE NOVAMENTE!");
						coloracaoTexto(0,15);
						Gotoxy(73, 27);
						scanf(" %c", &assento[a]);
					}
				}
			}
			Entrada(assento[2]);
			OcupacaoAssento(assento[0], assento[1]); break;
		case 1:
			Tabela();
			
	}
}

void Venda(){
	char assento[3];
	int a, opcao, soma;
	do{
		soma=0;
		coloracaoTexto(12,0);
		printf("* PARA FECHAR O PROGRAMA, DIGITE 0! ");
		coloracaoTexto(0,15);
		printf("PARA VOLTAR AO MENU DE OPCOES, DIGITE 1 !");
		coloracaoTexto(0,12);
		printf("PARA VOLTAR AO MENU DE OPCOES, DIGITE 2 ! *\n");
		coloracaoTexto(0, 15);
		Tabela(); // Mostra a Tabela de Preços + matriz das poltronas.
		coloracaoTexto(0, 15);
		printf("continuar?");
		Legenda();
		Gotoxy(10,24);
		scanf("%d", &opcao);
		Opcao();
		Gotoxy(0, 29);
		system("cls");
	}while(b!=0);
}

void Fechamento(){
	coloracaoTexto(15,4);
	printf(" FECHAMENTO DO DIA \t\t\t TABELA DE PRECOS ");
	coloracaoTexto(0,15);
	printf("\n\nRECEITA\nIngresso inteiro: %.2f - %d un.\nMeia-Entrada: %.2f - %d un.\n\nTOTAL: %.2f\n", Ingressos[0]*Valores[0], Ingressos[0], Ingressos[1]*Valores[1], Ingressos[1], Ingressos[0]*Valores[0] + Ingressos[1]*Valores[1] );
	Gotoxy(40,2);
	printf("VALORES");
	Gotoxy(40,3);
	printf("Ingresso inteiro: %.2f", Valores[0]);
	Gotoxy(40,4);
	printf("Meia-Entrada: %.2f", Valores[1]);
	Gotoxy(0, 9);
	
}

int main(){
	Start(); // Inicia as poltronas zeradas.
	Msg(1);  // D? as boas vindas ao sistema.
	coloracaoTexto(0,15);
	system("pause");
	system("cls");
	Msg(3);
	Verificacao();
	system("pause");
	system("cls");
	coloracaoTexto(0,15);
	Fechamento();
	system("pause");
	return 10;
}
/*
| Código | Cor do texto         |
| :----: | :------------------- |
|    0   | Preto                |
|    1   | Azul escuro          |
|    2   | Verde escuro         |
|    3   | Ciano escuro         |
|    4   | Vermelho escuro      |
|    5   | Roxo escuro          |
|    6   | Amarelo escuro       |
|    7   | Cinza claro (padrão) |
|    8   | Cinza escuro         |
|    9   | Azul claro           |
|   10   | Verde claro          |
|   11   | Ciano claro          |
|   12   | Vermelho claro       |
|   13   | Rosa                 |
|   14   | Amarelo              |
|   15   | Branco brilhante     |

*/