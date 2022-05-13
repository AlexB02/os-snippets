/* The fork() call creates an exact copy of the parent process */

// Returns pid of child process
int fork(void);

int example1(void) {
  if (fork() != 0) 
    printf("Parent code\n");
  else
    printf("Child code\n");

  printf("Common code");
}

/* Calling example1 gives:

"Parent code"
"Common code"

"Child code"
"Common code"

The parent and child processes may be interleaved by the scheduler
*/

// Function called by parent process A
int example2() {
  if (fork() != 0) // Creates child of A called X
    printf("%d: X\n", getpid());

  if (fork() != 0) // Reached by both A and X, creating a child each
    printf("%d: Y\n", getpid());

  printf("%d: Z\n", getpid()); // Called 4 times, once each by A, X, Y1 and Y2
}
