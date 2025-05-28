# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 15:58:09 by guvascon          #+#    #+#              #
#    Updated: 2025/05/28 15:17:05 by guvascon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/philosophers.c srcs/philo_utils.c srcs/init.c srcs/philos_aux.c
		srcs/monitor.c srcs/routine.c
		
OBJS = $(SRCS:.c=.o)

CC = @cc
CFLAGS = -g -Wall -Wextra -Werror -pthread
RM = rm -f

NAME = philo

all : $(NAME) 
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS) 
	@echo "all objects were removed"
	
fclean: clean
	@$(RM) $(NAME) 
	clear
	@echo "all files were removed"

re: fclean $(NAME)
	clear
	@echo "bla bla bla"
.PHONY: all clean fclean re