#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
int main()
{
	kill(91550, SIGINT);
}