/*Create a modular program in C that accepts only command-line arguments to carry out the following tasks:
- Create a file/named pipe, a user should give permissions for the file.


- Read data from a file, where a user can specify (i) the amount of data to read (in bytes), and (ii) from where to read the data in the file (e.g., read 100 bytes from a file f1.txt from the beginning)
- Write data to a file, where a user can specify (i) the amount of data to write (in bytes), and (ii) from where to start writing the data to the file (e.g., write 100 bytes from a file f1.txt from offset 10 from current position)

- Display statistical information of a specified file including owner, permissions, inode and all time stamps.
- Create an unnamed pipe designed for copying a file's content (say 'a.txt') to another file ('b.txt'). 

- Create a named pipe to help communicate between two processes, where a user can specify the purpose of the pipe i.e. reading or writing


NOTE:
1. Display proper messages to display errors in opening or closing files.
2. Take care of closing a file
3. Use system calls only 
4. Create documentation also.
5. Don't use any hard-coded filenames or values of any parameter.*/

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(int argc, char const *argv[])
{
	int testInteger;
	printf("%s\n", "Enter a number:");
	scanf("%d", &testInteger); 
	return 0;
}