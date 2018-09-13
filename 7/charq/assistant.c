#include <stdio.h>
#include "queue.h"
void printmenu() {
	printf("1. New patient\n");
	printf("2. Send patient to doctor\n");
	printf("3. Exit\n");
}
int main() {
	char name;
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
					getchar();
					scanf("%c", &name);
					enqueue(&q, name);
				} else {
					printf("Patient go home, business in full swing\n");
					continue;
				}
				break;
			case 2:
				if(!qempty(&q)) {
					name = dequeue(&q);
					printf("Send %c to doctor\n", name);
				} else {
					printf("No patients. Doctor, close the dukaan\n");
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
