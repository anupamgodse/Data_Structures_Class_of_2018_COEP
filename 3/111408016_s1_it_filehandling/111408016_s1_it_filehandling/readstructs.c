#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	int n = 0, count = 0, state = 0, i;
	FILE *fr;
	double s = 0;
	s = atof(argv[2]);
	typedef struct info {
		int id;  
		char name[16]; 
		double score; 
	}info;
	info *p;
	fr = fopen(argv[1], "r");
	if (fr == NULL) {
		perror("Open failed\n");
		return errno;
	}
	fread(&n, sizeof(int), 1, fr);
	p = (info *)malloc(sizeof(info));
	for(count = 0; count < n; count++){
		fread(p, sizeof(info), 1, fr); 
		if((p -> score) == s) { 
			state = 1;
			printf("Id = %d\nName = %s\nScore = %lf\n\n", p -> id, p -> name, p -> score);
		}	 	
	}
	if(state == 0)
		printf("No match found\n");
	printf("Total entries were : %d\n", n);
	free(p);
	fclose(fr);
	return 0;
}

