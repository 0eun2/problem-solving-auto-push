#include <stdio.h>

void f (int , int );

int main() {
	
	int num1, num2;
	
	while(1){
		scanf("%d %d", &num1, &num2);
		if(num1 == 0 && num2 == 0)
			break;
		f(num1, num2);
	}

	return 0;
}

void f(int n1, int n2){
	
	if(n1 > n2)
		printf("Yes\n");
	else
		printf("No\n");
	
}