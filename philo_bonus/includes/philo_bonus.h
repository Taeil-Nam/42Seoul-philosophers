/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:06:28 by jeekpark          #+#    #+#             */
/*   Updated: 2023/03/31 19:08:52 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
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
	long				time_elapsed;
	int					die_flag;
	pthread_mutex_t		mutex;
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
}	t_philo;

typedef struct s_fork
{
	long			fork_id;
	int				pickable;
	struct s_info	*info;
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
/** ft_atol_bonus **/
long		ft_atol(const char *str);
/** ft_strtol_bonus **/
long		ft_strtol(const char *nptr, char **endptr, int base);
/** ft_strtol_utils_bonus **/
int			ft_isspace(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
/** ft_error_bonus **/
int			ft_error(char *msg, int error_code);
/** ft_free_bonus **/
void		ft_free_philos(t_philo **philos, long count);
void		ft_free_forks(t_fork **forks, long count);
/** ft_current_time_bonus **/
long		ft_current_time(t_info *info);
long		ft_elapsed_time(long start_ms, long end_ms, t_info *info);


#endif