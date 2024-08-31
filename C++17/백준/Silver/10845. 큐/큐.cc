#include <stdio.h>
#include <string.h>

#define MAX 10000

typedef struct _Queue{
	int front, rear;
	int arr[MAX];
}Queue;

void InitQueue(Queue *q) {

	q->front = -1;
	q->rear = -1;
}

int Is_full(Queue* q) {

	if (q->rear >= MAX-1) return 1;
	else return 0;
}

int Is_empty(Queue* q) {

	if (q->front == q->rear) return 1;
	else return 0;
}

void Push(Queue* q, int item) {

	if (Is_full(q)) printf("FULL");
	else q->arr[++(q->rear)] = item;

}

int Pop(Queue* q) {

	if (Is_empty(q)) return -1;
	else return q->arr[++(q->front)];
	
}

int Size(Queue* q) {

	return ((q->rear) - (q->front));
}

int Front(Queue* q) {

	if (Is_empty(q)) return -1;
	else return q->arr[(q->front) + 1];
}

int Back(Queue* q) {

	if (Is_empty(q)) return -1;
	else return q->arr[(q->rear)];
}

int main(){

	int i, n, x;
	char str[6];
	Queue queue;

	InitQueue(&queue);

	scanf("%d", &n);
	fgetc(stdin);	//버퍼 비우기

	for (i = 0; i < n; i++) {
		scanf("%s", str);
		fgetc(stdin);

		if (!strcmp(str, "push")) {

			scanf("%d", &x);
			fgetc(stdin);

			Push(&queue, x);
		}

		else if (!strcmp(str, "pop")) {

			printf("%d\n", Pop(&queue));
		}

		else if (!strcmp(str, "size")) {

			printf("%d\n", Size(&queue));

		}

		else if (!strcmp(str, "empty")) {

			printf("%d\n", Is_empty(&queue));
		}

		else if (!strcmp(str, "front")) {
			printf("%d\n", Front(&queue));
		}

		else if (!strcmp(str, "back")) {
			printf("%d\n", Back(&queue));
		}

		else printf("입력 오류\n");
	}

	return 0;
}