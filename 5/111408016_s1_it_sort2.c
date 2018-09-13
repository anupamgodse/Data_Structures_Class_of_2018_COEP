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
void sort(int *s, int n) {
	int i, j, temp, max, c = n - 1;
	for(i = 0; i < c; c--) {
		max = i;
		for(j = 0; j < c; j++) {
			if(s[max] < s[j + 1]) 
				max = j + 1;
		}
		if(max != c) {
			temp = s[max];
			s[max] = s[c];
			s[c] = temp;
		}
	}	
}
