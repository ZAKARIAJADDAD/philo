# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 15:20:28 by zjaddad           #+#    #+#              #
#    Updated: 2023/03/18 14:41:17 by zjaddad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc -pthread
CFLAGS= -Wall -Wextra -Werror
AR= ar -rc

SRCS=philo.c philo_utils.c philo_utils_1.c

NAME=philo

OBJS= $(SRCS:.c=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	
fclean:
	rm -f $(NAME) $(OBJS)
	
re: fclean all

.PHONY: clean fclean all re