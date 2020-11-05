#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>


int access(const char *pathname, int mode);
ssize_t read(int fd, void *buf, size_t count);


int main(int argc, char *argv[]){

	// Check the number of args passed
	if(argc != 2){
		fprintf(stderr, "Please enter 1 arg as file_1\nUsage: ./victim file_1\n");
		return -1;
	}

	int fd;
	char buffer[256];
	printf("Input file: %s\n", argv[1]);

	// 1 - Check the privileges of the input file passed as parameter with access() syscall

	if(access(argv[1], R_OK) < 0){
		perror("Access error ");
		fprintf(stderr, "Cannot access file, errno = %d\n", errno);
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
