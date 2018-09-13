typedef struct node {
	char *s;
	struct node *next, *prev;
}node;
typedef struct Integer{
	char sign;
	node *head, *tail;
}Integer; 
Integer CreateIntegerFromString(char *str);
Integer CreateIntegerFromFile(char *fname);
Integer AddDigitToInteger(Integer a, char digit);
Integer AddIntegers(Integer a, Integer b);
Integer SubstractIntegers(Integer a, Integer b);
Integer MultiplyIntegers(Integer a, Integer b);
void PrintInteger(Integer a);
