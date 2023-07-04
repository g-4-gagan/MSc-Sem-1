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
#include <stdbool.h>

int main(int argc, char const *argv[])
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	printf("This is a Menu-Driven File Operations Simulation Program\n");
	bool main_flag = true;
	while(main_flag)
	{
		printf("File Operation Main Menu: \n");
		printf("1. Create a file\n");
		printf("2. Open a file\n");
		printf("3. other operations\n");
		printf("4. Exit\n");

		int choice;
		scanf("%d", &choice);
		if(choice==4){
			// main_flag = false;
			break;
		}
		if(choice<1 || choice>4)
		{
			printf("Invalid choice, Enter again\n");
		}
		else{
			switch(choice){
				case 1: printf("Creating file Menu:\n");
						char* file_name;
						char perm[9];
						printf("Enter file name:");
						scanf("%s",file_name);
						printf("Enter file permission in format 'rwxrwxrwx(USR-GRP-OTH)':\n");
						scanf("%s", perm);
						int fd = 12;
						if(fd!=-1){
							bool int_flag = true;
							printf("File created Successfully and opened in write mode: \n");
							while(int_flag){
								printf("1. Write to created file\n");
								printf("2. Close the file and return to main menu\n");
								printf("3. other operations\n");
								printf("4. Exit the simulation\n");
								int int_choice;
								scanf("%d", &int_choice);
								if(int_choice==4){
									main_flag = false;
									break;
								}
								if(int_choice<1 || int_choice>4)
								{
									printf("Invalid choice, Enter again\n");
								}
								else{
									switch(int_choice){
										case 1: printf("Write to file Menu:\n");
												break;
										case 2: printf("closing file and return to main menu\n");
												int_flag = false;
												break;
										case 3: printf("Other operations:\n");
												break;		
									}
								}
							}
						}
						
						break;
				case 2: printf("Opening file Menu:\n");
						break;
				case 3: printf("other operation file Menu:\n");
						break;
			}
		}
	}
	printf("Thanks for using the Simulation");
	return 0;
}