#include <stdio.h>

int han(int );

int main(void){
	
	int n, i, sum=0;
	
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		sum += han(i);
	}
	printf("%d", sum);
	
	return 0;
}

int han(int x){
	
	int x1, x2, x3;
	
	x1 = x/100;
	x2 = (x%100)/10;
	x3 = x%10;
	
	if(x1==0)
		return 1;
	else if((x2-x1) == (x3-x2))
		return 1;
	else
		return 0;
}