/* A program to find power y raised to x. */
#include <stdio.h>
long double power(long double, long long);
int main() {
	long double x;
	long long y;
	printf("Enter base and index :\n");
	while(scanf("%Lf%lli", &x, &y) != -1) {
		printf("Ans = %Lf\n", power(x,y));
		printf("Enter base and index :\n");
	}
	return 0;
} 
long double power(long double p, long long q) {
	long double t = p, a = 1;
	long long r = q;
	if(p == 0 && q == 0) {
		return; 
	}
	if(q < 0)
		r = -q;
	while(r > 0) {
		if(r % 3 == 1)
			a = a * t;
		else if(r % 3 == 2)
			a = a * t * t;
		t = t * t * t;
		r /= 3;
	}
	if(q < 0)
		a = 1 / a;
	return a;
}
