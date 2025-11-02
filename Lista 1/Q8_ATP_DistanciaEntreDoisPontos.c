#include<stdio.h>
#include<math.h>

int main(){
	float d, x1, x2, y1, y2;
	printf("*Questao 8*\nDigite as coordenadas do ponto 1:\n");
	scanf("%f%f", &x1, &y1);
	printf("\nAgora, Digite as coordenadas do ponto 2:\n");
	scanf("%f%f", &x2, &y2);
	d=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	printf("\nA distancia entre esses dois pontos e: %.1f", d);
	return 0;
}
