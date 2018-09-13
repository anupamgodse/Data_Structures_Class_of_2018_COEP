#include <stdio.h>
#include "qusingstack.h"
void printmenu() {
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Exit\n");
}
int main() {
	int name;
	int choice;
	queue q;
	qinit(&q);
	while(1) {
		qprint(&q);
		printmenu();
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				if(!qfull(&q)) {
					scanf("%d", &name);
					enqueue(&q, name);
				} else {
					printf("Queue is Full\n");
					continue;
				}
				break;
			case 2:
				if(!qempty(&q)) {
					name = dequeue(&q);
					printf("Removed %d from queue\n", name);
				} else {
					printf("Queue empty\n");
					continue;
				}
				break;
			case 3:
				return 0;
			default:
				break;
		}
	}
	return 0;
}
