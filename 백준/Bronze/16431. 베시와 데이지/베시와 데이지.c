#include <stdio.h>
#include <math.h>

int max(int x, int y){
	return (x>y) ? x:y;
}

struct point{
	int x, y;
};

int main(){
	struct point pt[3];
	int i, bessie, daisy;
	for(i=0; i<3; i++)
		scanf("%d %d", &pt[i].x, &pt[i].y);
		daisy = abs(pt[1].x - pt[2].x) +  abs(pt[1].y - pt[2].y);
		bessie = max(abs(pt[0].x - pt[2].x), abs(pt[0].y - pt[2].y));
		
		if(bessie<daisy)
			printf("bessie");
		else if(bessie>daisy)
			printf("daisy");
		else
			printf("tie");
					
	return 0;
}

