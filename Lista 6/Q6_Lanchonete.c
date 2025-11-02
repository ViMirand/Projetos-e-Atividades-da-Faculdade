/*
6) Faça um programa para simular um sistema de lanchonete, onde conterá um Menu 
mostrando os códigos, nomes e preço de 5 produtos. Permita que o usuário escolha 
até dois produtos, bem como a quantidade dos mesmos. O Menu possuirá 7 itens ao 
todo, onde os cinco primeiros serão destinados as informações dos produtos, o 
sexto será chamado pedido do cliente e o sétimo para sair do sistema. 
O pedido do cliente deve conter o nome do cliente, o código, o preço e quantidade
solicitada para até dois produtos, subtotal de cada produto, e por fim, o total
do pedido. 
(Obs. Usar apenas as estruturas até agora estudadas)
*/

#include<stdio.h>

int main(){
	char nome[50];
	printf("*QUESTAO 6 - Sistema de Lanchonete*\nDigite seu nome, por favor: ");
	scanf("%c", &nome);
	menu();
	escolha();
	printf("Cliente: %c", nome);
	return 10;
}
int oque(int P){
	int Valor;
	switch(P){
		case 1:
			Valor = 7;break;
		case 2:
			Valor = 10;break;
		case 3:
			Valor = 5;break;
		case 4:
			Valor = 8;break;
		case 5:
			Valor = 13;break;
		default:
			printf(" - Opcao invalida!");
	}
	return Valor;
}
int escolha(){
	int a1=1, a, P, Q, soma=0;
	printf("\nQuantos produtos ira escolher? OBS: SO PODE ESCOLHER ATE 2!\n");
	scanf("%d", &a);
	do{
		printf("\nO que voce vai escolher?\n ");
		scanf("%d", &P);
		printf("\nQuantidade: ");
		scanf("%d", &Q);
		soma = (oque(P)*Q) + soma;
		a1+=1;
	}while(a1<=a);
	a1=1;
	printf("\n\t*PEDIDO\n\nCOD|\tPRODUTOS \t\tPRECO\t\t| QTD\t| SUBTOTAL");
	do{
		switch(P){
			case 1:
				printf("\n 1 |\tX-salada \t\tRS 7,00\t\t|%d\t|%d,00", Q, Q*7);break;
			case 2:
				printf("\n 2 |\tX-caboquinho \t\tRS 10,00\t|%d\t|%d,00", Q, Q*10);break;
			case 3:
				printf("\n 3 |\tMini-pizza \t\tRS 5,00\t\t|%d\t|%d,00", Q, Q*5);break;
			case 4:
				printf("\n 4 |\tBolo de chocolate \tRS 8,00\t\t|%d\t|%d,00", Q, Q*8);break;
			case 5:
				printf("\n 5 |\tKikao \t\t\tRS 13,00\t|%d\t|%d,00", Q, Q*13);break;
			default:
				printf("\n");
		}
		a1+=1;
	}while(a1<a);
	printf("\n\n\t\t\t\t\t\t\tTOTAL: %d,00\n", soma);
	return 10;
}
int menu(){
	printf("\n\t\tMENU\n\nCOD|\tPRODUTOS \t\tPRECO\n 1 |\tX-salada \t\tRS 7,00\n 2 |\tX-caboquinho \t\tRS 10,00\n 3 |\tMini-pizza \t\tRS 5,00\n 4 |\tBolo de chocolate \tRS 8,00\n 5 |\tKikao \t\t\tRS 13,00\n");
	return 10;
}
