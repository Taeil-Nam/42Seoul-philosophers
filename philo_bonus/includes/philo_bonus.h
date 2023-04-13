/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:16:11 by tnam              #+#    #+#             */
/*   Updated: 2023/04/13 16:04:15 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <semaphore.h>
# include <signal.h>

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAILURE -1
# define STARVED 4
# define FINISH_EAT 0

typedef struct s_philo
{
	int				argc;
	char			**argv;
	long			num_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			must_eat_count;
	long			time_booted;
	long			philo_id;
	long			last_eat_time;
	long			eat_count;
	sem_t			*fork_holder;
	sem_t			*lock_philo;
	char			*lock_philo_id;
	pid_t			*child;
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

/* 0_utils */
/** ft_atol **/
long		ft_atol(const char *str);
/** ft_strtol **/
long		ft_strtol(const char *nptr, char **endptr, int base);
/** ft_strtol_utils **/
int			ft_isspace(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
/** ft_error **/
int			ft_error(char *msg, int error_code);
/** ft_current_time **/
long		ft_current_time(t_philo *philo);
/** ft_itoa **/
char		*ft_ltoa(long n);

/* 1_init */
/** ft_philo_init **/
int			ft_philo_init(int argc, char *argv[], t_philo *philo);
/** ft_sem_init **/
int			ft_sem_init(t_philo *philo);
/** ft_time_init **/
int			ft_time_init(t_philo *philo);

/* 2_run */
/** ft_child_routine **/
void		ft_child_routine(t_philo *philo);
/** ft_eat **/
void		ft_eat(t_philo *philo);
/** ft_sleep **/
void		ft_sleep(t_philo *philo);
/** ft_think **/
void		ft_think(t_philo *philo);

#endif