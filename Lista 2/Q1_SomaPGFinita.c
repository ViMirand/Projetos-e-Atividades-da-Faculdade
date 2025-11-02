#include<stdio.h>
#include<math.h>

int main(){
	int Sn, a1, q, n;
	printf("*Questao 1*\nDigite o valor do termo inicial, da razao e o numero de termos.\n");
	scanf("%d%d%d", &a1,&q,&n);
	if(q!=1){
		Sn=a1*(pow(q,n)-1)/(q-1);
	}else{
		Sn=a1*n;
	}
	printf("A soma dos termos dessa PG finita e: %d", Sn);
	return 0;
}
