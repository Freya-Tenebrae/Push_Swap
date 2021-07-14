/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:09:35 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/14 03:23:46 by cmaginot         ###   ########.fr       */
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
/* ************************************************************************** */
/*                                  TYPEDEF                                   */
/* ************************************************************************** */
typedef struct s_stacks
{
	int				content;
	unsigned int	order;
	struct s_stacks	*next;
}					t_stacks;
/* ************************************************************************** */
/*                                 MAIN PART                                  */
/* ************************************************************************** */
int					main(int argc, const char **argv);
int					ft_push_swap(t_stacks **stack_a, t_stacks **stack_b, \
						unsigned int size, char ***strs);
void				ft_push_swap_small_stack(t_stacks **stack_a, \
						t_stacks **stack_b, unsigned int size);
void				ft_push_swap_order_radix_sort(t_stacks **stack_a, \
						t_stacks **stack_b, unsigned int size);
/* ************************************************************************** */
/*                                   TOOLS                                    */
/* ************************************************************************** */
/* ***************************** Sorting Tools ****************************** */
int					ft_push(t_stacks **stack_a, t_stacks **stack_b, \
						char stack_letter);
int					ft_rotate(t_stacks **stack_a, t_stacks **stack_b, \
						char stack_letter);
int					ft_reverse_rotate(t_stacks **stack_a, t_stacks **stack_b, \
						char stack_letter);
int					ft_swap(t_stacks **stack_a, t_stacks **stack_b, \
						char stack_letter);
/* ****************************** Other Tools ******************************* */
void				ft_freestrs(char ***strs, int i);
t_stacks			*ft_stack_new(int content);
void				ft_stack_clear(t_stacks **stack);
t_stacks			*ft_stack_last(t_stacks *stack);
void				ft_stack_add_back(t_stacks **astack, t_stacks *new_stack);
void				ft_print_content_stack(t_stacks *stack_a, \
						t_stacks *stack_b);
void				ft_print_order_stack(t_stacks *stack_a, t_stacks *stack_b);
int					ft_found_position_smallest_number(t_stacks *stack);
int					ft_found_position_bigest_number(t_stacks *stack);

#endif