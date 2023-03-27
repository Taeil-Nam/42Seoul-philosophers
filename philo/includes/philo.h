/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:16:11 by tnam              #+#    #+#             */
/*   Updated: 2023/03/28 00:11:57 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAILURE -1

typedef struct s_info
{
	int		argc;
	char	**argv;
	struct s_philo **philos;
	long	num_of_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	must_eat_count;
	long	time_booted;
	long	time_passed;
}	t_info;

typedef struct s_philo
{
	pthread_t	thread;
	long		philo_num;
}	t_philo;

typedef struct s_strtol
{
	const char		*s;
	unsigned long	acc;
	int				c;
	unsigned long	cutoff;
	int				neg;
	int				any;
	int				cutlim;
}	t_strtol;

/* philo_main */
int			main(int argc, char *argv[]);

/* ft_argv_init */
int			ft_argv_init(int argc, char *argv[], t_info *info);

/* ft_philo_init */
int			ft_philo_init(t_info *info);

/* ft_time_init */
int			ft_time_init(t_info *info);

/* ft_atol */
long		ft_atol(const char *str);

/* ft_strtol */
long		ft_strtol(const char *nptr, char **endptr, int base);

/* ft_strtol_utils */
int			ft_isspace(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);

/* ft_make_thread */
int			ft_execute_logic(t_info *info, t_philo **philos);

/* ft_error */
int			ft_error(char *msg, int error_code);

/* ft_free */
void		ft_free_philos(t_philo **philos, long count);

/* ft_reset_time_passed */
long		ft_reset_time_passed(t_info *info);

#endif