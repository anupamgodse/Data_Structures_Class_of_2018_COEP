#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
void qinit(queue *head) {
	*head = NULL;
}
void enqueue(queue *head, char c) {
	node *x = *head;
	node *temp = (node *)malloc(sizeof(node));
	temp -> name = c;
	temp -> next = NULL;
	if(*head) {
		while(x -> next) 
			x = x -> next;
		x -> next = temp;
	}
	else
		*head = temp;
}
char dequeue(queue *head) {
	char c;
	node *x = *head;
	(*head) = (*head) -> next;
	c = x -> name;
	free(x);
	return c;
}
int qempty(queue *head) {
	if(*head)
		return 0;
	return 1;
}
int qfull(queue *head) {
	return 0;
}
void qprint(queue *head) {
	node *x = *head;
	printf("Queue : [");
	if(*head) {
		while(x -> next) {
			printf("%c\t", x -> name);
			x = x-> next;
		}
		printf("%c\t", x -> name);
	}
	printf("]\n");
}
