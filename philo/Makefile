# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 16:15:14 by tnam              #+#    #+#              #
#    Updated: 2023/05/08 20:23:58 by tnam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo

CC				=	cc
CFLAG			=	-Wall -Wextra -Werror
RM				=	rm -f

INCLUDES		=	includes/

SRCS			=	srcs/main.c							\
					srcs/0_utils/ft_atol.c				\
					srcs/0_utils/ft_strtol.c			\
					srcs/0_utils/ft_strtol_utils.c		\
					srcs/0_utils/ft_error.c				\
					srcs/0_utils/ft_free.c				\
					srcs/0_utils/ft_current_time.c		\
					srcs/0_utils/ft_print.c				\
					srcs/1_init/ft_info_init.c			\
					srcs/1_init/ft_fork_init.c			\
					srcs/1_init/ft_philo_init.c			\
					srcs/1_init/ft_time_init.c			\
					srcs/2_run/ft_start_logic.c			\
					srcs/2_run/ft_routine.c				\
					srcs/2_run/ft_eat.c					\
					srcs/2_run/ft_sleep.c				\
					srcs/2_run/ft_think.c				\
					srcs/2_run/ft_check_died.c			\
					srcs/2_run/ft_check_finish_eat.c	\
					srcs/2_run/ft_finish.c				\
					
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