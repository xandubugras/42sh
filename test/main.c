#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 
#include <stdlib.h>
#include <errno.h>  
#include <sys/wait.h>
#define WRITE_END 1
#define READ_END 0
 
int main(int argc, char **argv, char **env){
   pid_t  pid;
   int ret = 1;
   int status;
   int fd[2];
   int fd2[2];
   printf("oii\n");

   if (pipe(fd) == -1)
	   printf("err pipe1\n");
   if (pipe(fd2) == -1)
	   printf("err pipe1\n");
   pid = fork();
   if (pid == -1){
      // pid == -1 means error occured
      printf("can't fork, error occured\n");
      exit(EXIT_FAILURE);
   }
   else if (pid == 0){
      char *argv_list[] = {"cat", "add", NULL};
	  dup2(fd[WRITE_END], 1);
	  close(fd[0]);
	  close(fd[1]);
      //execve("/bin/cat", argv_list, env);
	  printf("1+1+1\n");
      exit(0);
   }
   else{
      printf("parent process, pid = %u\n", pid + 1);
	  pid = fork();
	  if (pid == 0)
	  {
	  	dup2(fd[READ_END], 0);
		dup2(fd2[WRITE_END], 1);
		close(fd[0]);
		close(fd[1]);
		close(fd2[0]);
		close(fd2[1]);
		execlp("bc", "bc", NULL);
	  }
	  else
	  {
		pid = fork();
		if (pid == 0)
		{
			dup2(fd2[READ_END], 0);
			close(fd2[0]);
			close(fd2[1]);
		printf("bc2:\n");
			execlp("bc", "bc", NULL);
		}
		else
		{
			close(fd2[0]);
			close(fd2[1]);
			exit(0);
		}
	  }
        if (waitpid(pid, &status, 0) > 0) {
             
            if (WIFEXITED(status) && !WEXITSTATUS(status)) 
              printf("program execution successfull\n");
             
            else if (WIFEXITED(status) && WEXITSTATUS(status)) {
                if (WEXITSTATUS(status) == 127) {
                    printf("execv failed\n");
                }
                else
                    printf("program terminated normally,"
                       " but returned a non-zero status\n");                
            }
            else
               printf("program didn't terminate normally\n");            
        } 
        else
           printf("waitpid() failed\n");
      exit(0);
   }
   return 0;
}
