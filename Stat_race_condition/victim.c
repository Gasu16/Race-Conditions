#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>



ssize_t read(int fd, void *buf, size_t count);
int stat(const char *pathname, struct stat *statbuf);


int main(int argc, char *argv[]){

	if(argc != 2){
		fprintf(stderr, "Please enter 1 arg as file_1\nUsage: ./victim file_1\n");
		return -1;
	}

	int fd;
	char buffer[256];

	printf("Input file: %s\n", argv[1]);

	struct stat stat_data;

	if(stat(argv[1], &stat_data) != 0){
		fprintf(stderr, "Cannot stat file %s: %s\n", argv[1], strerror(errno));
		return -1;
	}

	
	printf("stat uid => %d\n", stat_data.st_uid);

	// 1 - Check the privileges of the input file passed as parameter with stat_data.st_uid

	if(stat_data.st_uid == 0){
		fprintf(stderr, "File is owned by ROOT, you can't access it\n");
		return -1;
	}
	
	// 2 - Open the file

	if((fd = open(argv[1], O_RDONLY)) < 0){
		fprintf(stderr, "Open error: %s\nErrno code => %d\n", strerror(errno), errno);
		return -1;
	}

	read(fd, buffer, sizeof(buffer));
	printf("%s", buffer);
	return 0;
}
