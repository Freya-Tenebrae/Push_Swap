/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:09:35 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/08 12:33:16 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */
# include <unistd.h>
# include "../libft/libft.h"
/* ************************************************************************** */
/*                                  TYPEDEF                                   */
/* ************************************************************************** */
typedef struct s_stacks
{
	int				content;
	struct s_stacks	*next;
}					t_stacks;
/* ************************************************************************** */
/*                                 MAIN PART                                  */
/* ************************************************************************** */
int					main(int argc, const char **argv);
/* ************************************************************************** */
/*                                   TOOLS                                    */
/* ************************************************************************** */
int					ft_push(t_stacks **stack_a, t_stacks **stack_b, \
						char stack_letter);
int					ft_rotate(t_stacks **stack_a, t_stacks **stack_b, \
						char stack_letter);
int					ft_reverse_rotate(t_stacks **stack_a, t_stacks **stack_b, \
						char stack_letter);
int					ft_swap(t_stacks **stack_a, t_stacks **stack_b, \
						char stack_letter);
void				ft_print_stack(t_stacks *stack_a, t_stacks *stack_b);
t_stacks			*ft_stack_new(int content);
void				ft_stack_clear(t_stacks **stack);
t_stacks			*ft_stack_last(t_stacks *stack);
void				ft_stack_add_back(t_stacks **astack, t_stacks *new_stack);

#endif