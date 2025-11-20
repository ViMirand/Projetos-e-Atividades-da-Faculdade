#include<stdio.h>

int main(){
	int a, b, c, maior, menor, meio = 0;
	printf("Questao 3 - Ordem crescente*\nDigite os tres valores:\n");
	scanf("%d%d%d", &a, &b, &c);
	maior = a;
	menor = c;
	//b
	if( b>maior ){
		if( b>menor ){
			if( maior>menor ){
				maior = b;
				meio = a;
				menor = c;
			}else{
				maior = b;
				meio = c;
				menor = a;
			}
		}else{
			maior = c;
			meio = b;
			menor = a;
		}
	}else if( b>menor ){
			if( maior>menor ){
				maior = a;
				meio = b;
				menor = c;
			}
		}else if( maior>menor ){
				maior = a;
				meio = c;
				menor = b;
			}else{
				maior = c;
				meio = a;
				menor = b;
			}
	printf("A ordem crescente e: %d, %d e %d", menor, meio, maior);
	return 0;
}
