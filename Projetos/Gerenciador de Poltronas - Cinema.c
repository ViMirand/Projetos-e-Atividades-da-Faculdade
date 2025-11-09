#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define COL 12
#define LIN 13

void Menu(int a);
void Venda();
void Configuracoes();
void Opcao();
void Questionario(int a);
void AlteraAssento();

float Valores[2] = {50, 50/2};
char Poltronas[COL][LIN], novo[2];
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

void Msg(){
	int a;
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\tSistema de Gerenciamento de Poltronas"); 
	coloracaoTexto(0, 14); 
	printf(" ARCA DA ALIANCA.\n\n\n\n\n\n\n\n\n\n\n"); 
}

void OcupacaoAssento(char letra, char numero){
	int a, b;
	for(a=1;a<COL-1;a++){
		for(b=1;b<LIN-1;b++){
			if(letra== 75 - a && numero == '0' + b){
				Poltronas[a][b] = 'X';
				livres-=1;
				ocupados+=1;
			}
		}
	}
}
void RemocaoAssento(char letra, char numero){
	int a, b;
	for(a=1;a<COL-1;a++){
		for(b=1;b<LIN-1;b++){
			if(letra== 75 - a && numero == '0' + b){
				if(Poltronas[a][b] != '_' || Poltronas[a][b] != '#' ){
					if(a==10){
						Poltronas[a][b] = '#';
					}else{
						Poltronas[a][b] = '_';	
					}
					livres+=1;
					ocupados-=1;
				}/*else{
					Gotoxy(0,25);
					coloracaoTexto(15,2);
					printf("POLTRONA LIVRE!! escolha outra!");
					system("pause");
					coloracaoTexto(0,15);
					system("cls");
					AlteraAssento();
				}*/
			}/*else{
				Gotoxy(0,25);
				coloracaoTexto(15,12);
				printf("POLTRONA INEXISTENTE!! escolha outra!");
				system("pause");
				coloracaoTexto(0,15);
				system("cls");
				AlteraAssento();
			}*/
		}
	}
}
void NovoAssento(char letra, char numero){
	int a, b, A;
	for(a=1;a<COL-1;a++){
		for(b=1;b<LIN-1;b++){
			if(letra== 75 - a && numero == '0' + b){
				if(Poltronas[a][b] != 'X'){
					Poltronas[a][b] = 'X';
					livres-=1;
					ocupados+=1;
				}/*else{
					Gotoxy(0,25);
					coloracaoTexto(15,12);
					printf("POLTRONA JA OCUPADA!!");
					Questionario(6);
					Gotoxy(18,24);
					for(A=0; A<2;A++){
						scanf(" %c", &novo[A]);
						if(a==0){
							Gotoxy(45, 24);
						}
					}
					NovoAssento(novo[0], novo[1]);
				}*/
			}/*else{
				Gotoxy(0,25);
				coloracaoTexto(15,12);
				printf("POLTRONA INEXISTENTE!! escolha outra!");
				system("pause");
				coloracaoTexto(0,15);
				system("cls");
				AlteraAssento();
			}*/
		}
	}
}

void Entrada(int ingresso){
	if(ingresso == '1'){
		Ingressos[0] +=1;
	}else if(ingresso == '2'){
		Ingressos[1] +=1;
	}
}

void Legenda(){
	int A = 15;
	Gotoxy(50, A-1);
	printf("  LEGENDA DE ASSENTOS");
	Gotoxy(50, A);
	printf("_________________________");
	Gotoxy(50,A +1);
	printf("NORMAL:               ");
	coloracaoTexto(2, 15);
	printf(" _ ");
	Gotoxy(50, A + 2);
	coloracaoTexto(0, 15);
	printf("PRIORIDADE:           ");
	coloracaoTexto(6, 15);
	printf(" # ");
	Gotoxy(50, A + 3);
	coloracaoTexto(0, 15);
	printf("OCUPADO:              ");
	coloracaoTexto(4, 15);
	printf(" O ");
	Gotoxy(50, A + 4);
	coloracaoTexto(0, 15);
	printf("_________________________");
}
void Assentos(int col){
	int a, b;
	printf("\n\t\t    ASSENTOS\nLivres: \t\t\t\t%d\nOcupados: \t\t\t\t%d", livres, ocupados);
	printf("\n\n\t\tTABELA DE POLTRONAS\n\n");
	for(a=0;a<COL-1;a++){
		if(a==0){
			Gotoxy(6, col+a);
		}else{
			Gotoxy(5, col+a);
		}
		for(b=0;b<LIN-1;b++){
			Cor(Poltronas[a][b] == '_', Poltronas[a][b]);
			printf(" %c ", Poltronas[a][b]);
		}
	}
	printf("\n\t*********** TELA *************\n");
}

void Tabela(){
	int a;
	printf("\t\tTABELA DE PRECOS\n\nInteira: \nMeia: ");
	Gotoxy(40, 2);
	for(a=0; a<2;a++){
		printf("%.2f", Valores[a]);
		Gotoxy(40, 3);
	}
	Assentos(12);
}

void Verificacao(){
	int a;
	char assento[2];
	Gotoxy(18,24);
	for(a=0; a<3;a++){
		scanf(" %c", &assento[a]);
		if(a==0){
			Gotoxy(44, 24);
		}else if(a==1){
			Gotoxy(58, 24);
		}
		if(a==2){
			while(assento[a] !='1' && assento[a] !='2'){
				Gotoxy(75, 24);
				coloracaoTexto(12,15);
				printf("OPCAO INVALIDA! TENTE NOVAMENTE!");
				coloracaoTexto(0,15);
				Gotoxy(73, 24);
				scanf(" %c", &assento[a]);
			}
		}
	}
	
	Entrada(assento[2]);
	OcupacaoAssento(assento[0], assento[1]);
}

void EscolhaAssento(){
	Gotoxy(0,24);
	printf("Letra da fileira:\tNumero da poltrona:\tIngresso:    | 1-Inteira\t2-Meia");
	Verificacao();
}

void AlterarPrecos(){
	int a, b;
	coloracaoTexto(0, 15);
	printf("\t\tTABELA DE PRECOS\n\t\t\t\tANTIGOS\tNOVOS\nInteira: \nMeia: ");
	Gotoxy(30, 2);
	for(a=0; a<2;a++){
		printf("%.2f", Valores[a]);
		Gotoxy(30, 3);
	}
	Gotoxy(40, 2);
	scanf("%f", &Valores[0]);
	Valores[1] = Valores[0]/2;
	Gotoxy(40, 3);
	printf("%.2f", Valores[1]);
	Gotoxy(0, 5);
	Questionario(3);
}

void RemoveAssento(){
	int a;
	char assento[2];
	Assentos(7);
	Gotoxy(0,22);
	printf("Letra da fileira:\tNumero da poltrona:");
	Gotoxy(18,22);
	for(a=0; a<2;a++){
		scanf(" %c", &assento[a]);
		if(a==0){
			Gotoxy(45, 22);
		}
	}
	Gotoxy(0,24);
	RemocaoAssento(assento[0], assento[1]);
	Gotoxy(0,0);
	Assentos(7);
	Questionario(4);
}

void AlteraAssento(){
	int a;
	char assento[2];
	Assentos(7);
	Gotoxy(0,21);
	printf("Assento que desejas alterar:");
	Gotoxy(0,22);
	printf("Letra da fileira:\tNumero da poltrona:");
	Gotoxy(0,23);
	printf("Novo Assento:");
	Gotoxy(0,24);
	printf("Letra da fileira:\tNumero da poltrona:");
	Gotoxy(18,22);
	for(a=0; a<2;a++){
		scanf(" %c", &assento[a]);
		if(a==0){
			Gotoxy(45, 22);
		}
	}
	RemocaoAssento(assento[0], assento[1]);
	Gotoxy(18,24);
	for(a=0; a<2;a++){
		scanf(" %c", &novo[a]);
		if(a==0){
			Gotoxy(45, 24);
		}
	}
	NovoAssento(novo[0], novo[1]);
	Gotoxy(0,0);
	Assentos(7);
	Questionario(4);
}

void Questionario(int op){
	switch(op){
		case 1: //Tela de Vendas
			printf("Deseja Continuar?\n0-VOLTAR AO MENU\n1-CONTINUAR VENDA\n2-APRESENTAR RELATORIO DO DIA E FECHAR PROGRAMA");
			Gotoxy(19,26);
			scanf("%d", &opcao);
			if(opcao == 2){
				opcao = 3;
			}
			Opcao(); break;
		case 2: //Configurações
			coloracaoTexto(0,14);
			printf("Desejas: ");
			Gotoxy(50,16);
			printf("0-VOLTAR AO MENU");
			Gotoxy(50,17);
			printf("1-ALTERAR PRECOS");
			Gotoxy(50,18);
			printf("2-REMOVER COMPRA/ASSENTO");
			Gotoxy(50,19);
			printf("3-ALTERAR COMPRA/ASSENTO");
			Gotoxy(50,20);
			printf("4-APRESENTAR RELATORIO DO DIA E FECHAR PROGRAMA");
			Gotoxy(58,15);
			scanf("%d", &opcao);
			if(opcao==0 ||opcao == 4){
				if(opcao == 4) opcao = 3;
				Opcao();
			}
			system("cls"); 
			switch(opcao){
				case 1:AlterarPrecos(); 
					break;
				case 2:RemoveAssento(); 
					break;
				case 3:AlteraAssento(); 
					break;
			}break;
		case 3: //Alterar Preços
			printf("Deseja Continuar?\n0-VOLTAR AO MENU\n1-ALTERAR NOVAMENTE\n2-APRESENTAR RELATORIO DO DIA E FECHAR PROGRAMA");
			Gotoxy(18,5);
			scanf("%d", &opcao);
			if(opcao ==0 )Opcao();
			if(opcao == 1){
				system("cls");
				AlterarPrecos();
			}
			if(opcao == 2){
				opcao = 3;
				Opcao();
			}
			break;
		case 4: //Remover Assentos
			printf("Deseja Continuar?\n0-VOLTAR AO MENU\n1-REMOVER OUTRO ASSENTO\n2-APRESENTAR RELATORIO DO DIA E FECHAR PROGRAMA");
			Gotoxy(18,19);
			scanf("%d", &opcao);
			if(opcao ==0 )Opcao();
			if(opcao == 1){
				system("cls"); 
				RemoveAssento();	
			} 
			if(opcao == 2){
				opcao++;
				Opcao();
			}
			break;
		case 5: //Alterar Assentos
			printf("Deseja Continuar?\n0-VOLTAR AO MENU\n1-ALTERAR OUTRO ASSENTO\n2-APRESENTAR RELATORIO DO DIA E FECHAR PROGRAMA");
			Gotoxy(18,19);
			scanf("%d", &opcao);
			if(opcao == 0 )Opcao();
			if(opcao == 1){
				system("cls"); 
				AlteraAssento();	
			} 
			if(opcao == 2){
				opcao = 3;
				system("cls"); 
				Opcao();
			}
			break;
		/*case 6: //Alterar Assentos
			printf("0-VOLTAR AS CONFIGURACOES\n1-TENTAR NOVAMENTE");
			Gotoxy(18,19);
			scanf("%d", &opcao);
			if(opcao == 0 )Configuracoes();
			break;*/
	}
}

void Configuracoes(){
	system("cls");
	Tabela();
	Gotoxy(50,15);
	Questionario(2);
}

void Venda(){
	char assento[3];
	int a;
	coloracaoTexto(0, 15);
	Tabela(); // Mostra a Tabela de Preços + matriz das poltronas.
	coloracaoTexto(0, 15);
	Legenda();
	EscolhaAssento();
	system("cls");
	Tabela();
	Gotoxy(0,26);
	Questionario(1);
}

void Fechamento(){
	Gotoxy(0,0);
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

void Opcao(){
	system("cls");
	switch (opcao){
		case 0: Menu(0); break;
		case 1: Venda(); break;
		case 2: Configuracoes(); break;
		case 3: Fechamento(); break;
		default: printf("OPCAO INVALIDA! TENTE NOVAMENTE!"); system("pause"); Menu(0); break;
	}
}

void Menu(int a){
	system("cls");
	Gotoxy(20+a, 0);
	coloracaoTexto(0,14);
	printf("\t\tM E N U");
	Gotoxy(20+a, 2);
	printf("|OPCAO|\tIR PARA:\t\t|");
	Gotoxy(20+a, 3);
	printf("| 0\t |\tMENU DE OPCOES   \t|");
	Gotoxy(20+a, 4);
	printf("| 1\t |\tTELA DE VENDAS   \t|");
	Gotoxy(20+a, 5);
	printf("| 2\t |\tCONFIGURACOES    \t|");
	Gotoxy(20+a, 6);
	printf("| 3\t |\tRELATORIO DO DIA \t|");
	Gotoxy(20+a, 7);
	printf("Opcao: ");
	Gotoxy(27+a, 7);
	scanf("%d", &opcao);
	system("pause");
	system("cls");
	Opcao();
}

int main(){
	Start(); // Inicia as poltronas zeradas.
	Msg();  // Dá as boas vindas ao sistema.
	coloracaoTexto(0,15);
	system("pause");
	system("cls");
	Menu(0);
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
