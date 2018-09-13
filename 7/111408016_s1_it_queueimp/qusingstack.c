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
	init(temp);
	int retval;
	while(!empty(*q)) 
		push(temp, pop(*q)); 
	retval = pop(temp);
	while(!empty(temp)) 
		push(*q, pop(temp));	
	free(temp);
	return retval;
}
int qempty(queue *q) {
	return (empty(*q));
}
int qfull(queue *q) {
	return (full(*q));
}
void qprint(queue *q) {
	int value;
	stack *temp = (stack *)malloc(sizeof(SIZE));
	init(temp);
	while(!empty(*q)) 
		push(temp, pop(*q));
	printf("Queue : [");
	while(!empty(temp)) {
		value = pop(temp);
		printf("%d\t", value);
		push(*q, value);
	}
	printf("]\n");
	free(temp);
}
