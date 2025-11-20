#include<stdio.h>
#include<math.h>

int main(){
	float Peso, Imc, Alt;
	printf("*Questao 8 - IMC*\nDigite seu peso e altura:\n");
	scanf("%f%f", &Peso, &Alt);
	Imc=Peso/pow(Alt, 2);
	if(Imc>=18.5){
		if(Imc<=24.9){
			printf("\nClassificacao quanto a obesidade: NORMAL\nRisco de Co-morbidade: BAIXO");
		}else if(Imc<=29.9){
			printf("\nClassificacao quanto a obesidade: SOBREPESO\nRisco de Co-morbidade: POUCO AUMENTADO");
		}else if(Imc<=34.9){
			printf("\nClassificacao quanto a obesidade: OBESO CLASSE I\nRisco de Co-morbidade: MODERADO");
		}else if(Imc<=39.9){
			printf("\nClassificacao quanto a obesidade: OBESO CLASSE II\nRisco de Co-morbidade: GRAVE");
		}else{
			printf("\nClassificacao quanto a obesidade: OBESO CLASSE III\nRisco de Co-morbidade: MUITO GRAVE");
		}
	}else{
		printf("Acredito que voce tenha colocado algum valor errado!");
	}
	return 100;
}
