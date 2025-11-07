#include <stdio.h>
#include <string.h>

int main() {
	
	char a[8][9] = {{0}};
	int i, j, white = 0;
	
	for(i=0; i<8; i++)
		scanf("%s", a[i]);
	for(i=0; i<8; i++){
		if(i%2 == 0){
			for(j=0; j<4; j++){
				if(a[i][j*2] == 'F')
					white++;
			}
		}
		else{
			for(j=0; j<4; j++){
				if(a[i][j*2+1] == 'F')
					white++;
			}
		}
	}
	printf("%d", white);
	
	return 0;
}