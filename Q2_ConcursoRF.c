 #include<stdio.h>

int Tam = 2;

int main(){
	int Candidato[Tam][2], a, b;
	printf("Digite, nesta ordem, a MATRICULA e a MEDIA do ");
	for(a=0; a<Tam; a++){
		printf("Candidato %d: \n", a+1);
		for(b=0; b<2; b++){
			scanf("%d", &Candidato[a][b]);
		}
	}
	printf("\n\nPONTUACAO CONCURSO RECEITA FEDERAL\nCANDIDATO\tMEDIA\t\tSITUACAO\n");
	for(a=0; a<Tam; a++){
			printf("%d", Candidato[a][0]);
			if(Candidato[a][1]>=50){
		 	printf("\t\t%d\t\tAPROVADO!", Candidato[a][1]);
			}else{
		 	printf("\t\t%d\t\tREPROVADO!", Candidato[a][1]);	
			}
			printf("\n");
	}
	return 10;
}
