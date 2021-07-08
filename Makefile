# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2021/07/08 12:27:27 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
SRCS=$(addprefix ${FOLDER}/, \
	ft_push_swap.c \
	ft_tools_other.c \
	ft_tools_push.c \
	ft_tools_rotate.c \
	ft_tools_reverse_rotate.c \
	ft_tools_swap.c)
OBJS=$(SRCS:.c=.o)

HEADER=includes
FOLDER=srcs
LIBFT=libft

CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT) bonus
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)/libft.a

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< -I $(HEADER)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: 
	make fclean -C $(LIBFT)
	$(RM) $(OBJS)
	${RM} push_swap

re: fclean all
