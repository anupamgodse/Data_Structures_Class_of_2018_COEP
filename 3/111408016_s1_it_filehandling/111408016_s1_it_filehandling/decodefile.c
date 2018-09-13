#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main(int argc, char *argv[1]) {
	typedef struct decode {
		long mis;
		char name[40];
	}decode;
	decode a;
	FILE *fr; 
	int i;
	fr = fopen(argv[1], "r");
	if(fr == NULL) {
		perror("Open Failed!\n");
		return errno;
	}
	for(i = 0; i < 6; i++) {
		fread(&a, sizeof(decode), 1, fr);
		printf("%ld %s\n", a.mis, a.name);
	}
	fclose(fr);
	return 0;
}
