#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include<errno.h>
int main(int argc, char *argv[]) {
	int d, fd, n = 0, i;
	typedef struct info { 
		int id;  
		char name[16]; 
		double score; 
	}info;
	typedef struct temp {
		info data;
		struct temp *nptr;
	}temp;
	temp *header, *rear, *cptr, *t;
	fd = open(argv[1], O_WRONLY | O_CREAT, 00700);
	if (fd == -1) {
		perror("Open failed\n");
		return errno;
	}
	printf("Do you want to enter a entry:- 1 : YES\t0 : NO\n");
	scanf("%d", &d);
	if(d == 0) 
		return 0;
	if(d == 1) {
		header = (temp *)malloc(sizeof(temp));
		printf("Enter id :\n");
		scanf("%d", &(header -> data.id));
		printf("Enter Name :\n");
		scanf("%s", header -> data.name);
		printf("Enter Score :\n");
		scanf("%lf", &(header -> data.score));
		n++;
		rear = header;
		header -> nptr = NULL;
		cptr = header;
	}
	printf("Do you want to enter a new entry:- 1 : YES\t0 : NO\n");
	scanf("%d", &d);	
	while(d == 1) {
		cptr = (temp *)malloc(sizeof(temp));
		printf("Enter id :\n");
		scanf("%d", &(cptr -> data.id));
		printf("Enter Name :\n");
		scanf("%s", cptr -> data.name);
		printf("Enter Score :\n");
		scanf("%lf", &(cptr -> data.score));
		n++;
		rear -> nptr = cptr;
		rear = cptr;
		printf("Do you want to enter a new entry:- 1 : YES\t0 : NO\n");
		scanf("%d", &d);	
	}
	cptr -> nptr = NULL; 
	cptr = header;
	printf("Number of entries are : %d\n", n);
	write(fd, &n, sizeof(int));
	if(header -> nptr == NULL) 
		write(fd, &(header -> data), sizeof(info));
	else {
		do {
			write(fd, &(cptr -> data), sizeof(info));
			cptr = cptr -> nptr;
		}while(cptr -> nptr != NULL);
		write(fd, &(cptr -> data), sizeof(info));
	}
	close(fd);
	cptr = header;
	for(i = 0; i < n; i++) {
	t = cptr -> nptr;
	free(cptr);
	cptr = t;
	}
	return 0;
}
