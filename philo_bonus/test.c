#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_OF_PHILO 5

int main()
{
	sem_t *sem;
	pid_t pid[NUM_OF_PHILO];
	int child_id;

	sem_unlink("/semaphore");
	sem = sem_open("/semaphore", O_CREAT | O_EXCL, 0, 5);
	
	child_id = 0;
	while (child_id < NUM_OF_PHILO + 1)
	{
		pid[child_id] = fork();
		if (pid[child_id] == 0)
		{
			sem_wait(sem);
			printf("Child process %d\n", child_id + 1);
			sleep(5);
			sem_post(sem);
			return 0;
		}
		child_id++;
	}
	
	child_id = 0;
	while (child_id < NUM_OF_PHILO + 1)
	{
		waitpid(pid[child_id], NULL, 0);
		child_id++;
	}

	sem_close(sem);
	sem_unlink("/semephore");

	return 0;
}