#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
void sort(int *, int );
int main() {
	int *a, i, num, size = 1024;
	long int count = 0; 
	struct timeval tv1, tv2;
	a = (int *)malloc(sizeof(int) * size);
	while(scanf("%d", &num) != EOF) {
		if(count == size) {
			size *= 2;
			a = (int *)realloc(a, sizeof(int) * size);
			if(a == NULL) {
				printf("Failed for %d\n", size);
				exit(1);
			}
		}
		a[count] = num;
		count++;
	}
	sort(a, count);
	for(i = 0; i < count; i++) 
		printf("%d\n", a[i]);
	free(a);
	return 0;
}
void sort(int *s, int c) {
	int i, j, temp, state;
	for(i = 0; i < c - 1; i++) {
		state = 0;
		for(j = 0; j < c - i - 1; j++) {
			if(s[j] > s[j + 1]) {
				state = 1;
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
		if(state == 0)
			break;
	}	
}
