#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
int main(int argc, char *argv[]) {
	int fr, n, t, i, m, p;
	char c;
	struct data {         
		int age;
	        char name[16];
	}temp; 
	fr = open(argv[1], O_RDONLY, 00700);
	if(fr == -1) {
		perror("Open Failed!\n");
		return errno;
	}
	read(fr, &n, sizeof(int));
	for(i = 0; i < n; i++) {
		read(fr, &t, sizeof(int));
		printf("%d\n", t);
	}
	read(fr, &m, sizeof(int));
	for(i = 0; i < m; i++) {
		read(fr, &temp, sizeof(struct data));
		printf("%d %s\n", temp.age, temp.name);
	}
	read(fr, &p, sizeof(int));
	for(i = 0; i < p; i++) {
		read(fr, &c, sizeof(char));
		while(c != '\0') {
			printf("%c", c);
			read(fr, &c, sizeof(char));
		}
		printf("\n");
	}
		
		
	close(fr);
	return 0; 
}
