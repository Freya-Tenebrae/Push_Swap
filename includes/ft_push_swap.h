/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:09:35 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/21 14:31:22 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line_bonus.h"
/* ************************************************************************** */
/*                                  TYPEDEF                                   */
/* ************************************************************************** */
typedef struct s_stacks
{
	int				content;
	unsigned int	order;
	int				will_be_push;
	struct s_stacks	*next;
}					t_stacks;
/* ************************************************************************** */
/*                                 MAIN PART                                  */
/* ************************************************************************** */
int					main(int argc, const char **argv);
int					ft_push_swap(t_stacks **stack_a, t_stacks **stack_b, \
						unsigned int size, char ***strs);
void				ft_push_swap_custom_sort(t_stacks **stack_a, \
						t_stacks **stack_b, unsigned int size);
void				ft_push_swap_small_stack(t_stacks **stack_a, \
						t_stacks **stack_b, unsigned int size);
void				ft_push_swap_order_radix_sort(t_stacks **stack_a, \
						t_stacks **stack_b, unsigned int size);
/* void				ft_push_swap_quick_sort(t_stacks **stack_a, \             */
/*						t_stacks **stack_b, unsigned int size, int n);        */
/* ************************************************************************** */
/*                                   TOOLS                                    */
/* ************************************************************************** */
/* *************************** Custom Sort Tools **************************** */
void				ft_get_optimised_pivot_a(t_stacks *tmp_stack, \
						unsigned int size);
void				ft_get_optimised_push_a(t_stacks *tmp_stack_a, \
						t_stacks *tmp_stack_b, int *n_rotation_a, \
						int *n_rotation_b);
/* ***************************** Sorting Tools ****************************** */
int					ft_push(t_stacks **stack_a, t_stacks **stack_b, \
						char stack_letter);
int					ft_rotate(t_stacks **stack_a, t_stacks **stack_b, \
						char stack_letter);
int					ft_reverse_rotate(t_stacks **stack_a, t_stacks **stack_b, \
						char stack_letter);
int					ft_swap(t_stacks **stack_a, t_stacks **stack_b, \
						char stack_letter);
/* ************************** Found Position Tools ************************** */
unsigned int		ft_get_last_position_in_stack(t_stacks *stack);
unsigned int		ft_found_position_bigger_under_than_value(t_stacks *stack, \
						unsigned int value);
unsigned int		ft_found_position_smaller_over_than_value(t_stacks *stack, \
						unsigned int value);
unsigned int		ft_found_position_smallest_number(t_stacks *stack);
unsigned int		ft_found_position_bigest_number(t_stacks *stack);
/* **************************** Information Tools *************************** */
void				ft_print_content_stack(t_stacks *stack_a, \
						t_stacks *stack_b);
void				ft_print_order_stack(t_stacks *stack_a, t_stacks *stack_b);
unsigned int		ft_get_size_one_stacks(t_stacks *tmp_stack);
void				ft_get_size_stacks(t_stacks *tmp_stack_a, \
						t_stacks *tmp_stack_b, unsigned int *size_stack_a, \
						unsigned int *size_stack_b);
/* ************************** Memory & Access Tools ************************* */
void				ft_freestrs(char ***strs, int i);
t_stacks			*ft_stack_new(int content);
void				ft_stack_clear(t_stacks **stack);
t_stacks			*ft_stack_last(t_stacks *stack);
void				ft_stack_add_back(t_stacks **astack, t_stacks *new_stack);
/* ****************************** BONUS Tools ******************************* */
int					ft_fetch_actions(char ***standart_read);

#endif