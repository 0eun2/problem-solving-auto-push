#include <stdio.h>
#include <string.h>

int main() {
	
	int arr[26], t, i, j, n, sum = 0, len;
	char s[1001];
	
	scanf("%d", &t);
	for(i=0; i<t; i++){
		scanf("%s", s);
		for(j=0; j<26; j++)
			arr[j]=1;
		sum=0;
		len=strlen(s);
		for(j=0; j<len; j++)
			arr[s[j]-'A']=0;
		for(j=0; j<26; j++)
			sum+=arr[j]*(j+'A');
		printf("%d\n", sum);
	}
	
	return 0;
}