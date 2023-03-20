/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:15:35 by tnam              #+#    #+#             */
/*   Updated: 2023/03/20 21:37:50 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_test(void *arg)
{
	int	thread_num;

	thread_num = *(int *)arg;
	printf("My thread ID = %d\n", thread_num);
	return (EXIT_SUCCESS);
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
		if (pthread_create(&threads[i], NULL, thread_test, &arg[i]) != 0) // 새로운 스레드 생성 후, arg를 인자로 사용하여 thread_test 함수 실행.
			error();
		i++;
	}
	i = 0;
	while (i < 5)
	{
		if (pthread_join(threads[i], NULL) != 0) // pthread_create()로 생성된 스레드들이 실행을 끝낼 때까지 대기.
			error();
		i++;
	}
	return (0);
}
