# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2021/07/14 03:14:12 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
SRCS=$(addprefix ${FOLDER}/, \
	ft_main.c \
	ft_push_swap.c \
	ft_push_swap_small_stack.c \
	ft_push_swap_order_radix_sort.c \
	ft_tools_other_1.c \
	ft_tools_other_2.c \
	ft_tools_push.c \
	ft_tools_rotate.c \
	ft_tools_reverse_rotate.c \
	ft_tools_swap.c)
SRCS_BONUS==$(addprefix ${FOLDER}/, )
OBJS=$(SRCS:.c=.o)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

HEADER=includes
FOLDER=srcs
LIBFT=libft

CC=gcc -g
CFLAGS=-Wall -Wextra -Werror -g3 -fsanitize=address
RM=rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT) bonus
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)/libft.a

bonus: $(OBJS_BONUS)
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
