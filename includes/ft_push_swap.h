/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:09:35 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/03 14:18:47 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */
# include "../libft/libft.h"
/* ************************************************************************** */
/*                                  TYPEDEF                                   */
/* ************************************************************************** */
typedef struct s_stacks
{
	int				content;
	struct s_stacks	*next;
}	t_stacks;
/* ************************************************************************** */
/*                                 MAIN PART                                  */
/* ************************************************************************** */
int	main(int argc, const char **argv);

/* ************************************************************************** */
/*                                   TOOLS                                    */
/* ************************************************************************** */
int	ft_push(t_stacks **stack_a, t_stacks **stack_b, char stack_letter);
int	ft_rotate(t_stacks **stack_a, t_stacks **stack_b, char stack_letter);
int	ft_reverse_rotate(t_stacks **stack_a, t_stacks **stack_b, \
	char stack_letter);
int	ft_swap(t_stacks **stack_a, t_stacks **stack_b, char stack_letter);

#endif