#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
void init(list *l) {
	l->head = l->tail = NULL;
	l->length = 0;
}
void traverse(list *l){
	node *x = l->head;
	printf("[");
	while(x != l->tail) {
		printf("%s\t", x->s);
		x = x->next;
	}
	if(x)
		printf("%s\t", x->s);
	printf("]\n");
}
void insert(list *l, char *str, int pos) {
	node *temp, *x = l->head;
	int i = 0;
	if(pos >= 0 && pos <= (l->length)) {
		temp = (node *)malloc(sizeof(node));
		temp->s = (char *)malloc(strlen(str) + 1);
		strcpy(temp->s, str);
		if((l->length) == 0) {
			temp->next = temp->prev = NULL;
			l->head = l->tail = temp;
		}
		else if((pos == 0) && (l->head)) {
			temp->prev = NULL;
			temp->next = l->head;
			l->head->prev = temp;
			l->head = temp;
		}
		else if(pos == (l->length)) {
			temp->next = NULL;
			temp->prev = l->tail;
			l->tail->next = temp;
			l->tail = temp;
		}
		else {
			while(i != pos) {
				x = x->next;
				i++;
			}
			temp->next = x;
			temp->prev = x->prev;
			x->prev->next = temp;
			x->prev = temp;
		}
		(l->length)++;
	}
	else {
		printf("Enter Valid Position\n");	
		return;
	}
}
char *remov(list *l, int pos) {
	char *rets;
	int i = 0;
	node *x = l->head;
	if((pos >= 0) && (pos < (l->length))) {
		if((l->length) == 1) {
			rets = l->head->s;
			free(l->head);
			l->head = l->tail = NULL;
			(l->length)--;
			return rets;	
		}
		else if(pos == 0) {
			rets = x->s;
			l->head = x->next;
			x->next->prev = NULL;
			(l->length)--;
			return rets;
		}
		else if(pos == ((l->length) - 1)) {
			rets = l->tail->s;
			x = l->tail;
			x->prev->next = NULL;
			l->tail = x->prev;
			free(x);
			(l->length)--;
			return rets;
		}
		else {
			while(i != pos) {
				x = x->next;
				i++;
			}
			rets = x->s;
			x->prev->next = x->next;
			x->next->prev = x->prev;
			free(x);
			(l->length)--;
			return rets;	
		}
	}
	else {
		if((l->length) == 0) { 
			printf("No elements in list\n");
			return NULL;
		}
		else {
			printf("Enter Valid Position\n");	
			return NULL;
		}	
	}
}
void append(list *l, char *str) {
	insert(l, str, l->length);
}
int length(list *l) {
	return l->length;
}
void reverse(list *l) {
	if((l->length) == 0 || (l->length == 1))
		return;
	else {
		node *temp = l->head, *x = l->head->next, *p;
		l->head->next = l->tail->prev = NULL;
		while(x != (l->tail)) {
			p = x->next;
			x->next = temp;
			temp->prev = x;
			temp = x;
			x = p; 
		}
		temp->prev = x;
		x->next = temp;
		l->tail = l->head;
		l->head = x;
		return;
	}
}
