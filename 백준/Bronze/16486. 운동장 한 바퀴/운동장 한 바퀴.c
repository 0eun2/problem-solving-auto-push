#include <stdio.h>

int main() {
	
	int d1, d2;
	const double pi = 3.141592;
	double result;
	
	scanf("%d", &d1);
	scanf("%d", &d2);
	result = (2*d1) + (2 * d2 * pi);
	printf("%lf", result);
	return 0;
}