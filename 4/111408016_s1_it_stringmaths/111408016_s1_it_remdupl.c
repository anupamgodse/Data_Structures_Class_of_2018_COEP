#include <stdio.h>
#define MAX 100
void delete(double *); 
int n;
int main() {
	int i;
	printf("Enter no of elements :\n");
	scanf("%d", &n);
	double arr[n];
	printf("Enter array elements :\n");
	for(i = 0; i < n; i++) 
		scanf("%lf", &arr[i]);
	printf("Original array is :\n");
	for(i = 0; i < n; i++) 
		printf("%lf\t", arr[i]);
	printf("\n");
	delete(arr);
	printf("After duplicate removal array is :\n");
	for(i = 0; i < n; i++) 
		printf("%lf\t", arr[i]);
	printf("\n");
	return 0;
}
void delete(double *a) {
	int j, i, m;
	double temp;
	for(j = 0; j < n - 1; j++) {
		temp = a[j];
		for(i = j + 1; i < n; i++) {
			if(temp == a[i]) {
				for(m = i; m <  n; m++)
					a[m] = a[m+1];
			n--;
			i--;	
			}
				
		}
	} 
}
