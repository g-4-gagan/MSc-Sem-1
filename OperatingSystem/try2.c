#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main(){

   pid_t pid;
   pid = fork();
   if (pid==0){
      printf("child process");
   }
   else if(pid>0){
      printf("parent process");
   }
   else{
      printf("error in creating child process");
   }
   
   printf("common code for child and parent");
   
   return 0;
}

