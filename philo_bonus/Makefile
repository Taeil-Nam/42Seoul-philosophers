# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 16:15:14 by tnam              #+#    #+#              #
#    Updated: 2023/03/31 19:05:08 by jeekpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo_bonus

CC				=	cc
CFLAG			=	-Wall -Wextra -Werror
RM				=	rm -f

INCLUDES		=	includes/

SRCS			=	srcs/main_bonus.c						\
					srcs/0_utils/ft_atol_bonus.c			\
					srcs/0_utils/ft_strtol_bonus.c			\
					srcs/0_utils/ft_strtol_utils_bonus.c	\
					srcs/0_utils/ft_error_bonus.c			\
					srcs/0_utils/ft_free_bonus.c			\
					srcs/0_utils/ft_current_time_bonus.c	\
					srcs/1_init/ft_argv_init.c		\
					srcs/1_init/ft_fork_init.c		\
					srcs/1_init/ft_philo_init.c		\
					srcs/1_init/ft_time_init.c		\
					srcs/2_run/ft_start_logic.c		\
					srcs/2_run/ft_eat_sleep_think.c	\
					srcs/2_run/ft_eat.c				\
					srcs/2_run/ft_sleep.c			\
					srcs/2_run/ft_think.c			\
					srcs/2_run/ft_check_died.c		\
					srcs/2_run/ft_finish.c			\
					
OBJS			=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAG) -I$(INCLUDES) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY : all bonus clean fclean re