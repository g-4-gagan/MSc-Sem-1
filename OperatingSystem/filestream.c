#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int createFile(char* path, char* perm){
	// const char *perm = "rwxrwxrwx";
	// mode_t mode = 0;

	// if (perm[0] == 'r')
	//   mode |= 0400;
	// if (perm[1] == 'w')
	//   mode |= 0200;
	// if (perm[2] == 'x')
	//   mode |= 0100;
	// if (perm[3] == 'r')
	//   mode |= 0040;
	// if (perm[4] == 'w')
	//   mode |= 0020;
	// if (perm[5] == 'x')
	//   mode |= 0010;
	// if (perm[6] == 'r')
	//   mode |= 0004;
	// if (perm[7] == 'w')
	//   mode |= 0002;
	// if (perm[8] == 'x')
	//   mode |= 0001;
	mode_t mode = (((perm[0] == 'r') * 4 | (perm[1] == 'w') * 2 | (perm[2] == 'x')) << 6) |
              (((perm[3] == 'r') * 4 | (perm[4] == 'w') * 2 | (perm[5] == 'x')) << 3) |
              (((perm[6] == 'r') * 4 | (perm[7] == 'w') * 2 | (perm[8] == 'x')));
    int fd = creat(path, mode);
    if(fd == -1){
    	printf("Error while creating the File\n");
    }
	return fd;
}

int openFile(char* path, int mode){
	int fd;

	switch(mode){
		case 0: fd = open(path, O_RDONLY);
				break;
		case 1: fd = open(path, O_WRONLY);
				break;
		case 2: fd = open(path, O_RDWR);
				break; 
	}

	if(fd == -1){
		printf("Error while opening file check for file with given path and its permissions");
	}

	return fd;
}

int closeFile(int fd){
	int res = close(fd);
	if(res == -1){
		printf("Error while closing the file");
	}
	
	return res;
}


int main(int argc, char const *argv[])
{
	int testInteger;
	printf("%s\n", "Enter a number:");
	setvbuf(stdout, NULL, _IOLBF, 0);
	scanf("%d", &testInteger);
	int a = createFile("abc.txt", "rw-rw-rw-");
	printf("%d %d\n", testInteger, &a);
	return 0;
}
