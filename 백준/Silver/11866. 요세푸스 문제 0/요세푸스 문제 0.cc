#include <stdio.h>
#include <stdlib.h>

typedef struct CListNode {
	int data;
	struct CListNode* link;
}CListNode;

typedef struct ListMark {

	CListNode* head;
	CListNode* tail;
	int size;

}ListMark;

ListMark* Init(void) {

	ListMark* ls = (ListMark*)malloc(sizeof(ListMark));

	ls->head = NULL;
	ls->tail = NULL;
	ls->size = 0;

	return ls;

}

void InsertLast(ListMark* ls, int data) {
	
	CListNode* newnode = (CListNode*)malloc(sizeof(CListNode));
	newnode->data = data;
	if (ls->head == NULL) {
		ls->head = newnode;
		ls->tail = newnode;
		newnode->link = newnode;
	}
	else {
		newnode->link = ls->head;
		ls->tail->link = newnode;
		ls->tail = newnode;
	}
	(ls->size)++;
}

void DeleteFirst(ListMark* ls) {

	if (ls->head == NULL) return;
	else {
		CListNode* removed = ls->head;

		ls->tail->link = removed->link;
		ls->head = removed->link;
		(ls->size)--;
		free(removed);
	}
}

void Func1(ListMark* ls, int pos) {

	for (pos = pos - 1; pos > 0; pos--) {
		ls->head = ls->head->link;
		ls->tail = ls->tail->link;
	}
	printf("%d, ", ls->head->data);
	DeleteFirst(ls);
	
}


int main() {

	int n, k, i;

	scanf("%d %d", &n, &k);
	printf("<");

	ListMark* ls = Init();

	for (i = 1; i <= n; i++) {
		InsertLast(ls, i);
	}
	
	while (ls->size > 1) {
		Func1(ls, k);
	}
	
	printf("%d", ls->head->data);
	printf(">");

	free(ls);
	return 0;

}