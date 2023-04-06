# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeekpark <jeekpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 16:15:14 by tnam              #+#    #+#              #
#    Updated: 2023/04/06 16:39:33 by jeekpark         ###   ########.fr        #
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
					srcs/1_init/ft_info_init_bonus.c		\
					srcs/1_init/ft_fork_init_bonus.c		\
					srcs/1_init/ft_philo_init_bonus.c		\
					srcs/1_init/ft_time_init_bonus.c		\
					srcs/2_run/ft_start_logic_bonus.c		\
					srcs/2_run/ft_routine_bonus.c			\
					srcs/2_run/ft_eat_bonus.c				\
					srcs/2_run/ft_sleep_bonus.c				\
					srcs/2_run/ft_think_bonus.c				\
					srcs/2_run/ft_check_died_bonus.c		\
					srcs/2_run/ft_check_finish_eat_bonus.c	\
					srcs/2_run/ft_finish_bonus.c			\
					
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