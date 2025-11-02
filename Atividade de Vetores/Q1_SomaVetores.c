 #include<stdio.h>
int tam = 5;
int main(){
	int vet[tam], vet2[tam], a;
	printf("Preencha os vetores:\nVETOR 1:\n");
	for(a=0; a<tam; a++){
		scanf("%d", &vet[a]);
	}
	printf("\nVETOR 2:\n");
	for(a=0; a<tam; a++){
		scanf("%d", &vet2[a]);
	}
	printf("A soma dos vetores:\nVETOR 1\t\tVETOR 2\t\tVETOR SOMA");
	for(a=0; a<tam; a++){
		printf("\n%d\t\t%d\t\t%d", vet[a], vet2[a], vet[a]+vet2[a]);
	}
	return 10;
}
