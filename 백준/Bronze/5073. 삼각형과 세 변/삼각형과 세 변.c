#include <stdio.h>

int main() {
	
	int a=1;
	int b=1;
	int c=1;
	
	while(1){
		scanf("%d %d %d", &a, &b, &c);
		if((a==0) && (b==0) && (c==0)){
			break;
		}
		else if((a+b<=c) || (a+c<=b) || (b+c<=a)){
			printf("Invalid\n");
		}
		else if((a==b) && (b==c)){
			printf("Equilateral\n");
		}
		else if((a!=b) && (b!=c) && (a!=c)){
			printf("Scalene\n");
		}
		else if( ((a!=b) && (b==c)) || ((a==b) && (b!=c)) || ((a==c) && (a!=b))){
			printf("Isosceles\n");
		}
	}
	
	return 0;
}