#include <stdio.h>

int main() {
	
	int A, I, result;
	// A = 앨범에 수록된 곡의 개수, I = 평균값, result = 저작권이 있는 멜로디의 개수
		
	scanf("%d %d", &A, &I);
	result = ((I-1) * A) + 1;
	printf("%d", result); 
	
	return 0;
}