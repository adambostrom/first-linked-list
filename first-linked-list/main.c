#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//don't forget to bring a towel

typedef struct node {
	int val;
	struct node *next;
} node_t;

void print_list(node_t *head);
void pushEnd(node_t * head, int val);
void pushBeginning(node_t **head, int val);

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

	print_list(head); //<---------- print to see which value on every node

	int val = 0;
	printf("write down a number to add to the end of the list");
	scanf("%d", &val);

	pushEnd(head, val);  //<--------- given number as second argument will be added as the new last node
	print_list(head);


	printf("write down a number to add to the beginning of the list");
	scanf("%d", &val);
	pushBeginning(&head, val); //<-------------- given number will be added to the beginning of the list, not sure how i managed to actually do this
	print_list(head);			//               , should really go back and look at double pointers alot more

	system("pause");
	return 0;
}

void print_list(node_t * head) {
	node_t * current = head;

	while (current != NULL) {
		printf("%d\n", current->val);
		current = current->next;
	}
}

void pushEnd(node_t *head, int val) {
	node_t *current = head;
	while (current->next != NULL) {
		current = current->next;
	}

	/* now we can add a new variable */
	current->next = (node_t*)malloc(sizeof(node_t));
	current->next->val = val;
	current->next->next = NULL;
}

void pushBeginning(node_t **head, int val) {
	node_t * new_node;
	new_node = (node_t*)malloc(sizeof(node_t));

	new_node->val = val;
	new_node->next = *head;
	*head = new_node;
}