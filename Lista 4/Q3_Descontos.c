#include<stdio.h>
/*3) Uma loja fornece 15% de desconto para funcionários, 10% de desconto para clientes vips e 2% para os demais
clientes. Faça um programa que calcule o valor total a ser pago por um cliente. 

O programa deverá ler o valor total da
compra efetuada e um código que identifique se o comprador é um cliente comum (1), funcionário (2) ou vip (3).*/

int main(){
	float  VT;
	int cod;
	printf("*Questao 3 - DESCONTOS*\nDigite o valor da compra: ");
	scanf("%f", &VT);
	printf("\nAgora, digite o codigo de identificacao:\n1-CLIENTE COMUM\n2-FUNCIONARIO\n3-VIP\n");
	scanf("%d", &cod);
	switch(cod){
		case 1:
			VT = VT * 0.98;
			printf("O valor total a ser pago e: %.2f", VT);break;
		case 2:
			VT = VT * 0.85;
			printf("O valor total a ser pago e: %.2f", VT);break;
		case 3:
			VT = VT * 0.90;
			printf("O valor total a ser pago e: %.2f", VT);break;
		default:
			printf("\nVoce pode ter colocado o codigo errado, tente novamente\n");
			main();
	}
	return 0;
}
