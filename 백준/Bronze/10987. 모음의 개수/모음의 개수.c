#include <stdio.h>
#include <string.h>

int main() {
	
	char a[101];
	int i, vowel = 0, len;
	
	scanf("%s", a);
	len = strlen(a);
	for(i=0; i<len; i++){
		if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u')
			vowel++;
	}
	printf("%d", vowel);
	
	return 0;
}