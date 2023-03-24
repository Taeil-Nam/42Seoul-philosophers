/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:16:11 by tnam              #+#    #+#             */
/*   Updated: 2023/03/24 19:32:38 by tnam             ###   ########.fr       */
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

typedef struct s_info
{
	int		argc;
	char	**argv;
	long	num_of_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	must_eat_count;
}	t_info;

typedef struct s_philo
{
	pthread_t	thread;
	long		philo_num;
	long		fork_count;
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

/* ft_init_info */
void		ft_init_info(int argc, char *argv[], t_info *info);

/* ft_init_philo */
void		ft_init_philo(t_info *info, t_philo **philos);

/* ft_atol */
long		ft_atol(const char *str);

/* ft_strtol */
long		ft_strtol(const char *nptr, char **endptr, int base);

/* ft_strtol_utils */
int			ft_isspace(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);

/* ft_error */
void		ft_error(char *msg);

/* ft_free */
void		ft_free_philos(t_philo **philos, long count);

#endif