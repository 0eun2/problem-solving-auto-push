#include <stdio.h>

int main() {
	
	int n, i, j;
	int rej = 0; 
	int arr[100];
	
	for(i=0; i<100; i++){
		arr[i] = 0;
	}
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &j);
		if(arr[j-1] != 0){
			rej++;
		}
		else {
			arr[j-1] = 1;
		}
	}
	
	printf("%d", rej);
	 
	return 0;
}