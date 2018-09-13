#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include "integer.h"
Integer CreateIntegerFromString(char *str) {
	Integer myint;
	myint.head = myint.tail = NULL;
	node *temp;
	int  i = 0, j = 0, k = 0;
	if(str[0] == '-') {
		myint.sign = '-';
		strcpy(str, &str[1]);
	}
	else
		myint.sign = '+';
	while(str[i] == '0') 
		i++;
	strcpy(str, &str[i]);
	if((strlen(str) % 4) > 0) {
		temp = (node*)malloc(sizeof(node));
		temp->s = (char*)malloc(sizeof(5));
		for(i = 0; i < (strlen(str) % 4); i++) 
			(temp->s)[j++] = str[k++];
		(temp->s)[j] = '\0';
		temp->next = NULL;
		myint.head = myint.tail = temp; 
	}
	while(str[k] != '\0') {
		temp = (node*)malloc(sizeof(node));
		temp->s = (char*)malloc(5);
		j = 0;
		while(j < 4 && str[k] != '\0')
			(temp->s)[j++] = str[k++];
		(temp->s)[j] = '\0';
		temp->next = NULL;
		if(myint.head) {
			myint.tail->next = temp;
			temp->prev = myint.tail;
		}
		else 
			myint.head = temp;
		temp->prev = myint.tail;
		myint.tail = temp;
	}
	if(!(myint.head)) {
		temp = (node*)malloc(sizeof(node));
		temp->s = (char*)malloc(sizeof(2));
		strcpy(temp->s, "0");
		temp->next = NULL;
		myint.head = myint.tail = temp;
	}
	return myint;	
}
Integer CreateIntegerFromFile(char *fname) {
	int d,n, i = 0;
	char c;
	d = open(fname, O_RDONLY, 00700);
	if(d == -1) {
		printf("Open Failed\n");
	}	
	while(read(d, &c, sizeof(char))) 
		i++;
	char str[i];
	i = 0;
	close(d);
	d = open(fname, O_RDONLY, 00700);
	while(read(d, &c, sizeof(char)))
		str[i++] = c;
	close(d);
	return CreateIntegerFromString(str);
}
Integer AddDigitToInteger(Integer a, char digit) {
	int n = 0, i = 0, j;
	node *x;
	x = a.head; 
	while(x) {
		x = x->next;
		n++;
	}
	char str[(n + 1) * 4];
	if(a.sign == '-')
		str[i++] = '-';
	x = a.head; 
	while(x) {
		j = 0;
		while((x->s)[j] != '\0') 
			str[i++] = (x->s)[j++];
		x = x->next;
	}
	str[i++] = digit;
	str[i] = '\0';
	return CreateIntegerFromString(str); 
}
Integer AddIntegers(Integer a, Integer b) {
	int n = 0;
	int c = 0;
	int l, i = 0, j, z, f = 0, k, m, nz = 0;
	if(a.sign == b.sign) {
		node *x = a.tail;
		node *y = b.tail;
		while(x || y) {
			n++;
			if(x)
				x = x->prev;
			if(y)
				y = y->prev;
		}
		char result[n * 4 + 2], r[6], fresult[n * 4 + 3], temp[5];
		result[0] = '\0';
		x = a.tail;
		y = b.tail;
		while(x && y) {
			z = (atoi(x->s) + atoi(y->s) + c);
			snprintf(r, 6, "%d", z);
			if(strlen(x->s) == strlen(y->s)) {
				if(strlen(r) == ((strlen(x->s) + 1))) {
					c = 1;
					strcpy(r, &r[1]);
					nz = 0;
					while(r[nz] == '0')
						nz++;
					
				}
				else
					c = 0; 
			}
			else if(strlen(x->s) > strlen(y->s)) {
				if(strlen(r) == ((strlen(x->s) + 1))) {
					c = 1;
					strcpy(r, &r[1]);
					nz = 0;
					while(r[nz] == '0')
						nz++;
				}
				else 
					c = 0;
			}
			else {
				if(strlen(r) == ((strlen(y->s) + 1))) {
					c = 1;
					strcpy(r, &r[1]);
					nz = 0;
					while(r[nz] == '0')
						nz++;
				}
				else 
					c = 0;
			}
			i = 0;
			if(strlen(r) != 4) {
				strcpy(temp, r);
				j = 4 - strlen(r);
				while(j > 0) {
					r[i++] = '0';
					j--;	
				}
				while(temp[j] != '\0') 
					r[i++] = temp[j++];
				r[i] = '\0';
			}
			strcat(result, r);
			x = x->prev;
			y = y->prev; 
		} 	
		while(x) {
			z = atoi(x->s) + c;
			snprintf(r, 6, "%d", z);
			if(strlen(r) == (strlen(x->s) + 1)) {
				c = 1;
				strcpy(r, &r[1]);
				nz = 0;
				while(r[nz] == '0')
					nz++;
				
			}
			else
				c = 0; 
			i = 0;
			if(strlen(r) != 4) {
				strcpy(temp, r);
				j = 4 - strlen(r);
				while(j > 0) {
					r[i++] = '0';
					j--;	
				}
				while(temp[j] != '\0') 
					r[i++] = temp[j++];
				r[i] = '\0';
			}
			strcat(result, r);
			x = x->prev;
		}
		while(y) {
			z = atoi(y->s) + c;
			snprintf(r, 6, "%d", z);
			if(strlen(r) == (strlen(y->s) + 1)) {
				c = 1;
				strcpy(r, &r[1]);
				nz = 0;
				while(r[nz] == '0')
					nz++;
			}
			else
				c = 0;
			i = 0; 
			if(strlen(r) != 4) {
				strcpy(temp, r);
				j = 4 - strlen(r);
				while(j > 0) {
					r[i++] = '0';
					j--;	
				}
				while(temp[j] != '\0') 
					r[i++] = temp[j++];
				r[i] = '\0';
			}
			strcat(result, r); 
			y = y->prev;
		}
		l = strlen(result);
		k = 0;
		if((a.sign == '-') && (c == 0)) 
			fresult[k++] = '-';
		j = l;
		m = l % 4;
		j = l - m;
		for(i = 0; i < m; i++) {
			fresult[k++] = result[j++];
			l--;
		}
		while(l > 0) {
			j = l - 4;
			for(i = 0; i < 4; i++) {
				fresult[k++] = result[j++];
				l--;
			}
		}
		fresult[k] = '\0';
		i = 0;
		while(fresult[i] == '0' && i < 4)
		  		i++;
		strcpy(fresult, &fresult[i]);
		i = 0;
		if(nz != 0) {
			strcpy(result, fresult);
			if(nz == 1) 
				strcpy(fresult, "0");
			else if(nz == 2)
				strcpy(fresult, "00");
			else if(nz == 3)
				strcpy(fresult, "000");
			else if(nz == 4)
				strcpy(fresult, "0000");
			strcat(fresult, result);
		}
		j = 0;
		if(c == 1){
			strcpy(result, fresult);
			if(a.sign == '-')
				strcpy(fresult, "-1"); 
			else
				strcpy(fresult, "1");
			strcat(fresult, result);
		}
		return CreateIntegerFromString(fresult);
	}
	else {
		if(a.sign == '-')
			b.sign = '-';
		else 
			b.sign = '+'; 
		return SubstractIntegers(a, b);
	}
}
Integer SubstractIntegers(Integer a, Integer b) {
	Integer big, small;
	int n = 0, c = 0, state = 0, z, j, l, i, m, k;
	char str[2], temp[5];
	node *x = a.head, *y = b.head;
	while(x && y) {
		n++;
		if(x)
			x = x->next;
		if(y)	
			y = y->next;
	}
	if(x) 
		big = a;
	else if(y) 
		big = b;
	else {
		x = a.head;
		y = b.head;
		while(((atoi(x->s) - atoi(y->s)) == 0) && (x->next)) {
			x = x->next;
			y = y->next; 
		}
		if((atoi(x->s) - atoi(y->s)) >= 0) 
			big = a;
		else 
			big = b;
	}
	if(big.head == a.head)
		small = b;
	else
		small = a;
	if(big.sign == small.sign) {
		node *x = big.tail;
		node *y = small.tail;
		while(x || y) {
			n++;
			if(x)
				x = x->prev;
			if(y)
				y = y->prev;
		}
		char result[n * 4 + 2], r[6], fresult[n * 4 + 3];
		result[0] = '\0';
		x = big.tail;
		y = small.tail;
		while(x && y) {
			if(atoi(x->s) >= atoi(y->s)) {
				state = 0;
				z = (atoi(x->s) - atoi(y->s) - c);
			}
			else {
				state = 1;
				z = ((pow(10,(strlen(x->s))) + atoi(x->s)) - atoi(y->s) - c);
			}
			snprintf(r, 6, "%d", z);
			if(state == 1)
				c = 1;
			else 
				c = 0;
			i = 0;
			if(strlen(r) != 4) {
				strcpy(temp, r);
				j = 4 - strlen(r);
				while(j > 0) {
					r[i++] = '0';
					j--;	
				}
				while(temp[j] != '\0') 
					r[i++] = temp[j++];
				r[i] = '\0';
			}
			strcat(result, r);
			x = x->prev;
			y = y->prev;
		} 
		while(x) {
			if(atoi(x->s) >= c) {
				state = 0;
				z = (atoi(x->s) - c);
			}
			else {
				state = 1;
				z = ((pow(10,(strlen(x->s))) + atoi(x->s)) - c);
			}
			snprintf(r, 6, "%d", z);
			if(state == 1)
				c = 1;
			else 
				c = 0;
			i = 0;
			if(strlen(r) != 4) {
				strcpy(temp, r);
				j = 4 - strlen(r);
				while(j > 0) {
					r[i++] = '0';
					j--;	
				}
				while(temp[j] != '\0') 
					r[i++] = temp[j++];
				r[i] = '\0';
			}
			strcat(result, r);
			x = x->prev;
		}		
		while(y) {
			if(atoi(y->s) >= c) {
				state = 0;
				z = (atoi(y->s) - c);
			}
			else {
				state = 1;
				z = ((pow(10,(strlen(y->s))) + atoi(y->s)) - c);
			}
			snprintf(r, 6, "%d", z);
			if(state == 1)
				c = 1;
			else 
				c = 0;
			i = 0;
			if(strlen(r) != 4) {
				strcpy(temp, r);
				j = 4 - strlen(r);
				while(j > 0) {
					r[i++] = '0';
					j--;	
				}
				while(temp[j] != '\0') 
					r[i++] = temp[j++];
				r[i] = '\0';
			}
			strcat(result, r);
			y = y->prev;
		}
		l = strlen(result);
		while(result[l - 1] == 0) 
			l--;
		result[l] = '\0';	
		k = 0;
		if((big.head == b.head) && (b.sign == '+')) 
			fresult[k++] = '-';
		else if((big.head == a.head) && (a.sign == '-')) 
			fresult[k++] = '-';
		j = l;
		m = l % 4;
		j = l - m;
		for(i = 0; i < m; i++) {
			fresult[k++] = result[j++];
			l--;
		}
		while(l > 0) {
			j = l - 4;
			for(i = 0; i < 4; i++) {
				fresult[k++] = result[j++];
				l--;
			}
		}
		fresult[k] = '\0';
		return CreateIntegerFromString(fresult);
	}
	else {
		
		if(a.sign == '-')
			b.sign = '-';
		else 
			b.sign = '+'; 
		return AddIntegers(a, b);	
	}
}
Integer MultiplyIntegers(Integer a, Integer b) {
	int n = 0, zc = 0, z, c = 0, i, j;
	Integer sum;
	char str[2];
	strcpy(str, "0");
	sum = CreateIntegerFromString(str);
	node *x = a.tail;
	node *y = b.tail;
	while(x || y) {
		n++;
		if(x)
			x = x->prev;
		if(y)
			y = y->prev;
	}
	char result[n * 2 * 4 + 1], r[9], fresult[n * 2 * 4 + 1], temp[9];
	
	result[0] = '\0';
	y = b.tail;
	while(y) {
		c = 0;
		fresult[0] = '\0';
		x = a.tail;
		while(x) {
			r[0] = '\0';
			strcpy(result, fresult);
			z = (atoi(y->s) * atoi(x->s) + c);
			snprintf(r, 9, "%d", z);
			if(strlen(r) > (strlen(x->s) || strlen(y->s))) {
				if(strlen(x->s) >= strlen(y->s)) {
					strcpy(temp, &r[strlen(r) - strlen(x->s)]);
					r[strlen(r) - strlen(x->s)] = '\0';
					c = atoi(r);
				}
				else if (strlen(y->s) > strlen(x->s)) {
					strcpy(temp, &r[strlen(r) - strlen(y->s)]);
					r[strlen(r) - strlen(y->s)] = '\0';
					c = atoi(r);
				}
			}
			else {
				strcpy(temp, r);
				c = 0;
			}
			i = 0;
			if(strlen(temp) == strlen(r)) {
				strcpy(r, temp);
				j = 4 - strlen(temp);
				while(j > 0) {
					temp[i++] = '0';
					j--;	
				}
				while(r[j] != '\0') 
					temp[i++] = r[j++];
				temp[i] = '\0';
			}
			strcpy(fresult, temp);
			strcat(fresult, result);
			x = x->prev;
		}
		for(i = 0; i < (4 * zc); i++) 
			strcat(fresult, "0");
		zc++;
		if(c > 0) {
			strcpy(result, fresult);
			snprintf(fresult, 5, "%d", c);
			strcat(fresult, result);
		}
		sum = AddIntegers(CreateIntegerFromString(fresult), sum);
		y = y->prev;
	}
	if(a.sign == b.sign)
		sum.sign = '+';
	else
		sum.sign = '-';
	return sum;
}
void PrintInteger(Integer a) {
		int i, state = 0;	
		node *x;
		x = a.head; 
		while(x) {
			i = 0;
			while((x->s)[i] != '\0') {
				if((x->s)[i] != '0') {
					state = 1;
					break;
				}
				i++;
			}
			if(state == 1)
				break;
			x = x->next;
		}
		x = a.head;
		if(state == 1) {
			if(a.sign == '-')
				printf("-");
			while(x) {
				printf("%s", x->s);
				x = x->next;
			}
			printf("\n");
		}
		else 
			printf("0\n");
}
