#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
int main()
{
	char *a;
	a = "hello";
	a[2] = 'w';
	printf("%s\n", a);
}