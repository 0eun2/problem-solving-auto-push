#include <stdio.h>

int Factorial (int );

int main(){
	
	int n;
	
	scanf("%d", &n);
	printf("%d", Factorial(n));
	
	return 0;
}

int Factorial (int num){
	
	if(num == 0)
		return 1;
	else
		return num * Factorial (num-1);
}