# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 16:15:14 by tnam              #+#    #+#              #
#    Updated: 2023/04/06 15:14:26 by tnam             ###   ########.fr        #
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