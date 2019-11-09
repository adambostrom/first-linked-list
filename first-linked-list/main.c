#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //<--- using just to make a delay to simulate a 1 second processing process.

//don't forget to bring a towel

typedef struct node {
	int val;
	struct node *next;
} node_t;

void print_list(node_t *head);
void pushEnd(node_t * head, int val);
void pushBeginning(node_t **head, int val);
int pop(node_t ** head);
int remove_last(node_t * head);

void delay(int number_of_seconds);

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


	//Adding an item to the end of the list
	int val = 0;
	printf("Write a number to add to the end of the linked list: ");
	scanf("%d", &val);
	pushEnd(head, val);  //<--------- given number as second argument will be added as the new last node
	print_list(head);


	//Adding an item to the beginning of the list (pushing to the list)
	printf("Write a number to add to the beginning of the linked list(pushing): ");
	scanf("%d", &val);
	pushBeginning(&head, val); //<-------------- given number will be added to the beginning of the list, not sure how i managed to actually do this
	print_list(head);			//               , should really go back and look at double pointers alot more


	//Removing the first item (popping from the list)
	int removeFirstItem;
	printf("Removing the FIRST item in the linked list(popping)\nProcessing...\n");
	delay(3);
	removeFirstItem = pop(&head);
	printf("Removed item: %d\nPrinting updated linked list.\nProcessing...\n", removeFirstItem);
	delay(3);
	print_list(head);

	//Removing the last item
	int removeLastItem;
	printf("Removing the item at the END of the linked list(popping)\nProcessing...\n");
	delay(3);
	removeLastItem = remove_last(head);
	printf("Removed item: %d\nPrinting updated list.\nProcessing...\n", removeLastItem);
	delay(3);
	print_list(head);





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

int pop(node_t ** head) {
	int retval = -1;
	node_t * next_node = NULL;

	if (*head == NULL) {
		return -1;
	}

	next_node = (*head)->next;
	retval = (*head)->val;
	free(*head);
	*head = next_node;

	return retval;
}

int remove_last(node_t * head) {
	int retval = 0;
	/* if there is only one item in the list, remove it */
	if (head->next == NULL) {
		retval = head->val;
		free(head);
		return retval;
	}

	/* get to the second to last node in the list */
	node_t * current = head;
	while (current->next->next != NULL) {
		current = current->next;
	}

	/* now current points to the second to last item of the list, so let's remove current->next */
	retval = current->next->val;
	free(current->next);
	current->next = NULL;
	return retval;

}

void delay(int number_of_seconds)
{
	// Converting time into milli_seconds 
	int milli_seconds = 1000 * number_of_seconds;

	// Stroing start time 
	clock_t start_time = clock();

	// looping till required time is not acheived 
	while (clock() < start_time + milli_seconds)
		;
}