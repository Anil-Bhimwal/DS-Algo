#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
void forkexample()
{
	// child process because return value zero
	if (fork() == 0)
		printf("Hello from Child!\n");
	else
		printf("Hello from Parent!\n");
}
int main()
{
	fork();
	forkexample();
	pid_t cpid;
    if (fork()== 0)
        exit(0);           /* terminates child */
    else
        cpid = wait(NULL);
    printf("Parent pid = %d\n", getpid());
    printf("Child pid = %d\n", cpid);
	printf("Hello world!\n");
	return 0;
}
