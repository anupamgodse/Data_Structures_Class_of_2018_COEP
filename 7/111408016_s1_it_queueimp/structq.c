#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structq.h"
void qinit(queue *q) {
	q -> head = q -> tail = 0;
}
void enqueue(queue *q, data data) {
	strcpy(q -> array[q -> tail].name, data.name);
	q -> array[q -> tail].age = data.age;
	q -> tail++;
}
data dequeue(queue *q) {
	data temp;
	int shift = 0;
	strcpy(temp.name, q -> array[q -> head].name);
	temp.age = q -> array[q -> head].age;
	while(shift != q -> tail) {
		q -> array[shift] = q -> array[shift + 1];
		shift++;
	}
	q -> tail--;
	return temp;
}
int qempty(queue *q) {
	if(q -> tail)
		return 0;
	else
		return 1;
}
int qfull(queue *q) {
	if(q -> tail == SIZE)
		return 1;
	else 
		return 0;
}
void qprint(queue *q) {
	int temp = 0;
	printf("Queue : [");
	while(temp != q -> tail)	{
		printf("(%s,%d)\t", q -> array[temp].name , q -> array[temp].age);
		temp++;
	}
	printf("]\n");
}
