#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#define SIZE 128
int infixeval(char *);
char *evalpar(char *);
int evalexp(char *);
int main() {
	char infix[SIZE];
	int z;
	scanf("%[^\n]", infix);
	z = infixeval(infix);
	if(z != INT_MIN)
		printf("%d\n", z);
	return 0;
}
int infixeval(char *s) {
	char *d = (char *)malloc(SIZE);
	char *all = (char *)malloc(SIZE);
	char *final;
	const char delpar[SIZE] = {'*', '/', '+', '-', '%', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
	int ans, j = 0, i = 0, npar = 0;
	char *token;
	strcpy(d, s);
	token = strtok(d, " ");
	while(token != NULL) {
		while(token[i] != '\0')
			all[j++] = token[i++];		
		token = strtok(NULL, " ");
		i = 0;				
	}
	all[j] = '\0';
	if(all[0] == '-' || all[0] == '+' || all[0] == '*' || all[0] == '/' || all[0] == '%') {
		printf("Enter proper Expression\n");
		return INT_MIN;
	}
	while(all[i + 1] != '\0') {
		if((all[i] == '+' || all[i] == '-' || all[i] == '*' || all[i] == '/' || all[i] == '%') && (all[i + 1] == '+' || all[i + 1] == '-' || all[i + 1] == '*' || all[i + 1] == '/' || all[i + 1] == '%')) {
			printf("Enter proper expression\n");
			return INT_MIN;
		}
	i++;
	}
	if(all[i] == '+' || all[i] == '-'|| all[i] == '/' || all[i] == '*') {
		printf("Enter proper Expression\n");
		return INT_MIN;
	}
	i = 0;
	while(all[i + 1] != '\0') {
		if((all[i] == '(' && (all[i + 1] == '*' || all[i + 1] == '/' || all[i + 1] == ')'|| all[i + 1] == '%'|| all[i + 1] == '+')) || (all[i] == ')' && (isdigit(all[i+1]) || all[i + 1] == '(') || (isdigit(all[i]) && all[i + 1] == '('))) {
			printf("Enter proper expression\n");
			return INT_MIN;
		}
	i++;
	}
	strcpy(d, all);
	token = strtok(d, delpar);
	i = 0;
	while(token != NULL) {
		while(token[i] != '\0') {
			if(token[i] == '(' || token[i] == ')') { 
				if(token[i] == '(')
					npar++;
				else if(token[i] == ')' && npar > 0)
					npar--;
				else {
					printf("Insert proper paranthesis : Open bracket(s) missing\n");
					return INT_MIN;
				}
				i++;
			}
			else {
				printf("Enter proper expression\n");
				return INT_MIN;
			}
		}
		token = strtok(NULL, delpar);
		i = 0;	
	}
	free(d);
	if(npar != 0) {
		printf("Insert proper paranthesis : Close bracket(s) missing\n");
		return INT_MIN;
	}
	else {
		final = evalpar(all);
		free(all);
		ans = evalexp(final);
		free(final);
	}
	return ans;
}
int evalexp(char *str) {
	char a[SIZE];
	char b[SIZE];
	char opr[SIZE];
	char *token;
	int opd[SIZE], state = 0, c, j = 0, k, i = 0, nopd = 0, nopr = 0;
	const char delopd[SIZE] = {'*', '/', '+', '-', '%', '(', ')'};
	const char delopr[SIZE] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '(', ')'};
	strcpy(a, str);
	strcpy(b, str);
	if((b[0] == '-') && (b[1] == '-')) {
		while(b[j + 2] != '\0') {
			b[j] = b[j + 2];
			j++;
		}
		b[j] = '\0'; 
	}
	else if(b[0] == '-') {
		state = 1;
		while(b[j + 1] != '\0') {
			b[j] = b[j + 1];
			j++;
		}
		b[j] = '\0';
	}
	j = 0;
	token = strtok(a, delopd);
	while(token != NULL) {
		opd[j++] = atoi(token);
		nopd++;
		token = strtok(NULL, delopd);
	}
	token = strtok(b, delopr);
	j = 0;
	while(token != NULL) {
			if(token[1] == '-') { 
				opr[j++] = token[0];
				opd[j] = -opd[j];
				nopr++;
			}
			else{
				opr[j++] = token[0];
				nopr++;
			}
			token = strtok(NULL, delopr);	
		}
	if(state == 1)
		opd[0] = -opd[0];
	c = 0;
	j = 0;
	while(j < nopr) {
		if(opr[j] == '*' || opr[j] == '/' || opr[j] == '%') {
			i = j;
			if(opr[j] == '/' || opr[j] == '%') {
				if(opd[i + 1] != 0) {
					if(opr[j] == '/')
						opd[i] = opd[i] / opd[i + 1];
					else
						opd[i] = opd[i] % opd[i + 1];
				}
				else {
					printf("Indeterminate(x / 0)\n");
					exit(1);
				}
			}
			else 
				opd[i] = opd[i] * opd[i + 1];
			i++;
			while(i < nopd - 1) {
				opd[i] = opd[i + 1];
				i++;
			}
			nopd--;
			while(j < nopr - 1) {
				opr[j] = opr[j + 1];
				j++;
			}
			nopr--;
			j = 0;
		}
		else
			j++;
	}
	c = 0;
	j = 0;
	while(j < nopr) {
		if(opr[j] == '+' || opr[j] == '-') {
			i = j;
			if(opr[j] == '+')
				opd[i] = opd[i] + opd[i + 1];
			else 
				opd[i] = opd[i] - opd[i + 1];
			i++;
			while(i < nopd - 1) {
				opd[i] = opd[i + 1];
				i++;
			}
			nopd--;
			while(j < nopr - 1) {
				opr[j] = opr[j + 1];
				j++;
			}
			nopr--;
			j = 0;
		}
		else
			j++;
	}
	return opd[0];
}
char *evalpar(char *q) {
	static int i;
	int j = 0, k = 0;
	char *app;
	char *new = (char *)malloc(SIZE);
	while(q[i] != '\0') {
		if(q[i] == ')') {
			i++;
			snprintf(new, SIZE, "%d", (evalexp(new)));
			return new;
		}
		else if(q[i] == '(') {
			i++;
			app = evalpar(q);
			k = 0;
			while(app[k] != '\0') 
				new[j++] = app[k++];
		}
		else 
			new[j++] = q[i++];
	}
	new[j] = '\0';
	return new;
}































