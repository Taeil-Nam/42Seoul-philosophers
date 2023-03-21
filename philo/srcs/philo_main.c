/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:15:35 by tnam              #+#    #+#             */
/*   Updated: 2023/03/21 16:39:01 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	g_num = 0;

void	*add(void *count);
void	*sub(void *count);
void	error(void);

int	main(void)
{
	pthread_t	add_thread;
	pthread_t	sub_thread;
	int			count;

	count = 50000;
	if (pthread_create(&add_thread, NULL, add, &count) != 0
		|| pthread_create(&sub_thread, NULL, sub, &count) != 0)
		error();
	if (pthread_join(add_thread, NULL) != 0
		|| pthread_join(sub_thread, NULL) != 0)
		error();
	printf("result add() and sub() : %d\n", g_num);
	return (0);
}

void	*add(void *count)
{
	int	i;

	i = 0;
	while (i++ < *(int *)count)
		g_num++;
	return (EXIT_SUCCESS);
}

void	*sub(void *count)
{
	int	i;

	i = 0;
	while (i++ < *(int *)count)
		g_num--;
	return (EXIT_SUCCESS);
}

void	error(void)
{
	perror(NULL);
	exit(EXIT_FAILURE);
}
