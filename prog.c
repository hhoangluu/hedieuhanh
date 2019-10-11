#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdio_ext.h>
#define MAXLINE 80 /* The maximum length command */
int main(void)
{
  char *args[MAXLINE/2 + 1]; /* command line arguments */
  int shouldrun = 1; /* flag to determine when to exit program */
  int index = 0;
  char *p;
  int i = 0;
  char lastCharacter = 'a';
  char* command ;
  while (shouldrun) {
  index = 0;
  i = 0;
  lastCharacter = 'a';
  printf("osh>");
  fflush(stdout);
__fpurge(stdin);
  scanf("%[^\n]" , command);

  p = strtok(command," ");
  //printf("%s sasa", command);
  while (p != NULL) {
    args[index] = p;
    index++;
    p = strtok(NULL, " ");
   printf("args[%d] : %s", index, p);
    
  }
  for( i = index; i< MAXLINE/2 + 1; i++) {
    args[i] = NULL;
  } 
   lastCharacter = args[index-1][0];
  pid_t child_pid = fork();

  if (child_pid == 0) { // child process
  if ( lastCharacter == '&') {
    args[index-1] = NULL;
  }
  execvp( args[0], args);
  shouldrun = 0;
    _exit(0);
  
  }
  else if (child_pid > 0) { 
   
    if ( lastCharacter == '&') {
     wait(NULL); 

  }
  }
 
}
return 0;
}
