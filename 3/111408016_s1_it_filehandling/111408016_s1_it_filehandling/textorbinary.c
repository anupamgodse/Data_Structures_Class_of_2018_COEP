#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
int main(int argc, char *argv[]) {
	char c;
	int fr, x;
	fr = open(argv[1], O_RDONLY, 00400);
	if(fr == -1) {
		perror("Open Failed!\n");
		return errno;
	}
	while(read(fr, &c, sizeof(char))) {
		if((isprint(c) == 0) && (isspace(c) == 0)) {
			printf("Binary file\n");
			close(fr);
			return 1;
		}
	}
	printf("Text file\n");
	close(fr);
	return 0;
}
