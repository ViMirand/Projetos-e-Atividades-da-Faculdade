/*4) Codifique um programa que faça a leitura de dois número reais. 

A seguir o programa lê um caractere, que deve ser
+, -, * ou /, e realiza a operação indicada pelo caractere sobre os valores lidos.


• O programa deve imprimir o resultado da operação realizada sobre eles, como mostra o exemplo a seguir (exibindo
exatamente duas casas decimais). Como o exemplo a seguir.
• Resultado: 4.50 + 5.00 = 9.50*/

#include<stdio.h>
int main(){
	float N1, N2;
	int op;
	printf("*Questao 4 - Calculadora simples*\nDigite os dois valores que voce deseja calcular\n\tValor 1:");
	scanf("%f", &N1);
	printf("\n\tValor 2: ");
	scanf("%f", &N2);
	printf("\nAgora, escolha a operacao:\n\t1 -> ADICAO\n\t2 -> SUBTRACAO\n\t3 -> MULTIPLICACAO\n\t4 -> DIVISAO\n\t");
	scanf("%d", &op);
	
	switch(op){
		case 1:
			printf("\nOperacao escolhida: ADICAO\nRESULTADO: %.2f + %.2f = %.2f", N1, N2, N1+N2);break;
		case 2:
			printf("\nOperacao escolhida: SUBTRACAO\nRESULTADO: %.2f - %.2f = %.2f", N1, N2, N1-N2);break;
		case 3:
			printf("\nOperacao escolhida: MULTIPLICACAO\nRESULTADO: %.2f x %.2f = %.2f", N1, N2, N1*N2);break;
		case 4:
			if(N2 == 0 || N1 == 0){
				printf("\nOperacao escolhida: DIVISAO\nRESULTADO: DIVISAO INVIAVEL. HA ZERO EM UM DOS FATORES!!!");
			}else
				printf("\nOperacao escolhida: DIVISAO\nRESULTADO: %.2f / %.2f = %.2f", N1, N2, N1/N2);break;
		default:
			printf("\nOpcao indisponivel!");
	}
	return 10;
}
