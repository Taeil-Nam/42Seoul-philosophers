/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:15:35 by tnam              #+#    #+#             */
/*   Updated: 2023/03/18 20:23:08 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_test(void *arg)
{
	int	thread_num;

	thread_num = *(int *)arg;
	printf("My thread ID = %d\n", thread_num);
	pthread_exit(NULL);
}

void	error(void)
{
	perror(NULL);
	exit(EXIT_FAILURE);
}

int	main(void)
{
	pthread_t	threads[5];
	int			arg[5];
	int			i;

	i = 0;
	while (i < 5)
	{
		arg[i] = i;
		if (pthread_create(&(threads[i]), NULL, thread_test, &arg[i]) != 0)
			error();
		i++;
	}
	i = 0;
	while (i < 5)
	{
		if (pthread_join(threads[i], NULL) != 0)
			error();
	}
	return (0);
}
