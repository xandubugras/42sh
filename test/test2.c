#include <unistd.h>
#include <stdio.h>
int
main(int argc, char* argv[])
{
      /* List of arguments. Every argument must be a character string */
      char *new_args[] = { NULL, NULL};
      /* Pass in list of arguments */
      if (execlp("ls", new_args) < 0)
      {   
        /* Check for an error condition */
        perror ("execv");
      }   
      return 0;
}
