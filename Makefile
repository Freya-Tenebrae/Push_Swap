# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 23:11:43 by cmaginot          #+#    #+#              #
#    Updated: 2021/07/20 16:11:40 by cmaginot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
NAME_BONUS=checker
SRCS=$(addprefix ${FOLDER}/, \
	ft_main.c \
	ft_push_swap.c \
	ft_push_swap_custom_sort.c \
	ft_push_swap_order_radix_sort.c \
	ft_push_swap_quick_sort.c \
	ft_push_swap_small_stack.c \
	ft_tools_custom_sort_1.c \
	ft_tools_custom_sort_2.c \
	ft_tools_found_position_value_in_stacks.c \
	ft_tools_informations_stacks.c \
	ft_tools_memory_and_access_stacks.c \
	ft_tools_push.c \
	ft_tools_rotate.c \
	ft_tools_reverse_rotate.c \
	ft_tools_swap.c)
SRCS_BONUS=$(addprefix ${FOLDER}/, \
	ft_main_bonus.c \
	ft_push_swap_bonus.c \
	ft_tools_memory_and_access_stacks.c \
	ft_tools_push.c \
	ft_tools_rotate.c \
	ft_tools_reverse_rotate.c \
	ft_tools_swap.c)
OBJS=$(SRCS:.c=.o)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)

INCLUDES=includes
FOLDER=srcs
LIBFT=$(addprefix ${INCLUDES}/, libft)
GNL=$(addprefix ${INCLUDES}/, get_next_line)

CC=gcc -g
CFLAGS=-Wall -Wextra -Werror -g3 -fsanitize=address
RM=rm -f

all: $(NAME) bonus

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	make -C $(LIBFT) bonus
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)/libft.a

$(NAME_BONUS): $(OBJS_BONUS)
	make -C $(LIBFT) bonus
	make -C $(GNL)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)/libft.a $(GNL)/get_next_line.a

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< -I $(INCLUDES)

clean:
	make clean -C $(LIBFT)
	make clean -C $(GNL)
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all
