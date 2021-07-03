# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2021/07/03 13:30:37 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
SRCS=$(addprefix srcs/tools/, ft_swap.c, \
							ft_push.c, \
							ft_rotate.c \
							ft_reverse_rotate.c) \
	$(addprefix srcs/, ft_push_swap.c)
OBJS=$(SRCS:.c=.o)

HEADER=includes

CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< -I $(HEADER)

clean:
	$(RM) $(OBJS)

fclean: clean
	${RM} push_swap

re: fclean all
