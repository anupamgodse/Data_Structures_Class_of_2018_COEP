#define SIZE 128
#include <stdio.h>
#include "integer.h"
int main() {
	Integer a, b, z;
	char string1[SIZE], string2[SIZE];
	scanf("%s", string1);
	scanf("%s", string2);
	a = CreateIntegerFromString(string1);
	b = CreateIntegerFromString(string2);
	printf("addtoa = \t ");PrintInteger(AddDigitToInteger(a, '4')); printf("\n");
	printf("addtob = \t");PrintInteger(AddDigitToInteger(b, '4'));printf("\n");
	printf("adda_b = \t");PrintInteger(AddIntegers(a, b));printf("\n");
	printf("suba_b = \t");PrintInteger(SubstractIntegers(a, b));printf("\n");
	printf("mula_b = \t");PrintInteger(MultiplyIntegers(a, b));printf("\n");
	return 0;
}
