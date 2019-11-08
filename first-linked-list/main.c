#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node * next;
} node_t;

int main() {
	
	node_t *head = NULL;
	head = (node_t*)malloc(sizeof(node_t));
	if (head == NULL) {
		return 1;
	}

	head->val = 1;
	head->next = (node_t*)malloc(sizeof(node_t));
	

	head->next->val = 2;
	head->next->next = NULL;



	system("pause");
	return 0;
}