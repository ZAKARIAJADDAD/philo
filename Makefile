# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 15:20:28 by zjaddad           #+#    #+#              #
#    Updated: 2023/04/10 22:16:24 by zjaddad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
SANI_TH = -fsanitize=thread -g
CFLAGS= -Wall -Wextra -Werror #$(SANI_TH)

SRCS=philo.c philo_utils.c philo_utils_1.c ft_memset.c

NAME=philo

OBJS= $(SRCS:.c=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	
fclean:
	rm -f $(NAME) $(OBJS)
	
re: fclean all

.PHONY: clean fclean all re