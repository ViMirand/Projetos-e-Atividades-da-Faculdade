#include<stdio.h>
#include<math.h>

int main(){
	float x, y, z;
	printf("*QUestao 8*\nDigite o valor de x: ");
	scanf("%f", &x);
	if(x>2 || x<-2){
		y = pow(x,2)-1;
		z = x*2;
	}else{
		y = x/0.5;
		z = x;
	}
	printf("Os valores de x, y e z, sao respectivamente: %.2f, %.2f e %.2f", x, y, z);
	return 0;
}
