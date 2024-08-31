#include <stdio.h>

int main() {
	
	int A, B, C;
	
	scanf("%d %d %d", &A, &B, &C);
	
	if((A==B) && (B==C)){
		printf("%d", A);
	}
	else if((A==B) && (B<C)){
		printf("%d", B);
	}
	else if((A==B) && (B>C)){
		printf("%d", B);
	}
	else if((A<B) && (B==C)){
		printf("%d", B);
	}
	else if((A>B) && (B==C)){
		printf("%d", B);
	}
	else if((A==C)&&(B<C)){
		printf("%d", A);
	}
	else if((A==C)&&(B>C)){
		printf("%d", A);
	}
	else if(((A>B)&&(A<C)) || ((A<B)&&(C<A))){
		printf("%d", A);
	}
	else if(((A<B)&&(B<C)) || ((A>B)&&(B>C))){
		printf("%d", B);
	}
	else if(((A>C)&&(B<C)) || ((C>A)&&(B>C))){
		printf("%d", C);
	}

	
	return 0;
}