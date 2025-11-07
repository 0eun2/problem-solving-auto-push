#include <stdio.h>

int main() {
	
	int a[6] = {0}, i;
	
	for(i=0; i<5; i++){
		scanf("%d", &a[i]);
		a[5] += a[i]*a[i];
	}
	printf("%d", a[5]%10);
	return 0;
}