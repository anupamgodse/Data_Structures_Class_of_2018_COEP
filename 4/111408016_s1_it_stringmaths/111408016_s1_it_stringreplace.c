#include <stdio.h>
#include <string.h>
int stringreplace(char *, char *, char *);
int main() {
    char text[128], orig[128], new[128]; 
    int count;
    scanf("%s%s%s", text, orig, new);
    count = stringreplace(text, orig, new);
    printf("%d %s\n", count, text);
}
int stringreplace(char *p, char *q, char *r) {
	char *t, *o, *n, *g, *m, *x;
	int i;
	t = p;
	o = q;
	n = r;
	int np = strlen(p);
	int nq = strlen(q);
	int nr = strlen(r);
	g = p + np + 2;
	int c = 0;
	while(*t != '\0') {
		if(*t == *o) {
			t++;
			o++;
		}
		else{
			if(o == q)
				t++;
			else{
				t = t - (o - q -1);
				o = q; 
			}
		}
		if(*o == '\0') {
			c++;
			if(nq == nr) {
				for(t = t - (o - q); *n != '\0'; t++, n++)
					*t = *n;
				o = q;
				n = r;
			}
			else if(nr > nq) {
				for(i = 0, m = g - 1; i < g - t; i++, m--) {
					*(m + (nr - nq)) = *m;
				}
				for(t = t - (o - q); *n != '\0'; t++, n++)
					*t = *n;
				o = q;
				n = r;
				g = g + (nr - nq);
			}
			else {
				m = t;
				while(0 < q - m) {
					*(m - (nq - nr)) = *m;
					m++;
				}
				for(t = t - (o - q); *n != '\0'; t++, n++)
					*t = *n;
				o = q;
				n = r;
				g = g - (nq - nr);
			}
		}
	}
	return c;
}

