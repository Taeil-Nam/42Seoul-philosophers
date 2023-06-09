/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:16:11 by tnam              #+#    #+#             */
/*   Updated: 2023/05/08 20:25:45 by tnam             ###   ########.fr       */
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
	int					argc;
	char				**argv;
	struct s_philo		**philos;
	struct s_fork		**forks;
	long				num_of_philo;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				must_eat_count;
	long				time_booted;
	int					die_flag;
	int					finish_eat_flag;
	long				first_die_time;
	long				*eat_enough;
	pthread_mutex_t		die_mutex;
	pthread_mutex_t		finish_eat_mutex;
	pthread_mutex_t		print_mutex;
}	t_info;

typedef struct s_philo
{
	pthread_t		thread;
	long			philo_id;
	struct s_info	*info;
	struct s_fork	*left_fork;
	struct s_fork	*right_fork;
	int				left_fork_up;
	int				right_fork_up;
	long			last_eat_time;
	long			eat_count;
}	t_philo;

typedef struct s_fork
{
	long			fork_id;
	int				pickable;
	struct s_info	*info;
	pthread_mutex_t	mutex;
}	t_fork;

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
/** ft_free **/
void		ft_free_philos(t_philo **philos, long count);
void		ft_free_forks(t_fork **forks, long count);
/** ft_current_time **/
long		ft_current_time(t_info *info);
long		ft_elapsed_time(long start_ms, long end_ms, t_info *info);
/** ft_print **/
void		ft_print(t_info *info, long id, char *msg);

/* 1_init */
/** ft_info_init **/
int			ft_info_init(int argc, char *argv[], t_info *info);
/** ft_fork_init **/
int			ft_fork_init(t_info *info);
/** ft_philo_init **/
int			ft_philo_init(t_info *info);
/** ft_time_init **/
int			ft_time_init(t_info *info);

/* 2_run */
/** ft_start_logic **/
int			ft_start_logic(t_info *info, t_philo **philos);
/** ft_routine **/
void		*ft_routine(void *info);
/** ft_eat **/
int			ft_eat(t_philo *philo);
/** ft_sleep **/
int			ft_sleep(t_philo *philo);
/** ft_think **/
int			ft_think(t_philo *philo);
/** ft_check_died **/
int			ft_check_died(t_info *info, t_philo *philo);
int			ft_is_died(t_info *info, t_philo *philo);
int			ft_is_other_died(t_info *info);
/** ft_check_finish_eat **/
int			ft_check_finish_eat(t_philo *philo);
/** ft_finish **/
void		ft_finish(t_info *info);

#endif