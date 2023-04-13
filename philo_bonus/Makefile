# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 16:15:14 by tnam              #+#    #+#              #
#    Updated: 2023/04/13 14:12:32 by tnam             ###   ########.fr        #
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
					srcs/0_utils/ft_current_time_bonus.c	\
					srcs/0_utils/ft_itoa_bonus.c			\
					srcs/1_init/ft_philo_init_bonus.c		\
					srcs/1_init/ft_time_init_bonus.c		\
					srcs/1_init/ft_sem_init_bonus.c			\
					srcs/2_run/ft_child_routine_bonus.c		\
					srcs/2_run/ft_eat_bonus.c				\
					srcs/2_run/ft_sleep_bonus.c				\
					srcs/2_run/ft_think_bonus.c				\
					
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