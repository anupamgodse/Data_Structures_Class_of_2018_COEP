#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringq.h"
void qinit(queue *q) {
	q -> head = NULL;
	q -> tail = NULL;
}
void enqueue(queue *q, char *name) {
	node *temp = (node *)malloc(sizeof(node));
	char *name2 = (char *)malloc(sizeof(strlen(name) + 1));
	strcpy(name2, name);
	temp -> name = name2;
	temp -> next = NULL;
	if(q -> head) {
		q -> tail -> next = temp; 
	}
	else 
		q -> head = temp;
	q -> tail = temp;
}
char *dequeue(queue *q) {
	node *temp = q -> head;
	char *retname = q -> head -> name;
	q -> head = q -> head -> next;
	free(temp); 
	if(q -> head == NULL)
		q -> tail == NULL;
	return retname;
}
int qempty(queue *q) {
	if(q -> head)
		return 0;
	else
		return 1;
}
int qfull(queue *q) {
	return 0;
}
void qprint(queue *q) {
	node *temp = q -> head;
	printf("Queue : [");
	while(temp)	{
		printf("%s\t", temp -> name);
		temp = temp -> next;
	}
	printf("]\n");
}
