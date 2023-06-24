#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int createFile(char* path, mode_t mode){
	return creat(path, mode);
}

int main(int argc, char const *argv[])
{
	int testInteger;
	printf("%s\n", "Enter a number:");
	scanf("%d", &testInteger);
	int a = createFile("abc.txt", 0666);
	printf("%d %d\n", testInteger, &a);
	return 0;
}


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