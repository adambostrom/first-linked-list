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
int remove_by_index(node_t ** head, int n);

void delay(int number_of_seconds);

int main() {
	
	node_t *head = NULL;
	head = (node_t*)malloc(sizeof(node_t));
	if (head == NULL) {
		return 1;
	}

	head->val = 22;
	head->next = (node_t*)malloc(sizeof(node_t));
	

	head->next->val = 36;
	head->next->next = (node_t*)malloc(sizeof(node_t));

	head->next->next->val = 255;
	head->next->next->next = NULL;

	print_list(head); //<---------- print to see which value on every node


	//Adding an item to the end of the list
	int val = 0;
	printf("Write a number to end of the list: ");
	scanf("%d", &val);
	pushEnd(head, val);  //<--------- given number as second argument will be added as the new last node
	print_list(head);


	//Adding an item to the beginning of the list (pushing to the list)
	printf("Write number to beginning of list: ");
	scanf("%d", &val);
	pushBeginning(&head, val); //<-------------- given number will be added to the beginning of the list, not sure how i managed to actually do this
	print_list(head);			//               , should really go back and look at double pointers alot more


	//Removing the first item (popping from the list)
	int removeFirstItem;
	printf("Removing FIRST item in list\tProcessing...\n");
	delay(3);
	removeFirstItem = pop(&head);
	printf("New linked list:\n");
	print_list(head);

	//Removing the last item
	int removeLastItem;
	printf("Removing item at END of list\tProcessing...\n");
	delay(3);
	removeLastItem = remove_last(head);
	printf("New linked list:\n");
	print_list(head);

	//Remove specific item
	int removeSpecifItem,returValueFromFunc;
	printf("Which item do you want to remove?");
	scanf("%d", &removeSpecifItem);
	returValueFromFunc = remove_by_index(&head, removeSpecifItem-1);
	printf("New linked list:\n");
	print_list(head);



	system("pause");
	return 0;
}

void print_list(node_t * head) {
	node_t * current = head;
	int i = 1;

	while (current != NULL) {
		printf("[%d]:%d\n", i, current->val);
		current = current->next;
		i++;
	}
	printf("\n");
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

int remove_by_index(node_t ** head, int n) {
	int i = 0;
	int retval = -1;
	node_t * current = *head;
	node_t * temp_node = NULL;

	if (n == 0) {
		return pop(head);
	}

	for (i = 0; i < n - 1; i++) {
		if (current->next == NULL) {
			return -1;
		}
		current = current->next;
	}

	temp_node = current->next;
	retval = temp_node->val;
	current->next = temp_node->next;
	free(temp_node);

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