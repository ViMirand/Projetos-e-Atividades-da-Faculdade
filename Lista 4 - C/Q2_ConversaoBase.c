#include<stdio.h>
#include<conio.h>

int main(){
	int E, a;
	printf("\n*Questao 2 - CONVERSAO DE BASE*\nEscolha uma opcao para conversao:\n1-Decimal para hexadecimal\n2-Hexadecimal para decimal\n3-Decimal para octal\n4-Octal para Decimal\n0-sair do programa\n");
	scanf("%d", &E);
	switch (E){
		case 0:
			return 0;break;
		case 1:
			printf("digite o valor: ");
			scanf("%d", &a);
			printf("%d -> %x", a, a);break;
		case 2:
			printf("digite o valor: ");
			scanf("%x", &a);
			printf("%x -> %d", a, a);break;
		case 3:
			printf("digite o valor: ");
			scanf("%d", &a);
			printf("%d -> %o", a, a);break;
		case 4:
			printf("digite o valor: ");
			scanf("%o", &a);
			printf("%o -> %d", a, a);break;
		default:
			printf("Opcao nao reconhecida");break;
	}
	return 0;
}
