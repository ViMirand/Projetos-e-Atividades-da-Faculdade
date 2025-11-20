#include<stdio.h>

int main(){
	float A, B, C;
	printf("Questao 2 - Triangulos*\nDigite os tres lado do triangulo: ");
	scanf("%f%f%f", &A, &B, &C);
	if(A<B+C && B<A+C && C<A+B){
		if(A==B && B==C){
			printf("Triangulo equilatero!");
		}else if(A==B || B==C || A==C){
			printf("Triangulo isosceles!");
		}else
			printf("Triangulo escaleno!");
	}else{
		printf("A figura nao define uma triangulo.");
	}
	return 10;
}
