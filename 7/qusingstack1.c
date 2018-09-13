#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qusingstack.h"
void qinit(queue *q) {
	*q = (stack *)malloc(sizeof(SIZE));
	init(*q);
}
void enqueue(queue *q, int name) {
	push(*q, name);
}
int dequeue(queue *q) {
	stack *temp = (stack *)malloc(sizeof(SIZE));
	int retval;
	while(!empty(*q)) {
		push(temp, pop(*q)); 
	}
	retval = pop(temp);
	while(!empty(temp)) {
		push(*q, pop(temp));	
	}
	free(temp);
	return retval;
}
int qempty(queue *q) {
	if(!empty(*q))
		return 0;
	else
		return 1;
}
int qfull(queue *q) {
	if(!full(*q))
		return 0;
	else 
		return 1;
}
void qprint(queue *q) {
	int value;
	stack *temp = (stack *)malloc(sizeof(SIZE));
	while(!empty(*q)) {
		push(temp, pop(*q));
	}
	printf("Queue : [");
	while(!empty(temp)) {
		value = pop(temp);
		printf("%d\t", value);
		push(*q, value);
	}
	printf("]\n");
}
