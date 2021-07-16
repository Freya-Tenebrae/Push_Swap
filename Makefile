# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2021/07/15 15:10:47 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
SRCS=$(addprefix ${FOLDER}/, \
	ft_main.c \
	ft_push_swap.c \
	ft_push_swap_custom_sort_1.c \
	ft_push_swap_custom_sort_2.c \
	ft_push_swap_custom_sort_3.c \
	ft_push_swap_quick_sort.c \
	ft_push_swap_order_radix_sort.c \
	ft_push_swap_small_stack.c \
	ft_tools_other_1.c \
	ft_tools_other_2.c \
	ft_tools_push.c \
	ft_tools_rotate.c \
	ft_tools_reverse_rotate.c \
	ft_tools_swap.c)
SRCS_GNL==$(addprefix ${GNL}/, get_next_line_bonus.c \
	get_next_line_util_bonus.c)
SRCS_BONUS==$(addprefix ${FOLDER}/, )
OBJS=$(SRCS:.c=.o)
OBJS_GNL=$(SRCS_GNL:.c=.o)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

INCLUDES=includes
FOLDER=srcs
LIBFT=$(addprefix ${INCLUDES}/, libft)
GNL=$(addprefix ${INCLUDES}/, get_next_line)

CC=gcc -g
CFLAGS=-Wall -Wextra -Werror -g3 -fsanitize=address
RM=rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT) bonus
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)/libft.a

bonus: $(OBJS_GNL) $(OBJS_BONUS)
	make -C $(LIBFT) bonus
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)/libft.a

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< -I $(INCLUDES)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: 
	make fclean -C $(LIBFT)
	$(RM) $(OBJS)
	${RM} push_swap

re: fclean all
